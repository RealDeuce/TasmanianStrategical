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

#include"tazdef.h"
#include<ctype.h>




/*
void __cyanlite(int x, int y){
  char ins3[81],cyc19;
  sprintf(ins3,"%s",__language(x,y));
  od_set_colour(11,0);
  od_printf("%c",ins3[0]);
  od_set_colour(3,0);
  for(cyc19=1;cyc19<81;cyc19++){
  if(ins3[cyc19]==0)cyc19=100;
  else od_printf("%c",ins3[cyc19]);
  }
  space(1);
}

*/





void setproduction(void){
  int onw=5;__rc=15;__rc2=12;unsigned long c4;
  do{
  __matrix("PRODUCTION");
//  od_set_colour(3,0);od_printf("%s",__language(String,125));
  if(ny()){
  __matrix("PRODUCTIONLINE");
/*
    __cyanlite(String,70);
    __cyanlite(String,71);
    __cyanlite(String,68);
    __cyanlite(String,69);
    __cyanlite(String,65);
    __cyanlite(Word,0);
    od_set_colour(15,0);od_printf("\b? ");
*/
      result=toupper(getkey());cyc2=0;cyc3=100;
      od_set_colour(3,0);
      if(result=='I') {cyc2=1;od_printf("%s\n\n\r",__language(String,70));}
      else if(result=='M') {cyc2=2;od_printf("%s\n\n\r",__language(String,71));}
      else if(result=='F') {cyc2=3;od_printf("%s\n\n\r",__language(String,68));}
      else if(result=='G') {cyc2=4;od_printf("%s\n\n\r",__language(String,69));}
      else if(result=='B') {cyc2=5;od_printf("%s\n\n\r",__language(String,65));}
      else od_printf("%s\n\n\r",__language(Word,0));
      od_set_colour(__rc2,0);
	if(cyc2==1){
	  c4=__outta(String,53,1,20,cyc3);cyc3-=c4;_P_.industry[2]=c4;
	  c4=__outta(String,54,1,20,cyc3);cyc3-=c4;_P_.industry[3]=c4;
	  c4=__outta(String,55,1,20,cyc3);cyc3-=c4;_P_.industry[4]=c4;
	  c4=__outta(String,56,1,20,cyc3);cyc3-=c4;_P_.industry[5]=c4;
	  c4=__outta(String,95,1,20,cyc3);cyc3-=c4;_P_.industry[7]=c4;_P_.industry[9]=cyc3;
//	  od_printf("%s ",__language(String,53));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.industry[2]=c4;
//	  od_printf("%s ",__language(String,54));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.industry[3]=c4;
//	  od_printf("%s ",__language(String,55));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.industry[4]=c4;
//	  od_printf("%s ",__language(String,56));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.industry[5]=c4;
//	  od_printf("%s ",__language(String,95));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.industry[7]=c4;
	}
	if(cyc2==2){
	  c4=__outta(String,92,1,25,cyc3);cyc3-=c4;_P_.military[0]=c4;
	  c4=__outta(String,54,1,25,cyc3);cyc3-=c4;_P_.military[3]=c4;
	  c4=__outta(String,55,1,25,cyc3);cyc3-=c4;_P_.military[4]=c4;
	  c4=__outta(String,56,1,25,cyc3);cyc3-=c4;_P_.military[5]=c4;_P_.military[9]=cyc3;
//	  od_printf("%s ",__language(String,92));if(cyc3<25)ab=cyc3;else ab=25;c4=_proc(ab,cyc3);cyc3-=c4;_P_.military[0]=c4;
//	  od_printf("%s ",__language(String,54));if(cyc3<25)ab=cyc3;else ab=25;c4=_proc(ab,cyc3);cyc3-=c4;_P_.military[3]=c4;
//	  od_printf("%s ",__language(String,55));if(cyc3<25)ab=cyc3;else ab=25;c4=_proc(ab,cyc3);cyc3-=c4;_P_.military[4]=c4;
//	  od_printf("%s ",__language(String,56));if(cyc3<25)ab=cyc3;else ab=25;c4=_proc(ab,cyc3);cyc3-=c4;_P_.military[5]=c4;_P_.military[9]=cyc3;
	}
	if(cyc2==3){
	  c4=__outta(String,92,1,20,cyc3);cyc3-=c4;_P_.fortress[0]=c4;
	  c4=__outta(String,52,1,20,cyc3);cyc3-=c4;_P_.fortress[1]=c4;
	  c4=__outta(String,53,1,20,cyc3);cyc3-=c4;_P_.fortress[2]=c4;
	  c4=__outta(String,55,1,20,cyc3);cyc3-=c4;_P_.fortress[4]=c4;
	  c4=__outta(String,57,1,20,cyc3);cyc3-=c4;_P_.fortress[6]=c4;_P_.fortress[9]=cyc3;
//	  od_printf("%s ",__language(String,92));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.fortress[0]=c4;
//	  od_printf("%s ",__language(String,52));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.fortress[1]=c4;
//	  od_printf("%s ",__language(String,53));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.fortress[2]=c4;
//	  od_printf("%s ",__language(String,55));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.fortress[4]=c4;
//	  od_printf("%s ",__language(String,57));if(cyc3<20)ab=cyc3;else ab=20;c4=_proc(ab,cyc3);cyc3-=c4;_P_.fortress[6]=c4;
	}
	if(cyc2==4){
	  c4=__outta(String,92,1,100,cyc3);cyc3-=c4;_P_.gouvernment=c4;
//	  od_printf("%s ",__language(String,92));c4=_proc(100,cyc3);cyc3-=c4;
	}
	if(cyc2==5){
	  c4=__outta(String,95,1,100,cyc3);cyc3-=c4;_P_.biosphere=c4;
//	  od_printf("%s ",__language(String,95));c4=_proc(100,cyc3);cyc3-=c4;_P_.biosphere=c4;
	}
    }
    else
    onw=0;
  nl();
  nl();
  nl();
  }while(onw==5);
  __rc=10;__rc2=7;
}




