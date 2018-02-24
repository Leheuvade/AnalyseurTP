#pragma once

#include <string>
#include "etat.h"

using namespace std;

class E9: public Etat{
	public:
		E9():Etat("Etat"+to_string(9)){ };
		virtual ~E9() { };
		virtual bool transition(Automate & automate, Symbole *s);
};
