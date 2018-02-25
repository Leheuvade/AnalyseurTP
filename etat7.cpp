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
			automate.reduction2(s);
			break;
		case MULT:
			automate.decalage(s, new E5);
			break;
		case OPENPAR:
			break;
		case CLOSEPAR:
			automate.reduction2(s);
			break;
		case FIN:
			automate.reduction2(s);
			break;
		case ERREUR:
			break;
		case EXPR:
			break;
	}
	return false;
}
