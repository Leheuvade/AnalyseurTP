#include "etat6.h"
#include "etat4.h"
<<<<<<< HEAD
=======
#include "etat5.h"
>>>>>>> fe24e4f8c7b7ae6653eecdb0ce6f9a72c46dcfd9
#include "etat9.h"
#include "automate.h"

bool E6::transition(Automate & automate, Symbole *s)
{
	switch(*s)
	{
		case INT:
			break;
		case PLUS:
			automate.decalage(s, new E4);
			break;
		case MULT:
			automate.decalage(s, new E5);
			break;
		case OPENPAR:
			break;
		case CLOSEPAR:
			automate.decalage(s, new E9);
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
