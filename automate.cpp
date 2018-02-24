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

	for(int i=0;i<n;i++)
	{
		delete(symbole.back());
		symbole.pop_back();
	}

	symbole.push_back(new Symbole(EXPR));
	state.back()->transition(*this, new Symbole(EXPR));

}

void Automate::print() const{
	state.back()->print();
	symbole.back()->Affiche();
}

Etat * Automate::getEtatCourant(){
	return state.back();
}
