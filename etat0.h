#pragma once

#include <string>
#include "etat.h"

using namespace std;

class E0: public Etat{
	public:
		E0():Etat("Etat"+to_string(0)){ };
		virtual ~E0() { };
		virtual bool transition(Automate & automate, Symbole *s);
};
