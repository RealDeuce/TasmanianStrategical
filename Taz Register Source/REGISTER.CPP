#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
//#include"register.h"

void bp(char *registration_string, unsigned int security_code);
unsigned long rcount=0;
char extra[201],extra2[201],extra3[201],extra4[201],extra5[201],etch[201],level=1,xxx[10],arf,toggle[10][80];

/* Setup 1.00    */ void __window(int x1, int x2, int y1, int y2, int c1, int c2)
/* Initiate      */ {
/* Initiate      */   int cyc,cyc2;
/* Initiate      */   textcolor(c1);
/* Initiate      */   textbackground(c2);
/* Initiate      */   for(cyc=x1;cyc<x2;cyc++){
/* Initiate      */   gotoxy(y1+1,cyc);  for(cyc2=0;cyc2<y2-y1;cyc2++)cprintf(" ");
/* Initiate      */   }
/* Initiate      */   for(cyc=x1;cyc<x2;cyc++){
/* Initiate      */     gotoxy(y1,cyc);cprintf("º");
/* Initiate      */     gotoxy(y2,cyc);cprintf("º");
/* Initiate      */   }
/* Initiate      */   gotoxy(y1+1,x1);  for(cyc=0;cyc<y2-y1;cyc++)cprintf("Í");
/* Initiate      */   gotoxy(y1+1,x2);  for(cyc=0;cyc<y2-y1;cyc++)cprintf("Í");
/* Initiate      */   gotoxy(y1,x1);  cprintf("É");
/* Initiate      */   gotoxy(y1,x2);  cprintf("È");
/* Initiate      */   gotoxy(y2,x1); cprintf("»");
/* Initiate      */   gotoxy(y2,x2); cprintf("¼");
/* Initiate      */ }

