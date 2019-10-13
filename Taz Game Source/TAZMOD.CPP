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









