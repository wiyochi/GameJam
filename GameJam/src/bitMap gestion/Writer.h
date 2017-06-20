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
	bool isReleasedState() const;
	void reset();
	void end();
private:
	bool m_next;
	bool m_isReleased;
	int m_compteur;
	ofstream* m_file;
};

