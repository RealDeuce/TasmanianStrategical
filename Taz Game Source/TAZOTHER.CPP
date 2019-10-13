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

/***************************************************************************/
/*                                                                         */
/*   TTTTTTTTTTTTTTTTTTTTTTTTTTTTT                     Revolutionary       */
/*   TTTTTTTTTTTTTTTTTTTTTTTTTTTTT                       Inter-BBS         */
/*       TTTT                                          Online Gaming       */
/*       TTTT              AAAAA       ZZZZZZZZZZZ                         */
/*       TTTT             AAAAAAA            ZZZZZ         v0.90           */
/*       TTTT            AAAAA AAA          ZZZZZ                          */
/*       TTTT           AAAAA   AAA        ZZZZZ     By Severe Disorder    */
/*       TTTT          AAAAAAAAA AAA      ZZZZZ       (C)opyright 1993     */
/*       TTTT         AAAAA       AAA    ZZZZZ                             */
/*       TTTT        AAAAA         AAA  ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ    */
/*                                                                         */
/***************************************************************************/

#define NOOPEN
#include"tazdef.h"
#include<stream.h>
#include<dir.h>
char _fname[15];
extern char _current[80];
void __RST__main2(int _force);

/* Setup 1.00    */ void __errormessage(int x, char y[15]){
/* Setup 1.00    */   if(x==1){
/* Setup 1.00    */     cprintf("\n\rJeu n't pas configured. Ecrivez '%s SETUP'.\n\r",filename);
/* Setup 1.00    */     cprintf("Game has not been configured. Run '%s SETUP'.\n\r",filename);
/* Setup 1.00    */     exit(0);
/* Setup 1.00    */   }
/* Setup 1.00    */   if(x==5){
/* Setup 1.00    */     cprintf("\n\rJeu n't pas reset. Ecrivez '%s RESET'.\n\r",filename);
/* Setup 1.00    */     cprintf("Game has not been reset. Run '%s RESET'.\n\r",filename);
/* Setup 1.00    */     exit(0);
/* Setup 1.00    */   }
/* Setup 1.00    */   printf("Error #%d with file %s",x,y);
/* Setup 1.00    */   printf("Error #%d avec file %s",x,y);
/* Setup 1.00    */   exit(0);
/* Setup 1.00    */ }



void bp(char *registration_string, unsigned int security_code){
char tempstring[201];int cyc;
	strset(tempstring,0);
	  sprintf(tempstring,"%s",registration_string);
	  for(cyc=0;cyc<strlen(tempstring);cyc++){
	  rcount=rcount+tempstring[cyc]*security_code;
	  }
	rcount+=12111;
}











/* Setup 1.00    */ void __window(int x1, int x2, int c1, int c2)
/* Initiate      */ {
/* Initiate      */   int cyc;
/* Initiate      */   textcolor(c1);
/* Initiate      */   textbackground(c2);
/* Initiate      */   for(cyc=x1;cyc<x2;cyc++){
/* Initiate      */     gotoxy(1,cyc);cprintf("บ");
/* Initiate      */     gotoxy(80,cyc);cprintf("บ");
/* Initiate      */   }
/* Initiate      */   for(cyc=x1;cyc<x2;cyc++){
/* Initiate      */   gotoxy(2,cyc);cprintf("                                                                              ");
/* Initiate      */   }
/* Initiate      */   gotoxy(2,x1);  cprintf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
/* Initiate      */   gotoxy(2,x2);  cprintf("ออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ");
/* Initiate      */   gotoxy(1,x1);  cprintf("ษ");
/* Initiate      */   gotoxy(1,x2);  cprintf("ศ");
/* Initiate      */   gotoxy(80,x1); cprintf("ป");
/* Initiate      */   gotoxy(80,x2); cprintf("ผ");
/* Initiate      */ }

