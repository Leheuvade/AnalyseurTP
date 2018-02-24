#include <string>
#include "etat.h"

using namespace std;

class E6 : public Etat{
	public:
		E6():Etat("Etat"+to_string(6)) { };
		virtual ~E6() { };
		virtual bool transition(Automate & automate, Symbole *s);
};
