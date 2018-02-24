#pragma once

#include <string>
#include "etat.h"

using namespace std;
class E2: public Etat{
	public:
		E2():Etat("Etat"+to_string(2)){};
		virtual ~E2() { };
		virtual bool transition(Automate & automate, Symbole *s);
};