void __fill(void){
int cyc;textcolor(1);
for(cyc=0;cyc<25;cyc++)  {
    gotoxy(1,cyc);
    cprintf("²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
}}

void __line(int xx, int cu){int con=0;
if(xx==1) { gotoxy(3,1 +con); cprintf(" Program Name        "); cprintf("%-35s",toggle[1]);}
if(xx==2) { gotoxy(3,2 +con); cprintf(" Target Directory    "); cprintf("%-35s",toggle[2]);}
if(xx==3) { gotoxy(3,3 +con); cprintf(" Source Directory    "); cprintf("%-35s",toggle[3]);}
if(xx==4) { gotoxy(3,4 +con); cprintf(" Install First Disk  "); cprintf("%-35s",toggle[4]);}
if(xx==5) { gotoxy(3,5 +con); cprintf(" Install Bonus Disk  "); cprintf("%-35s",toggle[5]);}
if(xx==6) { gotoxy(3,6 +con); cprintf(" Configure           "); cprintf("%-35s",toggle[6]);}
if(xx==7) { gotoxy(3,7 +con); cprintf(" Initialize Game     "); cprintf("%-35s",toggle[7]);}
if(xx==8) { gotoxy(3,8 +con); cprintf(" Register Game       "); cprintf("%-35s",toggle[8]);}
if(xx==9) { gotoxy(3,9 +con); cprintf(" Printer Connected   "); cprintf("%-35s",toggle[9]);}
if(xx==10){ gotoxy(3,10+con); cprintf(" Proceed...          "); cprintf("%-35s",toggle[10]);}
}

main(){
char registered;
char registered_name[201];
char temp_string[201];
char registration_string[201];
char registration_verification[201];
int security_code;
char tempstring[201];
unsigned int security_verification;
directvideo=0;
_wscroll=0;
/*
    clrscr();
    textcolor(12);
    cprintf("\n");
    cprintf("  R E G I S T R A T I O N   K E Y");
    cprintf("\n\n\r");
    textcolor(10);
    cprintf("     Registration No. Module\n\r");
    cprintf("           Version 1.0\n\r");
    cprintf("       By Laurence Y. Maar\n\n\n\r");
    textcolor(9);
*/
textbackground(0);clrscr();
__fill();
__window(1,4,1,80,14,1);
gotoxy(2,2); cprintf("                            Maartian Enterprises                             ");
gotoxy(2,3); cprintf("                          REGISTER.EXE Version 1.0                           ");
__window(23,25,1,80,14,1);
gotoxy(3,24);cprintf("(C) Copyright Dec 1993 þ Laurence Maar þ Compiled on %s at %s",__DATE__,__TIME__);
__window(8,19,11,70,14,1);
window(12,9,69,18);
gotoxy(1,1); textcolor(12);cprintf("");textcolor(14);cprintf("³");
gotoxy(1,2); textcolor(10);cprintf("þ");textcolor(14);cprintf("³");
gotoxy(1,3); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
gotoxy(1,4); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
gotoxy(1,5); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
gotoxy(1,6); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
gotoxy(1,7); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
gotoxy(1,8); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
gotoxy(1,9); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
gotoxy(1,10);textcolor(12);cprintf("");textcolor(14);cprintf("³");
    _wscroll=1;
    gotoxy(4,1);cprintf("Smurf est 1 et 9[0]9   ou 3 et 123[45] a00 d00\n\r");
    gotoxy(4,2);cprintf("Taz09 est 1 et [12111] ou 2 et 16[669] a15 d17\n\r");

   textcolor(11);
   gotoxy(4,3); cprintf("Individule Nom  : ");
   gotoxy(25,3);gets(registration_string);

   textcolor(11);
   gotoxy(4,4);cprintf("Code Level      : ");
   gotoxy(25,4);gets(xxx);
   level=atoi(xxx);

   textcolor(11);
   gotoxy(4,5);cprintf("Programme Code  : ");
   gotoxy(25,5);gets(temp_string);
   security_code=atoi(temp_string);

   textcolor(11);
   gotoxy(4,6);cprintf("Ajouter Combien : ");
   gotoxy(25,6);gets(extra);

   textcolor(11);
   gotoxy(4,7);cprintf("Specification Y : ");
   gotoxy(25,7);gets(extra2);

   textcolor(11);
   gotoxy(4,8);cprintf("Definition Mont : ");
   gotoxy(25,8);gets(extra3);

   textcolor(11);
   gotoxy(4,9);cprintf("Ambiance Code   : ");
   gotoxy(25,9);gets(extra4);

   textcolor(11);
   gotoxy(4,10);cprintf("Devoir Code     : ");
   gotoxy(25,10);gets(extra5);

bp(registration_string,security_code);
sprintf(etch,"%s",registration_string);
   clrscr();
   textcolor(14);
   gotoxy(1,1);
   cprintf(" Individule Nom : [%s]\n\r",registration_string);
   cprintf("        Ajouter : [%dþ%dþ%s]\n\r",level,security_code,extra);
   cprintf("       Serialle : [%lu]\n\r",rcount);
   cprintf("  Specification : [%lu]\n\r",atol(extra2)*511);
   cprintf("     Definition : [%lu]\n\r",atol(extra3)*453);
   cprintf("       Ambiance : [%lu]\n\r",atol(extra4)*etch[0]+etch[1]+etch[2]+etch[3]);
   cprintf("         Devior : [%lu]\n\r",atol(extra5)*etch[0]+etch[1]+etch[2]+etch[3]);
if(atol(extra2)!=1977){
   cprintf("        Expires : [%lu-%lu]\n\r",atol(extra3),atol(extra2));
} else {
   cprintf("        Expires : [Infinity]\n\r");
}

if(security_code!=909){
fprintf(stdprn,"\n\r                  T A S M A N I A N   S T R A T E G I C A L\n\n\r",rcount);
			  fprintf(stdprn,"\n\r     Individule Nom : [%s]\n\r",registration_string);
} else {
fprintf(stdprn,"\n\r                             S M U R F   C O M B A T\n\n\r",rcount);
			  fprintf(stdprn,"\n\r     Individule Nom : [%s]\n\r",registration_string);
}
if(security_code!=909){
fprintf(stdprn,"           Serialle : [%lu]\n\r",rcount);
} else {
fprintf(stdprn,"           Serialle : [%lu]\n\n\r",rcount);
}

if(security_code!=909){   fprintf(stdprn,"      Specification : [%lu]\n\r",atol(extra2)*511);}
if(security_code!=909){   fprintf(stdprn,"         Definition : [%lu]\n\r",atol(extra3)*453);}
if(security_code!=909 && atol(extra4)){   fprintf(stdprn,"           Ambiance : [%lu]\n\r",atol(extra4)*etch[0]+etch[1]+etch[2]+etch[3]);}
if(security_code!=909 && atol(extra5)){   fprintf(stdprn,"             Devior : [%lu]\n\r",atol(extra5)*etch[0]+etch[1]+etch[2]+etch[3]);}
if(security_code!=909 && !atol(extra4)){   fprintf(stdprn,"           Ambiance : [0]\n\r");}
if(security_code!=909 && !atol(extra5)){   fprintf(stdprn,"             Devior : [0]\n\r");}
//if(security_code==909){   fprintf(stdprn,"   Intermediate : [   ]\n\r");}
/*
if(security_code==909){
   fprintf(stdprn,"\n\r   Name 0       :                              Use '<FILENAME> REGISTER'\n\r");
   fprintf(stdprn,"   Name 1       : \n\r");
   fprintf(stdprn,"   Name 2       :                              Smurf Combat Version 1.30\n\r");
   fprintf(stdprn,"   Name 3       :                              and later do NOT require\n\r");
   fprintf(stdprn,"   Name 4       :                              Intermediate codes and Name\n\r");
   fprintf(stdprn,"   Name 5       :                              0-9.\n\r");
   fprintf(stdprn,"   Name 6       : \n\r");
   fprintf(stdprn,"   Name 7       : \n\r");
   fprintf(stdprn,"   Name 8       : \n\r");
   fprintf(stdprn,"   Name 9       : \n\r");
}
*/
if(atol(extra2)!=1977){
  if(security_code!=909){  fprintf(stdprn,"            Expires : [%lu-%lu]\n\n\r",atol(extra3),atol(extra2));}
} else {
  if(security_code!=909){   fprintf(stdprn,"            Expires : [Infinity]\n\n\r");             }
}

  fprintf(stdprn,"     ----------------------------------------------------------------\n\n\r");

  fprintf(stdprn,"     After  expiration,  renewal is  available for  the insignificant\n\r");
  fprintf(stdprn,"     and small price of only $9 and includes latest releases!\n\n\r");

  fprintf(stdprn,"     Version upgrades are $6 which covers shipping, handling, and all\n\r");
  fprintf(stdprn,"     material expenses. This also does not apply to official sites.\n\n\r");

  fprintf(stdprn,"     Official Head Quarters, Distribution, and Test Sites all recieve\n\r");
  fprintf(stdprn,"     FREE registration on any Onliner.\n\n\r");

  fprintf(stdprn,"     Keep  posted  for  Tasmanian  Strategical [Synchronet Version]!!\n\r");
  fprintf(stdprn,"     Planned release date is July 1, 1994 or earlier.\n\n\r");

  fprintf(stdprn,"     ----------------------------------------------------------------\n\n\r");

  fprintf(stdprn,"     Our latest onliners and savings packages include:       Price   Release(d)\n\r");
  fprintf(stdprn,"       o  Smurf Combat              [Onliner V1.77]    $9 + $3 S&H   Jun 1 1994\n\r");
  fprintf(stdprn,"       o  Tasmanian Strategical     [Onliner V1.03]   $15 + $3 S&H   Jun 1 1994\n\r");
  fprintf(stdprn,"       o  Tasmanian S. AND Smurf C. [On.V1 & On.V2]   $18 + $3 S&H   Jun 1 1994\n\n\r");

  fprintf(stdprn,"     Future onliner and via modem developments inlucde:      Price   Release(d)\n\r");
  fprintf(stdprn,"       o  Smurf Combat              [Synchronet V1a]   $9 + $3 S&H   Jul 1 1994\n\r");
  fprintf(stdprn,"       o  Tasmanian Strategical     [Synchronet V1a]  $19 + $3 S&H   Jul 1 1994\n\r");
  fprintf(stdprn,"       o  Tasmanian S. AND Smurf C. [Sy.V1a & Sy.V1a] $25 + $3 S&H   Jul 1 1994\n\n\r");

  fprintf(stdprn,"     MS-DOS programs and savings packages include:           Price   Release(d)\n\r");
  fprintf(stdprn,"       o  Gradebook Ic              [MS-DOS V1.0]      $9 + $3 S&H   Jan 1 1995\n\r");
  fprintf(stdprn,"       o  Gradebook ][c             [MS-DOS V1.0]     $19 + $3 S&H   Jan 1 1995\n\n\r");

  fprintf(stdprn,"     ----------------------------------------------------------------\n\n\r");

  fprintf(stdprn,"     Maartian Enterprises  also encourages  safe drinking and driving\n\r");
  fprintf(stdprn,"     habits and reminds that Ground Hog abuse is life abuse!\n\n\r");

  fprintf(stdprn,"                        Thank You for your business!!!\f");
/*
if(security_code!=909){   fprintf(stdprn," TAZ: Your registration codes will be invalid after [       ].\n\n\r");    }
if(security_code!=909){   fprintf(stdprn,"      Continued registration is ONLY $5 every addition year plus $1\n\r"); }
if(security_code!=909){   fprintf(stdprn,"      for every node above the first.\n\n\r");                             }
if(security_code!=909){   fprintf(stdprn,"      'Infinity' registration is valid for 'infinity' and costs $38\n\r"); }
if(security_code!=909){   fprintf(stdprn,"      plus $2 each node over the first.\n\n\r");                           }
if(security_code!=909){   fprintf(stdprn,"      In order to participate in an Inter-BBS game consisting of over\n\r");}
if(security_code!=909){   fprintf(stdprn,"      3 parties, each member MUST have an Inter-BBS license.\n\n\r");      }
if(security_code!=909){   fprintf(stdprn,"      A Multinode BBS must pay a $5 one-time fee if it has more than 1 node.\n\n\r");}
if(security_code!=909){   fprintf(stdprn,"      MAARTIAN ENTERPRISES DISTRIBUTION SITES are entitled to Infinity,\n\r");}
if(security_code!=909){   fprintf(stdprn,"      Multi-Node, and Inter-BBS licenses FREE of charge at discretion.\n\n\n\n\n\r");}
*/
 sleep(5);
 window(1,1,80,25);
 textcolor(7);
 textbackground(0);
 clrscr();
 exit(0);
}



void bp(char *registration_string, unsigned int security_code){
char tempstring[201];int cyc;
    strset(tempstring,0);
      sprintf(tempstring,"%s",registration_string);
if(level==1){
      for(cyc=0;cyc<strlen(tempstring);cyc++){
      rcount=rcount+tempstring[cyc]*security_code;
      }}
if(level==2){
      if(strlen(tempstring)<10)arf=strlen(tempstring);else arf=10;
      for(cyc=0;cyc<arf;cyc++){
      rcount=rcount+tempstring[cyc]*security_code;
      }
      rcount=rcount+tempstring[1]*security_code;
      rcount=rcount+tempstring[2]*security_code;
      rcount=rcount+tempstring[3]*security_code;
      rcount=rcount+strlen(tempstring)*security_code;
      rcount=rcount+strlen(tempstring)*3-909;
      }
if(level==3){
      if(strlen(tempstring)<9)arf=strlen(tempstring);else arf=9;
      for(cyc=0;cyc<arf;cyc++){
      rcount=rcount+tempstring[cyc]*security_code;
      }
      rcount=rcount+tempstring[1]*security_code;
      rcount=rcount+tempstring[2]*security_code;
      rcount=rcount+tempstring[2]*security_code;
      rcount=rcount+tempstring[2]*security_code;
      rcount=rcount+tempstring[3]*security_code;
      rcount=rcount+strlen(tempstring)*security_code;
      rcount=rcount-strlen(tempstring)*11114+32909;
      }
    rcount+=atoi(extra);
}
