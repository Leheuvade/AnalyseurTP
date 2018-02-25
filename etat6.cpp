#include "etat6.h"
#include "etat4.h"
#include "etat5.h"
#include "etat9.h"
#include "automate.h"

bool E6::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case INT:
			break;
		case PLUS:
			return automate.decalage(s, new E4);
			break;
		case MULT:
			return automate.decalage(s, new E5);
			break;
		case OPENPAR:
			break;
		case CLOSEPAR:
			return automate.decalage(s, new E9);
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
