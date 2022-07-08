#pragma once
#include <utility>

#define NULL_TVALOARE -1
typedef int TCheie;
typedef int TValoare;

class IteratorDictionar;

typedef std::pair<TCheie, TValoare> TElem;

struct Node {
	TElem key;
	Node* next;
};

class Dictionar {
	friend class IteratorDictionar;

private:
	/* aici e reprezentarea */
	Node* start;
public:

	// constructorul implicit al dictionarului
	Dictionar();

	// adauga o pereche (cheie, valoare) in dictionar	
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	//Teta(1)  CF - i==1
	//Teta(n)  CD - i==n
	//Teta(n)  CM
	//O(n)  CT
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	//Teta(1)  CF - i==1
	//Teta(n)  CD - i==n
	//Teta(n)  CM
	//O(n)  CT
	TValoare cauta(TCheie c) const;

	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	//Teta(1)  CF - i==1
	//Teta(n)  CD - i==n
	//Teta(n)  CM
	//O(n)  CT
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar
	//Teta(1)  CF - i==1
	//Teta(n)  CD - i==n
	//Teta(n)  CM
	//O(n)  CT
	int dim() const;

	//verifica daca dictionarul e vid 
	//Teta(1) CF=CM=CD=CT
	bool vid() const;

	// se returneaza iterator pe dictionar
	IteratorDictionar iterator() const;


	// destructorul dictionarului	
	~Dictionar();

};


