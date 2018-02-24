#include "etat3.h"
#include "automate.h"

bool E3::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case INT:
			break;
		case PLUS:
			automate.reduction(1, s);
			break;
		case MULT:
			automate.reduction(1, s);
			break;
		case OPENPAR:
			break;
		case CLOSEPAR:
			automate.reduction(1, s);
			break;
		case FIN:
			automate.reduction(1, s);
			break;
		case ERREUR:
			break;
		case EXPR:
			break;
	}
	return false;
}
