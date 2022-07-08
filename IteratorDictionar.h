#pragma once
#include "Dictionar.h"

class IteratorDictionar
{
	friend class Dictionar;
private:

	//constructorul primeste o referinta catre Container
	//iteratorul va referi primul element din container
	IteratorDictionar(const Dictionar& d);

	//contine o referinta catre containerul pe care il itereaza
	const Dictionar& dict;
	/* aici e reprezentarea specifica a iteratorului */
	Node* act;
public:

	//reseteaza pozitia iteratorului la inceputul containerului
	//Teta(1) CF=CM=CD=CT
	void prim();

	//muta iteratorul in container
	// arunca exceptie daca iteratorul nu e valid
	//Teta(1) CF=CM=CD=CT
	void urmator();

	/* Subalgoritm avanseazaKPasi(lsi,act,k)
	* //Teta(1)  CF - i==1
	//Teta(k)  CD - i==k
	//Teta(n)  CM
	//O(n)  CT
	* pre:lsi:LSi,act:NodLsi,p!=Nil,k:int
	* post:muta cursorul iteratorului a.i sa refere al k-lea element
	* daca k <= 0
	*	@arunca exceptie
	* Sfdaca
	* pentru i=0,k,1 executa
	*	daca [act].urm==NIl
	*		@arunca exceptie
	*	SfDaca
	*	[act]<-[act].urmator
	* Sfpentru
	* SfSubAlgoritm
	*/
	void avanseazaKPasi(int k);

	//verifica daca iteratorul e valid (indica un element al containerului)
	//Teta(1) CF=CM=CD=CT
	bool valid() const;

	//returneaza valoarea elementului din container referit de iterator
	//arunca exceptie daca iteratorul nu e valid
	//Teta(1) CF=CM=CD=CT
	TElem element() const;
};
