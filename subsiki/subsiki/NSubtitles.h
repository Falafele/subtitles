#pragma once
#include "NLibraries.h"

// one subtitle in film
class Subtitle {

protected:
	string text;	// with endl after text
	int counter;
	// time to start and end printing text (h,m,s,ms)
	int shour, sminute, ssecond, smsecond;
	int ehour, eminute, esecond, emsecond;

public:

	// constructors
	Subtitle();
	Subtitle(string t, int c, int sh, int sm, int ss, int sms, int eh, int em, int es, int ems);
	~Subtitle();

	// accessors
	int GetCounter();
	void SetCounter(int c);
	int Getshour(); int Getsminute(); int Getssecond(); int Getsmsecond();
	int Getehour(); int Geteminute(); int Getesecond(); int Getemsecond();
	string GetText();

	//TODO

	//file

	// base file
	void ScanAsBase(ifstream &file);
	void PrintAsBase(ofstream &file);

	// scan from file
	void ScanAsSRT(ifstream &file);
	void ScanAsTXT(ifstream &file);
	void ScanAsSUB(ifstream &file);

	// print to file
	void PrintAsSRT(ofstream &file);
	void PrintAsTXT(ofstream &file);
	//void PrintAsSUB(ofstream &file);

	// movers
	void MoveStart(int mover); // mover in ms
	void MoveEnd(int mover);
	void Move(int mover);
};
