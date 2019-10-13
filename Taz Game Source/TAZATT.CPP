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
unsigned long emor;



unsigned long __dotak(unsigned long at,unsigned long ap,unsigned long a1,unsigned long a2,unsigned long a3,unsigned long a4,unsigned long a5,unsigned long _ins,unsigned long _ins3,unsigned long _tot3){int TTT;
	 if(__E.object[a1])TTT=a1;    else if(__E.object[a2])TTT=a2;    else if(__E.object[a3])TTT=a3;    else if(__E.object[a4])TTT=a4;    else if(warsub==6 && __E.object[a5])TTT=a5;    else if(warsub==6) TTT=6;    else TTT=a5;

//cccprintf("O: %7lu",__E.object[TTT]);

    _ins=__P.object[at]*.0001*ap;
    if(TTT==3 && at==2)_ins*=5;
    if(__E.object[TTT]<=_ins){
      _ins3=__E.object[TTT];od_set_colour(random(7)+9,0);if(price!=1)od_printf("þ");
    }
    else
    _ins3=_ins;
    _tot3+=_ins3;
    __E.object[TTT]-=_ins3;

//cccprintf(" (-)%7lu (=)%7lu   A[A]: %7lu <%9lu>\n\r",_ins3,__E.object[TTT],__P.object[at],_tot3);
return(_tot3);
}


unsigned long __detak(unsigned long at,unsigned long ap,unsigned long a1,unsigned long a2,unsigned long a3,unsigned long a4,unsigned long a5,unsigned long _ins,unsigned long _ins3,unsigned long _tot2){int TTT;
	 if(__P.object[a1])TTT=a1;    else if(__P.object[a2])TTT=a2;    else if(__P.object[a3])TTT=a3;    else if(__P.object[a4])TTT=a4;    else if(warsub==6 && __P.object[a5])TTT=a5;    else if(warsub==6) TTT=6;    else TTT=a5;

//cccprintf("D: %7lu",__P.object[TTT]);

    _ins=__E.object[at]*.0001*ap;
    if(TTT==3 && at==2)_ins*=5;
    if(__P.object[TTT]<=_ins){
      _ins3=__P.object[TTT];od_set_colour(random(7)+9,0);if(price!=1)od_printf("þ");
    }
    else
    _ins3=_ins;
    _tot2+=_ins3;
    __P.object[TTT]-=_ins3;

//cccprintf(" (-)%7lu (=)%7lu   A[D]: %7lu <%9lu>\n\r",_ins3,__P.object[TTT],__E.object[at],_tot2);
return(_tot2);
}


void __collect(int avail){
 int fx;
  do{
    res=__menu("COLLECT");
    od_printf("%s",__language(String,183));fx=_proc(0,avail);avail-=fx;
      switch(res){
	case 'A':_P_.area[0]+=fx;break;
	case 'B':_P_.area[1]+=fx;break;
	case 'C':_P_.area[2]+=fx;break;
	case 'G':_P_.area[5]+=fx;break;
	case 'I':_P_.area[6]+=fx;break;
	case 'M':_P_.area[7]+=fx;break;
	case 'R':_P_.area[8]+=fx;break;
      }
  }while(avail>0);
}




void __totallies(int quand){/*
char old=__empire;*/
for(cyc=0;cyc<20;cyc++)total.object[cyc]=0;/*
for(cyc=0;cyc<10;cyc++){
  ___empire(cyc);
  for(cyc2=0;cyc2<26;cyc2++){
    if(player[cyc2].statis==2){
      if(player[cyc2].relation[quand]){
	if(player[cyc2].relation[quand]>=3)
	  total.object[0]+=player[cyc2].object[0]*.1;
	if(player[cyc2].relation[quand]>=4){
	  total.object[0]+=player[cyc2].object[0]*.1;
	  total.object[1]+=player[cyc2].object[1]*.2;
	}
	if(player[cyc2].relation[quand]==5){
	  total.object[3]+=player[cyc2].object[3]*.9;
	  for(cyc=0;cyc<20;cyc++)total.object[cyc]=0;
	}
	if(player[cyc2].relation[quand]>=5){
	  total.object[3]+=player[cyc2].object[3]*.9;
	}
	if(player[cyc2].relation[quand]>=6){
	  total.object[4]+=player[cyc2].object[4]*.20;
	}
	if(player[cyc2].relation[quand]>=7){
	  total.object[0]+=player[cyc2].object[0]*.05;
	  total.object[1]+=player[cyc2].object[1]*.05;
	  total.object[2]+=player[cyc2].object[2]*.10;
	  total.object[3]+=player[cyc2].object[3]*.1;
	  total.object[4]+=player[cyc2].object[4]*.13;
	}
      }
    }
  }
}
___empire(old);
*/}



