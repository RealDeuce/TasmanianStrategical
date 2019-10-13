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









char _xent5[80],toggle5[10][80],correct5[10][80];
extern void NEWS_main(char ar[80]);
extern void NEWD_main(char ar[80]);
extern void NWDR_main(char ar[80]);
extern void INST_main(char ar[80]);
extern void __window(int x1, int x2, int y1, int y2, int c1, int c2);
extern void __fill(void);
extern int aar;












void __line5(int xx, int cu){int con=0;
if(xx==1) { gotoxy(3,1 +con); cprintf(" Program Name        "); cprintf("%-35s",toggle5[1]);}
if(xx==2) { gotoxy(3,2 +con); cprintf(" Target Directory    "); cprintf("%-35s",toggle5[2]);}
if(xx==3) { gotoxy(3,3 +con); cprintf(" Source Directory    "); cprintf("%-35s",toggle5[3]);}
if(xx==4) { gotoxy(3,4 +con); cprintf("                     "); cprintf("%-35s",toggle5[4]);}
if(xx==5) { gotoxy(3,5 +con); cprintf(" Install First Disk  "); cprintf("%-35s",toggle5[5]);}
if(xx==6) { gotoxy(3,6 +con); cprintf(" Install Bonus Disk  "); cprintf("%-35s",toggle5[6]);}
if(xx==7) { gotoxy(3,7 +con); cprintf("                     "); cprintf("%-35s",toggle5[7]);}
if(xx==8) { gotoxy(3,8 +con); cprintf("                     "); cprintf("%-35s",toggle5[8]);}
if(xx==9) { gotoxy(3,9 +con); cprintf("                     "); cprintf("%-35s",toggle5[9]);}
if(xx==10){ gotoxy(3,10+con); cprintf(" Proceed...          "); cprintf("%-35s",toggle5[10]);}
}








void INST_main(char ar[80]){
int x=79,cyc,ga,cp,en;char anew[80],anow[80],anot[80];
directvideo=0;_wscroll=0;ga=0;en=0;
window(1,1,80,25);clrscr();
__fill();
__window(8,19,11,70,14,1);
window(12,9,69,18);
gotoxy(1,2);
cprintf(" WARNING: Because of recent changes to the function and\n\r");
cprintf(" installation of Tasmanian Strategical, we strongly urge\n\r");
cprintf(" you to print the SysOp Manual. If you have a printer,\n\r");
cprintf(" make sure that it is ONLINE. If not, read the TAZ.DOC\n\r");
cprintf(" file after installation!\n\n\r");
cprintf(" Print Manual Now ? ");
cp=getch();
if(cp!='N' && cp!='n')
{
system("copy taz.doc prn");
}
cp=1;
sprintf(_xent5,"%s",ar);
if(aar==1)sprintf(anew,"UPGRADE");
if(aar==1)sprintf(anow,"UPGRADE");
if(aar==1)sprintf(anot,"UPGRADE");
do {
 _xent5[x]=0;
 x--;
}while(_xent5[x]!='\\');
sprintf(toggle5[1], "Tasmanian Strategical");
sprintf(toggle5[2], "%s",_xent5);
sprintf(toggle5[3], "%s",_xent5);
sprintf(toggle5[4], "");
sprintf(toggle5[5], "Yes");
sprintf(toggle5[6], "No");
sprintf(toggle5[7], "");
sprintf(toggle5[8], "");
sprintf(toggle5[9], "");
sprintf(toggle5[10],"");
  if(strnicmp(anew,"UPGRADE",7)==0) {
	sprintf(toggle5[6],"No");
	sprintf(toggle5[7],"No");
	sprintf(toggle5[9],"No");
  }
complete:;
window(1,1,80,25);
//textbackground(0);clrscr();
__fill();
__window(1,4,1,80,14,1);
gotoxy(2,2); cprintf("                            Maartian Enterprises                             ");
gotoxy(2,3); cprintf("                          INSTALL.EXE (II) Ver 1.00                          ");
__window(23,25,1,80,14,1);
gotoxy(3,24);cprintf("All Rights Reserved  (C)opyright 1993,1994 Laurence Maar  All Rights Reserved");
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
for(cyc=1;cyc<11;cyc++)__line5(cyc,cp);
do{
textbackground(0);__line5(cp,cp);
  if(strnicmp(anow,"UPGRADE",7)==0)
    {
    cp=10;
    ga=7181;
    }
  else
    ga=bioskey(0);
textbackground(1);__line5(cp,cp);
if(ga==18432 || ga==19200)cp--;
if(ga==20480 || ga==19712)cp++;
if(ga==7181 || ga==14624){

  if(cp==1){
	sound(375);	delay(100);	nosound();
  }

  if(cp==2){
	sound(200);	delay(75);	nosound();
	sprintf(toggle5[2],"");__line5(2,cp);
	gotoxy(24,2);gets(anew);
	sprintf(toggle5[2],"%s",anew);
	if(strlen(anew)<2)sprintf(toggle5[2],"%s",_xent5);
	if(toggle5[2][strlen(toggle5[2])-1]!='\\'){sprintf(anew,toggle5[2]);sprintf(toggle5[2],"%s\\",anew);}
	__line5(2,cp);
  }

  if(cp==3){
	sound(200);	delay(75);	nosound();
	sprintf(toggle5[3],"");__line5(3,cp);
	gotoxy(24,3);gets(anew);
	sprintf(toggle5[3],"%s",anew);
	if(strlen(anew)<2)sprintf(toggle5[3],"%s",_xent5);
	if(toggle5[3][strlen(toggle5[3])-1]!='\\'){sprintf(anew,toggle5[3]);sprintf(toggle5[3],"%s\\",anew);}
	__line5(3,cp);
  }

  if(cp>3 && cp<10){
	sound(200);	delay(75);	nosound();
	if(toggle5[cp][0]=='Y')sprintf(toggle5[cp],"No");
	else if(toggle5[cp][0]=='N')sprintf(toggle5[cp],"Yes");
  }

  if(cp==10){
	sound(200);	delay(75);	nosound();	sprintf(toggle5[10],"Processing...");	__line5(10,cp);sleep(1);
	mkdir(toggle5[2]);
	sound(200);	delay(75);	nosound();	sprintf(toggle5[10],"Uncompressing...");__line5(10,cp);sleep(1);

	  if(toggle5[5][0]=='Y')
	  {
		window(1,1,80,25);textbackground(0);clrscr();sprintf(anew,"LHA x /c %sEXEC %s",toggle5[3],toggle5[2]);system(anew);delay(200);
		window(1,1,80,25);textbackground(0);clrscr();sprintf(anew,"LHA x /c %sDATA %s",toggle5[3],toggle5[2]);system(anew);delay(200);
		//window(1,1,80,25);textbackground(0);clrscr();sprintf(anew,"LHA x /c %sDOCS %s",toggle5[3],toggle5[2]);system(anew);delay(200);
	  }
	  if(toggle5[6][0]=='Y')
	  {
		window(1,1,80,25);textbackground(0);clrscr();sprintf(anew,"LHA x /c %sBONS %s",toggle5[3],toggle5[2]);system(anew);delay(200);
	  }

	clrscr();
	toggle5[2][strlen(toggle5[2])-1]=0;
	chdir(toggle5[2]);
	return;
  }
}

if(cp==0)cp=10;

if(cp==11)cp=1;

if(ga==283){
	sound(100);
	delay(25);
	sound(200);
	delay(75);
	nosound();
//     window(1,1,80,25);
//     textbackground(0);
//     textcolor(7);
//     clrscr();
//     exit(0);
     return;
}

}while(en==0);
}
