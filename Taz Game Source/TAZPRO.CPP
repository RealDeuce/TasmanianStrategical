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





unsigned long __outqty(int _y,int _i,unsigned long _z,unsigned long _t,unsigned long _l,unsigned long _d,int autt,int autre){
unsigned long _r,_j;
char ins2[80];
_j=random(11)+95;
_r=_z*_d*.00000007*((_j*_l*_t*.01)*((_P_.approval+_P_.i_approval)*.45+10));
_r*=1.5;
if(!_r)return(0);
sprintf(ins2,"%s",_parsemoney(_r));od_set_colour(7,0);
if(_i==999)               	       od_printf("%s ",ins);
else if(strlen(__language(_y,_i))<13)  od_printf("  %-12.12s ",__language(_y,_i));
else if(_i==123 || _i==124)            od_printf("%s",__language(_y,_i));
else                                   od_printf("%s ",__language(_y,_i));
od_set_colour(11,0);
if(!autre)
  od_printf("%s\n\r",ins2);
else{
  od_printf("%s ",ins2);  od_set_colour(7,0);  od_printf("%s\n\r",__language(autt,autre));}
return(_r);
}

void production(void){
/*Initiate*/ unsigned long _toker=0,u1,u2,u3,rm;char ins2[80];int hit=0,imod=_P_.approval+_P_.i_approval;imod=imod/2;
/*Initiate*/ od_printf("\n\n\n\r");
/*Initiate*/ od_set_colour(12,0);for(cyc=0;cyc<70;cyc++)od_printf("Ä");nl();od_set_colour(7,0);

sprintf(ins,"%ss %s",__language(String,65),__language(String,100));
_toker+=__outqty(999,999,100-_P_.biosphere,_P_.area[1],random(1111)+6000,1000,Word,15);
///*Biospher*/ u1=_P_.area[1]; u2=random(200)+1000; u3=random(1111)+5000; rm=u2*u1;_toke=rm+u3*u1;_toke*=(100-_P_.biosphere)*.01;
///*Biospher*/ SiT od_printf("%ss %s ",__language(String,65),__language(String,100));
///*Biospher*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Biospher*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

sprintf(ins,"%s %s %s",__language(String,66),__language(String,102),__language(String,100));
_toker+=__outqty(999,999,100,_P_.area[2],random(5111)+12000,1000,Word,15);
///*Commerci*/ u1=_P_.area[2];u2=random(500)+2000; u3=random(5111)+10000; rm=u2*u1;_toke=rm+u3*u1;
///*Commerci*/ SiT od_printf("%s %s %s ",__language(String,66),__language(String,102),__language(String,100));
///*Commerci*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Commerci*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

_toker+=__outqty(String,105,_P_.industry[9],_P_.area[6],random(111)+500,1000,Word,15);
///*Factorys*/ u1=_P_.area[6]; u2=random(20)+10; u3=random(111)+500; rm=u2*u1;_toke=rm+u3*u1;_toke*=_P_.industry[9]*.01;
///*Factorys*/ SiT od_printf("%s ",__language(String,105));
///*Factorys*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Factorys*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

_toker+=__outqty(String,123,_P_.military[9],_P_.area[7],random(1111)+6000,1000,Word,15);
///*Militair*/ u1=_P_.area[7]; u2=random(200)+1000; u3=random(1111)+5000; rm=u2*u1;_toke=rm+u3*u1;_toke*=_P_.military[9]*.01;
///*Militair*/ SiT od_printf("%s",__language(String,123));
///*Militair*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Militair*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

_toker+=__outqty(String,124,_P_.fortress[9],_P_.area[4],random (11111)+500000,1000,Word,15);
///*Fortress*/ u1=_P_.area[4]; u2=random(20000)+100000; u3=random(111111)+400000; rm=u2*u1;_toke=rm+u3*u1;_toke*=_P_.fortress[9]*.01;
///*Fortress*/ SiT od_printf("%s",__language(String,124));
///*Fortress*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Fortress*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

sprintf(ins,"%s %s",__language(String,69),__language(String,100));
_toker+=__outqty(999,999,100-_P_.gouvernment,_P_.area[1],random(1111)+5000,1000,Word,15);
///*Gouvrnmt*/ u1=_P_.area[1]; u2=random(200)+1000; u3=random(1111)+5000; rm=u2*u1;_toke=rm+u3*u1;_toke*=(100-_P_.gouvernment)*.01;
///*Gouvrnmt*/ SiT od_printf("%s %s ",__language(String,69),__language(String,100));
///*Gouvrnmt*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Gouvrnmt*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

_toker+=__outqty(String,107,100,_P_.population,_P_.taxrate,18000,Word,15);
///*Populati*/ _toke=_P_.population*_P_.taxrate*100;
///*Populati*/  SiT od_printf("%s ",__language(String,107));
///*Populati*/  od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Populati*/  od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

sprintf(ins,"%s %s %s",__language(String,64),__language(String,103),__language(String,99));
_toker+=__outqty(999,999,100,_P_.area[0],random(111)+300,3500,Word,15);
///*Wastelan*/  u1=_P_.area[0]; u2=random(100)+100; u3=random(100)+300; rm=u2*u1;_toke=rm+u3*u1;
///*Wastelan*/  SiT od_printf("%s %s %s ",__language(String,64),__language(String,103),__language(String,99));sprintf(ins2,"%s",_parsemoney(_toke));
///*Wastelan*/  od_set_colour(11,0);od_printf("%s ",ins2);
///*Wastelan*/  od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

/*TOTALS  */ if(_toker){__matrix("TOTPROD");
/*TOTALS  */ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toker));od_printf("%s ",ins2);
/*TOTALS  */ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));}
/*TOTALS  */ _P_.bullion+=_toker;

