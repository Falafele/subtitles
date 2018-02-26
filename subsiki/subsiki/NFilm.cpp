#include "NFilm.h"
#include <codecvt>
#include <sstream>


Film::Film()
{
	next = prev = nullptr;
}

Film::Film(wstring FileName)
{
	next = prev = nullptr;
	ifstream file;
	file.open(FileName);
	int a = 0;
	if (!file.is_open())
		a = 8;

	// this for loops save file's name and check its type
	int i = FileName.length() - 1;
	string typeOfFile;
	string temp;
	for (i; i >= 0; i--) {
		if (FileName[i] == '.') {
			i--;
			break;
		}
		temp = typeOfFile;
		typeOfFile = FileName[i];
		typeOfFile += temp;
	}

	for (i; i >= 0; i--) {
		if (FileName[i] == '/')
			break;
		temp = title;
		title = FileName[i];
		title += temp;

	}
	

	// loop for scan subtitles from file

	i = 1;   // to set counter while ScanFromTXT
	while (!file.eof()) {
		if (typeOfFile != "srt"&&typeOfFile != "txt")
			break;
		Subtitle buffer;
		if (typeOfFile == "srt")
			buffer.ScanAsSRT(file);
		if (typeOfFile == "txt") {
			buffer.SetCounter(i);
			buffer.ScanAsTXT(file);
		}
		//	if (typeOfFile == "sub")
		//		buffer.ScanAsSUB(file);
		i++;
		subtitles.push_back(buffer);
	}
	file.close();
}

Film::~Film()
{
}

void Film::SetTitle(string t)
{
	title = t;
}

string Film::GetTitle()
{
	return title;
}

void Film::SetNext(Film * n)
{
	next = n;
}

Film * Film::GetNext()
{
	return next;
}

void Film::SetPrev(Film * p)
{
	prev = p;
}

Film * Film::GetPrev()
{
	return prev;
}

string Film::SubToString()
{
	string sub;

	for (int i = 0; i < subtitles.size(); i++) {

		stringstream counter;
		stringstream sh; stringstream sm; stringstream ss; stringstream sms;
		stringstream eh; stringstream em; stringstream es; stringstream ems;

		counter << subtitles[i].GetCounter();

		sh << subtitles[i].Getshour();
		sm << subtitles[i].Getsminute();
		ss << subtitles[i].Getssecond();
		sms << subtitles[i].Getsmsecond();

		eh << subtitles[i].Getehour();
		em << subtitles[i].Geteminute();
		es << subtitles[i].Getesecond();
		ems << subtitles[i].Getemsecond();

		sub += counter.str();
		sub += '\n';
		//start time
		if (sh.str().length() > 1)
			sub += sh.str();
		else
			sub += "0" + sh.str();
		sub += ':';
		if (sm.str().length() > 1)
			sub += sm.str();
		else
			sub += "0" + sm.str();
		sub += ':';
		if (ss.str().length() > 1)
			sub += ss.str();
		else
			sub += "0" + ss.str();
		sub += ',';
		if (sms.str().length() > 2)
			sub += sms.str();
		else if (sms.str().length() == 2)
			sub += "0" + sms.str();
		else sub += "00" + sms.str();
		sub += " --> ";

		//end time
		if (eh.str().length() > 1)
			sub += eh.str();
		else
			sub += "0" + eh.str();
		sub += ':';
		if (em.str().length() > 1)
			sub += em.str();
		else
			sub += "0" + em.str();
		sub += ':';
		if (es.str().length() > 1)
			sub += es.str();
		else
			sub += "0" + es.str();
		sub += ',';
		if (ems.str().length() > 2)
			sub += ems.str();
		else if (ems.str().length() == 2)
			sub += "0" + ems.str();
		else sub += "00" + ems.str();
		sub += '\n';

		//text
		sub += subtitles[i].GetText();
		sub += '\n';

	}
	return sub;
}