/* Setup 1.00    */ void __SET__main(void){
/* Setup 1.00    */ char smart[10],path[80],pathname[160],path2[80],path3[3],path4[80],type;FILE *stream;
/* Setup 1.00    */ if((stream=fopen(__CFGFILE__,"r"))!=NULL){fclose(stream);__loadconfiguration();};
/* Setup 1.00    */ __localfrench();
/* Setup 1.00    */ textbackground(0);clrscr();
/* Setup 1.00    */ __window(1,7,14,1);
/* Setup 1.00    */ gotoxy(5,3); cprintf("                        Maartian Enterprises");
/* Setup 1.00    */ gotoxy(5,5); cprintf("                           %sVersionne %s",__vsetsp,__vset);
/* Setup 1.00    */ __window(21,23,14,1);
/* Setup 1.00    */ gotoxy(3,22);cprintf("(C) Copyright Dec 1993 þ Laurence Maar þ This program is considered Freeware");
/* Setup 1.00    */ window(1,10,80,18);
/* Setup 1.00    */ gotoxy(1,1);textbackground(0);

/* Setup 1.00    */ textcolor(10);cprintf("Tasmanian Strategical Directory\n\r");
/* Setup 1.00    */ textcolor(10);cprintf("Tasmanian Strategical Rpertoire\n\r");
/* Setup 1.00    */ textcolor( 2);cprintf("%s [default/manquement]\n\r",_current);
/* Setup 1.00    */ textcolor(15);gets(path);
if(strlen(path)<2)sprintf(path,"%s",_current);

/* Setup 1.00    */ textcolor(10);cprintf("\n\rSystem Drop Directory (Dir with DOOR.SYS, CHAIN.TXT, etc.)\n\r Synchronet uses same directory as above\n\r");
/* Setup 1.00    */ textcolor(10);cprintf("Rpertoire … Systme (avec DOOR.SYS, CHAIN.TXT, etc.)\n\r Synchronet fais la mme … la sur\n\r");
/* Setup 1.00    */ textcolor( 2);cprintf("%s [default/manquement]\n\r",_current);
/* Setup 1.00    */ textcolor(15);gets(path2);
if(strlen(path2)<2)sprintf(path2,"%s",_current);

/* Setup 1.00    */ textcolor(10);cprintf("\n\rWrite TAZBAT.BAT to which directory (Usu. Main BBS Directory)\n\r");
/* Setup 1.00    */ textcolor(10);cprintf("Ecrive TAZBAT.BAT … quelle rpertoire\n\r");
/* Setup 1.00    */ textcolor( 2);cprintf("%s [default/manquement]\n\r",_current);
/* Setup 1.00    */ textcolor(15);gets(path4);
if(strlen(path4)<2)sprintf(path4,"%s",_current);

if(strnicmp(path,path2,strlen(path))==0 && strnicmp(path,path2,strlen(path2))==0) smart[1]=1; else smart[1]=0;

///* Setup 1.00    */ textcolor(10);cprintf("\n\rUser Monitor Window Default\n\r");
///* Setup 1.00    */ textcolor( 2);cprintf("[1] Yes þ [0] No (default)\n\r");
///* Setup 1.00    */ textcolor(15);gets(path3);config.parameter[5]=atol(path3);
config.parameter[5]=0;

/* Setup 1.00    */ textcolor(10);cprintf("\n\rLanguage Default To...\n\r");
/* Setup 1.00    */ textcolor(10);cprintf("Tout la monde ici parle quelle langue?\n\r");
/* Setup 1.00    */ textcolor( 2);cprintf("[1] Franais þ [0] English (default)\n\r");
/* Setup 1.00    */ textcolor(15);gets(path3);config.parameter[7]=atol(path3);

/* Setup 1.00    */ textcolor(10);cprintf("\n\rSet Spinning Cursor Default To...\n\r");
/* Setup 1.00    */ textcolor(10);cprintf("Faire tourner la cursor\n\r");
/* Setup 1.00    */ textcolor( 2);cprintf("[1] Yes/Oui þ [0] No/Non (default)\n\r");
/* Setup 1.00    */ textcolor(15);gets(path3);config.parameter[8]=atol(path3);

/* Setup 1.00    */ textcolor(10);
/* Setup 1.00    */ __saveconfiguration();
/* Setup 1.00    */ cprintf("\n\rSelect Drop File Used þ Choissez une vous faissez\n\r");
/* Setup 1.00    */ textcolor(2);
/* Setup 1.00    */ cprintf("[0] DOOR.SYS     - Synchronet can only function properly with DOOR.SYS!\n\r");
/* Setup 1.00    */ cprintf("[1] DOOR.SYS     - Apex/GAP/RemoteAccess/Spitfire v3/TAG/Telegard/Wildcat v3\n\r");
/* Setup 1.00    */ cprintf("[2] CHAIN.TXT    - Apex/Telegard/WWiV\n\r");
/* Setup 1.00    */ cprintf("[3] DORINFOx.DEF - Apex/QBBS/RBBS/RemoteAccess/Telegard\n\r");
/* Setup 1.00    */ cprintf("[4] SFDOORS.DAT  - Apex/Spitfire/Telegard/TriTel\n\r");
/* Setup 1.00    */ cprintf("[5] CALLINFO.BBS - Apex/Telegard/Wildcat [A]/Wildcat [B]\n\n\r");
/* Setup 1.00    */ textcolor(15);gets(path3);type=atoi(path3);
/* Setup 1.00    */ textcolor(11);textcolor(7);
/* Setup 1.00    */ window(1,1,80,25);clrscr();
/* Setup 1.00    */ chdir(path4);
/* Setup 1.00    */ sprintf(pathname,"TAZBAT.BAT");
/* Setup 1.00    */ stream=fopen(pathname,"w+");
/* Setup 1.00    */ fprintf(stream,"@echo off\n\r");
/* Setup 1.00    */ fprintf(stream,"echo Tasmanian Strategical þ Laurence Maar (c)1993                           \n\r");
/* Setup 1.00    */ fprintf(stream,"echo The Fossil Driver BNU is included with this program.         \n\r");
/* Setup 1.00    */ fprintf(stream,"echo The author of Tasmanian Strategical encourages that you register      \n\r");
/* Setup 1.00    */ fprintf(stream,"echo BNU if you already havn't done so. This program will         \n\r");
/* Setup 1.00    */ fprintf(stream,"echo not function without a fossil driver such as BNU or X00.                             \n\r");
/* Setup 1.00    */ fprintf(stream,"echo BNU 1.88แ þ (C) 1989 þ David Nugent & Unique Computing Ptd Ltd                      \n\r");
/* Setup 1.00    */ fprintf(stream,"cd %s\n\r",path);
if(!smart[1]){
/* Setup 1.00    */ if(type==0)fprintf(stream,"copy %s\\DOOR.SYS\n\r",path2);
/* Setup 1.00    */ if(type==1)fprintf(stream,"copy %s\\DOOR.SYS\n\r",path2);
/* Setup 1.00    */ if(type==2)fprintf(stream,"copy %s\\CHAIN.TXT\n\r",path2);
/* Setup 1.00    */ if(type==3)fprintf(stream,"copy %s\\DORINFO*.DEF\n\r",path2);
/* Setup 1.00    */ if(type==4)fprintf(stream,"copy %s\\SFDOORS.DAT\n\r",path2);
/* Setup 1.00    */ if(type==5)fprintf(stream,"copy %s\\CALLINFO.BBS\n\r",path2);
}
/* Setup 1.00    */ fprintf(stream,"BNU\n\r");
/* Setup 1.00    */ fprintf(stream,"%s %1\n\r",filename);
/* Setup 1.00    */ fprintf(stream,"cd %s\n\r",path2);
/* Setup 1.00    */ fclose(stream);
/* Setup 1.00    */ chdir(path);
/* Setup 1.00    */ }














