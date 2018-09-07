#ifndef _RINGNODE_H
#define _RINGNODE_H
#include <string>
#include <iostream>

class RingNode
{
	/*
	Die Klasse List dient zur Verwaltung von Ringnodes. Mit Hilfe der Klasse Ringpuffer
	kann ein Stapel oder Warteschlange realisiert werden.
	*/
private:
	int OldAge;				//Alter des Nodes
	std::string Description;		//Beschreibung des Nodes
	std::string SymbolicData;		//Daten des Nodes
	RingNode * next;				// Nachfolger des Nodes im Ring

	
public:
	RingNode(); 
	~RingNode();
	int getAge(void);				//Getter f�r das int OldAge
	void setAge(int key);			//Setter f�r das int OldAge
	std::string getDescription(void); //Getter f�r den String Description
	void setDescription(std::string key); //Setter f�r den String Description
	std::string getData(void); //Getter f�r den String Data
	void setData(std::string key); //Setter f�r den String Data
	void setNext(RingNode * key); //Setter f�r den Next Pointer
	RingNode * getNext(void); //Geter f�r den NextPointer;
	void inkrementAge(void); //Das Alter um 1 erh�hen


};

#endif