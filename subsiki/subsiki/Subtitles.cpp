#include "Subtitles.h"

// constructors
Subtitle::Subtitle()
{
	counter = shour = sminute = ssecond = smsecond = ehour = eminute = esecond = emsecond = 0;
}

Subtitle::Subtitle(string t, int c, int sh, int sm, int ss, int sms, int eh, int em, int es, int ems)
{
	text = t;
	counter = c;
	shour = sh; sminute = sm; ssecond = ss; smsecond = sms;
	ehour = eh; eminute = em; esecond = es; emsecond = ems;
}

Subtitle::~Subtitle()
{
}

int Subtitle::GetCounter()
{
	return counter;
}

void Subtitle::SetCounter(int c)
{
	counter = c;
}

// file
void Subtitle::ScanAsBase(ifstream & file)
// scan as base subtitle
{
	// counter has been set in Film::ScanFromBase
	file >> shour >> sminute >> ssecond >> smsecond;
	file >> ehour >> eminute >> esecond >> emsecond;
	string textbuffer;
	getline(file, textbuffer);
	do {
		getline(file, textbuffer);
		if (textbuffer != "")
			text += textbuffer + "\n";
	} while (textbuffer != "");
}

void Subtitle::PrintAsBase(ofstream & file)
// print as base subtitle
{
	file << counter << endl;
	file << shour << endl << sminute << endl << ssecond << endl << smsecond << endl;
	file << ehour << endl << eminute << endl << esecond << endl << emsecond << endl;
	file << text;
}

void Subtitle::ScanAsSRT(ifstream &file)
/*
Subtitle in file:
1									- counter
00:00:00,000 --> 00:00:00,000		- start time(h:m:s,ms) --> end time(h:m:s,ms)
text
another line
...
- one empty line
*/
{
	{
		file >> this->counter;
		string sbuffer, ebuffer;  // buffers with start and end time hh:mm:ss,ms
		string textbuffer;
		file >> sbuffer;
		file >> ebuffer;
		file >> ebuffer;
		getline(file, textbuffer);

		string tmp;    // buffer used to convert time

					   // start time
		tmp = sbuffer[0];
		tmp += sbuffer[1];
		shour = atoi(tmp.c_str());
		tmp = sbuffer[3];
		tmp += sbuffer[4];
		sminute = atoi(tmp.c_str());
		tmp = sbuffer[6];
		tmp += sbuffer[7];
		ssecond = atoi(tmp.c_str());
		tmp = sbuffer[9];
		tmp += sbuffer[10];
		tmp += sbuffer[11];
		smsecond = atoi(tmp.c_str());

		//end time
		tmp = ebuffer[0];
		tmp += ebuffer[1];
		ehour = atoi(tmp.c_str());
		tmp = ebuffer[3];
		tmp += ebuffer[4];
		eminute = atoi(tmp.c_str());
		tmp = ebuffer[6];
		tmp += ebuffer[7];
		esecond = atoi(tmp.c_str());
		tmp = ebuffer[9];
		tmp += ebuffer[10];
		tmp += ebuffer[11];
		emsecond = atoi(tmp.c_str());

		do {
			getline(file, textbuffer);
			if (textbuffer != "")
				text += textbuffer + "\n";
		} while (textbuffer != "");
	}
}
void Subtitle::ScanAsTXT(ifstream & file)
/*
Subtitle ine file:
[000][111]text|another_line|...        - [start time][end time]text.	'|'- new line.
{000}{111}text|another_line|...        - second version of subtitle
*/
{
	string line;
	string time[2]{ "","" };
	getline(file, line);
	int j = 1;
	// Scan time
	for (int i = 0; i < 2; i++) {
		for (j; line[j] != ']' && line[j] != '}'; j++) {
			time[i] += line[j];
		}
		j += 2;
	}
	j--;  //set pointer at first character of text

		  // set time in msecond
	smsecond = atoi(time[0].c_str());
	smsecond *= 100;
	emsecond = atoi(time[1].c_str());
	emsecond *= 100;
	Move(0);	//convert time to hour, minute, second, msecond

				// set text from string line
	for (j; j < line.length(); j++) {
		if (line[j] == '|')
			text += '\n';
		else
			text += line[j];
	}
	text += '\n';
}
/*
SUB
*/

