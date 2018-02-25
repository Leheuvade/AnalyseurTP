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
      void analyse();
      bool decalage(Symbole * s, Etat * e);
      bool reduction(int l, Symbole * s);
      bool reduction2(Symbole * s);
      bool reduction3(Symbole * s);
      bool reduction4(Symbole * s);
      bool reduction5(Symbole * s);
      void printStackState();
      void printStackSymbole();

   protected:
	  std::vector<Etat *> state; 
	  std::vector<Symbole *> symbole; 
     Lexer l;
};
