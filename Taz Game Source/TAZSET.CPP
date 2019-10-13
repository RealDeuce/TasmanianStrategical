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
#include<dir.h>
#include<stream.h>
char _fname[15];


/* Setup 1.00    */ void __errormessage(int x, char y[15]){
/* Setup 1.00    */   if(x==1){
/* Setup 1.00    */     system("TYPE TAZER1.NFO");
/* Setup 1.00    */     //cprintf("\n\rJeu n'‚t‚ pas configured. Ecrivez '%s SETUP'.\n\r",filename);
/* Setup 1.00    */     //cprintf("Game has not been configured. Run '%s SETUP'.\n\r",filename);
/* Setup 1.00    */     exit(0);
/* Setup 1.00    */   }
/* Setup 1.00    */   if(x==5){
/* Setup 1.00    */     system("TYPE TAZER2.NFO");
/* Setup 1.00    */     //cprintf("\n\rJeu n'‚t‚ pas reset. Ecrivez '%s RESET'.\n\r",filename);
/* Setup 1.00    */     //cprintf("Game has not been reset. Run '%s RESET'.\n\r",filename);
/* Setup 1.00    */     exit(0);
/* Setup 1.00    */   }
/* Setup 1.00    */   printf("<<<Error>>> #%d with/avec file/dossier <<<%s>>>",x,y);
/* Setup 1.00    */   exit(0);
/* Setup 1.00    */ }




