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





char __ratepercent(int perc){  char c2;
  c2=1;		  		  if(perc>25) c2=2;
  if(perc>50) c2=3;               if(perc>75) c2=4;
  if(perc>90) c2=5;               return(c2);
}

void _crime(void){
  _P_.i_crime=(_P_.i_punishment+_P_.i_enforcement+_P_.i_security)/3;
  cyc2=0; //75
    if(_P_.i_crime>10)cyc2=1;
    if(_P_.i_crime>25)cyc2=2;
    if(_P_.i_crime>50)cyc2=3;
    if(_P_.i_crime>75)cyc2=4;
    if(_P_.i_crime>90)cyc2=5;
    if(_P_.i_crime>99)cyc2=6;
  yen[cyc2+30]=1;
  sprintf(intra,"%s",__language(String,cyc2));
}


void ratings(void){
  val=__ratepercent(_P_.approval);
  if(val<3){
    buy=(50-_P_.approval)*.005*1000;max=0;
    price=_P_.area[1]*buy*.001;_P_.area[1]-=price;max+=price;
    price=_P_.area[2]*buy*.001;_P_.area[2]-=price;max+=price;
    price=_P_.area[6]*buy*.001;_P_.area[6]-=price;max+=price;
    price=_P_.area[8]*buy*.001;_P_.area[8]-=price;max+=price;
    _P_.area[3]+=max;
    if(max>recover){max-=recover;recover=0;}else{max-=recover;max=0;}
  sprintf(intrav[9],"%s",_parsemoney(max));
  intrav[8][0]='1';
  }
  max=_P_.area[8]*200*val;
  buy=_P_.area[8]*(2+random(3))*val;
  if(_P_.population<max){_P_.population+=buy;price=1;}
  else {buy*=.5;_P_.population-=buy;price=2;}
  sprintf(intrav[5],"%s",_parsemoney(buy));
  sprintf(intrav[0],"%s",_parsemoney(develop));
  sprintf(intrav[1],"%s",_parsemoney(recover));
  sprintf(intrav[2],"%s",_parsemoney(terraform));
  sprintf(intrav[3],"%s",_parsemoney(detox));
  for(cyc=0;cyc<40;cyc++)
    yen[cyc]=0;
  for(cyc=0;cyc<10;cyc++)
    if(intrav[cyc][0]>48)yen[cyc]=1;
    else                 yen[cyc]=0;
  if(_I_)yen[4]=1;
  yen[5+price]=1;
  yen[__ratepercent(_P_.morale)   +9]=1;
  yen[__ratepercent(_P_.approval)+19]=1;
  _crime();
  __matrix("LOCALEVENTS");
}






void displaystatus(void){
  _crime();
  sprintf(ins,"%s",_P_.empire);
  yen[0]=_P_.protection;
  __matrix("DISPSTATUS");
}














void __trim(void){
    develop=0;recover=0;terraform=0;detox=0;
 production();
    if(_P_.condition[9]>0)_P_.condition[9]+=5;
    for(cyc=0;cyc<10;cyc++)
    {
      if(_P_.condition[cyc]>100)  _P_.condition[cyc]=100;
      if(_P_.object[cyc]>25000000)_P_.object[cyc]=25000000;
      if(_P_.area[cyc]>10000)
      {
	_P_.area[cyc]-=100;
	if(_P_.area[cyc]<10000)_P_.area[cyc]=10000;
      }
    }
    if(_P_.bullion>   2500000000)_P_.bullion=   2500000000;
    if(_P_.food>      1000000000)_P_.food=      1000000000;
    if(_P_.population>1000000000)_P_.population=1000000000;
}