void Subtitle::PrintAsSRT(ofstream & file)
/*
Subtitle in file:
1									- counter
00:00:00,000 --> 00:00:00,000		- start time(h:m:s,ms) --> end time(h:m:s,ms)
text
another line
...
- one empty line
*/
{
	{
		file << counter << endl;
		//print start time
		if (shour < 9)
			file << "0";
		file << shour << ":";
		if (sminute < 9)
			file << "0";
		file << sminute << ":";
		if (ssecond < 9)
			file << "0";
		file << ssecond << ",";
		if (smsecond < 100)
			file << "0";
		if (smsecond < 10)
			file << "0";
		file << smsecond << " --> ";

		// print end time
		if (ehour < 9)
			file << "0";
		file << ehour << ":";
		if (eminute < 9)
			file << "0";
		file << eminute << ":";
		if (esecond < 9)
			file << "0";
		file << esecond << ",";
		if (emsecond < 100)
			file << "0";
		if (emsecond < 10)
			file << "0";
		file << emsecond << endl;
		file << text << endl;
	}

}
void Subtitle::PrintAsTXT(ofstream & file)
/*
Subtitle ine file:
[000][111]text|another_line|...        - [start time][end time]text.	'|'- new line.
*/
{
	int stime, etime;  //start and end time in ds
	stime = shour * 36000 + sminute * 600 + ssecond * 10 + smsecond * 0, 01;
	etime = ehour * 36000 + eminute * 600 + esecond * 10 + emsecond * 0, 01;

	vector <char>textToFile;
	for (int i = 0; i < text.length(); i++) {

		if (text[i] == '\n')
			textToFile.push_back('|');
		else
			textToFile.push_back(text[i]);
	}

	// printing to file
	file << "[" << stime << "]" << "[" << etime << "]";
	for (int i = 0; i < textToFile.size(); i++)
		file << textToFile[i];
	file << endl;
}
/*
SUB
*/

//movers
void Subtitle::MoveStart(int mover)
{
	smsecond += mover;
	if ((shour * 3600000 + sminute * 60000 + ssecond * 1000)<(0 - 999 - smsecond))
		smsecond -= mover;

	if (smsecond >= 0) {
		// transfer smsecond to ssecond
		if (smsecond > 999) {
			int a = smsecond / 1000;
			smsecond -= a * 1000;
			ssecond += a;
			// transfer ssecond to sminute
			if (ssecond > 59) {
				a = ssecond / 60;
				ssecond -= a * 60;
				sminute += a;
				// transfer sminute to shour
				if (sminute > 59) {
					a = sminute / 60;
					sminute -= a * 60;
					shour += a;
				}
			}
		}
	}
	// if smsecond < 0
	else {
		//transfer smsecond to ssecond
		if (smsecond < 0) {
			int a = smsecond / 1000;
			if (a == 0)
				ssecond--;
			else
				ssecond += a;
			if (a == -1)
				ssecond--;
			if (smsecond % 1000 != 0) {
				a--;
			}
			smsecond -= a * 1000;
			// transfer ssecond to sminute
			if (ssecond < 0) {
				a = ssecond / 60;
				if (a == 0)
					sminute--;
				else
					sminute += a;
				if (a == -1)
					sminute--;
				if (ssecond % 60 != 0) {
					a--;
				}
				ssecond -= a * 60;
				// transfer sminute to shour
				if (sminute < 0) {
					a = sminute / 60;
					if (a == 0)
						shour--;
					else
						shour += a;
					if (a == -1)
						shour--;
					if (sminute % 60 != 0) {
						a--;
					}
					sminute -= a * 60;
				}
			}
		}
	}
}
void Subtitle::MoveEnd(int mover)
{
	emsecond += mover;
	if ((ehour * 3600000 + eminute * 60000 + esecond * 1000)<(0 - emsecond - 999))
		emsecond -= mover;

	if (emsecond >= 0) {
		// transfer smsecond to ssecond
		if (emsecond > 999) {
			int a = emsecond / 1000;
			emsecond -= a * 1000;
			esecond += a;
			// transfer ssecond to sminute
			if (esecond > 59) {
				a = esecond / 60;
				esecond -= a * 60;
				eminute += a;
				// transfer sminute to shour
				if (eminute > 59) {
					a = eminute / 60;
					eminute -= a * 60;
					ehour += a;
				}
			}
		}
	}
	// if smsecond < 0
	else {
		//transfer smsecond to ssecond
		if (emsecond < 0) {
			int a = emsecond / 1000;
			if (a == 0)
				esecond--;
			else
				esecond += a;
			if (a == -1)
				esecond--;
			if (emsecond % 1000 != 0) {
				a--;
			}
			emsecond -= a * 1000;
			// transfer ssecond to sminute
			if (esecond < 0) {
				a = esecond / 60;
				if (a == 0)
					eminute--;
				else
					eminute += a;
				if (a == -1)
					eminute--;
				if (esecond % 60 != 0) {
					a--;
				}
				esecond -= a * 60;
				// transfer sminute to shour
				if (eminute < 0) {
					a = eminute / 60;
					if (a == 0)
						ehour--;
					else
						ehour += a;
					if (a == -1)
						ehour--;
					if (eminute % 60 != 0) {
						a--;
					}
					eminute -= a * 60;
				}
			}
		}
	}
}
void Subtitle::Move(int mover)
{
	MoveStart(mover);
	MoveEnd(mover);
}