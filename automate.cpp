#include "automate.h"
#include "etat.h"
#include "etat0.h"


void Automate::printStackState(){
	for (std::vector<Etat *>::iterator it = state.begin() ; it != state.end(); ++it)
    	(*it)->print();
}

void Automate::printStackSymbole(){
	for (std::vector<Symbole *>::iterator it = symbole.begin() ; it != symbole.end(); ++it){

    	(*it)->Affiche();
    	cout<<" "<<endl;
	}

}

void Automate::decalage(Symbole * s, Etat * e) {
	cout<<"décalage ";
	e->print();

	state.push_back(e);
	symbole.push_back(s);

	if(*s != EXPR)
	{
		l.Avancer();
	}

	s = l.Consulter();
	printStackState();
	printStackSymbole();
	s->Affiche();
	bool ok = e->transition(*this, s);
	cout<<" validité "<<ok<<endl;
}

void Automate::analyse() {
	E0 * e0 = new E0;
	Symbole *s = l.Consulter();
	e0->transition(*this, s);
	symbole.back()->Affiche();
   	
}

void Automate::reduction(int n, Symbole * s) {

	for(int i=0;i<n;i++)
	{
		delete(state.back());
		state.pop_back();
	}
	state.back()->transition(*this, s);

}
//E->id
void Automate::reduction5(Symbole * s) {
	cout<<"réduction 5"<<endl;
	Entier * e = (Entier *) symbole.back();
	symbole.pop_back();
	Expression * resultat = new Expression(e);
	delete e;
	reduction(1,resultat);
}

//E-> (E)
void Automate::reduction4(Symbole * s) {	
	cout<<"réduction 4"<<endl;
	Symbole * openpar = (Symbole *) symbole.back();
	symbole.pop_back();
	Entier * e = (Entier *) symbole.back();
	symbole.pop_back();
	Symbole * finpar = (Symbole *) symbole.back();
	symbole.pop_back();
	Expression * resultat = new Expression((e->getValeur()));
	delete openpar;
	delete e;
	delete finpar;
	reduction(3,resultat);
}

//E-> E*E
void Automate::reduction3(Symbole * s) {	
	cout<<"réduction 3"<<endl;
	Entier * e1 = (Entier *) symbole.back();
	symbole.pop_back();
	Symbole * mult = (Symbole *) symbole.back();
	symbole.pop_back();
	Entier * e2 = (Entier *) symbole.back();
	symbole.pop_back();
	Expression * resultat = new Expression(e1->getValeur() * e2->getValeur());
	delete e1;
	delete mult;
	delete e2;
	reduction(3,resultat);
}
//E-> E+E

void Automate::reduction2(Symbole * s) {

	cout<<"réduction 2"<<endl;
	Entier * e = (Entier *) symbole.back();
	symbole.pop_back();
	Symbole * plus = (Symbole *) symbole.back();
	symbole.pop_back();
	Entier * e2 = (Entier *) symbole.back();
	symbole.pop_back();
	Expression * resultat = new Expression(e->getValeur() + e2->getValeur());
	delete e;
	delete e2;
	delete plus;
	reduction(3,resultat);
}

void Automate::print() const{
	state.back()->print();
	symbole.back()->Affiche();
}

Etat * Automate::getEtatCourant(){
	return state.back();
}