sprintf(ins,"%ss %s",__language(String,65),__language(String,101));
_P_.food+=__outqty(999,999,_P_.biosphere,_P_.area[1],random(1111)+8000,3500,Word,42);
///*BiosFood*/ u1=_P_.area[1]; u2=random(1111)+8000; u3=random(1111)+8000; _toke=(u2+u3)*u1; _toke*=(imod/90+.10);_toke*=_P_.biosphere*.01;
///*BiosFood*/ SiT od_printf("%ss %s ",__language(String,65),__language(String,101));
///*BiosFood*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*BiosFood*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,42));_P_.food+=_toke;}

_P_.object[0]+=__outqty(String,104,_P_.gouvernment,_P_.area[4],random(111)+700,1000,Word,41);
///*GouvMili*/ u1=_P_.area[4]; u2=random(11)+100; u3=random(100)+700; _toke=u2*u1+u3*u1; _toke=(_toke*(imod/90+.10));_toke*=_P_.gouvernment*.01;
///*GouvMili*/ SiT od_printf("%s ",__language(String,104));
///*GouvMili*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*GouvMili*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,41));_P_.object[0]+=_toke;}

/*Initiate*/ pause();
/*Initiate*/ od_set_colour(12,0);
/*Initiate*/ for(cyc=0;cyc<70;cyc++)
/*Initiate*/ od_printf("Ä");
/*Initiate*/ nl();od_set_colour(7,0);

/*FACTORIE*/ if(_P_.industry[9]<100 && _P_.area[6]){od_printf("%s\n\r",__language(String,126));hit=1;
_P_.object[2]+=__outqty(String,53,_P_.industry[2],_P_.area[6],random(111)+900, 250,0,0);
_P_.object[3]+=__outqty(String,54,_P_.industry[3],_P_.area[6],random(111)+900, 167,0,0);
_P_.object[4]+=__outqty(String,55,_P_.industry[4],_P_.area[6],random(111)+900, 200,0,0);
_P_.object[5]+=__outqty(String,56,_P_.industry[5],_P_.area[6],random(111)+900,1000,0,0);
_P_.object[7]+=__outqty(String,95,_P_.industry[7],_P_.area[6],random(111)+900,3000,0,0);
/*FACTORIE*/ }

/*MILITAIR*/ if(_P_.military[9]<100 && _P_.area[7]){od_printf("%s\n\r",__language(String,127));hit=1;
_P_.object[0]+=__outqty(String,92,_P_.military[0],_P_.area[7],random(111)+900, 500,0,0);
_P_.object[3]+=__outqty(String,54,_P_.military[3],_P_.area[7],random(111)+900, 835,0,0);
_P_.object[4]+=__outqty(String,55,_P_.military[4],_P_.area[7],random(111)+900,1000,0,0);
_P_.object[5]+=__outqty(String,56,_P_.military[5],_P_.area[7],random(111)+900,5000,0,0);
/*MILITAIR*/ }

/*FORTRESS*/ if(_P_.fortress[9]<100 && _P_.area[4]){od_printf("%s\n\r",__language(String,128));hit=1;
_P_.object[0]+=__outqty(String,92,_P_.fortress[0],_P_.area[4],random(111)+900,1000*15,0,0);
_P_.object[1]+=__outqty(String,52,_P_.fortress[1],_P_.area[4],random(111)+900, 500*15,0,0);
_P_.object[2]+=__outqty(String,53,_P_.fortress[2],_P_.area[4],random(111)+900, 250*15,0,0);
_P_.object[4]+=__outqty(String,55,_P_.fortress[4],_P_.area[4],random(111)+900, 200*15,0,0);
_P_.object[6]+=__outqty(String,57,_P_.fortress[6],_P_.area[4],random(111)+900,  10*15,0,0);
/*FORTRESS*/ }
/*Terminat*/ if(hit)pause();
}