void __RST__main2(int _force){
   /*
   0 - PCBoard
   1 - Turns Per Cycle
 2/3/4 Date Of Start
   5 - Monitor Window
   6 - Protection
   7 - Default LAnguage(1-French)
   */

struct date d;
//d.da_day,d.da_mon,d.da_year
getdate(&d);
__loadconfiguration();
__localfrench();
clrscr();

if(_force==0){
  textcolor(13);cprintf("You are about to reset Tasmanian Strategical, continue? \n\r");
  textcolor(13);cprintf("Resetez Tasmanian Strategical? \n\r");
  if(!ny2()){textcolor(7);cprintf("Exiting . . . \n\n\r");exit(0);}
}
  textcolor(2);cprintf("Turns … cycle ");config.parameter[1]=y2(5,20);
  textcolor(2);cprintf("Turns … attack immunity/immunit ");config.parameter[6]=y2(20,20);
  textcolor(2);cprintf("Cycle length … days/jours ");y2(1,10);
  textcolor(7);cprintf("\n\rEnter game starting date\n\r");
  textcolor(7);cprintf("Entrez jeu date de commencement\n\r");
  textcolor(2);cprintf("Day  /Jour "); config.parameter[3]=y2(d.da_day,31);
  textcolor(2);cprintf("Month/Mois "); config.parameter[2]=y2(d.da_mon,12);
  textcolor(2);cprintf("Year /An   "); config.parameter[4]=y2(d.da_year,2100);

  textcolor(12);cprintf("\n\rþ ");textcolor(4);cprintf("Initializing Pointers...\n\r");
  textcolor(12);cprintf("þ ");textcolor(4);cprintf("Deleting old messages...\n\r");
  textcolor(12);cprintf("þ ");textcolor(4);cprintf("Writing to memory...\n\r");

  special.version   =__saveversion[1]-'0'+(__saveversion[0]-'0')*10;
  special.versiondec=__saveversion[3]-'0'+(__saveversion[2]-'0')*10;

  sprintf(player[26].name,"UNKNOWN");
  for(cyc=0;cyc<26;cyc++){
	player[cyc].statis=0;
    player[cyc]._W_=100;
  }
  for(cyc=0;cyc<50;cyc++){
	_W_[cyc].empire=0;
    _W_[cyc].player=0;
    _W_[cyc].statis=0;
	_W_[cyc].morale=0;
	_W_[cyc].approval=0;
    inter.statis[cyc]=0;
    sprintf(inter.planet[cyc],"*****");
  }
  textcolor(12);cprintf("þ ");textcolor(4);cprintf("Saving game/Sauve jeu...\n\r");
	sprintf(_E_[0],"Sovreign Tasmania");
  for(cyc=1;cyc<10;cyc++)
	sprintf(_E_[cyc],"Independent");
  for(cyc=0;cyc<10;cyc++){
	__empire=cyc;
	savegame();
	}
  __saveconfiguration();
  stream=fopen(__LOGFILE__,"w+");
  fclose(stream);
  textcolor(15);cprintf("þ ");textcolor(  7  );cprintf("Done/Finis...\n\n\r");
  exit(0);
}

