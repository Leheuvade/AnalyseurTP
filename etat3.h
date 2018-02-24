#include <string>
#include "etat.h"
using namespace std;
class E3: public Etat{
	public:
		E3():Etat("Etat"+to_string(3)) { };
		virtual ~E3() { };
		virtual bool transition(Automate & automate, Symbole *s);
};