void playgame(void){
  int cont=1;
  setproduction();
  __readnew(thisempire,thisuserno);
  if(_P_.warzone!=100)
  if(__W.statis>=6){
    __matrix("DEPMAINT");
//    od_printf("\n\r%s\n\n\r",__language(String,226));
//    pause();
    menu_2();
  }
  do{
    __trim();
    doinflation();
    displaystatus();
    _P_.turns--;
    if(_P_.protection)_P_.protection--;
    bank();
    paybills();
    bank();
    menu_sabo();
    menu_spending();
    menu_attack();
    if(_P_.warzone!=100)menu_2();
    if(_I_){
      _P_.approval*=.90;
      _P_.morale*=.90;
      _P_.i_approval*=.60;
      _P_.i_security*=.30;
    }
    ratings();
    savegame();
    pause();
    od_set_colour(15,0);od_printf("\n\r%s",__language(String,162)); if(ny()) menu_1();
    od_set_colour(15,0);od_printf("%s",__language(String,163)); if(ny()) menu_2();
    od_set_colour(15,0);od_printf("%s",__language(String,164));
      if(ny()){
	allscores();
	scores();
	pause();
	nl();
      }
//    od_set_colour(15,0);od_printf("%s",__language(String,165));
//      if(ny()){
//	scores();
//	pause();
//	nl();
//      }
      if(_P_.turns<1){
	__matrix("NOTURNS");
//	od_set_colour(12,0);
//	od_printf("%s\n\r",__language(String,91));
	cont=0;
      }
      else
      {
	__matrix("UCTTT");
//	od_set_colour(15,0);
//	od_printf("%s",__language(String,90));
	cont=yn();
	nl();
      }
  }while(cont==1);
}

unsigned long __outta(int _t,int _n,int _z,unsigned long _i,unsigned long _m){
unsigned long _r;
if(_i>_m)_i=_m;
if(_m<1)return(0);
od_printf("%s",__language(_t,_n));
space(_z);
_r=_proc(_i,_m);
return(_r);
}

void __mess(int x){
textbackground(0);
textcolor(7);
clrscr();
if(x!=5)return;
if(ENGLISH)system("type TAZENN.NFO");
if(FRENCH) system("type TAZFNN.NFO");
sleep(1);
}

void doinflation(void){
  unsigned long _toke, _toker, _tokish, tote=0;
  for(cyc3=0;cyc3<20;cyc3++)tote+=_P_.area[cyc3];
  _toke=random(450)+50;_toke+=tote*100;
  for(cyc=0;cyc<20;cyc++){total.area[cyc]=0;total.object[cyc]=0;inflation.area[cyc]=0;inflation.object[cyc]=0;}
      for(cyc=0;cyc<20;cyc++){ _toker=0;_tokish=1;
      if(cyc==1 || cyc==2 || cyc==5 || cyc==6){_toker=random(600)+100+tote*20;_tokish=100;}
      if(cyc==4){_toker=random(600)+100+tote*100;_tokish=1000;}
      if(cyc==7){_toker=random(250)+100+tote*50;_tokish=1000;}
      if(cyc==8){_toker=random(6000)+100+tote*1000;}
      _toker*=_tokish;      		inflation.area[cyc]=random(450)+50;
      inflation.area[cyc]+=_toke;      	inflation.area[cyc]+=_toker;
      inflation.object[cyc]=random(400*(cyc+1));}
  inflation.object[19]=_toke;
  _toke=random(900)+100;
  inflation.object[6]=random(5000);
  inflation.object[8]=random(10000);
  inflation.object[8]*=10;
  inflation.object[9]=random(500);
  inflation.object[9]*=_toke;
  for(cyc=0;cyc<7;cyc++)inflation.object[cyc]+=_P_.object[cyc]/50;
  for(cyc=0;cyc<19;cyc++){total.area[cyc]=inflation.area[cyc];total.object[cyc]=inflation.object[cyc];}
_inf_1=0;for(cyc=0;cyc<7;cyc++) _inf_1=total.object[cyc];_inf_1*=.001333;
_inf_2=0;for(cyc=0;cyc<20;cyc++)_inf_2+=total.area[cyc]; _inf_2*=.000001;
}

char __r(int mod){
  char _fname[15];
     int __userhandle, bytes=0;
     if(ENGLISH)sprintf(_fname,__LNGFILE__);
     if(FRENCH)sprintf(_fname,__FRNFILE__);
     if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(1,_fname);
     if ((bytes = read(__userhandle, (void *)&_____lang, sizeof(langrec))) == -1) __errormessage(2,_fname);
   close(__userhandle);
  return(_____lang.letter[mod]);
}



















