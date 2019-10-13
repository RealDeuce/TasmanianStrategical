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
/*   RESET.EXE Ver 1a                                                      */
/*   RESET.EXE Ver 1a                                                      */
/*   RESET.EXE Ver 1a                                                      */
/*                                                                         */
/***************************************************************************/

#define NOOPEN
#include"tazdef.h"
#include<stream.h>
#include<dir.h>
#include<bios.h>

char _xent3[80],toggle3[10][80];
extern void NEWD_main(char ar[80]);
extern void __window(int x1, int x2, int y1, int y2, int c1, int c2);
extern void __fill(void);



void __line3(int xx, int cu){
if(xx==0) { gotoxy(3,1 ); cprintf("                     "); cprintf("%-35s",toggle3[1]);}
if(xx==1) { gotoxy(3,1 ); cprintf(" Turns / Cycle       "); cprintf("%-35s",toggle3[1]);}
if(xx==2) { gotoxy(3,2 ); cprintf(" Turns / Immunity    "); cprintf("%-35s",toggle3[2]);}
if(xx==3) { gotoxy(3,3 ); cprintf(" Cycle length (Days) "); cprintf("%-35s",toggle3[3]);}
if(xx==4) { gotoxy(3,4 ); cprintf("                     "); cprintf("%-35s",toggle3[4]);}
if(xx==5) { gotoxy(3,5 ); cprintf(" Commence            "); cprintf("%-35s",toggle3[5]);}
if(xx==6) { gotoxy(3,6 ); cprintf("   Day   / Jour      "); cprintf("%-35s",toggle3[6]);}
if(xx==7) { gotoxy(3,7 ); cprintf("   Month / Mois      "); cprintf("%-35s",toggle3[7]);}
if(xx==8) { gotoxy(3,8 ); cprintf("   Year  / An        "); cprintf("%-35s",toggle3[8]);} //37
if(xx==9) { gotoxy(3,9 ); cprintf("                     "); cprintf("%-35s",toggle3[9]);}
if(xx==10){ gotoxy(3,10); cprintf(" Proceed...          "); cprintf("%-35s",toggle3[10]);}
}

void NEWD_main(char ar[80]){
int x=79,cyc,ga,cp,en;char smart[10],anew[80],pathname[20];FILE *stream;
directvideo=0;_wscroll=0;cp=1;ga=0;en=0;struct date d;getdate(&d);

sprintf(_xent3,"%s",ar);
do {
 _xent3[x]=0;
 x--;
}while(_xent3[x]!='\\');
sprintf(toggle3[1],"5");
sprintf(toggle3[2],"20");
sprintf(toggle3[3],"1");
sprintf(toggle3[4],"");
sprintf(toggle3[5],"");
sprintf(toggle3[6],"%d",d.da_day);
sprintf(toggle3[7],"%d",d.da_mon);
sprintf(toggle3[8],"%d",d.da_year);
sprintf(toggle3[9],"");
sprintf(toggle3[10],"");
complete:;
textbackground(0);clrscr();
__fill();
__window(1,4,1,80,14,1);
gotoxy(2,2); cprintf("                            Maartian Enterprises                             ");
gotoxy(2,3); cprintf("                         RESET.EXE (II) Version 1.0                          ");
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
for(cyc=1;cyc<11;cyc++)__line3(cyc,cp);
do{
textbackground(0);__line3(cp,cp);
ga=bioskey(0);
textbackground(1);__line3(cp,cp);
if(ga==18432 || ga==19200)cp--;
if(ga==20480 || ga==19712)cp++;
if(ga==7181 || ga==14624){

  if(cp==1){
	sound(500);	delay(70);	nosound();
	sprintf(toggle3[1],"");__line3(1,cp);
	gotoxy(24,1);gets(anew);
	sprintf(toggle3[1],"%lu",atol(anew));__line3(1,cp);
  }

  if(cp==2){
	sound(500);	delay(70);	nosound();
	sprintf(toggle3[2],"");__line3(2,cp);
	gotoxy(24,2);gets(anew);
	sprintf(toggle3[2],"%lu",atol(anew));__line3(2,cp);
	__line3(2,cp);
  }

  if(cp==3){
	sound(500);	delay(70);	nosound();
	sprintf(toggle3[3],"");__line3(3,cp);
	gotoxy(24,3);gets(anew);
	sprintf(toggle3[3],"%lu",atol(anew));__line3(3,cp);
	__line3(3,cp);
  }

  if(cp==4){
	sound(375);	delay(100);	nosound();
  }

  if(cp==5){
	sound(375);	delay(100);	nosound();
  }

  if(cp==6){
	sound(500);	delay(70);	nosound();
	sprintf(toggle3[6],"");__line3(6,cp);
	gotoxy(24,6);gets(anew);
	sprintf(toggle3[6],"%lu",atol(anew));__line3(6,cp);
	__line3(6,cp);
  }

  if(cp==7){
	sound(500);	delay(70);	nosound();
	sprintf(toggle3[7],"");__line3(7,cp);
	gotoxy(24,7);gets(anew);
	sprintf(toggle3[7],"%lu",atol(anew));__line3(7,cp);
	__line3(7,cp);
  }

  if(cp==8){
	sound(500);	delay(70);	nosound();
	sprintf(toggle3[8],"");__line3(8,cp);
	gotoxy(24,8);gets(anew);
	sprintf(toggle3[8],"%lu",atol(anew));__line3(8,cp);
	__line3(8,cp);
  }

  if(cp==9){
	sound(375);	delay(100);	nosound();
  }

  if(cp==10){
  sound(500);	delay(70);	nosound();
  sprintf(toggle3[10],"Processing...");__line3(10,cp);sleep(1);
  __loadconfiguration();

  config.parameter[1]=atoi(toggle3[1]);
  config.parameter[6]=atoi(toggle3[2]);

  config.parameter[3]=atoi(toggle3[6]);
  config.parameter[2]=atoi(toggle3[7]);
  config.parameter[4]=atoi(toggle3[8]);

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

  sprintf(toggle3[10],"Done...");    __line3(10,cp);sleep(1);
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
