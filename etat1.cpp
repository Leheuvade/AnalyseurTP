#include "etat1.h"
#include "etat4.h"
#include "etat5.h"
#include "automate.h"

bool E1::transition(Automate & automate, Symbole * s){
	
	switch(*s){
		case PLUS :
			automate.decalage(s, new E4);
			break;
		case MULT :
			automate.decalage(s, new E5);
			break;
		case FIN :
			return true;
			break;
		
	}
	return false; 
}


