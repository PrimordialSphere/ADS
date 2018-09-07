#include "ringpuffer.h"
#include <iostream>


RingPuffer::RingPuffer()
{
	anker = new RingNode();
	anker->setAge(0);
	_size = 0;
	_maxSize = 6;
	
}

RingPuffer::~RingPuffer()
{
	RingNode * tmp = anker;
	RingNode * del_next;
	for (int i = 0; i < 6; i++)
	{
		del_next = anker->getNext();
		anker->setNext(del_next->getNext());
		delete del_next;
	}
}

bool RingPuffer::addNode(std::string description, std::string data)
{

	std::cout << _size << std::endl;
	if (this->getSize() == 0) {
		anker->setDescription(description);
		anker->setData(data);
		anker->setAge(0);
		anker->setNext(anker);
		_size++;
		std::cout << _size << std::endl;
		return true;
}
	else if (this->getSize() < _maxSize )
	{
		RingNode * tmpAnker = anker;
		RingNode * neuerEintrag = new RingNode();
		neuerEintrag->setDescription(description);
		neuerEintrag->setData(data);
		neuerEintrag->setAge(0);
		
		while (tmpAnker->getNext() != anker)
		{
			tmpAnker = tmpAnker->getNext();
		}

		tmpAnker->setNext(neuerEintrag);
		neuerEintrag->setNext(anker);
		anker = neuerEintrag;
		
		_size++;

		tmpAnker = anker;
		while (tmpAnker->getNext() != anker)
		{
			tmpAnker = tmpAnker->getNext();
			tmpAnker->inkrementAge();
		}
		
		std::cout << anker->getNext()->getDescription() << std::endl;
		
		return true;
	}
	else if (this->getSize() >= _maxSize)
	{
		RingNode * tmpAnker;
		tmpAnker = anker;
		RingNode * newEntry = new RingNode();
		newEntry->setDescription(description);
		newEntry->setData(data);
		newEntry->setAge(0);

		while (tmpAnker->getAge() != 5)
		{
			tmpAnker = tmpAnker->getNext();
		}

		newEntry->setNext(tmpAnker->getNext());

		while (tmpAnker->getNext()->getAge() != 5)
		{
			tmpAnker = tmpAnker->getNext();
		}

		tmpAnker->setNext(newEntry);

		anker = newEntry;

		tmpAnker = anker;
		while (tmpAnker->getNext() != anker)
		{
			tmpAnker = tmpAnker->getNext();
			tmpAnker->inkrementAge();
		}
		

		return true;
	}
	return false;
}


void RingPuffer::search(std::string key)
{
	RingNode * tmpAnker;
	tmpAnker = anker->getNext();
	


	while (tmpAnker != anker)
	{
		if (tmpAnker->getData() == key) { break; }
		tmpAnker = tmpAnker->getNext();
		
	}

	if (tmpAnker->getData() == key) {
		std::cout << "+ Gefunden in Backup " << tmpAnker->getAge() << ", Beschreibung: " << tmpAnker->getDescription() << ", Daten: " << tmpAnker->getData() << std::endl;
	}
	else
	{
		std::cout << "+ Datensatz konnte nicht gefunden werden" << std::endl;
	}






}

void RingPuffer::outputRingpuffer()
{
	RingNode * tmp = anker;
	std::string  description, data;
	int age;

	while (tmp->getNext() != anker) {
		
		age = tmp->getAge();
		description = tmp->getDescription();
		data = tmp->getData();
		std::cout << "OldAge: " << age << ", Descr: " << description << ", Data: " << data << std::endl;
		std::cout << std::string(34, '-') << std::endl;




		tmp = tmp->getNext();
	}

	age = tmp->getAge();
	description = tmp->getDescription();
	data = tmp->getData();
	std::cout << "OldAge: " << age << ", Descr: " << description << ", Data: " << data << std::endl;
	std::cout << std::string(34, '-') << std::endl;

}

RingNode * RingPuffer::getAnker(void)
{
	return anker;
}

int RingPuffer::getSize(void)
{
	return _size;
}

void RingPuffer::setSize(int key)
{
	_size = key;
}