void palais(void){
  sprintf(intrav[0],"%s",_parsemoney(1000000*((100-_P_.condition[7])*_P_.object[7])));
  sprintf(intrav[1],"%s",_parsemoney(100000000*(_P_.object[7]+1)));
  sprintf(intrav[2],"%d",100-_P_.object[7]*9);
top:;
  __matrix("PALAIS");
  res=toupper(getkey());
    if(res=='R'){
      od_set_colour(11,0);od_printf("%s\n\n\r",__language(Word,40));od_set_colour(15,0);
      if(_P_.bullion>1000000*(100*_P_.object[7]-_P_.condition[7])){
	_P_.bullion-=(1000000*(100*_P_.object[7]-_P_.condition[7]));
	_P_.condition[7]=100;
	od_printf("\n\r%s\n\n\r",__language(String,98));
      } else {
	__matrix("NOARGENT");
//	od_printf("\n\r%s\n\n\r",__language(String,84));
      }
    pause();
    }
    else if(res=='U'){
      od_set_colour(11,0);od_printf("%s\n\n\r",__language(Word,37));od_set_colour(15,0);
      if(_P_.bullion>100000000*(_P_.object[7]+1)){
	_P_.bullion-=100000000*(_P_.object[7]+1);
	  if(random(100)<100-_P_.object[7]*9){
	    _P_.object[7]++;
	    od_printf("\n\r%s\n\n\r",__language(String,96));
	  } else {
	    od_printf("\n\r%s\n\n\r",__language(String,97));
	  }
      } else {
	__matrix("NOARGENT");
//	od_printf("\n\r%s\n\n\r",__language(String,84));
      }
    pause();
    }
    else    {
      od_set_colour(11,0);
      od_printf("%s\n\n\r",__language(Word,0));return;
      }
goto top;
}