/* Bolivia 0.11  */ void ___loadgame(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__SPCFILE__);
/* Open Save     */   if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(5,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&special, sizeof(specrec))) == -1) __errormessage(6,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }

/* Bolivia 0.11  */ void ___savegame(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__SPCFILE__);
/* Open Save     */   if ((__userhandle = open(_fname, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE)) == -1) __errormessage(7,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&special, sizeof(specrec))) != sizeof(specrec)) __errormessage(8,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }



/* Bolivia 0.11  */ void __loadgame(void)/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__WARFILE__);
/* Open Save     */   if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(5,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&savedata, sizeof(saverec))) == -1) __errormessage(6,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&empire, sizeof(contrec))) == -1) __errormessage(6,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&warzone, sizeof(battrec)*50)) == -1) __errormessage(6,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&interattack, sizeof(grparec)*10)) == -1) __errormessage(6,_fname);
/* Close Up      */   close(__userhandle);/* Terminate     */ }

/* Bolivia 0.11  */ void __savegame(void)/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__WARFILE__);
/* Open Save     */   if ((__userhandle = open(_fname, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE)) == -1) __errormessage(7,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&savedata, sizeof(saverec))) != sizeof(saverec)) __errormessage(8,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&empire, sizeof(contrec))) != sizeof(contrec)) __errormessage(8,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&warzone, sizeof(battrec)*50)) != sizeof(battrec)*50) __errormessage(8,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&interattack, sizeof(grparec)*10)) != sizeof(grparec)*10) __errormessage(8,_fname);
/* Close Up      */   close(__userhandle);/* Terminate     */ }

