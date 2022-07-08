#include "Dictionar.h"
#include <iostream>
#include <exception>
#include "IteratorDictionar.h"

void deleteList(Node* head_ref)
{

	Node* current = head_ref;
	Node* next = NULL;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	head_ref = NULL;
}


Dictionar::Dictionar() {
	/* de adaugat */
	start = new Node;
	start = NULL;
}


Dictionar::~Dictionar() {
	auto head = start;
	deleteList(head);
	/* de adaugat */
}

TValoare Dictionar::adauga(TCheie c, TValoare v) {
	/* de adaugat */
	Node* elem_nou = new Node;
	elem_nou->key =std:: make_pair(c, v);
	elem_nou->next = NULL;
	if (start == NULL) {
		start = elem_nou;
		return NULL_TVALOARE;
	}
	auto head = start;
	while (head->key.first != elem_nou->key.first && head->next!=NULL) {
		head = head->next;
	}
	if (head->key.first == elem_nou->key.first)
	{
		TValoare ret = head->key.second;
		head->key = elem_nou->key;
		return ret;
	}

	head->next = elem_nou;
	return NULL_TVALOARE;
}



//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare Dictionar::cauta(TCheie c) const {
	/* de adaugat */
	auto head = start;
	while (head != NULL)
	{
		if (head->key.first == c)
		{
			TValoare ret = head->key.second;
			return ret;


		}
		head = head->next;
	}
	return NULL_TVALOARE;
}


TValoare Dictionar::sterge(TCheie c) {
	/* de adaugat */
	if (start == NULL) {
		return NULL_TVALOARE;
	}
	if (start->next != NULL)
	{
		if (start->key.first == c)
		{
			TValoare s = start->key.second;
			start = start->next;
			return s;
		}
	}
	if (start->key.first == c)
	{
		Node* victim = start;
		TValoare ret = start->key.second;
		start = start->next;
		delete victim;
		return ret;
	}
	auto head = start;
	while (head->next != NULL && head->next->key.first != c) {
		head = head->next;
	}
	if (head->next == NULL)
	{
		return NULL_TVALOARE;
	}
	else
	{
		TValoare ret = head->next->key.second;
		head->next = head->next->next;

		return ret;
	}
	return NULL_TVALOARE;
}


int Dictionar::dim() const {
	/* de adaugat */
	int size = 0;
	Node* head = start;
	while (head != NULL) {
		head = head->next;
		++size;
	}
	return size;
}

bool Dictionar::vid() const {
	/* de adaugat */
	if (start == NULL)
		return true;
	return false;
}


IteratorDictionar Dictionar::iterator() const {
	return  IteratorDictionar(*this);
}


