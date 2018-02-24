#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "etat0.h"

int main(void) {
string chaine("(1+34)*123");

   Lexer l(chaine);
	Automate automate;
	Etat * e;
   Symbole * s;
   int i=0;
   while(*(s=l.Consulter())!=FIN) {
	   e = automate.getEtatCourant();
      //s->Affiche();
      cout<<endl;
      e->transition(automate, s);
      automate.print();
      l.Avancer();
      if(i==2)
      {
    	  break;
      }
      i++;
   }
   return 0;
}

