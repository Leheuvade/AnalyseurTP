#include "etat4.h"
#include "etat3.h"
#include "etat2.h"
#include "etat7.h"
#include "automate.h"

bool E4::transition(Automate & automate, Symbole *s)
{
	switch(*s){
    		case INT:
    			return automate.decalage(s, new E3);
    			break;
    		case PLUS:
    			break;
    		case MULT:
    			break;
    		case OPENPAR:
    			return automate.decalage(s, new E2);
    			break;
    		case CLOSEPAR:
    			break;
    		case FIN:
    			break;
    		case ERREUR:
    			break;
    		case EXPR:
    			return automate.decalage(s, new E7);
    			break;
	}
	return false;
}
