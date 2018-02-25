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

bool Automate::decalage(Symbole * s, Etat * e) {

	state.push_back(e);
	symbole.push_back(s);

	if(*s != EXPR)
	{
		l.Avancer();
	}

	s = l.Consulter();

	return  e->transition(*this, s);
}

void Automate::analyse() {
	E0 * e0 = new E0;
	Symbole *s = l.Consulter();
	bool ok = e0->transition(*this, s);
	cout<<"validité : "<<ok<<endl;
	if(ok)
	{
		cout<<"résultat : ";
		Expression * e = (Expression *) symbole.back();
		cout<<e->eval()<<endl;
	}
}

bool Automate::reduction(int n, Symbole * s) {

	for(int i=0;i<n;i++)
	{
		delete(state.back());
		state.pop_back();
	}
	return state.back()->transition(*this, s);
}
//E->id
bool Automate::reduction5(Symbole * s) {
	Entier * e = (Entier *) symbole.back();
	symbole.pop_back();
	Expression * resultat = new Expression(e);
	delete e;
	return reduction(1,resultat);
}

//E->(E)
bool Automate::reduction4(Symbole * s) {	
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
	return reduction(3,resultat);
}

//E->E*E
bool Automate::reduction3(Symbole * s) {	
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
	return reduction(3,resultat);
}
//E->E+E
bool Automate::reduction2(Symbole * s) {
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
	return reduction(3,resultat);
}
