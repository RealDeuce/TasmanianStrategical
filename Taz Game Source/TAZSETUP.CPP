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
/*   SETUP.EXE Ver 1a                                                      */
/*   SETUP.EXE Ver 1a                                                      */
/*   SETUP.EXE Ver 1a                                                      */
/*                                                                         */
/***************************************************************************/

#define NOOPEN
#include"tazdef.h"
#include<stream.h>
#include<dir.h>
#include<bios.h>

char _xent[80],toggle[10][80];

extern void NEWS_main(char ar[80]);




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
if(xx==2) { gotoxy(3,2 +con); cprintf(" Program Directory   "); cprintf("%-35s",toggle[2]);}
if(xx==3) { gotoxy(3,3 +con); cprintf(" Get Drop File From  "); cprintf("%-35s",toggle[3]);}
if(xx==4) { gotoxy(3,4 +con); cprintf(" Write Batch File To "); cprintf("%-35s",toggle[4]);}
if(xx==5) { gotoxy(3,5 +con); cprintf(" þ Monitor Window    "); cprintf("%-35s",toggle[5]);}
if(xx==6) { gotoxy(3,6 +con); cprintf(" þ Language Default  "); cprintf("%-35s",toggle[6]);}
if(xx==7) { gotoxy(3,7 +con); cprintf(" þ Spinning Cursor   "); cprintf("%-35s",toggle[7]);}
if(xx==8) { gotoxy(3,8 +con); cprintf(" þ Drop File Type    "); cprintf("%-37s",toggle[8]);} //37
if(xx==9) { gotoxy(3,9 +con); cprintf(" System Directory    "); cprintf("%-35s",toggle[9]);}
if(xx==10){ gotoxy(3,10+con); cprintf(" Proceed...          "); cprintf("%-35s",toggle[10]);}
}

