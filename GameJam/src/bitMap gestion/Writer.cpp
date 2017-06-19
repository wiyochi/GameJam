#include "Writer.h"

Writer::Writer(ofstream* file)
{
	m_next = false;
	m_isReleased = true;
	m_compteur = 0;
	m_file = file;
}


Writer::~Writer()
{
}

void Writer::nextIs()
{
	m_next = true;
	m_isReleased = false;
}

void Writer::write()
{
	if (m_next && !m_isReleased)
	{
		*m_file << m_compteur;
		*m_file << " ";
		m_next = false;
		m_compteur = 0;
	}
	else
	{
		m_compteur++;
	}
		
}

bool Writer::isReleasedState() const
{
	return m_isReleased;
}

void Writer::reset()
{
	m_isReleased = true;
}
