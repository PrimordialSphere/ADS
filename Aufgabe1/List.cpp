#include "List.h"
List::List()
{
	head = new Node;
	tail = new Node;
	_size = 0;
	temp = false;
	head->next = tail;
	tail->prev = head;
}
List::~List()
{
	Node * tmp_node;
		Node * tmp_del;
		tmp_node = head;
		while (tmp_node->next != 0)
		{
			tmp_del = tmp_node;
			tmp_node = tmp_node->next;
			delete tmp_del;
		}
}
void List::InsertFront(int key)
{
	Node * tmp = new Node; 
	tmp->prev = head;
	tmp->next = head->next;
	head->next->prev = tmp; 
	head->next = tmp; 
	tmp->key = key;
	
	_size++;
	
}
void List::InsertBack(int key)
{
	Node * tmp = new Node;
	tmp->next = tail;
	tmp->prev = tail->prev;
	tail->prev->next = tmp;
	tail->prev = tmp;
	tmp->key = key;
	_size++;
}
bool List::getFront(int & key)
{
	
	if (head->next != tail) {
		Node * tmp = new Node;
		tmp = head->next;
		key = tmp->key;
		head->next = tmp->next;
		tmp->next->prev = head;
		_size--;
		return true;
	}
	else { return false;  }
}
bool List::getBack(int & key)
{
	
	if (tail->prev != head) {
		Node * tmp = new Node;
		tmp = tail->prev;
		key = tmp->key;
		tail->prev = tmp->prev;
		tmp->prev->next = tail;
		_size--;
		return true;
	}
	else { return false; }
	
}
bool List::del(int key)
{
	int j = key;
	Node * tmp = new Node;
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
bool List::search(int key)
{
	int j = key;
	int k;
	Node * tmp = new Node;
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
bool List::swap(int key1, int key2)
{
	Node * tmp = new Node;
	tmp = head->next;
	Node * tmp1 = new Node;
	Node * tmp2 = new Node;

	int * j = &key1;
	while (tmp->next != tail) {
		if (tmp->key == *j) {
			tmp1 = tmp;
			int * k = &key2;
			while (tmp->next != head) {
				if (tmp->key == *k) {
					tmp2 = tmp;

					Node * tmp3 = new Node; 
					tmp3->prev = tmp1->prev;
					tmp3-> next = tmp1->next;
					Node * tmp4 = new Node;
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
int List::size(void)
{

	int j = _size;
	return j; 
	
}
bool List::test(void)
{
	Node * tmp = new Node;
	tmp = head; 
	while (tmp->next!=tail)
	{
		tmp = tmp->next;
	}
	if (tmp = tail){
		while (tmp->prev!=head)
		{
			if (tmp=head)
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

void List::format(const std::string & start, const std::string & zwischen, const std::string & ende)
{
	_form.start = start;
	_form.zwischen = zwischen;
	_form.ende = ende;
}

List & List::operator = (const List & _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == &_List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventüll vorhandenen Knoten in this löschen
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
	if (_List.temp) delete & _List;		// ist die übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

List & List::operator = (const List * _List)
{
	// in dem Objekt _List sind die Knoten enthalten, die Kopiert werden sollen.
	// Kopiert wird in das Objekt "this"
	if (this == _List) return *this;	//  !! keine Aktion notwendig
	Node * tmp_node;
	if (_size)
	{
		Node * tmp_del;
		tmp_node = head->next;
		while (tmp_node != tail)		// Alle eventüll vorhandenen Knoten in this löschen
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
	if (_List->temp) delete _List;		// ist die übergebene Liste eine temporäre Liste? -> aus Operator +
	return *this;
}

List & List::operator + (const List & List_Append)
{
	Node * tmp_node;
	List * tmp;
	if (temp){								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List;						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail){
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append._size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append.head->next;
		while (tmp_node != List_Append.tail){
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append.temp) delete & List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}

List & List::operator + (const List * List_Append)
{
	Node * tmp_node;
	List * tmp;
	if (temp){								// this ist eine temporäre Liste und kann verändert werden
		tmp = this;
	}
	else {
		tmp = new List;						// this ist keine temporäre Liste -> Kopie erzeugen
		tmp->temp = true;					// Merker setzten, dass es sich um eine temporäre Liste handelt
		tmp_node = head->next;
		while (tmp_node != tail){
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->_size) {				// anhängen der übergebenen Liste an tmp
		tmp_node = List_Append->head->next;
		while (tmp_node != List_Append->tail){
			tmp->InsertBack(tmp_node->key);
			tmp_node = tmp_node->next;
		}
	}
	if (List_Append->temp) delete List_Append;		// wurde eine temporäre Liste übergeben, dann wird diese gelöscht							// 
	return *tmp;
}

std::ostream & operator<<(std::ostream  & stream, List const & Liste)
{
	stream << Liste._form.start;
	for (Node * tmp = Liste.head->next; tmp != Liste.tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste.tail ? Liste._form.ende : Liste._form.zwischen);
	if (Liste.temp) delete & Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}

std::ostream & operator << (std::ostream & stream, List const * Liste)
{
	stream << Liste->_form.start;
	for (Node * tmp = Liste->head->next; tmp != Liste->tail; tmp = tmp->next)
		stream << tmp->key << (tmp->next == Liste->tail ? Liste->_form.ende : Liste->_form.zwischen);
	if (Liste->temp) delete Liste;			// wurde eine temporäre Liste übergeben, dann wird diese gelöscht
	return stream;
}
