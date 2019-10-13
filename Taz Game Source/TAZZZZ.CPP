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

/****************************************************************************
PALAIS
  /*
  char ins2[20],ins3[20];
  sprintf(ins2,"%s",_parsemoney(100000000*(_P_.object[7]+1)));
  sprintf(ins3,"%s",_parsemoney(1000000*((100-_P_.condition[7])*_P_.object[7])));  od_printf("\n\n\r");
  od_set_colour(13,0);for(cyc=0;cyc<30;cyc++)od_printf("ฤ");nl();
  od_set_colour(15,0);od_printf("Palais Status\n\r");od_set_colour(7,0);
  od_printf("%-10s : %lu\n\r",__language(Word,39),_P_.object[7]);
  od_printf("%-10s : %lu%%\n\r",__language(String,178),_P_.condition[7]);
  od_printf("%-10s : $%s\n\r",__language(Word,40),ins3);
  od_printf("%-10s : $%s\n\r",__language(Word,37),ins2);
  od_printf("%-10s : %lu%%\n\r",__language(Word,38),100-_P_.object[7]*9);
  od_set_colour(13,0);for(cyc=0;cyc<30;cyc++)od_printf("ฤ");nl();
  __cyanlite(Word,37);
  __cyanlite(Word,40);
  __cyanlite(Word,0);
  od_set_colour(15,0);od_printf("\b? ");
  */

PRODUCTION
/*od_set_colour(13,0);for(cyc=0;cyc<50;cyc++)od_printf("ฤ");nl();
  od_set_colour(15,0);od_printf("%-13.13s Indus Milit Fortr Govrn Biosp\n\r",__language(String,93));  od_set_colour(7,0);
  od_printf("%-13.13s  ----  %3lu%%  %3lu%%  %3lu%%  ----\n\r",__language(String,92),_P_.military[0],_P_.fortress[0],_P_.gouvernment);
  od_printf("%-13.13s  ----  ----  %3lu%%  ----  ----\n\r",__language(String,52),_P_.fortress[1]);
  od_printf("%-13.13s  %3lu%%  ----  %3lu%%  ----  ----\n\r",__language(String,53),_P_.industry[2],_P_.fortress[2]);
  od_printf("%-13.13s  %3lu%%  %3lu%%  ----  ----  ----\n\r",__language(String,54),_P_.industry[3],_P_.military[3]);
  od_printf("%-13.13s  %3lu%%  %3lu%%  %3lu%%  ----  ----\n\r",__language(String,55),_P_.industry[4],_P_.military[4],_P_.fortress[4]);
  od_printf("%-13.13s  %3lu%%  %3lu%%  ----  ----  ----\n\r",__language(String,56),_P_.industry[5],_P_.military[5]);
  od_printf("%-13.13s  ----  ----  %3lu%%  ----  ----\n\r",__language(String,57),_P_.fortress[6]);
  od_printf("%-13.13s  %3lu%%  ----  ----  ----  %3lu%%\n\r",__language(String,95),_P_.industry[7],_P_.biosphere);
  od_printf("%-13.13s  %3lu%%  %3lu%%  %3lu%%  %3lu%%  %3lu%%\n\r",__language(Word,43),_P_.industry[9],_P_.military[9],_P_.fortress[9],100-_P_.gouvernment,100-_P_.biosphere);
  od_set_colour(13,0);for(cyc=0;cyc<50;cyc++)od_printf("ฤ");nl();
*/

BANK
//  nl();
//  od_set_colour(14,0);od_printf("%s\n\r",__language(String,149));
//  sprintf(ins2,"%s",_parsemoney(_P_.bank));
//  od_set_colour(7,0); od_printf("%s%s %s\n\r",__language(String,150),ins2,__language(Word,15));
//  sprintf(ins2,"%s",_parsemoney(_P_.investment));
//  od_set_colour(7,0); od_printf("%s%s %s\n\r",__language(String,151),ins2,__language(Word,15));
//  nl();
//  __cyanlite(Word,24);
//  __cyanlite(Word,23);
//  __cyanlite(Word,25);
//  __cyanlite(Word,26);
//  __cyanlite(Word,0);
//  od_set_colour(15,0);od_printf("\b? ");

