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









char _xent7[80],toggle7[10][80],correct7[10][80];
extern void NEWS_main(char ar[80]);
extern void NEWD_main(char ar[80]);
extern void NWDR_main(char ar[80]);
extern void INST_main(char ar[80]);
extern void MAIN_main(char ar[80]);
extern void MAIN_prnt(char ar[80]);
extern void __window(int x1, int x2, int y1, int y2, int c1, int c2);
extern void __fill(void);
extern int aar;










void __line7(int xx, int cu){int con=0;
if(xx==1) { gotoxy(3,1 +con); cprintf(" Tasmanian Strategical Manual...    "); /*cprintf("%-35s",toggle7[1]);*/}
if(xx==2) { gotoxy(3,2 +con); cprintf(" Order Form...                      "); /*cprintf("%-35s",toggle7[2]);*/}
if(xx==3) { gotoxy(3,3 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[3]);*/}
if(xx==4) { gotoxy(3,4 +con); cprintf(" Proceed...                         "); /*cprintf("%-35s",toggle7[4]);*/}
//if(xx==5) { gotoxy(3,5 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[5]);*/}
//if(xx==6) { gotoxy(3,6 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[6]);*/}
//if(xx==7) { gotoxy(3,7 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[7]);*/}
//if(xx==8) { gotoxy(3,8 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[8]);*/}
//if(xx==9) { gotoxy(3,9 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[9]);*/}
//if(xx==10){ gotoxy(3,10+con); cprintf(" Exit...                            "); /*cprintf("%-35s",toggle7[10]);*/}
}








void MAIN_prnt(char ar[80]){
int x=79,cyc,ga,cp,en;char anew[80],anow[80],anot[80];

directvideo=0;
_wscroll=0;
cp=1;
ga=0;
en=0;

sprintf(_xent7,"%s",ar);

do {
 _xent7[x]=0;
 x--;
}while(_xent7[x]!='\\');





sprintf(toggle7[1], "");
sprintf(toggle7[2], "");
sprintf(toggle7[3], "");
sprintf(toggle7[4], "");
sprintf(toggle7[5], "");
sprintf(toggle7[6], "");
sprintf(toggle7[7], "");
sprintf(toggle7[8], "");
sprintf(toggle7[9], "");
sprintf(toggle7[10],"");

if(aar==1)sprintf(anew,"UPGRADE");
if(aar==1)sprintf(anow,"UPGRADE");
if(aar==1)sprintf(anot,"UPGRADE");
if(strnicmp(anew,"UPGRADE",7)==0) {
	sprintf(toggle7[6],"No");
	sprintf(toggle7[7],"No");
	sprintf(toggle7[9],"No");
}

complete:;
window(1,1,80,25);
//textbackground(0);clrscr();
__fill();
__window(1,4,1,80,14,1);
gotoxy(2,2); cprintf("                            Maartian Enterprises                             ");
gotoxy(2,3); cprintf("                           PRINT.EXE (I) Ver 1.00                            ");
__window(23,25,1,80,14,1);
gotoxy(3,24);cprintf("All Rights Reserved  (C)opyright 1993,1994 Laurence Maar  All Rights Reserved");
//gotoxy(3,24);cprintf("(C) Copyright 1994 þ Laurence Maar þ Compiled on [%s] at [%s]",__DATE__,__TIME__);
__window(11,16,21,60,14,1);
  window(22,12,59,15);
lin:;
gotoxy(1,1); textcolor(12);cprintf("");textcolor(14);cprintf("³");
gotoxy(1,2); textcolor(10);cprintf("þ");textcolor(14);cprintf("³");
gotoxy(1,3); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
//gotoxy(1,4); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
//gotoxy(1,5); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
//gotoxy(1,6); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
//gotoxy(1,7); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
//gotoxy(1,8); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
//gotoxy(1,9); textcolor(15);cprintf("°");textcolor(14);cprintf("³");
gotoxy(1,4);textcolor(12);cprintf("");textcolor(14);cprintf("³");
//_wscroll=1;
for(cyc=1;cyc<11;cyc++)__line7(cyc,cp);
do{
textbackground(0);__line7(cp,cp);
  if(strnicmp(anow,"UPGRADE",7)==0)
    {
    cp=10;
    ga=7181;
    }
  else
    ga=bioskey(0);
textbackground(1);__line7(cp,cp);
if(ga==18432 || ga==19200)cp--;
if(ga==20480 || ga==19712)cp++;
if(ga==7181 || ga==14624){

  if(cp==1)
  {
	sound(200);
	delay(75);
	nosound();
	system("copy taz.doc prn");
	cp=2;
	goto lin;
  }
  if(cp==2)
  {
	sound(200);
	delay(75);
	nosound();
	system("copy taz.ord prn");
	cp=4;
	goto lin;
  }
  if(cp==4)
  {
	sound(100);
	delay(25);
	sound(200);
	delay(75);
	nosound();
//	window(1,1,80,25);
//	textcolor(7);
//	textbackground(0);
//	clrscr();
//	exit(0);
	return;
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
//	exit(0);
	return;
}

  if(cp==0)cp=4;
  if(cp==5)cp=1;

}while(en==0);
}
