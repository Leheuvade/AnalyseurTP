#pragma once

#include <string>
#include "etat.h"

using namespace std;

class E7: public Etat{
	public:
		E7():Etat("Etat"+to_string(7)){ };
		virtual ~E7() { };
		virtual bool transition(Automate & automate, Symbole *s);
};
