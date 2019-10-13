/***************************************************************************/
/*                                                                         */
/*   INSTALL.EXE Ver 1c                                                    */
/*   INSTALL.EXE Ver 1c                                                    */
/*   INSTALL.EXE Ver 1c                                                    */
/*                                                                         */
/***************************************************************************/

#include"install.h"
#include<stream.h>
#include<dir.h>
#include<bios.h>









char _xent6[80],toggle6[10][80],correct6[10][80];
extern void NEWS_main(char ar[80]);
extern void NEWD_main(char ar[80]);
extern void NWDR_main(char ar[80]);
extern void INST_main(char ar[80]);
extern void MAIN_main(char ar[80]);
extern void MAIN_prnt(char ar[80]);
extern void __window(int x1, int x2, int y1, int y2, int c1, int c2);
extern void __fill(void);
extern int aar,i78;










void __line6(int xx, int cu){int con=0;
if(xx==1) { gotoxy(3,1 +con); cprintf(" Install Program...                 "); /*cprintf("%-35s",toggle6[1]);*/}
if(xx==2) { gotoxy(3,2 +con); cprintf(" Update Version...                  "); /*cprintf("%-35s",toggle6[2]);*/}
if(xx==3) { gotoxy(3,3 +con); cprintf(" Reconfigure Program...             "); /*cprintf("%-35s",toggle6[3]);*/}
if(xx==4) { gotoxy(3,4 +con); cprintf("                                    "); /*cprintf("%-35s",toggle6[4]);*/}
if(xx==5) { gotoxy(3,5 +con); cprintf(" Initialize New Game...             "); /*cprintf("%-35s",toggle6[5]);*/}
if(xx==6) { gotoxy(3,6 +con); cprintf(" Register Program...                "); /*cprintf("%-35s",toggle6[6]);*/}
if(xx==7) { gotoxy(3,7 +con); cprintf("                                    "); /*cprintf("%-35s",toggle6[7]);*/}
if(xx==8) { gotoxy(3,8 +con); cprintf(" Printer Forms...                   "); /*cprintf("%-35s",toggle6[8]);*/}
if(xx==9) { gotoxy(3,9 +con); cprintf("                                    "); /*cprintf("%-35s",toggle6[9]);*/}
if(xx==10){ gotoxy(3,10+con); cprintf(" Exit...                            "); /*cprintf("%-35s",toggle6[10]);*/}
}








void MAIN_main(char ar[80]){
int x=79,cyc,ga,cp,en;char anew[80],anow[80],anot[80];

directvideo=0;_wscroll=0;
cp=1;
ga=0;
en=0;

sprintf(_xent6,"%s",ar);

do {
 _xent6[x]=0;
 x--;
}while(_xent6[x]!='\\');






sprintf(toggle6[1], "");
sprintf(toggle6[2], "");
sprintf(toggle6[3], "");
sprintf(toggle6[4], "");
sprintf(toggle6[5], "");
sprintf(toggle6[6], "");
sprintf(toggle6[7], "");
sprintf(toggle6[8], "");
sprintf(toggle6[9], "");
sprintf(toggle6[10],"");

if(aar==1)sprintf(anew,"UPGRADE");
if(aar==1)sprintf(anow,"UPGRADE");
if(aar==1)sprintf(anot,"UPGRADE");
if(strnicmp(anew,"UPGRADE",7)==0) {
	sprintf(toggle6[6],"No");
	sprintf(toggle6[7],"No");
	sprintf(toggle6[9],"No");
}

//if(i78==255)cp=5;
complete:;
window(1,1,80,25);
//textbackground(0);clrscr();
__fill();
__window(1,4,1,80,14,1);
gotoxy(2,2); cprintf("                            Maartian Enterprises                             ");
gotoxy(2,3); cprintf("                         INSTALL.EXE (III) Ver 1.00                          ");
__window(23,25,1,80,14,1);
gotoxy(3,24);cprintf("All Rights Reserved  (C)opyright 1993,1994 Laurence Maar  All Rights Reserved");
//gotoxy(3,24);cprintf("(C) Copyright 1994 þ Laurence Maar þ Compiled on [%s] at [%s]",__DATE__,__TIME__);
__window(8,19,21,60,14,1);
  window(22,9,59,18);
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
for(cyc=1;cyc<11;cyc++)__line6(cyc,cp);
do{
textbackground(0);__line6(cp,cp);
  if(strnicmp(anow,"UPGRADE",7)==0)
    {
    cp=10;
    ga=7181;
    }
  else
    ga=bioskey(0);
textbackground(1);__line6(cp,cp);
if(ga==18432 || ga==19200)cp--;
if(ga==20480 || ga==19712)cp++;
if(ga==7181 || ga==14624){

  if(cp==1)
  {
	sound(200);
	delay(75);
	nosound();
	INST_main(ar);
	ar[78]=255;
	NEWS_main(ar);
	NEWD_main(ar);
	goto complete;
  }
  if(cp==2)
  {
	sound(200);
	delay(75);
	nosound();
	ar[78]=255;
	INST_main(ar);
	goto complete;
  }
  if(cp==3)
  {
	sound(200);
	delay(75);
	nosound();
	NEWS_main(ar);
	goto complete;
  }
  if(cp==5)
  {
	sound(200);
	delay(75);
	nosound();
	NEWD_main(ar);
	i78=0;
	goto complete;
  }
  if(cp==6)
  {
	sound(200);
	delay(75);
	nosound();
	NWDR_main(ar);
	goto complete;
  }
  if(cp==8)
  {
	sound(200);
	delay(75);
	nosound();
	MAIN_prnt(ar);
	goto complete;
  }
  if(cp==10)
  {
	sound(100);
	delay(25);
	sound(200);
	delay(75);
	nosound();
	window(1,1,80,25);
	textcolor(7);
	textbackground(0);
	clrscr();
	exit(0);
  }
}
if(ga==283){
	sound(100);
	delay(25);
	sound(200);
	delay(75);
	nosound();
//	window(1,1,80,25);
//	textcolor(7);
//	textbackground(0);
//	clrscr();
	exit(0);
}

  if(cp==0)cp=10;
  if(cp==11)cp=1;

}while(en==0);
}