void NEWS_main(char ar[80]){
int x=79,cyc,ga,cp,en;char smart[10],anew[80],pathname[20];FILE *stream;
directvideo=0;_wscroll=0;cp=1;ga=0;en=0;
sprintf(_xent,"%s",ar);
do {
 _xent[x]=0;
 x--;
}while(_xent[x]!='\\');
sprintf(toggle[1],"Tasmanian Strategical");
sprintf(toggle[2],"%s",_xent);
sprintf(toggle[3],"%s",_xent);
sprintf(toggle[4],"%s",_xent);
sprintf(toggle[5],"Never");
sprintf(toggle[6],"English");
sprintf(toggle[7],"Yes");
sprintf(toggle[8],"1\bDOOR.SYS SYNCHR GAP APEX RA WC3.0 ");
sprintf(toggle[9],"C:\\SBBS\\NODE1");
sprintf(toggle[10],"");
complete:;
textbackground(0);clrscr();
__fill();
__window(1,4,1,80,14,1);
gotoxy(2,2); cprintf("                            Maartian Enterprises                             ");
gotoxy(2,3); cprintf("                              SETUP.EXE Ver 1a                               ");
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
//_wscroll=1;
for(cyc=1;cyc<11;cyc++)__line(cyc,cp);
do{
textbackground(0);__line(cp,cp);
ga=bioskey(0);
textbackground(1);__line(cp,cp);
if(ga==18432 || ga==19200)cp--;
if(ga==20480 || ga==19712)cp++;
if(ga==7181 || ga==14624){

  if(cp==1){
	sprintf(toggle[1],"Death Warrior");__line(1,cp);
	sound(375);	delay(100);	nosound();
	sprintf(toggle[1],"Chemical Warfare");__line(1,cp);
	sound(375);	delay(100);	nosound();
	sprintf(toggle[1],"Sonic Nuker I");__line(1,cp);
	sound(375);	delay(100);	nosound();
	sprintf(toggle[1],"Smurf Combat");__line(1,cp);
	sound(375);	delay(100);	nosound();
	sprintf(toggle[1],"Cannot Find Setup Information");__line(1,cp);
	sleep(1);
	sprintf(toggle[1],"Tasmanian Strategical");__line(1,cp);
  }

  if(cp==2){
	sound(500);	delay(70);	nosound();
	sprintf(toggle[2],"");__line(2,cp);
	gotoxy(24,2);gets(anew);
	sprintf(toggle[2],"%s",anew);
	if(strlen(anew)<2)sprintf(toggle[2],"%s",_xent);
	if(toggle[2][strlen(toggle[2])-1]!='\\'){sprintf(anew,toggle[2]);sprintf(toggle[2],"%s\\",anew);}
	__line(2,cp);
  }

  if(cp==3){
	sound(500);	delay(70);	nosound();
	sprintf(toggle[3],"");__line(3,cp);
	gotoxy(24,3);gets(anew);
	sprintf(toggle[3],"%s",anew);
	if(strlen(anew)<2)sprintf(toggle[3],"%s",_xent);
	if(toggle[3][strlen(toggle[3])-1]!='\\'){sprintf(anew,toggle[3]);sprintf(toggle[3],"%s\\",anew);}
	__line(3,cp);
  }

  if(cp==4){
	sound(500);	delay(70);	nosound();
	sprintf(toggle[4],"");__line(4,cp);
	gotoxy(24,4);gets(anew);
	sprintf(toggle[4],"%s",anew);
	if(strlen(anew)<2)sprintf(toggle[4],"%s",_xent);
	if(toggle[4][strlen(toggle[4])-1]!='\\'){sprintf(anew,toggle[4]);sprintf(toggle[4],"%s\\",anew);}
	__line(4,cp);
  }

  if(cp==5){
	sound(375);	delay(100);	nosound();
  }

  if(cp==6){
	if(toggle[cp][0]=='E')sprintf(toggle[cp],"Fran‡ais");
	else if(toggle[cp][0]=='F')sprintf(toggle[cp],"English");
	sound(500);	delay(70);	nosound();
  }

  if(cp==7){
	if(toggle[cp][0]=='Y')sprintf(toggle[cp],"No");
	else if(toggle[cp][0]=='N')sprintf(toggle[cp],"Yes");
	sound(500);	delay(70);	nosound();
  }

  if(cp==8){
	if(toggle[cp][0]=='1')sprintf(toggle[cp],"2\bCHAIN.TXT APEX TELEGARD WWIV      ");
   else if(toggle[cp][0]=='2')sprintf(toggle[cp],"3\bDORINFOx.DEF QBBS RBBS TELEGARD   ");
   else if(toggle[cp][0]=='3')sprintf(toggle[cp],"4\bSFDOORS.DAT SPITFIRE TRITEL TELEG ");
   else if(toggle[cp][0]=='4')sprintf(toggle[cp],"5\bCALLINFO.BBS WILDCAT A & B TELEGA ");
   else                       sprintf(toggle[cp],"1\bDOOR.SYS SYNCHR GAP APEX RA WC3.0 ");
	sound(500);	delay(70);	nosound();
  }

  if(cp==9){
	sound(500);	delay(70);	nosound();
	sprintf(toggle[9],"");__line(9,cp);
	gotoxy(24,9);gets(anew);
	sprintf(toggle[9],"%s",anew);
	if(strlen(anew)<2)sprintf(toggle[9],"%s",_xent);
	if(toggle[9][strlen(toggle[9])-1]!='\\'){sprintf(anew,toggle[9]);sprintf(toggle[9],"%s\\",anew);}
	__line(9,cp);
  }

  if(cp==10){
	sound(500);	delay(70);	nosound();
  sprintf(toggle[10],"Processing...");__line(10,cp);sleep(1);
  sprintf(toggle[10],"Saving...");    __line(10,cp);sleep(1);

  if((stream=fopen(__CFGFILE__,"r"))!=NULL)
    {
    fclose(stream);
    __loadconfiguration();
  }

  if(toggle[5][0]=='Y')config.parameter[5]=1; else config.parameter[5]=0;
  if(toggle[6][0]=='F')config.parameter[7]=1; else config.parameter[7]=0;
  if(toggle[7][0]=='Y')config.parameter[8]=1; else config.parameter[8]=0;
//if(toggle[8][0]=='Y')config.parameter[9]=1; else config.parameter[9]=0;
//if(toggle[9][0]=='Y')config.parameter[9]=1; else config.parameter[9]=0;
  if(strnicmp(toggle[2],toggle[3],strlen(toggle[2]))==0) smart[0]=1;
  else smart[0]=0;
  __saveconfiguration();

 sprintf(pathname,"%sTAZBAT.BAT",toggle[4]);
 stream=fopen(pathname,"w+");
 fprintf(stream,"@echo off\n\r");
 fprintf(stream,"echo Tasmanian Strategical þ Laurence Maar (c)1993                           \n\r");
 fprintf(stream,"echo The Fossil Driver BNU is included with this program.         \n\r");
 fprintf(stream,"echo The author of Tasmanian Strategical encourages that you register      \n\r");
 fprintf(stream,"echo BNU if you already havn't done so. This program will         \n\r");
 fprintf(stream,"echo not function without a fossil driver such as BNU or X00.                             \n\r");
 fprintf(stream,"echo BNU 1.88á þ (C) 1989 þ David Nugent & Unique Computing Ptd Ltd                      \n\r");
 fprintf(stream,"cd %s\n\r",toggle[2]);
if(!smart[0]){
 if(toggle[8][0]=='1')fprintf(stream,"copy %sDOOR.SYS\n\r",toggle[3]);
 if(toggle[8][0]=='2')fprintf(stream,"copy %sCHAIN.TXT\n\r",toggle[3]);
 if(toggle[8][0]=='3')fprintf(stream,"copy %sDORINFO*.DEF\n\r",toggle[3]);
 if(toggle[8][0]=='4')fprintf(stream,"copy %sSFDOORS.DAT\n\r",toggle[3]);
 if(toggle[8][0]=='5')fprintf(stream,"copy %sCALLINFO.BBS\n\r",toggle[3]);
}
 fprintf(stream,"BNU\n\r");
 fprintf(stream,"%s %1\n\r",filename);
 fprintf(stream,"cd %s\n\r",toggle[9]);
 fclose(stream);

	sprintf(toggle[10],"Done...");    __line(10,cp);sleep(1);
	window(1,1,80,25);
	textcolor(7);
	textbackground(0);
	clrscr();
	exit(0);
  }
}

if(cp==0)cp=10;

if(cp==11)cp=1;

if(ga==283){
     window(1,1,80,25);
     textbackground(0);
     textcolor(7);
     clrscr();
     exit(0);
}

}while(en==0);
}
