#include "etat7.h"
#include "etat5.h"
#include "automate.h"

bool E7::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case INT:
			break;
		case PLUS:
			return automate.reduction2(s);
			break;
		case MULT:
			return automate.decalage(s, new E5);
			break;
		case OPENPAR:
			break;
		case CLOSEPAR:
			return automate.reduction2(s);
			break;
		case FIN:
			return automate.reduction2(s);
			break;
		case ERREUR:
			break;
		case EXPR:
			break;
	}
	return false;
}