DISPLAY STATUS
void displaystatus(void){
//  unsigned long tote;char ins2[80];
//  od_set_colour(12,0);
//  for(cyc=0;cyc<70;cyc++)od_printf("ฤ");
    _P_.i_crime=(_P_.i_punishment+_P_.i_enforcement+_P_.i_security)/3;
    cyc2=75;
    if(_P_.i_crime>10)cyc2=76;
    if(_P_.i_crime>25)cyc2=77;
    if(_P_.i_crime>50)cyc2=78;
    if(_P_.i_crime>75)cyc2=79;
    if(_P_.i_crime>90)cyc2=80;
    if(_P_.i_crime>99)cyc2=81;
/*    nl();
      od_set_colour(8,0);od_printf("-");
      od_set_colour(D_CYAN,0);od_printf("ฎ");
      od_set_colour(11,0);od_printf("*");
      od_set_colour(15,0);od_printf("%s",_P_.empire);
      od_set_colour(11,0);od_printf("*");
      od_set_colour(D_CYAN,0);od_printf("ฏ");
      od_set_colour(8,0);od_printf("-");
      nl();
      od_set_colour(D_MAGENTA,0);od_printf("%s",__language(String,34));od_set_colour(13,0);od_printf("%d\n\r",_P_.turns);
      od_set_colour(D_MAGENTA,0);od_printf("%s",__language(String,35));od_set_colour(13,0);sprintf(ins2,"%s",_parsemoney(_P_.bullion));od_printf("%s ",ins2);
      od_set_colour(D_MAGENTA,0);od_printf("[%s",__language(String,36));od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.bank));od_printf("%s",ins2);od_set_colour(D_MAGENTA,0);od_printf("]\n\r");
      od_set_colour(D_MAGENTA,0);od_printf("%s",__language(String,37));od_set_colour(13,0);sprintf(ins2,"%s",_parsemoney(_P_.population));od_printf("%s",ins2);od_set_colour(D_MAGENTA,0);od_printf(" %s ",__language(String,38));
      od_set_colour(D_GREEN,0);od_printf("(%s",__language(Word,56));od_set_colour(10,0);od_printf("%d",_P_.taxrate);od_set_colour(D_GREEN,0);od_printf("%%) ");
      od_set_colour(D_GREEN,0);od_printf("(%s",__language(Word,57));od_set_colour(10,0);od_printf("%d",_P_.draftrate);od_set_colour(D_GREEN,0);od_printf("%%) ");
      od_set_colour(D_GREEN,0);od_printf("(%s",__language(String,41));od_set_colour(10,0);od_printf("%d",_P_.approval);od_set_colour(D_GREEN,0);od_printf("%%)\n\r");
      od_set_colour(D_MAGENTA,0);od_printf("%s",__language(String,43));od_set_colour(13,0);sprintf(ins2,"%s",_parsemoney(_P_.object[0]));od_printf("%s",ins2);od_set_colour(D_MAGENTA,0);od_printf(" %s ",__language(String,45));
      od_set_colour(D_GREEN,0);od_printf("(%s",__language(String,42));od_set_colour(10,0);sprintf(ins2,"%s",_parsemoney(_P_.food));od_printf("%s",ins2);od_set_colour(D_GREEN,0);od_printf(") ");
      od_set_colour(D_GREEN,0);od_printf("(%s",__language(String,44));od_set_colour(10,0);od_printf("%d",_P_.morale);od_set_colour(D_GREEN,0);od_printf("%%)\n\r");
      od_set_colour(D_MAGENTA,0);od_printf("%s",__language(String,46));od_set_colour(13,0);od_printf("%s\n\r",__language(String,cyc2));
      if(__laboum){od_set_colour(D_GREEN,0);od_printf("(%s",__language(String,47));od_set_colour(10,0);od_printf("%d",_P_.i_security);od_set_colour(D_GREEN,0);od_printf("%%) ");
      od_set_colour(D_GREEN,0);od_printf("(%s",__language(String,48));od_set_colour(10,0);od_printf("%d",_P_.i_punishment);od_set_colour(D_GREEN,0);od_printf("%%) ");
      od_set_colour(D_GREEN,0);od_printf("(%s",__language(String,49));od_set_colour(10,0);od_printf("%d",_P_.i_enforcement);od_set_colour(D_GREEN,0);od_printf("%%) ");
      od_set_colour(D_GREEN,0);od_printf("(%s",__language(String,50));od_set_colour(10,0);od_printf("%d",_P_.i_crime);od_set_colour(D_GREEN,0);od_printf("%%)\n\r");}
      od_set_colour(D_MAGENTA,0);od_printf("%s",__language(String,82));sprintf(ins,"%s",__language(String,51));
	od_set_colour(D_MAGENTA,0);od_printf("[");
	od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.object[7]));od_printf("%s ",ins2);
	od_set_colour(D_MAGENTA,0);od_printf("%s ",__language(String,60));
	od_set_colour(13,0);od_printf("%d",_P_.condition[7]);od_set_colour(D_MAGENTA,0);od_printf("%%] [%s",__language(String,61));
	od_set_colour(13,0);od_printf("%d",_P_.condition[9]);od_set_colour(D_MAGENTA,0);od_printf("%%] [");
	od_set_colour(13,0);sprintf(ins2,"%s",_parsemoney(_P_.object[8]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s]\n\r",__language(String,59));
      od_set_colour(D_MAGENTA,0);od_printf("%s",__language(String,51));
	od_set_colour(D_MAGENTA,0);od_printf("[");od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.object[1]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] [",__language(String,52));
	od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.object[2]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] [",__language(String,53));
	od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.object[3]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s]\n\r",__language(String,54));
	space(strlen(ins));od_set_colour(D_MAGENTA,0);od_printf("[");od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.object[4]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] [",__language(String,55));
	od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.object[5]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] [",__language(String,56));
	od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.object[6]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s]\n\r",__language(String,57));
      od_set_colour(D_MAGENTA,0);od_printf("%s",__language(String,63));sprintf(ins,"%s",__language(String,63));
	od_set_colour(D_MAGENTA,0);od_printf("[");od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[0]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] ",__language(String,64));
	od_set_colour(D_MAGENTA,0);od_printf("[");od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[1]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] [",__language(String,65));
	od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[2]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s]\n\r",__language(String,66));
	space(strlen(ins));od_set_colour(D_MAGENTA,0);od_printf("[");od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[3]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] ",__language(String,67));
	od_set_colour(D_MAGENTA,0);od_printf("[");od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[4]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] [",__language(String,68));
	od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[5]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s]\n\r",__language(String,69));
	space(strlen(ins));od_set_colour(D_MAGENTA,0);od_printf("[");od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[6]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] ",__language(String,70));
	od_set_colour(D_MAGENTA,0);od_printf("[");od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[7]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] [",__language(String,71));
	od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[8]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s]\n\r",__language(String,72));
	space(strlen(ins));od_set_colour(D_MAGENTA,0);od_printf("[");od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[9]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] [",__language(String,73));tote=0;for(cyc3=0;cyc3<20;cyc3++)tote+=_P_.area[cyc3];
	od_set_colour(L_MAGENTA,0);sprintf(ins2,"%s",_parsemoney(_P_.area[10]));od_printf("%s ",ins2);od_set_colour(D_MAGENTA,0);od_printf("%s] [",__language(String,74));od_set_colour(15,0);sprintf(ins2,"%s",_parsemoney(tote));od_printf("%s",ins2);od_set_colour(D_MAGENTA,0);od_printf("]\n\r");
	space(strlen(ins));od_set_colour(13,0);od_printf("%d ",_P_.protection);	od_set_colour(5,0);od_printf("%s\n\r",__language(String,225));
  od_set_colour(12,0);
  for(cyc=0;cyc<70;cyc++)od_printf("ฤ");
  nl();
  pause();*/
  sprintf(ins,"%s",_P_.empire);
  sprintf(intra,"%s",__language(String,cyc2));
  __matrix("DISPSTATUS");
}

