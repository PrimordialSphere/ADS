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
	int _size;					// Größe des Ringpuffers
	int _maxSize;		// maximale Größe des Ringpuffers
public:
	RingPuffer(
		
	);
	~RingPuffer();
	bool addNode(std::string description, std::string data);		// Einfügen eines neuen RingNodes
	void search(std::string key);		// Suchen nach einem Datenbanksatz
	void outputRingpuffer(); //Rinpuffer Inhalt formatiert ausgeben
	RingNode * getAnker(void);//Testweise den Anker holen 
	int getSize(void);
	void setSize(int key);
	
};

#endif