void bank(void){
  unsigned long max,ans;char ins2[80];__rc=15;
  sprintf(intra,"%s",_E_);
  val=_P_.population*.00357;
  if(!val)val=1;
  sprintf(intrav[0],"%s",_parsemoney(val));
bdo:;
  __matrix("BANQUE");
  res=toupper(getkey());od_set_colour(11,0);
  if(res=='D')od_printf("%s",__language(Word,24));
  else if(res=='W')od_printf("%s",__language(Word,23));
  else if(res=='P')od_printf("%s",__language(Word,25));
  else if(res=='S')od_printf("%s",__language(Word,26));
  else if(res=='H')__matrix("BANKHELP");
  else {od_printf("%s\n\r",__language(Word,0));__rc=10;return;}
  nl();od_set_colour(7,0);
  if(res=='D'){
  max=2500000000-_P_.bank;
  if(max>_P_.bullion)max=_P_.bullion;
  ans=__outta(String,7,1,0,max);
  _P_.bank+=ans;_P_.bullion-=ans;
  }
  if(res=='W'){
  max=2500000000-_P_.bullion;
  if(max>_P_.bank)max=_P_.bank;
  ans=__outta(String,7,1,0,max);
  _P_.bank-=ans;_P_.bullion+=ans;
  }
  if(res=='P'){
  max=2500000000-_P_.investment;
  ans=(_P_.bullion/val);
  if(max>ans)max=ans;
  ans=__outta(String,7,1,0,max);
  _P_.investment+=ans;_P_.bullion-=ans*val;
  }
  if(res=='S'){
  max=2500000000-_P_.bullion;
  if(max*.01>(_P_.investment*.01)*val)max=_P_.investment*val;
  ans=max/val;max=ans;
  ans=__outta(String,7,1,0,max);
  _P_.investment-=ans;_P_.bullion+=ans*val;
  }
goto bdo;
}
















void __scoreit(void){
  char ins2[80],cyc03;unsigned long tote=0;int xt,oldr;
      for(cyc03=0;cyc03<26;cyc03++){
	if(player[cyc03].statis){
	  od_set_colour(13,0);od_printf(" %c  ",cyc03+'A');
	  od_set_colour(5,0);if(__empire==thisempire && cyc03==thisuserno)od_set_colour(13,0);	  od_printf(" %d  ",__empire);
	  /*od_set_colour(7,0);*/
	  od_printf("%-34.34s",player[cyc03].empire);tote=0;
	  for(cyc3=0;cyc3<10;cyc3++)tote+=player[cyc03].object[cyc3]*.005;
	  for(cyc3=0;cyc3<10;cyc3++)tote+=player[cyc03].area[cyc3]  *.01;oldr=cyc03;
	  sprintf(ins2,"%s",_parsemoney(tote));od_printf("%13s",ins2);
	  tote=0;for(cyc3=0;cyc3<20;cyc3++)tote+=player[cyc03].area[cyc3];sprintf(ins2,"%s",_parsemoney(tote));
	  /*od_set_colour(14,0);*/od_printf("%10s ",ins2);/*od_set_colour(7,0);*/cyc03=oldr;space(FRENCH);
	  xt=0;for(cyc5=0;cyc5<50;cyc5++)if(_W_[cyc5].empire==__empire && _W_[cyc5].player==cyc03 && _W_[cyc5].statis>0)xt=_W_[cyc5].statis;
	  if(player[cyc03].statis==1)od_printf("%s",__language(Word,33));
	  else if(xt==0 || xt>=4){if(player[cyc03].approval<50){od_set_colour(15,0);od_printf("Coup");} else od_printf("%s",__language(Word,31));}
	  else /*if(xt<=3)*/{od_set_colour(12,0);od_printf("%s",__language(Word,32));}
	  nl();	}      }
}

