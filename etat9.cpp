#include "etat9.h"
#include "automate.h"

bool E9::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case INT:
			break;
		case PLUS:
			break;
		case MULT:
			automate.reduction4(s);
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
