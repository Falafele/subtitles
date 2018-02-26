#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_subsiki.h"
#include "NFilm.h"

class subsiki : public QMainWindow
{
	Q_OBJECT

	Base MBase;
	Film * currFilm = nullptr;

public:
	subsiki(QWidget *parent = Q_NULLPTR);

	bool is_digits(const string & str);

private:
	Ui::subsikiClass ui;
	private slots:
	void Add_currFilm_To_Base();
	void Clear_currFilm();
	void Move_sub();
	void open_file();
	void Save_File();

};
