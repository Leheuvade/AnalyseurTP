#pragma once

#include <vector>
#include "symbole.h"
#include "lexer.h"
#include "etat0.h"
#include <string>

using namespace std;
class Etat; 

class Automate {

   public:
      Automate(string chaine) : l(chaine) { state.push_back(new E0); };
      ~Automate() { }
	void print() const;
      void analyse();
      void decalage(Symbole * s, Etat * e);
      void reduction(int l, Symbole * s);
      void reduction2(Symbole * s);
      void reduction3(Symbole * s);
      void reduction4(Symbole * s);
      void reduction5(Symbole * s);
      void printStackState();
      void printStackSymbole();
      Etat * getEtatCourant();

   protected:
	  std::vector<Etat *> state; 
	  std::vector<Symbole *> symbole; 
     Lexer l;
};
