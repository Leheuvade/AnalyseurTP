#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "etat0.h"

int main(void) {

   string chaine("(1+((3*8888)*(4+5))+(34*4))*123");
	Automate automate(chaine);
   automate.analyse();
	
   return 0;
}

