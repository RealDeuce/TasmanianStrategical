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
#include<process.h>




void newplayer(int mod){
  int open[10];char yea=0;FILE *stream;

  if(!mod)od_clr_scr();

  cyc5=0;cyc=0;
  thisuserno=26;

for(cyc4=0;cyc4<10;cyc4++){
  ___empire(cyc4);
  open[cyc4]=0;
  cyc=0;
  cyc5=0;
  do{
    if(player[cyc].statis==0)open[cyc4]=1;
    if(strnicmp(player[cyc].name,UserName,strlen(UserName))==0){cyc5=1;open[cyc4]=2;yea=1;}
    cyc++;
  }while(cyc5==0 && cyc<26);
}

thisempire=0;
___empire(0);

if(!yea)selectempire(open);
if(yea)for(cyc4=0;cyc4<10;cyc4++)if(open[cyc4]==2)___empire(cyc4);

thisempire=__empire;

cyc=0;cyc5=0;
  do{
    if(player[cyc].statis==0){thisuserno=cyc;cyc5=1;}
    else
    cyc++;
  }while(cyc5==0 && cyc<26);

cyc=0;cyc5=0;
    do{
    if(strnicmp(player[cyc].name,UserName,strlen(UserName))==0){thisuserno=cyc;cyc5=1;}
    else
    cyc++;
  }while(cyc5==0 && cyc<26);

  if(thisuserno==26){__matrix("PLEIN");od_exit(0,FALSE);}

  if(_P_.statis==2){
    for(cyc=0;cyc<10;cyc++)return;
    _P_.statis=1;savegame();
  }

  if(_P_.statis==1){
    __matrix("MORT");
    od_exit(0,FALSE);
  }

__matrix("BEINVENU");

    init1:;
//      od_set_colour(L_YELLOW,D_BLACK);od_printf("%s",UserName);
//      od_set_colour(D_GREY,D_BLACK);od_printf(", %s",__language(String,3));
//      od_set_colour(L_CYAN,D_BLACK);
      __matrix("CHRISTIAN");
      od_input_str(ins,25,32,167);
      sprintf(_P_.empire,"%s",ins);adjust(thisuserno);
	if(strlen(ins)<1){
	  od_set_colour(L_RED,D_BLACK);
	  od_printf("%s. . .\n\r",__language(Word,9));
	  pause();
	  od_exit(0,FALSE);
	}
	for(cyc=0;cyc<26;cyc++){
	  if(strcmp(player[cyc].empire,_P_.empire)==0 && cyc!=thisuserno){
	    __matrix("NONLIBRE");
//	    od_set_colour(L_CYAN,D_BLACK);
//	    od_printf("%s\n\n\r",__language(String,7));
	    goto init1;
	  }
	}
      sprintf(intra,"%s ",_P_.empire);
      __matrix("APPELLE");
//      od_set_colour(D_CYAN,D_BLACK);
//      od_printf("\n\r%s",__language(String,10));
//      od_set_colour(L_YELLOW,D_BLACK);
//      od_printf("%s ",_P_.empire);
      checkhot();
	if(!ny())goto init1;

sprintf(_P_.name,"%s",UserName);
_P_.turns           =config.parameter[1];
_P_.protection      =/*config.parameter[6];*/0;
//_P_.inactive        =0;
_P_.taxrate         =(random(7))+7;
_P_.draftrate       =(random(7))+7;
_P_.food            =(random(11111))+40000;
_P_.bullion         =(random(11111))+190000;
_P_.bank            =(random(11111));
_P_.investment      =(random(11111));
for(cyc=0;cyc<10;cyc++)_P_.object[cyc]=0;
for(cyc=0;cyc<10;cyc++)_P_.condition[cyc]=100;
for(cyc=0;cyc<10;cyc++)_P_.relation[cyc]=0;
_P_.population      =(random(91))+10;
_P_.morale          =(random(11))+90;
_P_.approval        =(random(11))+90;
_P_.i_approval      =(random(11))+90;
_P_.i_enforcement   =(random(11))+90;
_P_.i_punishment    =(random(11))+90;
_P_.i_security      =(random(11))+90;
_P_.i_crime         =(random(11))+90;
for(cyc=0;cyc<10;cyc++)_P_.area[cyc]=0;
for(cyc=0;cyc<10;cyc++)_P_.efficiency[cyc]=100;
_P_.object[7]=1;
_P_.condition[9]=0;
_P_.area[0]=(random(6))+10;
_P_.object[0]=_P_.population/5;
_P_.object[1]=(random(20))+50;
_P_.statis=2;
_P_.warzone=100;
for(cyc=0;cyc<10;cyc++)_P_.industry[cyc]=0;_P_.industry[7]=100;
for(cyc=0;cyc<10;cyc++)_P_.military[cyc]=0;_P_.military[4]=100;
for(cyc=0;cyc<10;cyc++)_P_.fortress[cyc]=0;_P_.fortress[2]=100;
_P_.gouvernment=100;
_P_.biosphere=100;
_I_=0;
savegame();
__NEWFILE__(thisempire,thisuserno);
stream=fopen(ins,"w+");
fclose(stream);
}





























