#pragma once

#include <string>
#include "etat.h"

using namespace std;

class E5: public Etat{
	public:
		E5():Etat("Etat"+to_string(5)){ };
		virtual ~E5() { };
		virtual bool transition(Automate & automate, Symbole *s);
};