RATINGS
void ratings(void){
/*  unsigned long inter=0,deux=0;char ins2[80];
  od_set_colour(12,0);for(cyc=0;cyc<70;cyc++)od_printf("ฤ");nl();
  od_set_colour(7,0);
  _P_.i_crime=(_P_.i_punishment+_P_.i_enforcement+_P_.i_security)/3;cyc2=0;
  cyc2=__ratepercent(_P_.i_crime); od_printf("%s",__language(Line,cyc2+8));
  cyc2=__ratemorale (_P_.morale);  od_printf("%s",__language(Line,cyc2+14));
  cyc2=__ratemorale (_P_.approval);od_printf("%s",__language(Line,cyc2+20));
  if(cyc2<3){
    cyc3=(50-_P_.approval)*.005;
    deux=_P_.area[1]*cyc3;_P_.area[1]-=deux;inter+=deux;
    deux=_P_.area[2]*cyc3;_P_.area[2]-=deux;inter+=deux;
    deux=_P_.area[6]*cyc3;_P_.area[6]-=deux;inter+=deux;
    deux=_P_.area[8]*cyc3;_P_.area[8]-=deux;inter+=deux;
    _P_.area[3]+=inter;
    if(inter>recover){inter-=recover;recover=0;}else{recover-=inter;inter=0;}
  sprintf(ins2,"%s",_parsemoney(inter));
  if(inter)     od_printf("%s%s%s\n\r",__language(String,152),ins2,__language(String,153));
  else          od_printf("%s\n\r",__language(String,154));
  }
  sprintf(ins2,"%s",_parsemoney(develop));  if(develop)   od_printf("%s%s%s\n\r",__language(String,155),ins2,__language(String,159));
  sprintf(ins2,"%s",_parsemoney(recover));  if(recover)   od_printf("%s%s%s\n\r",__language(String,156),ins2,__language(String,160));
  sprintf(ins2,"%s",_parsemoney(terraform));if(terraform) od_printf("%s%s%s\n\r",__language(String,157),ins2,__language(String,159));
  sprintf(ins2,"%s",_parsemoney(detox));    if(detox)     od_printf("%s%s%s\n\r",__language(String,158),ins2,__language(String,161));
  if(_I_) od_printf("%s\n\r",__language(String,188));
*/}


