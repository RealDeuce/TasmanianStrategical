/***************************************************************************/
/*                                                                         */
/*   REGIS.EXE Ver 1a                                                      */
/*   REGIS.EXE Ver 1a                                                      */
/*   REGIS.EXE Ver 1a                                                      */
/*                                                                         */
/***************************************************************************/

#define NOOPEN
#include"install.h"
#include<stream.h>
#include<dir.h>
#include<bios.h>

char _xent2[80],toggle2[10][80],correct[10][80];
extern void NWDR_main(char ar[80]);
extern void __window(int x1, int x2, int y1, int y2, int c1, int c2);
extern void __fill(void);



void __line2(int xx, int cu){
if(xx==0) { gotoxy(3,1 ); cprintf(" Individule Nom      "); cprintf("%-35s",toggle2[1]);}
if(xx==1) { gotoxy(3,1 ); cprintf(" Individule Nom      "); cprintf("%-35s",toggle2[1]);}
if(xx==2) { gotoxy(3,2 ); cprintf(" Serialle            "); cprintf("%-35s",toggle2[2]);}
if(xx==3) { gotoxy(3,3 ); cprintf(" Specification       "); cprintf("%-35s",toggle2[3]);}
if(xx==4) { gotoxy(3,4 ); cprintf(" Definition          "); cprintf("%-35s",toggle2[4]);}
if(xx==5) { gotoxy(3,5 ); cprintf(" Ambiance            "); cprintf("%-35s",toggle2[5]);}
if(xx==6) { gotoxy(3,6 ); cprintf(" Devior              "); cprintf("%-35s",toggle2[6]);}
if(xx==7) { gotoxy(3,7 ); cprintf("                     "); cprintf("%-35s",toggle2[7]);}
if(xx==8) { gotoxy(3,8 ); cprintf(" Expires             "); cprintf("%-35s",toggle2[8]);} //37
if(xx==9) { gotoxy(3,9 ); cprintf(" Verify...           "); cprintf("%-35s",toggle2[9]);}
if(xx==10){ gotoxy(3,10); cprintf(" Save...             "); cprintf("%-35s",toggle2[10]);}
}