void scores(void){
  unsigned long value;char ins2[80],old=__empire,cyc01;
  savegame();__matrix("GRPSCORES");
  for(cyc4=0;cyc4<10;cyc4++){
  ___empire(cyc4);cyc01=0;
  od_set_colour(13,0);
  od_printf(" %d  ",__empire);
  if(thisempire!=__empire)od_set_color(5,0);
  od_printf("%-24.24s ",_E_[__empire]);
  value=0;for(cyc2=0;cyc2<26;cyc2++)for(cyc3=0;cyc3<10;cyc3++)if(player[cyc2].statis==2)value+=(player[cyc2].object[cyc3]/1000);
  sprintf(ins2,"%s",_parsemoney(value));if(thisempire!=__empire)od_set_color(5,0);od_printf("%10s",ins2);
  for(cyc2=0;cyc2<26;cyc2++)if(player[cyc2].statis>0)cyc01++;
  if(thisempire!=__empire)od_set_color(5,0);od_printf("%8d",cyc01);
  value=0;for(cyc2=0;cyc2<26;cyc2++)if(player[cyc2].statis>0)value+=((player[cyc2].bullion/1000000)+(player[cyc2].bank/1000000));
  if(thisempire!=__empire)od_set_color(5,0);od_printf("%8lu ",value);
  value=0;for(cyc2=0;cyc2<26;cyc2++)for(cyc3=0;cyc3<10;cyc3++)if(player[cyc2].statis>0)value+=player[cyc2].area[cyc3];value*=.1;
  if(thisempire!=__empire)od_set_color(5,0);space(FRENCH);od_printf("%6lu ",value);
  value=0;
  for(cyc2=0;cyc2<26;cyc2++)if(player[cyc2].area[3]>0)value=2;
  for(cyc2=0;cyc2<26;cyc2++)if(player[cyc2].area[10]>0)value=3;
  for(cyc5=0;cyc5<50;cyc5++)if(_W_[cyc5].empire==__empire && _W_[cyc5].statis>0 && _W_[cyc5].statis<4)value=1;
if(thisempire!=__empire)od_set_colour(5,0);
  if(value==0)od_printf("%s",__language(String,167));
  if(value==2)od_printf("%s",__language(String,168));
  if(value==3)od_printf("%s",__language(String,169));
od_set_colour(12,0);
  if(value==1)od_printf("%s",__language(String,170));
  nl();
}
  od_set_colour(L_GREEN,D_BLACK);
  __matrix("LINE78");//  for(cyc01=0;cyc01<78;cyc01++)od_printf("Ä");nl();
//  nl();
  ___empire(old);
}

void allscores(void){
  char old=__empire,cyc02;
//  nl();
//  od_set_colour(7,0);
//  od_set_colour(4,0);
//  od_printf("Des GRP %-10s                                %s %s %s\n\r",__language(Word,36),__language(Word,34),__language(String,58),__language(Word,35));
//  od_set_colour(13,0);
//  for(cyc02=0;cyc02<70+FRENCH;cyc02++)od_printf("Ä");
//  nl();
  __matrix("EMPSCORES");
  if(__theman)__scoreit(); else
  for(cyc4=0;cyc4<10;cyc4++){
  od_printf("%d\r",cyc4);
  ___empire(cyc4);
  __scoreit();
  }
  ___empire(thisempire);
  __matrix("LINE72");
//  od_set_colour(13,0);
//  for(cyc02=0;cyc02<70+FRENCH;cyc02++)od_printf("Ä");
//  nl();
  ___empire(old);
}

















void selectempire(int openings[10]){
  unsigned long value;char ins2[80];
  init3:;
//  od_set_colour(D_GREEN,D_BLACK);od_printf("\n\r%s",__language(String,9));
//  od_set_colour(L_GREEN,D_BLACK);od_printf("%s ",fullname);
//  od_set_colour(D_GREEN,D_BLACK);od_printf("v");
//  od_set_colour(L_GREEN,D_BLACK);od_printf("%s.\n\r",__version);
  sewage();__matrix("BEINVENUE");  scores();
  cyc5=2;
do{
  __matrix("DECLAIR");
//  od_set_colour(2,0);
//  od_printf("%s",__language(String,171));
  __rc=10;
  sprintf(ins,"%s",_dinput(2));od_printf("\n\n\r");
//  __rc=10;
  cyc=atoi(ins);
  if(openings[cyc]==0)__matrix("NOPGRP");
  else {
  thisempire=cyc;
  __empire=cyc;
  loadgame();
init2:;
  sprintf(ins,"%s",__language(String,174));
  if(strcmp(_E_[__empire],ins)==0){
  __matrix("NEWGRP");
//  od_set_colour(7,0);od_printf("%s\n\r",__language(String,175));
//  od_set_colour(3,0);od_printf("%s ",__language(String,176));
//  od_set_colour(11,0);
  od_input_str(ins,25,32,167);
	if(strlen(ins)<1){
	  od_set_colour(10,0);
	  od_printf("%s. . .\n\r",__language(Word,9));
	  pause();
	  goto init3;
	}
      sprintf(intra,"%s ",ins);
      __matrix("GAPPELLE");
//      od_set_colour(D_CYAN,D_BLACK);
//      od_printf("\n\r%s",__language(String,10));
//      od_set_colour(L_YELLOW,D_BLACK);
//      od_printf("%s ",ins);
      checkhot();
	if(!yn())goto init2;
  sprintf(_E_[__empire],"%s",ins);
  savegame();
  }
  }
  cyc5=0;
}while(cyc5==2);
  bbsexit=1;
}








