#pragma once

#include <string>
#include <iostream>
#include "symbole.h"

using namespace std;
class Automate;

class Etat {

   public:
      Etat(string name) : name(name) { };
      virtual ~Etat() { };
	virtual bool transition(Automate & automate, Symbole * s)=0;
      void print() const;
      
   protected:
	  string name;
};
