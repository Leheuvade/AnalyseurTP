#include "etat0.h"
#include "etat3.h"
#include "etat2.h"
#include "automate.h"

bool E0::transition(Automate & automate, Symbole *s)
{
	switch(*s){
		case INT:
			automate.decalage(s, new E3);
			break;
		case PLUS:
			break;
		case MULT:
			break;
		case OPENPAR:
			automate.decalage(s, new E2);
			break;
		case CLOSEPAR:
			break;
		case FIN:
			break;
		case ERREUR:
			break;
		case EXPR:
			break;

	}
	return false;
}

