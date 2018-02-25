#include "etat4.h"
#include "etat3.h"
<<<<<<< HEAD
=======
#include "etat2.h"
>>>>>>> fe24e4f8c7b7ae6653eecdb0ce6f9a72c46dcfd9
#include "etat7.h"
#include "automate.h"

bool E4::transition(Automate & automate, Symbole *s)
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
    			automate.decalage(s, new E7);
    			break;
	}
	return false;
}
