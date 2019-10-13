/*
Tasmanian Strategical
Copyright (C) 1993, 1994, 2019 Laurence Maar

laurencemaar@gmail.com
https://www.facebook.com/laurencemaar/
https://www.linkedin.com/in/laurencemaar/
https://github.com/laurencemaar/
https://sourceforge.net/u/laurencemaar/

-----

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include"smurfver.h"

void bp(char *registration_string, unsigned int security_code);
unsigned long rcount=0;

main(){
char registered;
char registered_name[201];
char temp_string[201];
char registration_string[201];
char registration_verification[201];
unsigned int security_code;
char tempstring[201];
unsigned int security_verification;
    clrscr();
    textcolor(12);
    cprintf("\n   S M U R F   C O M B A T\n\n\r");
    textcolor(10);
    cprintf("  Registration No. Module\n\r");
    cprintf("        %sVersion %s\n\r",__vkeysp,__vkey);
    cprintf("     By Laurence Maar\n\n\n\r");
    textcolor(9);
    cprintf(" Smurf Combat est 909 ou 12345\n\n\r");

   textcolor(11);
   cprintf(" Programme Code : ");
   gets(temp_string);
   security_code=atoi(temp_string);
   cprintf("        Repetez : ");
   gets(temp_string);
   security_verification=atoi(temp_string);
   if(security_code!=security_verification)
      {
      printf("\nCodes ne match pas!\n");
      return(1);
      }

    textcolor(11);
   cprintf(" Individule Nom : ");
   gets(registration_string);
   cprintf("        Repetez : ");
   gets(registration_verification);
   if(strcmp(registration_string,registration_verification)!=0)
      {
      printf("\nStrings ne match pas!\n");
      return(1);
      }
bp(registration_string,security_code);
   textcolor(9);
   cprintf("\n Individule Nom : [%s]\n\r",registration_string);
   cprintf("       Serialle : [%lu]\n\n\r",rcount);

}



void bp(char *registration_string, unsigned int security_code){
char tempstring[201];int cyc;
    strset(tempstring,0);
      sprintf(tempstring,"%s",registration_string);
      for(cyc=0;cyc<strlen(tempstring);cyc++){
      rcount=rcount+tempstring[cyc]*security_code;
      }
}