/*
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
/* Setup 1.00    */ char path[80],pathname[160],path2[80],path3[3],type;FILE *stream;
/* Setup 1.00    */ if((stream=fopen(__CFGFILE__,"r"))!=NULL){fclose(stream);__loadconfiguration();};
/* Setup 1.00    */ __localfrench();
/* Setup 1.00    */ textbackground(0);clrscr();
/* Setup 1.00    */ __window(1,7,14,1);
/* Setup 1.00    */ gotoxy(5,3); cprintf("                        Maartian Enterprises");
/* Setup 1.00    */ gotoxy(5,5); cprintf("                   %s%s %s",__vsetsp,__language(String,21),__vset);
/* Setup 1.00    */ __window(21,23,14,1);
/* Setup 1.00    */ gotoxy(3,22);cprintf("%s",__language(Line,2));
/* Setup 1.00    */ gotoxy(3,22);cprintf("(C) Copyright 1993 þ Laurence Maar þ");
/* Setup 1.00    */ window(1,10,80,18);
/* Setup 1.00    */ gotoxy(1,1);textbackground(0);
/* Setup 1.00    */ textcolor(10);cprintf("%s\n\r",__language(Line,1));
/* Setup 1.00    */ textcolor( 2);cprintf("%s\n\r",__language(String,15));
/* Setup 1.00    */ textcolor(15);cin >> config.directory[0];
/* Setup 1.00    */ textcolor(10);cprintf("\n\r%s\n\r",__language(Line,3));
/* Setup 1.00    */ textcolor( 2);cprintf("%s\\%s\n\r",__language(String,15),filename);
/* Setup 1.00    */ textcolor(15);cin >> config.directory[1];
/* Setup 1.00    */ textcolor(10);cprintf("\n\r%s\n\r",__language(String,229));
/* Setup 1.00    */ textcolor( 2);cprintf("%s\n\r",__language(Word,47));
/* Setup 1.00    */ textcolor(15);cin >> config.directory[2];
/* Setup 1.00    */ textcolor(10);cprintf("\n\r%s\n\r",__language(String,18));
/* Setup 1.00    */ textcolor( 2);cprintf("%s\n\r",__language(String,16));
/* Setup 1.00    */ textcolor(15);cin >> path3;config.parameter[0]=atol(path3);
/* Setup 1.00    */ textcolor(10);cprintf("\n\r%s\n\r",__language(String,19));
/* Setup 1.00    */ textcolor( 2);cprintf("%s\n\r",__language(String,16));
/* Setup 1.00    */ textcolor(15);cin >> path3;config.parameter[5]=atol(path3);
/* Setup 1.00    */ textcolor(10);cprintf("\n\r%s\n\r",__language(String,146));
/* Setup 1.00    */ textcolor( 2);cprintf("%s\n\r",__language(String,147));
/* Setup 1.00    */ textcolor(15);cin >> path3;config.parameter[7]=atol(path3);
/* Setup 1.00    */ textcolor(10);cprintf("\n\r%s\n\r",__language(String,148));
/* Setup 1.00    */ textcolor( 2);cprintf("%s\n\r",__language(String,16));
/* Setup 1.00    */ textcolor(15);cin >> path3;config.parameter[8]=atol(path3);
/* Setup 1.00    */ textcolor(11);textcolor(7);
/* Setup 1.00    */ __saveconfiguration();
/* Setup 1.00    */ cprintf("\n\n\r%s\n\r",__language(String,14));
/* Setup 1.00    */ cprintf("[1] CHAIN.TXT    - Apex/Telegard/WWiV\n\r");
/* Setup 1.00    */ cprintf("[2] DOOR.SYS     - Apex/GAP/RemoteAccess/Spitfire v3/TAG/Telegard/Wildcat v3\n\r");
/* Setup 1.00    */ cprintf("[3] DORINFOx.DEF - Apex/QBBS/RBBS/RemoteAccess/Telegard\n\r");
/* Setup 1.00    */ cprintf("[4] SFDOORS.DAT  - Apex/Spitfire/Telegard/TriTel\n\r");
/* Setup 1.00    */ cprintf("[5] CALLINFO.BBS - Apex/Telegard/Wildcat [A]/Wildcat [B]\n\r");
/* Setup 1.00    */ cprintf("[9] PCBOARD.SYS  - Pcboard\n\n\r");
/* Setup 1.00    */ textcolor(15);cin >> path3;type=atoi(path3);
/* Setup 1.00    */ textcolor(11);textcolor(7);
/* Setup 1.00    */ window(1,1,80,25);clrscr();
/* Setup 1.00    */ chdir(config.directory[1]);
/* Setup 1.00    */ sprintf(pathname,"%s.BAT",filename);
/* Setup 1.00    */ stream=fopen(pathname,"w+");
/* Setup 1.00    */ fprintf(stream,"@echo off\n\r");
/* Setup 1.00    */ fprintf(stream,"echo %s v%s %s Laurence Maar (c)1993                           \n\r",fullname,__version,__language(String,20));
/* Setup 1.00    */ fprintf(stream,"echo The Fossil Driver BNU is included with this program.         \n\r");
/* Setup 1.00    */ fprintf(stream,"echo The author of Smurf Combat encourages that you register      \n\r");
/* Setup 1.00    */ fprintf(stream,"echo BNU if you already havn't done so. This program will         \n\r");
/* Setup 1.00    */ fprintf(stream,"echo not function without a fossil driver such as BNU or X00.                             \n\r");
/* Setup 1.00    */ fprintf(stream,"echo BNU 1.88แ þ (C) 1989 þ David Nugent & Unique Computing Ptd Ltd                      \n\r");
/* Setup 1.00    */ fprintf(stream,"cd %s\n\r",config.directory[1]);
/* Setup 1.00    */ if(type==1)fprintf(stream,"copy %s\\CHAIN.TXT\n\r",config.directory[0]);
/* Setup 1.00    */ if(type==2)fprintf(stream,"copy %s\\DOOR.SYS\n\r",config.directory[0]);
/* Setup 1.00    */ if(type==3)fprintf(stream,"copy %s\\DORINFO*.DEF\n\r",config.directory[0]);
/* Setup 1.00    */ if(type==4)fprintf(stream,"copy %s\\SFDOORS.DAT\n\r",config.directory[0]);
/* Setup 1.00    */ if(type==5)fprintf(stream,"copy %s\\CALLINFO.BBS\n\r",config.directory[0]);
/* Setup 1.00    */ if(type==9)fprintf(stream,"copy %s\\PCBOARD.SYS\n\r",config.directory[0]);
/* Setup 1.00    */ fprintf(stream,"BNU\n\r");
/* Setup 1.00    */ if(type==9)fprintf(stream,"%s PCBOARD\n\r",filename);
/* Setup 1.00    */ fprintf(stream,"%s %1 %2 %3 %4 %5 %6 %7 %8 %9\n\r",filename);
/* Setup 1.00    */ fprintf(stream,"cd %s\n\r",config.directory[0]);
/* Setup 1.00    */ fclose(stream);
/* Setup 1.00    */ chdir(config.directory[1]);
/* Setup 1.00    */ }

