#pragma once

#include <string>
#include "etat.h"

using namespace std;

class E8: public Etat{
	public:
		E8():Etat("Etat"+to_string(8)){ };
		virtual ~E8() { };
		virtual bool transition(Automate & automate, Symbole *s);
};
