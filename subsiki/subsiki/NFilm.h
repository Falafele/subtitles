#pragma once
#include "NSubtitles.h"

enum Type { SRT, TXT, SUB };

// subtitles for one film
class Film {
	friend class Base;
	friend class Subsiki;
protected:
	vector <Subtitle>subtitles; // array with subtitles for one film
	string title;


	Film *next, *prev;
public:

	Film();
	Film(wstring FName); // scan subtitles from file
	~Film();

	// accessors
	void SetTitle(string t);
	string GetTitle();
	void SetNext(Film *n);
	Film *GetNext();
	void SetPrev(Film *p);
	Film *GetPrev();
	string SubToString();



	void PrintToFile(Type typeOfSubtitles, wstring fileName);		// print as subtitles
	bool ScanFromBase(ifstream &file);			// scan from base file   if next subtitles return 0, else return 1
	void PrintToBase(ofstream &file);			// print to base file


												// moving whole subtitles
	void MoveSub(int mover);
	void MoveStartSub(int mover);
	void MoveEndSub(int mover);

};



// Base with films
class Base {
	Film *baseHead; // Head of base list

public:
	// constructors
	Base();
	Base(Film *head);
	~Base();

	//accessors
	Film*GetBaseHead();

	// operations on base
	void AddToBase(Film film);
	void DeleteFromBase(string name);
	void DeleteBase();

	// BaseFile
	void ScanFromBaseFile();
	void PrintToBaseFile();
	void PrintBase(Film *Head, ofstream &file);

};