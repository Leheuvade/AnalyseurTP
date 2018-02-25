#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPR"};

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
      int getValeur();
   protected:
      int valeur;
};

class Expression : public Symbole {
	public:
   	Expression(Entier * e): Symbole(EXPR), valeur(e->getValeur()) {}
      Expression(int v): Symbole(EXPR), valeur(v) {}
   	virtual ~Expression() {}
      virtual void Affiche();
      inline int eval(){return valeur;};
   protected:
      int valeur;
};


