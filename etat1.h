#pragma once

#include <string>
#include "etat.h"

using namespace std;

class E1 : public Etat {
   public:
      E1() : Etat("Etat"+to_string(1)) { };
      virtual ~E1() { };
      bool transition(Automate & automate, Symbole * s);
};
