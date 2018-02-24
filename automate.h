#pragma once

#include <vector>
#include "symbole.h"
#include "lexer.h"
#include "etat0.h"


using namespace std;
class Etat; 

class Automate {

   public:
      Automate() { state.push_back(new E0); };
      ~Automate() { }
	void print() const;
      void decalage(Symbole * s, Etat * e);
      void reduction(int l, Symbole * s);
      Etat * getEtatCourant();

   protected:
	  std::vector<Etat *> state; 
	  std::vector<Symbole *> symbole; 
};