void attack(void){
  int quand,qui;unsigned long _ins=0,_ins2=0,_ins3=0,_tot=0,_tot2=0,_tot3=0,_tot4=0,_tot5=0;char ins2[80],ins3[80];warsub=5;
    __help2("KKKK_ATTACK");
    quand = __select(177);    if(quand==100)return;	___empire(quand);
    qui   = __select(119);    if(qui==100){___empire(thisempire);return;}

for(cyc=0;cyc<50;cyc++){
  if(warzone[cyc].empire==quand && warzone[cyc].player==qui && warzone[cyc].statis>0 && warzone[cyc].statis<4){
    __help2("ATTACK_BUFFER");
    return;
  }
}

if(player[qui].protection){__matrix("PROTED");return;}

    for(cyc=0;cyc<10;cyc++){ __T.object[cyc]    = player[qui].object[cyc];    _tot+=__T.object[cyc]; }
    for(cyc=0;cyc<10;cyc++){ __T.object[cyc+10] = player[qui].condition[cyc]; }
    for(cyc=0;cyc<20;cyc++)  __E.object[cyc]    = __T.object[cyc];
    for(cyc=0;cyc<20;cyc++)  __T.area[cyc]      = player[qui].area[cyc];
    __totallies(quand);
    for(cyc=0;cyc<10;cyc++)  __E.object[cyc]    += __T.object[cyc];
    emor=player[qui].morale;
    ___empire(thisempire);
    __P.area[19]=_P_.morale;
    for(cyc=0;cyc<20;cyc++)__P.object[cyc]      = 0;

    od_set_colour(__rc2,0);
_ins2=_P_.object[5]*60;if(_ins2>_P_.object[0])_ins2=_P_.object[0];
__P.object[0]=__outta(String,92,1,_P_.object[0],_ins2        );_P_.object[0]-=__P.object[0];_tot4+=__P.object[0];
__P.object[1]=__outta(String,52,1,_P_.object[1],_P_.object[1]);_P_.object[1]-=__P.object[1];_tot4+=__P.object[1];
__P.object[3]=__outta(String,54,1,_P_.object[3],_P_.object[3]);_P_.object[3]-=__P.object[3];_tot4+=__P.object[3];
__P.object[4]=__outta(String,55,1,_P_.object[4],_P_.object[4]);_P_.object[4]-=__P.object[4];_tot4+=__P.object[4];
__P.object[6]=__outta(String,57,1,_P_.object[6],_P_.object[6]);_P_.object[6]-=__P.object[6];_tot4+=__P.object[6];
    _tot*=.333;
    _tot4*=.2;

  bbsexit=2;

  _ins=__P.object[0];
  _ins2=_P_.object[5];
  if(_ins<_ins2)_ins2=_ins;
  if(_ins>0){
  od_set_colour(random(7)+9,0);
  _ins3=_ins/_ins2;
  _ins=__E.object[3]*.0001*4; // Bom
  if(_ins>_P_.object[5]){_ins=_P_.object[5];od_printf("þ");}
  if(_ins*_ins3>__P.object[0]){_ins=__P.object[0]/_ins3;od_printf("þ");}
  __P.object[0]-=_ins*_ins3;
  _P_.object[5]-=_ins;
  _tot2+=(_ins)+((_ins)*(_ins3));
  od_set_colour(random(7)+9,0);
  od_printf("ù");
  delay(100);
  }

  _ins3=__P.object[4];
  if(_ins3>0){
  od_set_colour(random(7)+9,0);
  _ins=__E.object[3]*.0001*4; // Bom
  if(_ins>_ins3){_ins=_ins3;od_printf("þ");}
  __P.object[4]-=_ins;
  _tot2+=_ins;
  od_set_colour(random(7)+9,0);
  od_printf("ù");
  delay(100);
  }

  price=1;

  do{

    /*----- Offensive Volley -----------------------------------------------*/
    _tot3=__dotak(0,  1/*100*/,0,1,2,4,8,_ins,_ins3,_tot3);
    _tot3=__dotak(1,  2/* 50*/,1,0,2,4,8,_ins,_ins3,_tot3);
    _tot3=__dotak(3,  8/*  1*/,2,1,0,4,8,_ins,_ins3,_tot3);
    _tot3=__dotak(4,  5/* 20*/,4,2,1,0,8,_ins,_ins3,_tot3);
    _tot3=__dotak(6, 10/* 50*/,8,2,1,0,0,_ins,_ins3,_tot3);

    od_set_colour(random(7)+9,0);
    od_printf("ù");
    delay(20);

    /*----- Defensive Volley -----------------------------------------------*/
    _tot2=__detak(0,  1*emor  ,0,1,6,3,4,_ins,_ins3,_tot2);
    _tot2=__detak(0,  1/*100*/,0,1,3,4,6,_ins,_ins3,_tot2);
    _tot2=__detak(1,  2/* 50*/,1,0,3,4,6,_ins,_ins3,_tot2);
    _tot2=__detak(2, 96/*  1*/,3,4,6,1,0,_ins,_ins3,_tot2);
    _tot2=__detak(3,  1/*  1*/,3,4,6,1,0,_ins,_ins3,_tot2);
    _tot2=__detak(4,  5/* 20*/,3,4,6,1,0,_ins,_ins3,_tot2);

    od_set_colour(random(7)+9,0);
    od_printf("ù");
    delay(20);

    /*----- Counting Losses ------------------------------------------------*/
    _ins=0;for(cyc=0;cyc<5;cyc++)_ins+=__E.object[cyc]; if(_tot3>_tot  || _ins<100)bbsexit=3; //cprintf("{[%lu %lu %lu]}\n\n\r",_ins,_tot3,_tot);
    _ins=0;for(cyc=0;cyc<7;cyc++)_ins+=__P.object[cyc]; if(_tot2>_tot4 || _ins<100)bbsexit=4; //cprintf("{[%lu %lu %lu]}\n\n\r",_ins,_tot2,_tot4);

  }while(bbsexit==2);
  max=bbsexit;
  bbsexit=1;

    for(cyc=0;cyc<10;cyc++){
      if(__E.object[cyc]<__T.object[cyc])__E.object[cyc]=0;
      else
      __E.object[cyc]-=__T.object[cyc];
    }

  od_set_colour(7,0);
  sprintf(ins,"%s",_parsemoney(_tot2));od_printf("\n\r\n\r%s%s%s\n\r",__language(String,180),ins,__language(Word,52));
  sprintf(ins,"%s",_parsemoney(_tot3));od_printf("%s%s%s\n\r",__language(String,181),ins,__language(Word,52));

  _tot3=0;
  for(cyc=0;cyc<10;cyc++)_tot3+=__T.object[cyc];

  sprintf(ins,"%s",_parsemoney(_tot3));od_printf("%s%s\n\n\r",ins,__language(String,182));

  for(cyc=0;cyc<10;cyc++)_P_.object[cyc]+=__P.object[cyc];

  if(max==4){
    ___empire(quand);
    for(cyc=0;cyc<10;cyc++)player[qui].object[cyc]    = __E.object[cyc];
    for(cyc=0;cyc<10;cyc++)player[qui].area  [cyc]    = __T.area  [cyc];
    sprintf(ins3,"%s",player[qui].empire);
    ___empire(thisempire);
    sprintf(ins2,"%s%s%s",ins3,__language(String,108),_P_.empire);__log(ins2,99,99);
    sprintf(ins2,"%s%s!!!",__language(String,195),_P_.empire);    __log(ins2,quand,qui);
    return;
    }

  for(cyc=0;cyc<10;cyc++){
    _ins=__T.area[cyc]*.1;
    __T.area[cyc]-=_ins;
    _tot5+=_ins;
    }
  max=_tot5;

    sprintf(ins2,"%s %s %lu%s",_P_.empire,__language(String,193),max,__language(String,194));
    __log(ins2,quand,qui);

__collect(max);

  ___empire(quand);
  for(cyc=0;cyc<10;cyc++)player[qui].object[cyc]    = __E.object[cyc];
  for(cyc=0;cyc<10;cyc++)player[qui].area  [cyc]    = __T.area  [cyc];  sprintf(ins3,"%s",player[qui].empire);
  ___empire(thisempire);
  sprintf(ins2,"%s%s%s",_P_.empire,__language(String,94),ins3);    __log(ins2,99,99);
}