void Film::PrintToFile(Type typeOfSubtitles, wstring fileName)
{
	ofstream file;

	file.open(fileName);
	// printing subtitles to file
	for (int i = 0; i < subtitles.size(); i++) {
		switch (typeOfSubtitles) {
		case 0: subtitles[i].PrintAsSRT(file);
			break;
		case 1: subtitles[i].PrintAsTXT(file);
			break;
			//	case 2: subtitles[i].PrintAsSUB(file);
			//		break;
		}
	}
	file.close();
}

bool Film::ScanFromBase(ifstream & file)
{
	file >> title;
	int counter;
	string buffer;
	while (!file.eof()) {
		file >> counter;
		Subtitle buffersub;
		buffersub.SetCounter(counter);
		buffersub.ScanAsBase(file);
		subtitles.push_back(buffersub);
		getline(file, buffer);
		if (buffer == "end")
			return true;
		if (buffer == "next subtitles")
			return false;
	}
	return true;
}

void Film::PrintToBase(ofstream & file)
{
	file << title << endl;
	int i = 0;
	for (i; i < subtitles.size() - 1; i++) {
		subtitles[i].PrintAsBase(file);
		file << endl << endl;
	}
	subtitles[i].PrintAsBase(file);
	file << endl;
}

void Film::MoveSub(int mover)
{
	MoveStartSub(mover);
	MoveEndSub(mover);
}

void Film::MoveStartSub(int mover)
{
	for (int i = 0; i < subtitles.size(); i++)
		subtitles[i].MoveStart(mover);
}

void Film::MoveEndSub(int mover)
{
	for (int i = 0; i < subtitles.size(); i++)
		subtitles[i].MoveEnd(mover);
}









// class Base
Base::Base()
{
	baseHead = nullptr;
}

Base::Base(Film * head)
{
	baseHead = head;
	baseHead->SetNext(nullptr);
	baseHead->SetPrev(nullptr);
}

Base::~Base()
{
}

Film * Base::GetBaseHead()
{
	return baseHead;
}



void Base::AddToBase(Film film)
{
	if (baseHead == nullptr)
		baseHead = &film;
	else {
		Film *ptr = baseHead;
		bool end = false;
		while (!end) {
			if (film.title > ptr->title) {
				if (ptr->next == nullptr) {
					ptr->next = &film;
					film.prev = ptr;
					end = true;
				}
				else {
					ptr = ptr->next;
				}
			}
			else if (film.title < ptr->title) {
				if (ptr->prev == nullptr) {
					film.next = ptr;
					baseHead = ptr->prev = &film;
					end = true;
				}
				else {
					film.next = ptr;
					film.prev = ptr->prev;
					ptr->prev = &film;
					film.prev->next = &film;
					end = true;
				}
			}
			else { end = true; }
		}
	}
}

void Base::DeleteFromBase(string name)
{
	Film *element = baseHead;
	while (element != nullptr) {
		if (element->title == name) {
			if (element->prev == nullptr) {
				baseHead = element->next;
				element->next->prev = nullptr;
				delete element;
				break;
			}
			else {
				element->prev->next = element->next;
				if (element->next != nullptr)
					element->next->prev = element->prev;
				delete element;
				break;
			}
		}
		element = element->next;
	}
}

void Base::DeleteBase()
{
	Film *element;
	while (baseHead != nullptr) {
		element = baseHead;
		baseHead = baseHead->next;
		delete element;
	}
}

void Base::ScanFromBaseFile()
{
	if (baseHead == nullptr) {  // prevent reading from file when the program running
		ifstream file;
		file.open("Base.MySub");
		if (file.is_open()) {
			bool end = false;
			Film *ptr = new Film();
			baseHead = ptr;
			while (!end) {
				end = ptr->ScanFromBase(file);
				if (end) break;
				ptr->next = new Film();
				ptr->next->prev = ptr;
				ptr = ptr->next;
			}
		}
	}
}

void Base::PrintToBaseFile()
{
	if (baseHead != nullptr) {		// prevent from creating empty file
		ofstream file;
		file.open("Base.MySub");
		PrintBase(baseHead, file);
		file << "end";
	}
}

void Base::PrintBase(Film *head, ofstream & file)
{
	head->PrintToBase(file);
	if (head->GetNext() != nullptr) {
		file << "next subtitles" << endl;
		PrintBase(head->GetNext(), file);
	}
}
