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


/* Setup 1.00    */ void __errormessage(int x, char y[15]){__mess(5);
/* Setup 1.00    */   if(x==1){
/* Setup 1.00    */     system("TYPE TAZER1.NFO");
/* Setup 1.00    */     //cprintf("\n\rJeu n'‚t‚ pas configured. Ecrivez '%s SETUP'.\n\r",filename);
/* Setup 1.00    */     //cprintf("Game has not been configured. Run '%s SETUP'.\n\r",filename);
/* Setup 1.00    */     od_exit(0,FALSE);
/* Setup 1.00    */   }
/* Setup 1.00    */   if(x==5){
/* Setup 1.00    */     system("TYPE TAZER2.NFO");
/* Setup 1.00    */     //cprintf("\n\rJeu n'‚t‚ pas reset. Ecrivez '%s RESET'.\n\r",filename);
/* Setup 1.00    */     //cprintf("Game has not been reset. Run '%s RESET'.\n\r",filename);
/* Setup 1.00    */     od_exit(0,FALSE);
/* Setup 1.00    */   }
/* Setup 1.00    */   printf("<<<Error>>> #%d with/avec file/dossier <<<%s>>>",x,y);
/* Setup 1.00    */   od_exit(0,FALSE);
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
	  if(player[cyc].investment)player[cyc].investment+=player[cyc].investment*.05;
	  if(player[cyc].bank)player[cyc].bank+=player[cyc].bank*.10;
	  if(player[cyc].investment>2500000000)player[cyc].investment=2500000000;
	  if(player[cyc].bank>2500000000)player[cyc].bank=2500000000;
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
		  _W_[cyc2].object[0]+=player[_W_[cyc2].player].object[0];player[_W_[cyc2].player].object[0]=0;
		  _W_[cyc2].object[1]+=player[_W_[cyc2].player].object[1];player[_W_[cyc2].player].object[1]=0;
		  _W_[cyc2].statis=5;
		  sprintf(ins2,"@15@%s",__language(String,26));
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
  // Statis=0 - Unused
  // Statis=1 - Attacking Homeland \
  // Statis=2 - Neutral Warzone    |---- Warzone
  // Statis=3 - Defending Homeland /
  // Statis=4 - Deploying (24hrs)
  // Statis=5 - Deploying (48hrs)
  // Statis=6 - Deploying (72hrs) *-* Autodeployment
  // Statis=7 - Deploying (96hrs) *-* Forced in
for(cyc=0;cyc<50;cyc++)
  if(_W_[cyc].statis==1)_W_[cyc].statis=2;
for(cyc=0;cyc<50;cyc++)
  if(_W_[cyc].statis==2)
    {
      ___empire(_W_[cyc].empire);
      player[_W_[cyc].player].condition[7]=100;
    }
for(cyc=0;cyc<50;cyc++)ins2[cyc]=0;cyc2=0;cyc3=0;cyc4=0;cyc5=0;
for(cyc=0;cyc<50;cyc++)
 {
  if(_W_[cyc].statis==2)
  {
    ins2[cyc2]=cyc;
    cyc2++;
  }
  if(_W_[cyc].statis==3)
    cyc3++;
 }
numb=cyc2;
  if(cyc2>1)
    for(cyc=0;cyc<cyc2+3;cyc++){
      max=0;price=0;
      cyc21=cyc2;cyc5=random(cyc21);
      max=ins2[cyc5];
      cyc21=cyc2;cyc5=random(cyc21);
      cyc9=ins2[cyc5];
      cyc4=random(3);home=0;
	if(cyc4==1 && cyc3)
	{
	  home=1;
	  cyc21=cyc3;cyc4=random((cyc21));cyc7=0;
	    for(cyc5=0;cyc5<50;cyc5++)
	      {
		if(_W_[cyc5].statis==3){
		  if(cyc7==cyc4)cyc9=cyc5;
		    cyc7++;
		  if(cyc7==cyc4)cyc9=cyc5;
		}
	      }
	}
      price=cyc9;
	if(max!=price)
	  {
	    /*if(!home)*/  warroll(max,price);
//	    /*if(home) */ homeroll(max,price);
	  }
	else
	  if(cyc>0)cyc--;
    }
if(cyc2==1)
  {
    cyc2=0;
      for(cyc=0;cyc<50;cyc++)
	if(_W_[cyc].statis>0)
	  {
	    cyc2++;
	    cyc3=cyc;
	  }
      if(cyc2==1)
      {
	cyc=cyc3;
	___empire(_W_[cyc].empire);
	sprintf(ins3,"@14?%s%s",player[_W_[cyc].player].empire,__language(String,8));
	  for(cyc4=0;cyc4<10;cyc4++)
	    for(cyc5=0;cyc5<26;cyc5++)
	      __log(ins3,cyc4,cyc5);
	      __log(ins3,99,99);
	sprintf(ins3,"@12@%s",__language(String,9));
	  for(cyc4=0;cyc4<10;cyc4++)
	    for(cyc5=0;cyc5<26;cyc5++)
	      __log(ins3,cyc4,cyc5);
	      __log(ins3,99,99);
	player[_W_[cyc].player].warzone=100;
	_W_[cyc].statis=0;
	  for(cyc2=0;cyc2<10;cyc2++)
	    player[_W_[cyc].player].object[cyc2]+=_W_[cyc].object[cyc2];
      }
}
for(cyc=0;cyc<50;cyc++)
  if(_W_[cyc].statis==3)
    {
      tot=0;
      ___empire(_W_[cyc].empire);
	  player[_W_[cyc].player].warzone=100;
	  player[_W_[cyc].player].approval*=.335;
	  player[_W_[cyc].player].morale*=.335;
	  _W_[cyc].statis=0;
	for(cyc3=0;cyc3<10;cyc3++)
	tot+=_W_[cyc].object[cyc3];
	tot-=_W_[cyc].object[7];
	for(cyc3=0;cyc3<10;cyc3++)
	player[_W_[cyc].player].object[cyc3]+=_W_[cyc].object[cyc3];
	if(tot==0){
		  tot=0;
		  for(cyc3=0;cyc3<10;cyc3++)
		    tot+=player[_W_[cyc].player].area[cyc3]*.335;
		  if(tot<3)tot*=3;numb=0;
		    for(cyc5=0;cyc5<50;cyc5++){
		      if(_W_[cyc5].statis==2 || _W_[cyc5].statis==1){
			___empire(_W_[cyc5].empire);numb++;
			player[_W_[cyc5].player].area[0]+=tot*.55;
			player[_W_[cyc5].player].area[3]+=tot*.55;
		      }
		    }
		  for(cyc3=0;cyc3<10;cyc3++) player[_W_[cyc].player].area[cyc3]=0;
	  player[_W_[cyc].player].statis=1;
	  _W_[cyc].statis=0;
	  sprintf(ins3,"@15?%s%s!!!!!",__language(String,3),player[_W_[cyc].player].empire);
	    for(cyc4=0;cyc4<10;cyc4++)
	      for(cyc5=0;cyc5<26;cyc5++)
		__log(ins3,cyc4,cyc5);
		__log(ins3,99,99);
	  sprintf(ins3,"@15@%s%lu%s",__language(String,181),tot*numb,__language(String,6));
	    for(cyc4=0;cyc4<10;cyc4++)
	      for(cyc5=0;cyc5<10;cyc5++)
		__log(ins3,cyc4,cyc5);
		__log(ins3,99,99);
      sprintf(ins3,"@15!%s",__language(String,77));
	      __log(ins3,99,99);
      sprintf(ins3,"@12@%s%s",player[_W_[cyc3].player].empire,__language(String,78));
	      __log(ins3,99,99);
       } else {
      sprintf(ins3,"@15!%s",__language(String,77));
	      __log(ins3,99,99);
      sprintf(ins3,"@12@%s%s",player[_W_[cyc3].player].empire,__language(String,76));
	      __log(ins3,99,99);
      }
    }
for(cyc3=0;cyc3<50;cyc3++)
  if(_W_[cyc3].statis==2)
  {
    tot=0;
      for(cyc5=0;cyc5<10;cyc5++)
	tot+=_W_[cyc3].object[cyc5];
	tot-=_W_[cyc3].object[7];
    if(tot==0)
    {
      ___empire(_W_[cyc3].empire);
      for(cyc5=0;cyc5<10;cyc5++)
      {
	_W_[cyc3].object[cyc5]+=player[_W_[cyc3].player].object[cyc5];
	player[_W_[cyc3].player].object[cyc5]=0;
      }
      _W_[cyc3].statis=3;
      sprintf(ins3,"@15!%s",__language(String,77));
	      __log(ins3,99,99);
      sprintf(ins3,"@12@%s%s",player[_W_[cyc3].player].empire,__language(String,75));
	      __log(ins3,99,99);
    }
  }
savegame();
}