void NWDR_main(char ar[80]){
int x=79,cyc,ga,cp,en;char smart[10],anew[80],pathname[20];FILE *stream;
directvideo=0;_wscroll=0;cp=1;ga=0;en=0;struct date d;getdate(&d);
sprintf(_xent2,"%s",ar);
do {
 _xent2[x]=0;
 x--;
}while(_xent2[x]!='\\');
sprintf(toggle2[1],"The Kelvar Porcupine");
sprintf(toggle2[2],"12345");
sprintf(toggle2[3],"12345");
sprintf(toggle2[4],"12345");
sprintf(toggle2[5],"0");
sprintf(toggle2[6],"0");
sprintf(toggle2[7],"");
sprintf(toggle2[8],"Expired");
sprintf(toggle2[9],"Unverified");
sprintf(toggle2[10],"");
complete:;
window(1,1,80,25);
//textbackground(0);clrscr();
__fill();
__window(1,4,1,80,14,1);
gotoxy(2,2); cprintf("                            Maartian Enterprises                             ");
gotoxy(2,3); cprintf("                       REGISTER.EXE (II) Version 1.00                        ");
__window(23,25,1,80,14,1);
gotoxy(3,24);cprintf("All Rights Reserved  (C)opyright 1993,1994 Laurence Maar  All Rights Reserved");
__window(8,19,11,70,14,1);
partial:;
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
for(cyc=1;cyc<11;cyc++)__line2(cyc,cp);
do{
textbackground(0);__line2(cp,cp);
ga=bioskey(0);
textbackground(1);__line2(cp,cp);
if(ga==18432 || ga==19200)cp--;
if(ga==20480 || ga==19712)cp++;
if(ga==7181 || ga==14624){

  if(cp==1){
	sound(500);	delay(70);	nosound();
	sprintf(toggle2[1],"");__line2(1,cp);
	gotoxy(24,1);gets(anew);
	sprintf(toggle2[1],"%s",anew);__line2(1,cp);
  }

  if(cp==2){
	sound(500);	delay(70);	nosound();
	sprintf(toggle2[2],"");__line2(2,cp);
	gotoxy(24,2);gets(anew);
	sprintf(toggle2[2],"%lu",atol(anew));__line2(2,cp);
	__line2(2,cp);
  }

  if(cp==3){
	sound(500);	delay(70);	nosound();
	sprintf(toggle2[3],"");__line2(3,cp);
	gotoxy(24,3);gets(anew);
	sprintf(toggle2[3],"%lu",atol(anew));__line2(3,cp);
	__line2(3,cp);
  }

  if(cp==4){
	sound(500);	delay(70);	nosound();
	sprintf(toggle2[4],"");__line2(4,cp);
	gotoxy(24,4);gets(anew);
	sprintf(toggle2[4],"%lu",atol(anew));__line2(4,cp);
	__line2(4,cp);
  }

  if(cp==5){
	sound(500);	delay(70);	nosound();
	sprintf(toggle2[5],"");__line2(5,cp);
	gotoxy(24,5);gets(anew);
	sprintf(toggle2[5],"%lu",atol(anew));__line2(5,cp);
	__line2(5,cp);
  }

  if(cp==6){
	sound(500);	delay(70);	nosound();
	sprintf(toggle2[6],"");__line2(6,cp);
	gotoxy(24,6);gets(anew);
	sprintf(toggle2[6],"%lu",atol(anew));__line2(6,cp);
	__line2(6,cp);
  }

  if(cp==7){
	sound(375);	delay(100);	nosound();
  }

  if(cp==8){
	sound(375);	delay(100);	nosound();
  }

  if(cp==9){
	sound(500);	delay(70);	nosound();
  sprintf(toggle2[9],"Processing...");__line2(9,cp);sleep(1);

  sprintf(toggle2[9],"Verifying...");__line2(9,cp);delay(200);

	      sprintf(toggle2[8],"Infinity");  __line2(8,cp);
	      sprintf(toggle2[9],"Verified");  __line2(9,cp);

	  bp(toggle2[1],12111);
	  sprintf(correct[2],"%lu",rcount);rcount=0;
	    if(strnicmp(toggle2[2],correct[2],strlen(correct[2]))!=0){
	      sprintf(toggle2[2],"Incorrect");  __line2(2,cp);
	      sprintf(toggle2[9],"Unverified"); __line2(9,cp);
	    } else {
	      sprintf(toggle2[2],"Correct");    __line2(2,cp); sprintf(toggle2[2],correct[2]);
	    }

       sprintf(correct[3],"%lu",(atol(toggle2[3])/511));
       sprintf(correct[4],"%lu",(atol(toggle2[4])/453));
       if(atol(correct[3])!=1977){
	 if(atol(correct[3])<1994 || atol(correct[4])>12 || atol(correct[4])<1){
	      sprintf(toggle2[3],"Incorrect");  __line2(3,cp);
	      sprintf(toggle2[4],"Incorrect");  __line2(4,cp);
	      sprintf(toggle2[8],"Unverified"); __line2(8,cp);
	 } else {
	      sprintf(_xent2,toggle2[3]);
	      sprintf(toggle2[3],"Correct");    __line2(3,cp); sprintf(toggle2[3],_xent2);
	      sprintf(_xent2,toggle2[4]);
	      sprintf(toggle2[4],"Correct");    __line2(4,cp); sprintf(toggle2[4],_xent2);
	 if(atol(correct[3])<d.da_year || (atol(correct[3])==d.da_year && atol(correct[4])<d.da_mon)){
	      sprintf(toggle2[3],"Incorrect");  __line2(3,cp);
	      sprintf(toggle2[4],"Incorrect");  __line2(4,cp);
	      sprintf(toggle2[8],"Expired");  __line2(8,cp);
	 } else {
	      sprintf(toggle2[8],"%lu þ %lu",atol(correct[4]),atol(correct[3]));  __line2(8,cp);
	 }
	 }
       } else {
	 sprintf(_xent2,toggle2[3]);
	 sprintf(toggle2[3],"Correct");    __line2(3,cp); sprintf(toggle2[3],_xent2);
	 sprintf(_xent2,toggle2[4]);
	 sprintf(toggle2[4],"Correct");    __line2(4,cp); sprintf(toggle2[4],_xent2);
       }

	  sprintf(correct[5],"%d",(15*toggle2[1][0]+toggle2[1][1]+toggle2[1][2]+toggle2[1][3]));
	    if(strnicmp(toggle2[5],correct[5],strlen(correct[5]))!=0 && toggle2[5][0]!='0'){
	      sprintf(toggle2[5],"Incorrect");  __line2(5,cp);
	      sprintf(toggle2[9],"Unverified"); __line2(9,cp);
	    } else {
	      if(toggle2[5][0]=='0'){
	      sprintf(toggle2[5],"Not Applicable");    __line2(5,cp); sprintf(toggle2[5],"0");
	      } else {
	      sprintf(toggle2[5],"Correct");    __line2(5,cp); sprintf(toggle2[5],correct[5]);
	      }
	    }

	  sprintf(correct[6],"%d",(17*toggle2[1][0]+toggle2[1][1]+toggle2[1][2]+toggle2[1][3]));
	    if(strnicmp(toggle2[5],correct[5],strlen(correct[5]))!=0 && toggle2[6][0]!='0'){
	      sprintf(toggle2[6],"Incorrect");  __line2(6,cp);
	      sprintf(toggle2[9],"Unverified"); __line2(9,cp);
	    } else {
	      if(toggle2[6][0]=='0'){
	      sprintf(toggle2[6],"Not Applicable");    __line2(6,cp); sprintf(toggle2[6],"0");
	      } else {
	      sprintf(toggle2[6],"Correct");    __line2(6,cp); sprintf(toggle2[6],correct[6]);
	      }
	    }
    if(toggle2[8][0]=='E' && toggle2[9][0]=='V'){
      sprintf(toggle2[8],"Expired þ Press ESC");  __line2(8,cp);
      sprintf(toggle2[9],"Expired þ Press ESC");  __line2(9,cp);
      sprintf(toggle2[10],"Expired þ Press ESC"); __line2(10,cp);
    }
  }

  if(cp==10){
	sound(500);	delay(70);	nosound();
  sprintf(toggle2[10],"Processing...");__line2(10,cp);sleep(1);
  sprintf(toggle2[10],"Verifying...");    __line2(10,cp);sleep(1);
    if(toggle2[9][0]=='E' || toggle2[9][0]=='U'){
      sprintf(toggle2[10],"All Codes must be verified first");  __line2(10,cp);sleep(2);
      sprintf(toggle2[10],"Press ESC to abort");  __line2(10,cp);sleep(1);
      goto partial;
    }
  sprintf(toggle2[10],"Saving...");    __line2(10,cp);sleep(1);
	stream=fopen(__REGFILE__,"w+");
	fprintf(stream,"%s\n\r",toggle2[1]);
	fprintf(stream,"%s\n\r",toggle2[2]);
	fprintf(stream,"%s\n\r",toggle2[3]);
	fprintf(stream,"%s\n\r",toggle2[4]);
	fprintf(stream,"%s\n\r",toggle2[5]);
	fprintf(stream,"%s\n\r",toggle2[6]);
	fclose(stream);
  sprintf(toggle2[10],"Done...");    __line2(10,cp);sleep(1);
  window(1,1,80,25);
  textcolor(7);
  textbackground(0);
  clrscr();
//  exit(0);
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
