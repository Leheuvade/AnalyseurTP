#include "etat5.h"
#include "automate.h"

bool E5::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case INT:
			break;
		case PLUS:
			break;
		case MULT:
			break;
		case OPENPAR:
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
