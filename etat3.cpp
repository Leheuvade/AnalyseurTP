#include "etat3.h"
#include "automate.h"

bool E3::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case INT:
			break;
		case PLUS:
			return automate.reduction5(s);
			break;
		case MULT:
			return automate.reduction5(s);
			break;
		case OPENPAR:
			break;
		case CLOSEPAR:
			return automate.reduction5(s);
			break;
		case FIN:
			return automate.reduction5(s);
			break;
		case ERREUR:
			break;
		case EXPR:
			break;
	}
	return false;
}
