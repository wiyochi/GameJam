#include "Writer.h"

Writer::Writer(ofstream* file)
{
	m_next = false;
	m_compteur = 0;
	m_file = file;
	*m_file << "L:";
}


Writer::~Writer()
{
}

void Writer::nextIs()
{
	m_next = true;
}

void Writer::write()
{
	if (m_next)
	{
		*m_file << m_compteur;
		*m_file << "&";
		m_next = false;
		m_compteur = 0;
	}
	else
	{
		m_compteur++;
	}
		
}