void warscores(void){
  char ins2[80];unsigned long tote=0;int xt,oldr,old=__empire;
  ___empire(old);
//  nl();
//  od_set_colour(7,0);
//  od_set_colour(4,0);
//  od_printf("Des GRP %-10s                      %15s %s\n\r",__language(Word,36),__language(String,71),__language(Word,28));
//  __matrix("LINE70");//  for(cyc=0;cyc<70;cyc++)od_printf("Ä");nl();
__matrix("WARSCORES");
      for(cyc=0;cyc<50;cyc++){
	if(_W_[cyc].statis>0){
	  ___empire(_W_[cyc].empire);
	  od_set_colour(13,0);od_printf(" %c  ",_W_[cyc].player+'A');
	  od_set_colour(5,0);if(_W_[cyc].empire==thisempire && _W_[cyc].player==thisuserno)od_set_colour(13,0);
	  od_printf(" %d  ",_W_[cyc].empire);	  /*od_set_colour(7,0);*/
	  od_printf("%-30.30s",player[_W_[cyc].player].empire);tote=0;
	  for(cyc3=0;cyc3<10;cyc3++)tote+=_W_[cyc].object[cyc3]*.01;
	  sprintf(ins2,"%s",_parsemoney(tote));
	  /*od_set_colour(14,0);*/od_printf("%17s ",ins2);
	  xt=_W_[cyc].statis;//od_set_colour(5,0);
	  if(player[_W_[cyc].player].statis==1)od_printf("%s",__language(String,35));
	  else if(xt==1)od_printf("%s",__language(String,34));
	  else if(xt==2)od_printf("%s",__language(String,33));
	  else if(xt==3)od_printf("%s",__language(String,32));
	  else if(xt>=4)__matrix("DEPLOYING");//od_printf("%s",__language(String,226));
	  nl();
	}
      }
  __matrix("LINE72");
//  __matrix("LINE70");//  for(cyc=0;cyc<70;cyc++)od_printf("Ä");nl();
  ___empire(old);
}








