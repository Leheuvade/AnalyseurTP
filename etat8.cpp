#include "etat8.h"
#include "automate.h"

bool E8::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case INT:
			break;
		case PLUS:
		automate.reduction3(s);
			break;
		case MULT:
		automate.reduction3(s);
			break;
		case OPENPAR:
			break;
		case CLOSEPAR:
		automate.reduction3(s);
			break;
		case FIN:
			automate.reduction3(s);
			break;
		case ERREUR:
			break;
		case EXPR:
			break;
	}
	return false;
}
