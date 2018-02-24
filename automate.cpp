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

void Automate::reduction5(Symbole * s) {

	Entier * e = (Entier *) symbole.back();
	symbole.pop_back();
	Expression * resultat = new Expression(e);
	delete e;
	reduction(1,resultat);
}

void Automate::reduction3(Symbole * s) {

	Entier * e = (Entier *) symbole.back();
	Symbole * fois = (Symbole *) symbole.back()
	Entier * e2 = (Entier *) symbole.back();
	symbole.pop_back();
	Expression * resultat = new Expression(e*e2);
	delete e;
	delete e2;
	delete fois;
	reduction(3,resultat);
}


void Automate::reduction4(Symbole * s) {

	Symbole * openpar = (Symbole *) symbole.back()
	Entier * e = (Entier *) symbole.back();
	Symbole * closepar = (Symbole *) symbole.back()
	symbole.pop_back();
	//Expression * resultat = new Expression(*e2);
	delete openpar;
	delete e;
	delete closepar;
	reduction(3,resultat);
}
void Automate::print() const{
	state.back()->print();
	symbole.back()->Affiche();
}

Etat * Automate::getEtatCourant(){
	return state.back();
}
