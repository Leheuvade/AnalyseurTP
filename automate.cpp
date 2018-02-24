#include "automate.h"
#include "etat.h"

void Automate::decalage(Symbole * s, Etat * e) {
	
	state.push_back(e);
	symbole.push_back(s);
 
}

void Automate::reduction(int n, Symbole * s) {
	for(int i=0;i<n;i++)
	{
		delete(state.back());
		state.pop_back();
	}

	state.back()->transition(*this, s);

}

void Automate::reduction5(int n, Symbole * s) {

	Entier * e = (Entier *) symbole.back();
	symbole.pop_back();
	Expression * resultat = new Expression(e);
	delete e;
	reduction(n,resultat);
}


void Automate::print() const{
	state.back()->print();
	symbole.back()->Affiche();
}

Etat * Automate::getEtatCourant(){
	return state.back();
}
