#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <string>
#include <iostream>

template <class T>
class List 
{
/* 
	Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse List
	kann ein Stapel oder Warteschlange realisiert werden.
*/
private:
	struct form { std::string start = "<< "; std::string zwischen = ", "; std::string ende = " >>\n"; } _form;
	Node<T> * head, * tail;			// Zeiger auf Kopf- und End-Element
	int _size;						// Länge der Kette
	bool temp;						// normalerweise false; ist true, wenn es sich um eine temporäre Liste handelt
									// die innerhalb der überladenen Operatoren angelegt wird
public:
	List();
	~List();
	void InsertFront(T key);		// Einfügen eines Knotens am Anfang
	void InsertBack(T key);		// Einfügen eines Knotesn am Ende
	bool getFront(T & key);		// Entnehmen eines Knoten am Anfang
	bool getBack(T & key);		// Entnehmen eines Knoten am Ende
	bool del(T key);				// löschen eines Knotens [key]
	bool search(T key);			// Suchen eines Knoten
	bool swap(T key1, T key2);	// Knoten in der Liste vertauschen
	int size(void);					// Größe der Lise (Anzahl der Knoten)
	bool test(void);				// Überprüfen der Zeigerstruktur der Liste
	void format(const std::string & start, const std::string & zwischen, const std::string & ende);	// Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
	List<T> & operator = (const List<T> & _List);						// Zuweisungsoperator definieren
	List<T> & operator = (const List<T> * _List);						// Zuweisungsoperator definieren
	List<T> & operator + (const List<T> & List_Append);					// Listen zusammenführen zu einer Liste
	List<T> & operator + (const List<T> * List_Append);					// Listen zusammenführen zu einer Liste
	template <typename Tf>
	friend std::ostream & operator << (std::ostream & stream, const List<Tf> & Liste);		// Ausgabeoperator überladen
	template <typename Tf>
	friend std::ostream & operator << (std::ostream & stream, const List<Tf> * Liste);		// Ausgabeoperator überladen
};



template <class T>
List<T>::List()
{
	head = new Node<T>;
	tail = new Node<T>;
	_size = 0;
	temp = false;
	head->next = tail;
	tail->prev = head;
}
template <class T>
List<T>::~List()
{
	Node<T> * tmp_node;
	Node<T> * tmp_del;
	tmp_node = head;
	while (tmp_node->next != 0)
	{
		tmp_del = tmp_node;
		tmp_node = tmp_node->next;
		delete tmp_del;
	}
}
template <class T>
void List<T>::InsertFront(T key)
{
	Node<T> * tmp = new Node<T>;
	tmp->prev = head;
	tmp->next = head->next;
	head->next->prev = tmp;
	head->next = tmp;
	tmp->key = key;

	_size++;

}
template <class T>
void List<T>::InsertBack(T key)
{
	Node<T> * tmp = new Node<T>;
	tmp->next = tail;
	tmp->prev = tail->prev;
	tail->prev->next = tmp;
	tail->prev = tmp;
	tmp->key = key;
	_size++;
}
template <class T>
bool List<T>::getFront(T & key)
{

	if (head->next != tail) {
		Node * tmp = new Node<T>;
		tmp = head->next;
		key = tmp->key;
		head->next = tmp->next;
		tmp->next->prev = head;
		_size--;
		return true;
	}
	else { return false; }
}
template <class T>
bool List<T>::getBack(T & key)
{

	if (tail->prev != head) {
		Node<T> * tmp = new Node<T>;
		tmp = tail->prev;
		key = tmp->key;
		tail->prev = tmp->prev;
		tmp->prev->next = tail;
		_size--;
		return true;
	}
	else { return false; }

}
template <class T>
bool List<T>::del(T key)
{
	T j = key;
	Node * tmp = new Node<T>;
	tmp = head;
	while (tmp->next != head) {
		if (tmp->key == j) {
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			_size--;
			return true;
		}
		else { return false; }
		tmp = tmp->next;
	}

	return false;
}
template <class T>
bool List<T>::search(T key)
{
	T j = key;
	T k;
	Node<T> * tmp = new Node<T>;
	tmp = head->next;
	while (tmp->next != tail) {
		k = tmp->key;

		if (k == j) {

			return true;
		}

		tmp = tmp->next;

	}
	return false;
}
template <class T>
bool List<T>::swap(T key1, T key2)
{
	Node<T> * tmp = new Node<T>;
	tmp = head->next;
	Node<T> * tmp1 = new Node<T>;
	Node<T> * tmp2 = new Node<T>;

	T * j = &key1;
	while (tmp->next != tail) {
		if (tmp->key == *j) {
			tmp1 = tmp;
			T * k = &key2;
			while (tmp->next != head) {
				if (tmp->key == *k) {
					tmp2 = tmp;

					Node<T> * tmp3 = new Node<T>;
					tmp3->prev = tmp1->prev;
					tmp3->next = tmp1->next;
					Node<T> * tmp4 = new Node<T>;
					tmp4->next = tmp2->next;
					tmp4->prev = tmp2->prev;

					tmp2->prev = tmp3->prev;
					tmp2->next = tmp3->next;
					tmp3->next->prev = tmp2;
					tmp3->prev->next = tmp2;

					tmp1->prev = tmp4->prev;
					tmp1->next = tmp4->next;
					tmp4->next->prev = tmp1;
					tmp4->prev->next = tmp1;

					return true;
				}
				tmp = tmp->next;
			}
		}
		tmp = tmp->next;
	}
	return false;



}
template <class T>
int List<T>::size(void)
{

	int j = _size;
	return j;

}
template <class T>
bool List<T>::test(void)
{
	Node<T> * tmp = new Node<T>;
	tmp = head;
	while (tmp->next != tail)
	{
		tmp = tmp->next;
	}
	if (tmp = tail) {
		while (tmp->prev != head)
		{
			if (tmp = head)
			{
				return true;
			}
			else
			{
				return false;

			}
		}
	}
	else
	{
		return false;
	}
	return false;
}

template <class T>
void List<T>::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}

template <class T>
List<T> & List<T>::operator = (const List<T> & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List.head->next;
	while (tmp_node != _List.tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List.temp) delete & _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template <class T>
List<T> & List<T>::operator = (const List<T> * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node<T> * tmp_node;
	if (_size)
	{
		Node<T> * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventuell vorhandenen Knoten in this löschen
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
		_size = 0;
		head->next = tail;
		tail->prev = head;
	}
	tmp_node = _List->head->next;
	while (tmp_node != _List->tail)
	{
		InsertBack(tmp_node->key);
		tmp_node = tmp_node->next;
	}
	if (_List->temp) delete _List;		// ist die Übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

template <class T>
List<T> & List<T>::operator + (List<T> const & List_Append)
{
	Node<T> * tmp_node;
	List * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List<T>;					// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append._size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append.head->next;
		while (tmp_node != List_Append.tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append.temp) delete & List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}

template <class T>
List<T> & List<T>::operator + (List<T> const * List_Append)
{
	Node<T> * tmp_node;
	List * tmp;
	if (temp) {								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List<T>;					// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->_size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append->head->next;
		while (tmp_node != List_Append->tail) {
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->temp) delete List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}


template <class Tf>
std::ostream & operator << (std::ostream  & stream, const List<Tf> & Liste)
{
	stream << Liste._form.start;
	for (Node<Tf> * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

template <class Tf>
std::ostream & operator << (std::ostream  & stream, const List<Tf> * Liste)
{
	stream << Liste->_form.start;
	for (Node<Tf> * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

#endif
