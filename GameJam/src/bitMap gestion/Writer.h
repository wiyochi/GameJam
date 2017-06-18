#pragma once
#include <fstream>

using namespace std;

class Writer
{
public:
	Writer(ofstream* file);
	~Writer();
	void nextIs();
	void write();
private:
	bool m_next;
	int m_compteur;
	ofstream* m_file;
};

