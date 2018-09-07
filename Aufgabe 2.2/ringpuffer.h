#ifndef _RINGPUFFER_H
#define _RINGPUFFER_H
#include "RingNode.h"
#include <string>
#include <iostream>

class RingPuffer
{
	/*
	Die Klasse Ringpuffer dient zur Verwaltung von Ringnodes (Node). Mit Hilfe der Klasse Ringpuffer
	kann ein Ringpuffer realisiert werden.
	*/
private:
	RingNode * anker;			// Zeiger auf Ankernode
	int _size;					// Gr��e des Ringpuffers
	int _maxSize;		// maximale Gr��e des Ringpuffers
public:
	RingPuffer(
		
	);
	~RingPuffer();
	bool addNode(std::string description, std::string data);		// Einf�gen eines neuen RingNodes
	void search(std::string key);		// Suchen nach einem Datenbanksatz
	void outputRingpuffer(); //Rinpuffer Inhalt formatiert ausgeben
	RingNode * getAnker(void);//Testweise den Anker holen 
	int getSize(void);
	void setSize(int key);
	
};

#endif