/* Setup 1.00    */ void __loadconfiguration(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,"%s",__CFGFILE__);
/* Open Save     */   if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(1,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&config, sizeof(configrec))) == -1) __errormessage(2,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&inter, sizeof(interrec))) == -1) __errormessage(2,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }

/* Setup 1.00    */ void __saveconfiguration(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,"%s",__CFGFILE__);
/* Open Save     */   if ((__userhandle = open(_fname, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE)) == -1) __errormessage(3,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&config, sizeof(configrec))) != sizeof(configrec)) __errormessage(4,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&inter, sizeof(interrec))) != sizeof(interrec)) __errormessage(4,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }

/* Bolivia 0.11  */ void ___loadgame(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__SPCFILE__);
/* Open Save     */   if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(5,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&special, sizeof(specrec))) == -1) __errormessage(6,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }

/* Bolivia 0.11  */ void ___savegame(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__SPCFILE__);
/* Open Save     */   if ((__userhandle = open(_fname, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE)) == -1) __errormessage(7,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&special, sizeof(specrec))) != sizeof(specrec)) __errormessage(8,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }



/* Bolivia 0.11  */ void __loadgame(void)/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__WARFILE__);
/* Open Save     */   if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(5,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&savedata, sizeof(saverec))) == -1) __errormessage(6,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&empire, sizeof(contrec))) == -1) __errormessage(6,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&warzone, sizeof(battrec)*50)) == -1) __errormessage(6,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&interattack, sizeof(grparec)*10)) == -1) __errormessage(6,_fname);
/* Close Up      */   close(__userhandle);/* Terminate     */ }