/* Bolivia 0.11  */ void _loadgame(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;/* Open Save     */   sprintf(_fname,__SAVFILE__[__empire]);
/* Open Save     */   if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(5,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&player, sizeof(userrec)*27)) == -1) __errormessage(6,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }

/* Bolivia 0.11  */ void _savegame(void)
/* Initiate      */ {char _fname[15];/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__SAVFILE__[__empire]);
/* Open Save     */   if ((__userhandle = open(_fname, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE)) == -1) __errormessage(7,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&player, sizeof(userrec)*27)) != sizeof(userrec)*27) __errormessage(8,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }





void loadgame(void){
___loadgame();
__loadgame();
_loadgame();
}

void savegame(void){
___savegame();
__savegame();
_savegame();
}

/* Setup 1.00    */ void __loadconfiguration(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,"%s",__CFGFILE__);
/* Open Save     */   if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(1,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&config, sizeof(configrec))) == -1) __errormessage(2,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&inter, sizeof(interrec))) == -1) __errormessage(2,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }

/* Setup 1.00    */ void __saveconfiguration(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,"%s",__CFGFILE__);
/* Open Save     */   if ((__userhandle = open(_fname, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE)) == -1) __errormessage(3,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&config, sizeof(configrec))) != sizeof(configrec)) __errormessage(4,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&inter, sizeof(interrec))) != sizeof(interrec)) __errormessage(4,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }


void __REG__main(void){
  char code[40],name[80],ins2[40],cod,ins3[15],ins4[15];
  FILE *fp;                           /* File pointer for REGISTER.KEY file */
  FILE *stream;
  unsigned long correct_year;                       /* Key supplied by user */
  unsigned long correct_mont;                       /* Key supplied by user */
   unsigned long supplied_yer;                       /* Key supplied by user */
   unsigned long supplied_mon;                       /* Key supplied by user */
   unsigned long supplied_key;                       /* Key supplied by user */
   unsigned long correct_key;                    /* Correct registration key */
   struct date d;
   getdate(&d);
  __localfrench();
    cprintf("\n\r");
	cprintf("Input Registration Serialle: ");gets(code);
	cprintf("Input Registration Name:     ");gets(name);
	  bp(name,12111);        /* Calculate correct key */
	  correct_key=rcount;
	 if(correct_key!=atol(code)){       /* Compare correct & supplied keys */
	   cprintf("\n\n\rName and serial doesn't match!\n\r");
	   cprintf("Name et serial n'est pas correct!\n\n\r");
	   exit(1);
	 }
	cprintf("Input Specification:         ");gets(ins);
	cprintf("Input Definition:            ");gets(ins2);
 correct_year=atol(ins)/511;
 correct_mont=atol(ins2)/453;
 if(correct_year!=1977){
 if(correct_year<1993 || correct_mont>12 || correct_mont<1){
 cprintf("\n\n\rWrong Spec/Def Code Entered!\n\r");
 cprintf("Specification et Definition n'est pas correct!\n\n\r");
 exit(1);
 }
 if(correct_year>d.da_year || (correct_year==d.da_year && correct_mont<d.da_mon))
 {
 cprintf("\n\n\rRegistration Expired!\n\r");
 cprintf("Registrationne a expir!\n\n\r");
 }
 }
	cprintf("Input Ambiance:              ");gets(ins3);
if(atoi(ins3)!=15*name[0]+name[1]+name[2]+name[3] && strlen(ins3)){
 cprintf("\n\n\rWrong Code Entered!\n\r");
 cprintf("Ambiance n'est pas correct!\n\n\r");
 exit(1);
 }
	cprintf("Input Devior:                ");gets(ins4);
if(atoi(ins4)!=17*name[0]+name[1]+name[2]+name[3] && strlen(ins4)){
 cprintf("\n\n\rWrong Code Entered!\n\n\r");
 cprintf("Devior n'est pas correct!\n\n\r");
 exit(1);
 }
	stream=fopen(__REGFILE__,"w+");
	fprintf(stream,"%s\n\r",name);
	fprintf(stream,"%s\n\r",code);
	fprintf(stream,"%s\n\r",ins);
	fprintf(stream,"%s\n\r",ins2);
	fprintf(stream,"%s\n\r",ins3);
	fprintf(stream,"%s\n\r",ins4);
  fclose(stream);
  exit(0);
}






