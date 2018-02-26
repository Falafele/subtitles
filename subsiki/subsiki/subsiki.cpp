#include "subsiki.h"
#include <QFileDialog>
#include <QTextStream>

subsiki::subsiki(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.wrong_mover->hide();
	ui.radioButton_up->click();
	connect(ui.closeButton, SIGNAL(clicked()), this, SLOT(Clear_currFilm()));
	connect(ui.Save, SIGNAL(clicked()), this, SLOT(Save_File()));
	connect(ui.Move, SIGNAL(clicked()), this, SLOT(Move_sub()));
	connect(ui.Open, SIGNAL(clicked()), this, SLOT(open_file()));
	
}

bool subsiki::is_digits(const string &str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}


void subsiki::Add_currFilm_To_Base()
{


	// To jest Ÿleeeeeeeeee
	MBase.AddToBase(*currFilm);




}

void subsiki::Clear_currFilm()
{
	if (currFilm == nullptr)
		return;
	ui.Title->setText("Tytul Filmu");
	delete currFilm;
	int i = 0;
	i--;
	currFilm = nullptr;
}

void subsiki::Move_sub()
{
	if (!ui.wrong_mover->isHidden())
		ui.wrong_mover->hide();
	QString qmover = ui.line_mover->text();
	ui.line_mover->clear();
	string smover = qmover.toStdString();
	if (!is_digits(smover)) {
		ui.wrong_mover->setText("Podaj liczbe\ncalkowita");
		ui.wrong_mover->show();
	}
	else if (currFilm == nullptr) {
		ui.wrong_mover->setText("Nie wybrano\n napisow");
		ui.wrong_mover->show();
	}
	else {
		int mover = atoi(smover.c_str());
		if (ui.radioButton_down->isChecked())
			mover -= 2 * mover;
		currFilm->MoveSub(mover);
		string sub = currFilm->SubToString();
		QString qsub = QString::fromStdString(sub);
		ui.Subtitles->setText(qsub);
	}
}

void subsiki::open_file()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Otworz..."), "/home/", tr("Pliki srt,txt (*.srt *.txt)"));

	QStringList list = fileName.split('/');
	QString fname = list[list.size() - 1];
	//ifstream
	wstring SFileName = fileName.toStdWString();
	if (!SFileName.empty()) {
		Film * cFilm = new Film(SFileName);
		currFilm = cFilm;


		// QFile
		QFile qfile(fileName);
		if (!qfile.open(QIODevice::ReadOnly | QIODevice::Text))
			return;


		QString text;
		QTextStream stream(&qfile);
		text = stream.readAll();
		ui.Title->setText(fname);
		ui.Subtitles->setText(text);
		qfile.close();
	}
}

void subsiki::Save_File()
{
	if (currFilm == nullptr)
		return;
	QString fileName = QFileDialog::getSaveFileName(this, tr("Zapisz"), "/home/", tr("Plik srt (*.srt);; Plik txt (*.txt)"));
	wstring wFileName = fileName.toStdWString();
	string type, temp;
	for (int i = wFileName.length() - 1; i >= 0; i--) {
		if (wFileName[i] == '.')
			break;
		temp = type;
		type = wFileName[i];
		type += temp;
	}
	if (type == "srt")
		currFilm->PrintToFile(SRT, wFileName);
	if (type == "txt")
		currFilm->PrintToFile(TXT, wFileName);

}
