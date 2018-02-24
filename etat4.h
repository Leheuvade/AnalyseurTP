#pragma once

#include <string>
#include "etat.h"

using namespace std;

class E4: public Etat{
	public:
		E4():Etat("Etat"+to_string(4)){ };
		virtual ~E4() { };
		virtual bool transition(Automate & automate, Symbole *s);
};