void intercontinnental(void){/*
int mod=bbsinkey-'0';
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(mod==1){
  interattack[0].statis=0;
  interattack[0].toplanet=0;
  interattack[0].toqui=0;
  interattack[0].fromplanet=thisplanet;
  for(cyc=0;cyc<10;cyc++)interattack[0].fromqui[cyc]=thisuserno;
  for(cyc=0;cyc<10;cyc++)interattack[0].proportion[cyc]=0;
  interattack[0].returnval=0;
  for(cyc=0;cyc<10;cyc++)interattack[0].unit[cyc]=0;
  __header(253);
  sprintf(ins,"%s",_dinput(2));od_printf("\n\n\r");
  cyc=atoi(ins);
  if(cyc)cyc--; else return;
  od_set_colour(3,0);
  if(!inter.statis[cyc]){
  __matrix("PLANON");
  //od_printf("%s\n\n\r",__language(String,255));
  pause();
  return;
  }
  }
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(mod==2){
  }
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(mod==3){
  }
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(mod==4){
  mpl(10);nl();
  locmpl(20);nl();
  od_set_colour(13,0);for(cyc=0;cyc<70;cyc++)od_printf("ฤ");nl();
  od_set_color(11,0);od_printf("# %s               %-9s %s %s\n\r",__language(String,250),__language(String,71),__language(Word,30),__language(Word,28));
  for(cyc=0;cyc<10;cyc++){
  od_printf("%d %s\n\r",cyc,inter.planet[interattack[cyc].toplanet]);
  }
  od_set_colour(13,0);for(cyc=0;cyc<70;cyc++)od_printf("ฤ");nl();
  pause();
  }
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(mod==5){
  }
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(mod==6){
  }
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(mod==7){
  }
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
*/}







*/
****************************************************************************/