void __DAY__main(void){
  char ins2[80],ins3[80],cyc7,cyc9,cyc21,home;
  unsigned long tot,numb;
  __loadconfiguration();
  for(cyc5=0;cyc5<10;cyc5++){
    __empire=cyc5;
      loadgame();
	for(cyc=0;cyc<26;cyc++){
	  player[cyc].turns=config.parameter[1];
	  if(player[cyc].statis==1){
	  player[cyc].statis=0;
	  for(cyc3=0;cyc3<50;cyc3++)
	  if(_W_[cyc3].player==cyc && _W_[cyc3].empire==__empire)_W_[cyc3].statis=0;
	  player[cyc].name[0]=0;
	  player[cyc].empire[0]=0;
	  }
	  if(player[cyc].investment)player[cyc].investment+=player[cyc].investment*.15;
	  if(player[cyc].bank)player[cyc].bank+=player[cyc].bank*.05;
	  if(player[cyc].investment>4000000000)player[cyc].investment=4000000000;
	  if(player[cyc].bank>4000000000)player[cyc].bank=4000000000;
	  if(player[cyc].implants)player[cyc].implants*=4;
	    for(cyc2=0;cyc2<50;cyc2++){
	      if(_W_[cyc2].empire==__empire && _W_[cyc2].player==cyc){
		if(_W_[cyc2].statis==4){
		  _W_[cyc2].statis=2;
		}
		if(_W_[cyc2].statis==5){
		  _W_[cyc2].statis=4;
		}
		if(_W_[cyc2].statis==6){
		  _W_[cyc2].object[0]+=player[cyc].object[0];player[cyc].object[0]=0;
		  _W_[cyc2].object[1]+=player[cyc].object[1];player[cyc].object[1]=0;
		  _W_[cyc2].statis=5;
		  sprintf(ins2,"@15@%s",__language(String,214));
		  __log(ins2,__empire,cyc);
		}
		if(_W_[cyc2].statis==7){
		  _W_[cyc2].statis=6;
		}
	      }
	    }
	}
      savegame();
  }
for(cyc=0;cyc<50;cyc++)ins2[cyc]=0;cyc2=0;cyc3=0;cyc4=0;cyc5=0;
for(cyc=0;cyc<50;cyc++){
  if(_W_[cyc].statis<3 && _W_[cyc].statis>1){ins2[cyc2]=cyc;cyc2++;}
  if(_W_[cyc].statis==1)cyc3++;
}numb=cyc2;
if(cyc2>1)for(cyc=0;cyc<cyc2+3;cyc++){
max=0;price=0;
cyc21=cyc2;cyc5=random(cyc21);
max=ins2[cyc5];
cyc21=cyc2;cyc5=random(cyc21);
cyc9=ins2[cyc5];
cyc4=random(3);home=0;
if(cyc4==1 && cyc3){
home=1;
cyc21=cyc3;cyc4=random((cyc21));cyc7=0;
for(cyc5=0;cyc5<50;cyc5++){
  if(_W_[cyc5].statis==1){
  if(cyc7==cyc4)cyc9=cyc5;
  cyc7++;
  if(cyc7==cyc4)cyc9=cyc5;
  }
}
}
price=cyc9;
if(max!=price){
if(!home)warroll(max,price);
if(home)homeroll(max,price);
}
else
if(cyc>0)cyc--;
}
if(cyc2==1){cyc2=0;
for(cyc=0;cyc<50;cyc++)
  if(_W_[cyc].statis>1){cyc2++;cyc3=cyc;}
if(cyc2==1){cyc=cyc3;
  ___empire(_W_[cyc].empire);
  sprintf(ins3,"@14?%s%s",player[_W_[cyc].player].empire,__language(String,39));
  for(cyc4=0;cyc4<10;cyc4++)for(cyc5=0;cyc5<10;cyc5++)__log(ins3,cyc4,cyc5);__log(ins3,99,99);
  sprintf(ins3,"@12@%s",__language(String,40));
  for(cyc4=0;cyc4<10;cyc4++)for(cyc5=0;cyc5<10;cyc5++)__log(ins3,cyc4,cyc5);__log(ins3,99,99);
  player[_W_[cyc].player].warzone=100;
  _W_[cyc].statis=0;
  for(cyc2=0;cyc2<10;cyc2++)
  player[_W_[cyc].player].object[cyc2]=_W_[cyc].object[cyc2];

}
}
for(cyc=0;cyc<50;cyc++)
  if(_W_[cyc].statis==1)
    {
      tot=0;
      ___empire(_W_[cyc].empire);
	  player[_W_[cyc].player].warzone=100;
	  player[_W_[cyc].player].approval*=.5;
	  player[_W_[cyc].player].morale*=.5;
	  _W_[cyc].statis=0;
	for(cyc3=0;cyc3<10;cyc3++)
	tot+=player[_W_[cyc].player].object[cyc3];
	tot-=player[_W_[cyc].player].object[7];
	if(tot==0){
	  player[_W_[cyc].player].statis=1;
	  _W_[cyc].statis=1;
	  sprintf(ins3,"@15?%s%s!!!!!",__language(String,29),player[_W_[cyc].player].empire);
	  for(cyc4=0;cyc4<10;cyc4++)for(cyc5=0;cyc5<10;cyc5++)__log(ins3,cyc4,cyc5);
	  __log(ins3,99,99);
	  sprintf(ins3,"@15@%s%lu%s",__language(String,156),tot*3*numb,__language(String,159));
	  for(cyc4=0;cyc4<10;cyc4++)for(cyc5=0;cyc5<10;cyc5++)__log(ins3,cyc4,cyc5);
	  __log(ins3,99,99);
	  tot=0;
	  for(cyc3=0;cyc3<10;cyc3++) tot+=player[_W_[cyc].player].area[cyc3];
	  tot*=.33334;
	  if(numb<3)tot*=3;
	    for(cyc5=0;cyc5<50;cyc5++){
	    if(_W_[cyc5].statis>1 && _W_[cyc5].statis<3){
	    ___empire(_W_[cyc5].empire);
	    player[_W_[cyc5].player].area[0]+=tot*.5;
	    player[_W_[cyc5].player].area[3]+=tot*.5;
	    }
	    }
	  for(cyc3=0;cyc3<10;cyc3++) player[_W_[cyc].player].area[cyc3]=0;
	}
    }
savegame();
}


