void warzoneit(int mode){
 /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  unsigned long _ins=100,_ins2=0;int quand,qui;char ins2[80];

  // Statis=0 - Unused
  // Statis=1 - Attacking Homeland \
  // Statis=2 - Neutral Warzone    |---- Warzone
  // Statis=3 - Defending Homeland /
  // Statis=4 - Deploying (24hrs)
  // Statis=5 - Deploying (48hrs)
  // Statis=6 - Deploying (72hrs) *-* Autodeployment
  // Statis=7 - Deploying (96hrs) *-* Forced in

  ___empire(thisempire);
  for(cyc=0;cyc<50;cyc++)if(_W_[cyc].statis==0){_ins=cyc;cyc=100;}

if(mode==1){ /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
	quand = __select(177);    if(quand==100)return;	___empire(quand);
	qui   = __select(119);    if(qui==100){___empire(thisempire);return;}
	if(player[qui].protection){
	__matrix("PROTED");
	return;
	}

	___empire(thisempire);

  if(_P_.warzone==100){
	if(_ins==100){od_printf("\n\r%s\n\n\r",__language(String,22));return;
	} else {
	_P_._W_=_ins;
	__W.statis=6;
	__W.player=thisuserno;
	__W.empire=thisempire;
	__W.morale=100;
	__W.approval=100;
	for(cyc=0;cyc<10;cyc++)__W.object[cyc]=0;
  }
  }
  sprintf(ins2,"@12@%s%s",_P_.empire,__language(String,27));
  __log(ins2,quand,qui);
  ___empire(quand);
  for(cyc=0;cyc<50;cyc++)if(_W_[cyc].statis==0){_ins=cyc;cyc=100;}
  if(player[qui]._W_==100){
    if(_ins==100){od_printf("\n\r%s\n\n\r",__language(String,29));return;
	} else {
    player[qui]._W_=_ins;
    warzone[player[qui]._W_].statis=7;
    warzone[player[qui]._W_].player=qui;
    warzone[player[qui]._W_].empire=quand;
    warzone[player[qui]._W_].morale=100;
    warzone[player[qui]._W_].approval=100;
    for(cyc=0;cyc<10;cyc++)warzone[player[qui]._W_].object[cyc]=0;
    }
  }
  ___empire(thisempire);
  sprintf(ins2,"@12@%s%s",_P_.empire,__language(String,30));
  __log(ins2,99,99);
  if(__W.statis>4)__matrix("WAR_RAPID");
}/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
if(mode==2){ /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(_P_.warzone==100){max=0;
    for(cyc=0;cyc<50;cyc++)if(_W_[cyc].statis)max=1;
    if(!max){
    __matrix("MAISNTJ");
    //od_printf("\n\r%s\n\n\r",__language(String,228));pause();
    return;}
    if(_ins==100){od_printf("\n\r%s\n\n\r",__language(String,22));return;
    } else {
    _P_._W_=_ins;
	__W.statis=6;
    __W.player=thisuserno;
    __W.empire=thisempire;
    __W.morale=100;
    __W.approval=100;
    for(cyc=0;cyc<10;cyc++)__W.object[cyc]=0;
  ___empire(thisempire);
  sprintf(ins2,"@12@%s%s",_P_.empire,__language(String,30));
  __log(ins2,99,99);
    }
  }
  if(__W.statis>4)__help2("WAR_RAPID");
}/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
if(mode==3 || mode==4){ /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(_P_.warzone==100){
  __matrix("DECLR1ER");
  return;}
  if(__W.statis==3){__help2("HELP_RETREAT");return;}
  _ins2=__outta(String,92,1,25000000-__W.object[0],_P_.object[0]);__W.object[0]+=_ins2; _P_.object[0]-=_ins2;
  _ins2=__outta(String,52,1,25000000-__W.object[1],_P_.object[1]);__W.object[1]+=_ins2; _P_.object[1]-=_ins2;
  _ins2=__outta(String,53,1,25000000-__W.object[2],_P_.object[2]);__W.object[2]+=_ins2; _P_.object[2]-=_ins2;
  _ins2=__outta(String,54,1,25000000-__W.object[3],_P_.object[3]);__W.object[3]+=_ins2; _P_.object[3]-=_ins2;
  _ins2=__outta(String,55,1,25000000-__W.object[4],_P_.object[4]);__W.object[4]+=_ins2; _P_.object[4]-=_ins2;
  _ins2=__outta(String,57,1,25000000-__W.object[5],_P_.object[6]);__W.object[6]+=_ins2; _P_.object[6]-=_ins2;
  if(__W.statis>=6)__W.statis=5;
}/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
if(mode==5){ /*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  if(_P_.warzone==100){
  __matrix("DECLR1ER");
//  od_printf("\n\r%s\n\n\r",__language(String,227));
//  pause();
  return;}
  od_printf("%s",__language(Word,59));
  if(ny()){
  _ins2=__outta(String,92,1,250000000-_P_.object[0],__W.object[0]);__W.object[0]-=_ins2; _P_.object[0]+=_ins2;
  _ins2=__outta(String,52,1,250000000-_P_.object[1],__W.object[1]);__W.object[1]-=_ins2; _P_.object[1]+=_ins2;
  _ins2=__outta(String,53,1,250000000-_P_.object[2],__W.object[2]);__W.object[2]-=_ins2; _P_.object[2]+=_ins2;
  _ins2=__outta(String,54,1,250000000-_P_.object[3],__W.object[3]);__W.object[3]-=_ins2; _P_.object[3]+=_ins2;
  _ins2=__outta(String,55,1,250000000-_P_.object[4],__W.object[4]);__W.object[4]-=_ins2; _P_.object[4]+=_ins2;
  _ins2=__outta(String,57,1,250000000-_P_.object[5],__W.object[6]);__W.object[6]-=_ins2; _P_.object[6]+=_ins2;
  __W.statis=3;
  __help2("HELP_RETREAT");
      sprintf(ins,"@15!%s",__language(String,77));
	      __log(ins,99,99);
      sprintf(ins,"@12@%s%s",_P_.empire,__language(String,75));
	      __log(ins,99,99);
  }
}/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
  ___empire(thisempire);
}

void ___empire(int newter){
savegame();
__empire=newter;
loadgame();
}