/* Bolivia 0.11  */ void __savegame(void)/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__WARFILE__);
/* Open Save     */   if ((__userhandle = open(_fname, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE)) == -1) __errormessage(7,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&savedata, sizeof(saverec))) != sizeof(saverec)) __errormessage(8,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&empire, sizeof(contrec))) != sizeof(contrec)) __errormessage(8,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&warzone, sizeof(battrec)*50)) != sizeof(battrec)*50) __errormessage(8,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&interattack, sizeof(grparec)*10)) != sizeof(grparec)*10) __errormessage(8,_fname);
/* Close Up      */   close(__userhandle);/* Terminate     */ }

/* Bolivia 0.11  */ void _loadgame(void)
/* Initiate      */ {char _fname[15];
/* Initiate      */   int __userhandle, bytes=0;/* Open Save     */   sprintf(_fname,__SAVFILE__[__empire]);
/* Open Save     */   if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(5,_fname);
/* Open Save     */   if ((bytes = read(__userhandle, (void *)&player, sizeof(userrec)*27)) == -1) __errormessage(6,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }

/* Bolivia 0.11  */ void _savegame(void)
/* Initiate      */ {char _fname[15];/* Initiate      */   int __userhandle, bytes=0;
/* Open Save     */   sprintf(_fname,__SAVFILE__[__empire]);
/* Open Save     */   if ((__userhandle = open(_fname, O_WRONLY | O_BINARY | O_CREAT | O_TRUNC, S_IREAD | S_IWRITE)) == -1) __errormessage(7,_fname);
/* Open Save     */   if ((bytes = write(__userhandle, (void *)&player, sizeof(userrec)*27)) != sizeof(userrec)*27) __errormessage(8,_fname);
/* Close Up      */   close(__userhandle);
/* Terminate     */ }





void writeBKD(void){
}

void detectsave(void){
  detectversion();
  detectwin();
}

void detectwin(void){
  return;
}

void detectversion(void){
  return;
}

void loadgame(void){
___loadgame();
__loadgame();
_loadgame();
}

void savegame(void){
___savegame();
__savegame();
_savegame();
}













void newplayer(int mod){
  int open[10];char yea=0;FILE *stream;

  __matrix("VAITON");

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

if(!yea){if(!mod)od_clr_scr();selectempire(open);}
if(yea){for(cyc4=0;cyc4<10;cyc4++)if(open[cyc4]==2)___empire(cyc4);}

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

sewage();

  if(thisuserno==26){__matrix("PLEIN");od_exit(0,FALSE);}

  if(_P_.statis==2){
    __matrix("ALLFIN");
    return;
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
	  if(strcmp(player[cyc].empire,_P_.empire)==0 && cyc!=thisuserno
	  ){
	    __matrix("NONLIBRE");
//	    od_set_colour(L_CYAN,D_BLACK);
//	    od_printf("%s\n\n\r",__language(String,7));
	    goto init1;
	  }
	}
	if(strncmp(_P_.empire,"The Kelvar",10)==0 || strncmp(_P_.empire,"Tasmania",8)==0){
	    __matrix("TASMANIAN");
	    if(getkey()!='!'){
		  od_input_str(ins,25,32,167);
		  goto init1;
	    }
	    nl();
	    nl();
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
_P_.protection      =config.parameter[6];
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
//__NEWFILE__(thisempire,thisuserno);
//stream=fopen(ins,"w+");
//fclose(stream);

__matrix("NEWSTRUCTQ");
  if(yn())
__matrix("NEWSTRUCT");
}




