void __localfrench(void){
  textbackground(0);
}

void locmpl(int modmpl){
int cyc33;
textcolor(15);
textbackground(1);
for(cyc33=0;cyc33<modmpl;cyc33++)
cprintf(" ");
for(cyc33=0;cyc33<modmpl;cyc33++)
cprintf("\b \b");
}
char yn2(void){
  textcolor(3);cprintf("(");
  textcolor(11);cprintf("Y,O");
  textcolor(3);cprintf("/");
  textcolor(11);cprintf("n");
  textcolor(3);cprintf(")");
  textcolor(3);cprintf("? ");
  result=getkey2();
  textcolor(11);
  if(result=='Y' || result=='y'){cprintf("Yes\n\n\r");return 1;}
  if(result=='O' || result=='o'){cprintf("Oui\n\n\r");return 1;}
  cprintf("No\n\n\r");
  return 0;
}

char ny2(void){
  textcolor(3);cprintf("(");
  textcolor(11);cprintf("y,o");
  textcolor(3);cprintf("/");
  textcolor(11);cprintf("N");
  textcolor(3);cprintf(")");
  textcolor(3);cprintf("? ");
  result=getkey2();
  textcolor(11);
  if(result=='N' || result=='n'){cprintf("No\n\n\r");return 0;}
  cprintf("Yes/Oui\n\n\r");
  return 1;
}

unsigned long y2(unsigned long x, unsigned long y){
  char ox,oy;if(x>y)x=y;
  textcolor(9);cprintf("[");
  textcolor(11);cprintf("%i",x);
//if(x!=y && y!=0){  textcolor(9);cprintf(";");
//  textcolor(3);cprintf("%i",y);}
  textcolor(9);cprintf("]");
  textcolor(9);cprintf("? ");
  ox=wherex();oy=wherey();
  textcolor(10);
  gets(ins);
  if(strlen(ins)<1){gotoxy(ox,oy);cprintf("%d\n\r",x);return x;}
  return atol(ins);
}

int getkey2(void){
  int rAm;result=0;cyc5=4;
  do{
	textcolor(random(7)+9);
	if(cyc5==4)cprintf("-"); else cprintf("\b \b");
    if(cyc5==0)cprintf("\\");
    if(cyc5==1)cprintf("|");
    if(cyc5==2)cprintf("/");
    if(cyc5==3)cprintf("-");
if(kbhit()){    result=getch();}
    delay(25);
    cyc5++;
	if(cyc5>3)cyc5=0;
  }while(!result);
  cprintf("\b \b");
  return(result);
}

void __CNV__main(void){
textcolor(7);
cprintf("Je regrette, mais ce funtienne est mort.\n\rVous fautez faire <<<TAZLOCAL RESET>>>\n\r");
cprintf("Sorry, but this funtion is dead.\n\rYou must use 'TAZLOCAL RESET'\n\n\r");
}






