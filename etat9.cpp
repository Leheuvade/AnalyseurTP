#include "etat9.h"
#include "automate.h"

bool E9::transition(Automate & automate, Symbole *s)
{
	switch(*s)
    	{
    		case INT:
    			break;
    		case PLUS:
    		  return automate.reduction4(s);
    			break;
    		case MULT:
    		  return automate.reduction4(s);
    			break;
    		case OPENPAR:
    			break;
    		case CLOSEPAR:
    		  return automate.reduction4(s);
    			break;
    		case FIN:
    		  return automate.reduction4(s);
    			break;
    		case ERREUR:
    			break;
    		case EXPR:
    			break;
    	}
    	return false;
 }