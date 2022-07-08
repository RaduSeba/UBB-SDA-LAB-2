#include "IteratorDictionar.h"
#include "Dictionar.h"
#include <exception>

using namespace std;

IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d) {
	/* de adaugat */
	act = dict.start;
}


void IteratorDictionar::prim() {
	/* de adaugat */
	act = dict.start;
}


void IteratorDictionar::urmator() {
	/* de adaugat */
	act = act->next;
}

void IteratorDictionar::avanseazaKPasi(int k)
{
	if (k <=0)
	{
		throw exception();
	}
	for (int i = 0; i < k; i++)
	{
		if (act->next == NULL)
		{
			throw exception();
		}
		act = act->next;
	}
		
}


TElem IteratorDictionar::element() const {
	/* de adaugat */
	return pair <TCheie, TValoare>(act->key.first, act->key.second);
}


bool IteratorDictionar::valid() const {
	/* de adaugat */
	if (act == NULL)
		return false;
	return true;
}