void coup(void){
  int quand,qui;unsigned long _ins=0,_ins2=0,_ins3=0,_tot=0,_tot2=0,_tot3=0,_tot4=0,_tot5=0;char ins2[80],ins3[80];warsub=5;
    __help2("KKKK_COUP");
    quand = __select(177);    if(quand==100)return;	___empire(quand);
    qui   = __select(119);    if(qui==100){___empire(thisempire);return;}

if(player[qui].protection){__matrix("PROTED");return;}

    for(cyc=0;cyc<10;cyc++){ __T.object[cyc]    = player[qui].object[cyc];    _tot+=__T.object[cyc]; }
    for(cyc=0;cyc<10;cyc++){ __T.object[cyc+10] = player[qui].condition[cyc]; }
    for(cyc=0;cyc<20;cyc++)  __E.object[cyc]    = __T.object[cyc];
    for(cyc=0;cyc<20;cyc++)  __T.area[cyc]      = player[qui].area[cyc];
    __totallies(quand);
    for(cyc=0;cyc<10;cyc++)  __E.object[cyc]    += __T.object[cyc];
    emor=player[qui].morale;
    ___empire(thisempire);
    for(cyc=0;cyc<20;cyc++)__P.object[cyc]      = 0;

    od_set_colour(__rc2,0);
_ins2=_P_.object[5]*60;if(_ins2>_P_.object[0])_ins2=_P_.object[0];
__P.object[0]=__outta(String,92,1,_P_.object[0],_ins2        );_P_.object[0]-=__P.object[0];_tot4+=__P.object[0];
__P.object[1]=__outta(String,52,1,_P_.object[1],_P_.object[1]);_P_.object[1]-=__P.object[1];_tot4+=__P.object[1];
__P.object[4]=__outta(String,55,1,_P_.object[4],_P_.object[4]);_P_.object[4]-=__P.object[4];_tot4+=__P.object[4];
    _tot*=.3333;
    _tot4*=1;

  bbsexit=2;

  _ins=__P.object[0];
  _ins2=_P_.object[5];
  if(_ins<_ins2)_ins2=_ins;
  if(_ins>0){
  od_set_colour(random(7)+9,0);
  _ins3=_ins/_ins2;
  _ins=__E.object[3]*.0001*4; // Bom
  if(_ins>_P_.object[5]){_ins=_P_.object[5];od_printf("þ");}
  if(_ins*_ins3>__P.object[0]){_ins=__P.object[0]/_ins3;od_printf("þ");}
  __P.object[0]-=_ins*_ins3;
  _P_.object[5]-=_ins;
  _tot2+=(_ins)+((_ins)*(_ins3));
  od_set_colour(random(7)+9,0);
  od_printf("ù");
  delay(100);
  }

  _ins3=__P.object[4];
  if(_ins3>0){
  od_set_colour(random(7)+9,0);
  _ins=__E.object[3]*.0001*4; // Bom
  if(_ins>_ins3){_ins=_ins3;od_printf("þ");}
  __P.object[4]-=_ins;
  _tot2+=_ins;
  od_set_colour(random(7)+9,0);
  od_printf("ù");
  delay(100);
  }

  price=1;

  do{

    /*----- Offensive Volley -----------------------------------------------*/
//    if(__E.object[0])TTT=0;    else if(__E.object[1])TTT=1;    else if(__E.object[2])TTT=2;    else if(__E.object[4])TTT=4;    else TTT=8;    _ins=__P.object[0]*.0001*__P.area[TTT]; /* Mil */ if(__E.object[8]*5>_ins){_ins3=0;od_set_colour(random(7)+9,0);od_printf("ú");} else if(__E.object[TTT]<_ins){_ins3=__E.object[TTT];od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; __E.object[TTT]-=_ins3; _tot3+=_ins3;
//    if(__E.object[1])TTT=1;    else if(__E.object[0])TTT=0;    else if(__E.object[2])TTT=2;    else if(__E.object[4])TTT=4;    else TTT=8;    _ins=__P.object[1]*.0002*__P.area[TTT]; /* Ter */ if(__E.object[TTT]<_ins){_ins3=__E.object[TTT];od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot3+=_ins3; __E.object[TTT]-=_ins3;
//    if(__E.object[4])TTT=4;    else if(__E.object[2])TTT=2;    else if(__E.object[1])TTT=1;    else if(__E.object[0])TTT=0;    else TTT=8;    _ins=__P.object[4]*.0005*__P.area[TTT]; /* Tan */ if(__E.object[TTT]<_ins){_ins3=__E.object[TTT];od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot3+=_ins3; __E.object[TTT]-=_ins3;
    _tot3=__dotak(0, 10/* 10*/,0,1,2,4,8,_ins,_ins3,_tot3);
    _tot3=__dotak(1, 25/* 10*/,1,0,2,4,8,_ins,_ins3,_tot3);
    _tot3=__dotak(4, 50/* 60*/,4,2,1,0,8,_ins,_ins3,_tot3);
/*
  inflation.area[0]= 10;
  inflation.area[1]= 10;
  inflation.area[2]= 10;
  inflation.area[3]= 01;
  inflation.area[4]= 60;
  inflation.area[5]=100;
  inflation.area[6]= 50;
  inflation.area[8]= 01;
*/
    od_set_colour(random(7)+9,0);
    od_printf("ù");
    delay(20);

    /*----- Defensive Volley -----------------------------------------------*/
    _tot2=__detak(0,   3/*100*/*emor,0,1,3,4,6,_ins,_ins3,_tot2);
    _tot2=__detak(0,  16/*100*/,0,1,3,4,6,_ins,_ins3,_tot2);
    _tot2=__detak(1,   6/* 50*/,1,0,3,4,6,_ins,_ins3,_tot2);
    _tot2=__detak(2,  50/*  1*/,3,4,6,1,0,_ins,_ins3,_tot2);
    _tot2=__detak(3,   8/* 20*/,4,3,6,1,0,_ins,_ins3,_tot2);
    _tot2=__detak(4,   5/*  1*/,4,3,6,1,0,_ins,_ins3,_tot2);
    _tot2=__detak(8,1500/*  1*/,3,4,0,6,1,_ins,_ins3,_tot2);
    _tot2=__detak(6,  50/* 18*/,3,4,0,6,1,_ins,_ins3,_tot2);
/*
    if(__P.object[0])TTT=0;    else if(__P.object[1])TTT=1;    else if(__P.object[3])TTT=3;    else if(__P.object[4])TTT=4;    else TTT=6;    _ins=__E.object[0]*.0003*__P.area[TTT]; /* Mil */ if(__P.object[TTT]<_ins){_ins3=__P.object[TTT]; od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot2+=_ins3; __P.object[TTT]-=_ins3;    _ins2=__E.object[8]*500;if(_ins2>__E.object[0])_ins2=__E.object[0];
    if(__P.object[0])TTT=0;    else if(__P.object[1])TTT=1;    else if(__P.object[3])TTT=3;    else if(__P.object[4])TTT=4;    else TTT=6;    _ins=_ins2        *.0016*__P.area[TTT]; /* Mil */ if(__P.object[TTT]<_ins){_ins3=__P.object[TTT]; od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot2+=_ins3; __P.object[TTT]-=_ins3;
    if(__P.object[1])TTT=1;    else if(__P.object[0])TTT=0;    else if(__P.object[3])TTT=3;    else if(__P.object[4])TTT=4;    else TTT=6;    _ins=__E.object[1]*.0006*__P.area[TTT]; /* Ter */ if(__P.object[TTT]<_ins){_ins3=__P.object[TTT]; od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot2+=_ins3; __P.object[TTT]-=_ins3;
    if(__P.object[3])TTT=3;    else if(__P.object[4])TTT=4;    else if(__P.object[6])TTT=6;    else if(__P.object[1])TTT=1;    else TTT=0;    _ins=__E.object[2]*.0050*__P.area[TTT]; /* Lau */ if(TTT==3)_ins*=5; if(__P.object[TTT]<_ins){_ins3=__P.object[TTT]; od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot2+=_ins3; __P.object[TTT]-=_ins3;
    if(__P.object[4])TTT=4;    else if(__P.object[3])TTT=3;    else if(__P.object[6])TTT=6;    else if(__P.object[1])TTT=1;    else TTT=0;    _ins=__E.object[3]*.0016*__P.area[TTT]; /* Tan */ if(__P.object[TTT]<_ins){_ins3=__P.object[TTT]; od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot2+=_ins3; __P.object[TTT]-=_ins3;
    if(__P.object[4])TTT=4;    else if(__P.object[3])TTT=3;    else if(__P.object[6])TTT=6;    else if(__P.object[1])TTT=1;    else TTT=0;    _ins=__E.object[4]*.0005*__P.area[TTT]; /* Tan */ if(__P.object[TTT]<_ins){_ins3=__P.object[TTT]; od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot2+=_ins3; __P.object[TTT]-=_ins3;
    if(__P.object[3])TTT=3;    else if(__P.object[4])TTT=4;    else if(__P.object[0])TTT=0;    else if(__P.object[6])TTT=6;    else TTT=1;    _ins=__E.object[8]*.1500*__P.area[TTT]; /* Out */ if(__P.object[TTT]<_ins){_ins3=__P.object[TTT]; od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot2+=_ins3; __P.object[TTT]-=_ins3;
    if(__P.object[3])TTT=3;    else if(__P.object[4])TTT=4;    else if(__P.object[0])TTT=0;    else if(__P.object[6])TTT=6;    else TTT=1;    _ins=__E.object[6]*.0010*__P.area[TTT]; /* Out */ if(__P.object[TTT]<_ins){_ins3=__P.object[TTT]; od_set_colour(random(7)+9,0);od_printf("þ");} else _ins3=_ins; _tot2+=_ins3; __P.object[TTT]-=_ins3;
*/
    od_set_colour(random(7)+9,0);
    od_printf("ù");
    delay(20);

    /*----- Counting Losses ------------------------------------------------*/
    _ins=0;for(cyc=0;cyc<10;cyc++)_ins+=__E.object[cyc];_ins-=__E.object[3];_ins-=__E.object[5];_ins-=__E.object[6];_ins-=__E.object[7];_ins-=__E.object[9];
    if(_tot3>_tot || _ins<100)bbsexit=3;
    _ins=0;for(cyc=0;cyc<10;cyc++)_ins+=__P.object[cyc];
    if(_tot2>_tot4 || _ins<100)bbsexit=4;

  }while(bbsexit==2);
  max=bbsexit;
  bbsexit=1;

    for(cyc=0;cyc<10;cyc++){
      if(__E.object[cyc]<__T.object[cyc])__E.object[cyc]=0;
      else
      __E.object[cyc]-=__T.object[cyc];
    }

  od_set_colour(7,0);
  sprintf(ins,"%s",_parsemoney(_tot2));od_printf("\n\r\n\r%s%s%s\n\r",__language(String,180),ins,__language(Word,52));
  sprintf(ins,"%s",_parsemoney(_tot3));od_printf("%s%s%s\n\r\n\r",__language(String,181),ins,__language(Word,52));

  for(cyc=0;cyc<10;cyc++)_P_.object[cyc]+=__P.object[cyc];

  if(max==4){
    ___empire(quand);
    for(cyc=0;cyc<10;cyc++)player[qui].object[cyc]    = __E.object[cyc];
    for(cyc=0;cyc<10;cyc++)player[qui].area  [cyc]    = __T.area  [cyc];
    sprintf(ins3,"%s",player[qui].empire);
    ___empire(thisempire);
    sprintf(ins2,"%s%s%s",ins3,__language(String,120),_P_.empire);__log(ins2,99,99);
    sprintf(ins2,"%s%s!!!",__language(String,121),_P_.empire);    __log(ins2,quand,qui);
    return;
    }

  for(cyc=0;cyc<10;cyc++){
    _ins=__T.area[cyc]*.1;
    __T.area[cyc]-=_ins;
    _tot5+=_ins;
    }
  max=_tot5;

  __T.area[3]+=max;

    sprintf(ins2,"%s %s %lu%s",_P_.empire,__language(String,10),max,__language(String,122));
    __log(ins2,quand,qui);

  ___empire(quand);
  for(cyc=0;cyc<10;cyc++)player[qui].object[cyc]    = __E.object[cyc];
  for(cyc=0;cyc<10;cyc++)player[qui].area  [cyc]    = __T.area  [cyc];  sprintf(ins3,"%s",player[qui].empire);
  ___empire(thisempire);
  sprintf(ins2,"%s%s!!!",__language(String,11),ins3);
  __log(ins2,99,99);
  od_set_colour(15,0);od_printf("\n\r%s\n\n\r",ins2);
}


void nuclear(void){
  int quand,qui;unsigned long _tot=0,_ins=0;char ins2[15];
    __help2("KKKK_NUKE");
    nl();
    quand = __select(177);    if(quand==100)return;	___empire(quand);
    qui   = __select(119);    if(qui==100){___empire(thisempire);return;}

if(player[qui].protection){__matrix("PROTED");return;}

    for(cyc=0;cyc<10;cyc++){ __T.object[cyc]    = player[qui].object[cyc];    }
    for(cyc=0;cyc<10;cyc++){ __T.object[cyc+10] = player[qui].condition[cyc]; }
    for(cyc=0;cyc<20;cyc++)  __E.object[cyc]    = __T.object[cyc];
    for(cyc=0;cyc<10;cyc++){ __T.area[cyc]      = player[qui].area[cyc];      _tot+=__T.object[cyc]; }
    __T.area[19]=player[qui].morale;
    ___empire(thisempire);

    od_set_colour(7,0);
    sprintf(intra,"%s",_parsemoney(_tot*600));
    __matrix("ITCOST");
//    od_printf("%s%s %s ",__language(String,185),ins2,__language(Word,15));

    if(_tot*600>_P_.bullion) {
	__matrix("NOARGENT2");
//	od_printf("\n\r%s\n\n\r",__language(String,84));
//    pause();
    return;}

    if(!yn())return;

    _P_.bullion-=_tot*600;
    price=1;
    _ins=0;

    max=random(10)+6;

  for(cyc=0;cyc<10;cyc++){
    _tot=__T.area[cyc]*.01*max;
    __T.area[cyc]-=_tot;
    _ins+=_tot;
    }
  max=_ins;
  __T.area[10]=_ins;

  od_set_colour(10,0);
  sprintf(ins2,"%s",_parsemoney(max));
  od_printf("%s%s\n\r\n\r",ins2,__language(String,186));

  ___empire(quand);
  for(cyc=0;cyc<10;cyc++)player[qui].area  [cyc]    = __T.area  [cyc];
  ___empire(thisempire);
}









void warroll(int awar, int dwar){
  int quand,qui,cyc8;
  unsigned long pa,pd,ca,cd;
  unsigned long _ins=0,_ins3=0;
  unsigned long _tot2=0,_tot3=0;
  char ins2[120],ins3[50],ins4[50],ins5[15],ins6[15];textcolor(7);
  warsub=6;price=1;

  ___empire(_W_[awar].empire);
  pa=player[_W_[awar].player].condition[7]+player[_W_[awar].player].object[7]*35+10;ca=player[_W_[awar].player].condition[9]+10;
  ___empire(_W_[dwar].empire);
  pd=player[_W_[dwar].player].condition[7]+player[_W_[dwar].player].object[7]*35+10;cd=player[_W_[dwar].player].condition[9]+10;

//od_printf("\n\n\r%%: %lu-%lu & %lu-%lu\n\r",pa,pd,ca,cd);

  _ins3=_W_[dwar].object[0];

//cccprintf("B: %7lu",_ins3);

  if(_ins3>0){
  _ins=_W_[awar].object[3]*.0001*4; // Bom
  if(_ins>_ins3)_ins=_ins3;
  _W_[dwar].object[0]-=_ins;
  _tot2+=_ins;
  }

//cccprintf(" (-)%7lu (=)%7lu   A[D]: %7lu <%7lu>\n\r",_ins,_W_[awar].object[0],_W_[awar].object[3],_tot2);

  _ins3=_W_[dwar].object[4];

//cccprintf("B: %7lu",_ins3);

  if(_ins3>0){
  _ins=_W_[awar].object[3]*.0001*4; // Bom
  if(_ins>_ins3)_ins=_ins3;
  _W_[dwar].object[4]-=_ins;
  _tot2+=_ins;
  }

//cccprintf(" (-)%7lu (=)%7lu   A[D]: %7lu <%7lu>\n\r",_ins,_W_[awar].object[4],_W_[dwar].object[3],_tot2);

for(cyc8=0;cyc8<10;cyc8++) __E.object[cyc8]=_W_[awar].object[cyc8];
for(cyc8=0;cyc8<10;cyc8++) __P.object[cyc8]=_W_[dwar].object[cyc8];

    /*----- Offensive Volley -----------------------------------------------*/
    _tot3=__dotak(0,  1/*100*/*pa,0,1,4,2,3,_ins,_ins3,_tot3);
    _tot3=__dotak(1,  2/* 50*/*ca,1,0,4,2,3,_ins,_ins3,_tot3);
    _tot3=__dotak(2,100/*  6*/*ca,4,2,1,0,3,_ins,_ins3,_tot3);
    _tot3=__dotak(3,100/*  3*/*pa,3,2,4,1,0,_ins,_ins3,_tot3);
    _tot3=__dotak(4, 10/* 12*/*pa,2,4,1,0,3,_ins,_ins3,_tot3);
    _tot3=__dotak(6,  5/* 25*/*ca,1,4,2,3,0,_ins,_ins3,_tot3);
    /*----- Defensive Volley -----------------------------------------------*/
    _tot2=__detak(0,  1/*100*/*pd,0,1,4,2,3,_ins,_ins3,_tot2);
    _tot2=__detak(1,  2/* 50*/*cd,1,0,4,2,3,_ins,_ins3,_tot2);
//cccprintf("??\n\r");
    _tot2=__detak(2,300/*  6*/*cd,3,2,4,1,0,_ins,_ins3,_tot2);
    _tot2=__detak(3, 50/*  3*/*pd,2,4,1,0,3,_ins,_ins3,_tot2);
    _tot2=__detak(4,  8/*128*/*pd,4,2,1,0,3,_ins,_ins3,_tot2);
    _tot2=__detak(6,  4/* 25*/*cd,1,4,2,3,0,_ins,_ins3,_tot2);
    max=random(4);

    ___empire(_W_[awar].empire);sprintf(ins3,"%s",player[_W_[awar].player].empire);player[_W_[awar].player].condition[7]*=.85;player[_W_[awar].player].condition[9]*=.90;
    ___empire(_W_[dwar].empire);sprintf(ins4,"%s",player[_W_[dwar].player].empire);player[_W_[dwar].player].condition[7]*=.95;player[_W_[dwar].player].condition[9]*=.90;

    sprintf(ins2,"@15!%s",__language(String,77));                     __log(ins2,99,99);
    sprintf(ins2,"&&%s%s%s",ins3,__language(String,146+max),ins4);    __log(ins2,99,99);

//cccprintf("1: A:%20s D:%20s\n\r",ins3,ins4);
//cccprintf("2: A:%20lu D:%20lu\n\r",_tot2,_tot3);

for(cyc8=0;cyc8<10;cyc8++) _W_[awar].object[cyc8]=__E.object[cyc8];
for(cyc8=0;cyc8<10;cyc8++) _W_[dwar].object[cyc8]=__P.object[cyc8];

    sprintf(ins5,"%s",_parsemoney(_tot2));
    sprintf(ins6,"%s",_parsemoney(_tot3));
    sprintf(ins2,"!!%s%s%s. %s%s%s. ",ins3,__language(Word,51),ins5,ins4,__language(Word,51),ins6);
    __log(ins2,99,99);
    savegame();
}

void homeroll(int awar, int dwar){/*
  int quand,qui,cyc8;warsub=6;
  unsigned long _ins=0,_ins3=0;
  unsigned long _tot2=0,_tot3=0;
  char ins2[120],ins3[50],ins4[50],ins5[15],ins6[15];

  for(cyc8=0;cyc8<20;cyc8++)
  inflation.area[cyc8]=0;
  inflation.area[0]=100;
  inflation.area[1]= 50;
  inflation.area[2]= 06;
  inflation.area[3]= 03;
  inflation.area[4]= 12;
  inflation.area[6]= 25;

  ___empire(_W_[dwar].empire);

  for(cyc8=0;cyc8<10;cyc8++)  _W_[dwar].object[cyc8]=player[_W_[dwar].player].object[cyc8];


  _ins3=_W_[awar].object[0];
  if(_ins3>0){
  _ins=_W_[dwar].object[3]*.0001*4; // Bom
  if(_ins>_ins3)_ins=_ins3;
  _W_[awar].object[0]-=_ins;
  _tot2+=_ins;
  }

  _ins3=_W_[awar].object[4];
  if(_ins3>0){
  _ins=_W_[dwar].object[3]*.0001*4; // Bom
  if(_ins>_ins3)_ins=_ins3;
  _W_[awar].object[4]-=_ins;
  _tot2+=_ins;
  }

    /*----- Offensive Volley -----------------------------------------------*/
    _tot3=__dotak(0,  1/*100*/,0,1,4,2,3,_ins,_ins3,_tot3);
    _tot3=__dotak(1,  2/* 50*/,1,0,4,2,3,_ins,_ins3,_tot3);
    _tot3=__dotak(2,100/*  6*/,4,2,1,0,3,_ins,_ins3,_tot3);
    _tot3=__dotak(3,100/*  3*/,3,2,4,1,0,_ins,_ins3,_tot3);
    _tot3=__dotak(4, 10/* 12*/,2,4,1,0,3,_ins,_ins3,_tot3);
    _tot3=__dotak(6,  5/* 25*/,1,4,2,3,0,_ins,_ins3,_tot3);
    /*----- Defensive Volley -----------------------------------------------*/
    _tot2=__detak(0,  3/*100*/,0,1,4,2,3,_ins,_ins3,_tot2);
    _tot2=__detak(1,  6/* 50*/,1,0,4,2,3,_ins,_ins3,_tot2);
    _tot2=__detak(2,900/*  6*/,3,2,4,1,0,_ins,_ins3,_tot2);
    _tot2=__detak(3,300/*  3*/,2,4,1,0,3,_ins,_ins3,_tot2);
    _tot2=__detak(4, 30/* 12*/,4,2,1,0,3,_ins,_ins3,_tot2);
    _tot2=__detak(6, 15/* 25*/,1,4,2,3,0,_ins,_ins3,_tot2);

  ___empire(_W_[awar].empire);sprintf(ins3,"%s",player[_W_[awar].player].empire);  player[_W_[awar].player].condition[7]*=.85;
  ___empire(_W_[dwar].empire);sprintf(ins4,"%s",player[_W_[dwar].player].empire);  player[_W_[dwar].player].condition[7]*=.95;

  sprintf(ins2,"@15!%s",__language(String,77));
  __log(ins2,99,99);

  sprintf(ins2,"&&%s%s%s",ins3,__language(String,239),ins4);
  __log(ins2,99,99); //FLAG

  sprintf(ins5,"%s",_parsemoney(_tot2));
  sprintf(ins6,"%s",_parsemoney(_tot2));
  sprintf(ins2,"!!%s%s%s. %s%s%s. ",ins3,__language(Word,51),ins5,ins4,__language(Word,51),ins6);
  __log(ins2,99,99);

  ___empire(_W_[dwar].empire);
  for(cyc8=0;cyc8<10;cyc8++){
  player[_W_[dwar].player].object[cyc8]=_W_[dwar].object[cyc8];
  _W_[dwar].object[cyc8]=0;
  }
*/}










