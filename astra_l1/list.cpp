#include "list.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

void List::reset_list()
{
	head = nullptr;
	tail = nullptr;
}

List::List()
{
	reset_list();
	size = 0;
}

List::~List()
{
	clear();
}

void List::add_first(int newElem)
{
	head = new Elem(newElem);
	tail = head;
}
//checks is the list is empty
bool List::isEmpty() {
	return (head == nullptr);
}

//gets size of list
size_t List::get_size() const
{
	return size;
}

//insert element in the end of list
void List::push_back(int newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		tail->next = new Elem(newElem);
		tail = tail->next;
	}
	size++;
}

//insert element in the begining of the list
void List::push_front(int newElem)
{
	if (size == 0) {
		add_first(newElem);
	}
	else {
		head = new Elem(newElem, head);
	}
	size++;

}
//removes the last element
void List::pop_back()
{
	if (size == 0) {
		throw out_of_range("Removing elements in an empty list is not possible");
		return;
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Elem* current = head;
		while (current->next != tail) {
			current = current->next;
		}
		current->next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}
//removes the first element
void List::pop_front() {
	if (size == 0) {
		throw out_of_range("Removing elements in an empty list is not possible");
		return;
	}
	if (size == 1) {
		delete head;
		reset_list();
	}
	else {
		Elem* current = head;
	
		head = current->next;
		delete current;
	}
	size--;
}
//insert the element at index (insertion before an item that was previously accessible at that index)
void List::insert(int insertData, size_t index) {
	
	if (index == 0) {
		push_front(insertData);
	} else
		if (index >= size) {
			throw out_of_range("Index is greater than list size");
		}
		else {
			size_t count = 0;
			Elem* current = head;
			while (count != index - 1) {
				current = current->next;
				count++;
			}
			Elem* insertElem = new Elem(insertData, current->next);
			current->next = insertElem;
			size++;
		}
}
//gets an element by index
int List::at(size_t index) const
{
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	else {
		size_t counter = 0;
		Elem* current = head;
		while (counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}
//deleting an element by index
void List::remove(size_t index) {
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	if (index == 0)
		pop_front();
	else {
		size_t count = 0;
		Elem* current = head;
		while (count != index - 1) {
			current = current->next;
			count++;
		}
		Elem* deleting_Element = current->next;
		current->next = deleting_Element->next;
		delete deleting_Element;
		size--;
	}
}
//output of list elements to the console
void List::print_to_console() {
	Elem* current = head;
	while (current->next != tail) {
		cout << current->data<<' ';
		current = current->next;
	}
	cout << endl;
}
//removing all the list elements
void List::clear() {
	if (size == 0) {
		throw out_of_range("Removing elements in an empty list is not possible");
	}
	Elem* current = head;
	while (!(this->isEmpty())) {
		current = head;
		head = current->next;
		delete current;
	}
}
//replacing the elemen by index with the passed element
void List::set( size_t index, int newData) {
	if (index >= size) {
		throw out_of_range("Index is greater than list size");
	}
	size_t count = 0;
	Elem* current = head;
	while (count != index) {
		current = current->next;
		count++;
	}
	current->data = newData;
}
//swapping two list elements by indices 
void List::swap(size_t index1, size_t index2) {
	if ((index1 >= size) || (index2 >= size)) {
		throw out_of_range("Index is greater than list size");
	}
	Elem* current_1 = head;
	size_t count=0;
	while (count != index1) {
		current_1 = current_1->next;
		count++;
	}
	count = 0;
	Elem* current_2 = head;
	while (count != index2) {
		current_2 = current_2->next;
		count++;
	}
	int buffer=current_1->data;
	current_1->data = current_2->data;
	current_2->data = buffer;
}
