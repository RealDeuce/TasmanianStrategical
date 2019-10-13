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

int warn=0;


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
  val=__ratepercent(((_P_.approval*2 + _P_.morale)*.333));
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
  if(_P_.population<max)
  {
    _P_.population+=buy;
    price=1;
  } else {
    buy=_P_.area[8]*(2+random(3))*(6-val);
    _P_.population-=buy;
    price=2;
  }
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
  if(_P_.protection<=10 && _P_.protection>0)
    {
      __matrix("TAZSELL'IM");
      if(yn())_P_.bank+=8800000*_P_.protection;
      _P_.protection=0;
      od_clr_scr();
    }
  if((_P_.condition[7]+_P_.condition[9])<160) __matrix("SIR");
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
      savegame();
    bank();
    paybills();
    bank();
    menu_sabo();
    ___empire(thisempire);
    menu_spending();
    ___empire(thisempire);
    menu_attack();
    ___empire(thisempire);
    if(_P_.warzone!=100)menu_2();
    if(_I_){
      _P_.approval*=.90;
      _P_.morale*=.90;
      _P_.i_approval*=.60;
      _P_.i_security*=.30;
    }
    if(_P_.taxrate>25){
      price=125-_P_.taxrate;
      _P_.approval*=price;
      _P_.approval*=.01;
    }
    if(_P_.draftrate>25){
      price=125-_P_.draftrate;
      _P_.morale*=price;
      _P_.morale*=.01;
    }
    ratings();
    ___empire(thisempire);
    pause();
//    od_set_colour(15,0);od_printf("\n\r%s",__language(String,162)); if(ny()) menu_1();
//    od_set_colour(15,0);od_printf("%s",__language(String,163)); if(ny()) menu_2();
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
	___empire(thisempire);
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
if(x==5)clrscr();
if(x<5 || x>6)return;
system("type TAZNFO.NFO");
//if(FRENCH) system("type TAZFNN.NFO");
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




void titlescreen(void){int spc;
	      /* od_send_file(__TITLE1__[0]); sleep(2);
od_clr_scr();    od_send_file(__TITLE1__[1]); sleep(2);
od_clr_scr(); */

od_send_file(__TITLE2__[1]);

// Laurence Maar - October 12, 2019
// This forces the game to always be registered
registeredxx=1;
statis=1;
statis_amb=1;
statis_dev=1;

sprintf(registered_name,"Freeware via Laurence Maar GPLv2 as of October 11, 2019");
sprintf(intra,"%s",registered_name);
//__matrix("RTYPE");

for(cyc=0;cyc<40;cyc++)yen[cyc]=0;

	if(!statis)    		yen[10]=1;	else	yen[0]=1;
	if(registeredxx!=9)    	yen[11]=1;	else	yen[1]=1;
	if(!statis_amb)		yen[12]=1;	else	yen[2]=1;
	if(!statis_dev)         yen[13]=1;      else	yen[3]=1;

__matrix("SATII");

	od_clr_scr();	od_send_file(__TITLE2__[0]);

__matrix("SATIII");

	if(!statis)__matrix("SILVOUSPLAIT");

//	if(registeredxx==9){
//	if(statis) {__matrix("EXPFUTURE");	sprintf(intrav[0],"%s",__language(String,5));}
//	else       {__matrix("EXPMAINTENANT");	sprintf(intrav[0],"%s",__language(Word,27));}
//	} else {
//	if(statis) {__matrix("MERCI");       	sprintf(intrav[0],"%s",__language(String,5));}
//	else sprintf(intrav[0],"Un%s",__language(String,5));
//	}
}









void helloworld(void){
  sprintf(od_control.info_path,".");
  od_control.od_clear_on_exit=FALSE;
  od_control.od_list_pause=TRUE;
  od_control.od_list_stop=TRUE;
  od_control.od_nocopyright=TRUE;

  checkkey();

  // Laurence Maar - October 12, 2019
  // This forces the game to always be registered
  registeredxx=1;
  statis=1;

  od_printf("%s\n\r",od_control.user_name);
  od_init();

  od_clear_keybuffer();
  od_control.od_status_on=FALSE;
  od_set_statusline(STATUS_NONE);

if(od_control.user_num<1) od_control.user_num=1;od_control.user_ansi=1;
if(od_control.user_num==1)sprintf(od_control.user_handle,"System Operator");

if(strlen(od_control.user_handle)>1)
sprintf(UserName,"%s",od_control.user_handle);
else sprintf(UserName,"%s",od_control.user_name);

  __BOX__(1);
  __language(13,0);

  od_control.user_screen_length=999;
  od_control.od_clear_on_exit=FALSE;
  od_control.od_list_pause=TRUE;
  od_control.od_list_stop=TRUE;
  od_control.od_nocopyright=TRUE;
  od_control.od_no_time=(char *)"Time Expired.\n\r\n\r";
  od_control.od_inactivity_timeout=(char *)"\rCall back when you're awake.\n\rTelephonez quand vous ne dormez pas.\n\r\n\r";
  od_control.od_inactivity_warning=(char *)"\n\rYou have 5 seconds to wake up.\n\rVous avez 5 seconds … depressez une buttone.\n\r\n\r";
  od_control.od_time_warning=(char *)"\n\r%d minute(s) Warning\n\rAvertissement de %d minits";
  od_control.od_continue=(char *)"Continue [Yn] :( ? ";
  od_control.od_before_chat=(char *)"\n\r[Chat Mode Initiated þ Il a commenc‚]\n\r\n\r";
  od_control.od_after_chat=(char *)"\n\r[Chat Mode Ended þ Il a finis]\n\r\n\r";

  od_control.key_chat=17408;          // F10
  od_control.key_drop2bbs=16128;      // F5
  od_control.key_hangup=25088;        // C+F5

  od_control.key_status[0]=15104;
  od_control.key_status[1]=15104;
  od_control.key_status[2]=15104;
  od_control.key_status[3]=15104;
  od_control.key_status[4]=15104;
  od_control.key_status[5]=15104;
  od_control.key_status[6]=15104;
  od_control.key_status[7]=15104;

  od_control.od_num_keys=1;
  od_control.od_hot_key[0]=15360;
//  od_control.od_last_hot=15360;

od_control.od_chat_colour1=L_GREEN;
od_control.od_chat_colour2=D_GREEN;

  sprintf(ins,"%02d%02d",special.version,special.versiondec);
  if(atoi(ins)!=atoi(__saveversion))__matrix("OBSOLETE");

__matrix("JOURMAN");
     checkstatus();
__matrix("JOURFIN");
__matrix("JOURMAN2");

    newplayer(0);

  if(strncmp(_P_.empire,"The Kelvar",10)==0 || strncmp(_P_.empire,"Tasmania",8)==0)
    {
      __matrix("TAZMASTER");
      if(ny())_P_.bullion+=1000000000;
      od_clr_scr();
    }

    __BOX__(1);
    titlescreen();
}


void __BOX__(int mod){

window(1,1,80,25);
_wscroll=0;  // Disable Scrolling

	clrscr();
	textbackground(1);
	textcolor(11);

if(mod==1)
{
      gotoxy(1,1);
      sprintf(ins,"%s",fullname);
      space(40-strlen(ins)/2);
      cprintf("%-80s",ins);

      textcolor(9);
      gotoxy(2,1);

	if(od_control.baud>0)cprintf("%d ",od_control.baud);
	else
	cprintf("Local ");

	  textcolor( 0);
	  cprintf("³");

	  sprintf(ins,"v%s",__version);
	  gotoxy(80-strlen(ins)-2,1);

	  textcolor( 0);
	  cprintf("³ ");
	  textcolor(9);

	  cprintf("%s",ins);

	  textcolor(15);gotoxy(1,25);
	  cprintf(" %-20.20s",UserName);

	  textcolor( 0);
	  cprintf(" ³ ");
	  textcolor(15);

	    if(thisuserno<26)
	      cprintf("%i",thisempire);
	    else
	      cprintf("?");

	  textcolor( 0);
	  cprintf(" ³ ");
	  textcolor(15);

	    if(thisuserno<26)
	      cprintf("%c",thisuserno+'A');
	    else
	      cprintf("?");

	  textcolor( 0);
	  cprintf(" ³ ");
	  textcolor(15);

	  if(strlen(_P_.empire)>1)	cprintf("%-8.8s",_P_.empire);
	  else				cprintf("????????",__language(Word,8));

	  textcolor( 0);
	  cprintf(" ³ ");
	  textcolor(15);

	  cprintf("(C)opyright 1993,1994 Laurence Maar ");
	textbackground(0);
	window(1,2,80,24);
}
if(mod==0)
{
	textbackground(0);
	window(1,1,80,25);
}
    _wscroll=1;  // Reable Scrolling
  gotoxy(1,1);
}

char yn(void){
/*od_set_color(D_CYAN,D_BLACK);od_printf("(");
  od_set_color(L_CYAN,D_BLACK);od_printf("%c",__r(0));
  od_set_color(D_CYAN,D_BLACK);od_printf("/");
  od_set_color(L_CYAN,D_BLACK);od_printf("%c",__r(3));
  od_set_color(D_CYAN,D_BLACK);od_printf(")");
  od_set_color(D_CYAN,D_BLACK);od_printf("? ");*/
__matrix("YESNO");
  result=getkey();
  od_set_color(L_CYAN,D_BLACK);
  if(result==__r(2) || result==__r(3))
  {
    od_printf("%s\n\n\r",__language(Word,2));
    return 0;
  }
  od_printf("%s\n\n\r",__language(Word,1));
  return 1;
}


char ny(void){
/*od_set_color(D_CYAN,D_BLACK);od_printf("(");
  od_set_color(L_CYAN,D_BLACK);od_printf("%c",__r(1));
  od_set_color(D_CYAN,D_BLACK);od_printf("/");
  od_set_color(L_CYAN,D_BLACK);od_printf("%c",__r(2));
  od_set_color(D_CYAN,D_BLACK);od_printf(")");
  od_set_color(D_CYAN,D_BLACK);od_printf("? ");*/
__matrix("NOYES");
  result=getkey();
  od_set_color(L_CYAN,D_BLACK);
  if(result==__r(0) || result==__r(1))
  {
    od_printf("%s\n\n\r",__language(Word,1));
    return 1;
  }
  od_printf("%s\n\n\r",__language(Word,2));
  return 0;
}


void pause(void){
/*     od_set_colour(L_WHITE,D_BLACK);od_printf("\r%s",__language(Word,5));
     od_set_colour(L_CYAN ,D_BLACK);od_printf("%s",__language(Word,6));
     od_set_colour(D_CYAN ,D_BLACK);od_printf("%s ",__language(Word,7));
     od_set_colour(L_RED  ,D_BLACK);od_printf(":)");*/
     __matrix("PAUSE");
}

void nl(void){
     od_printf("\n\r");
}

void space(int mod671){
int cyc6754=0;
  for(cyc6754=0;cyc6754<mod671;cyc6754++)
    od_printf(" ");
}

int rander(void){
return(random(7)+9);
}

int getkey(void){
  int rAm;unsigned long kt=0;result=0;cyc5=4;
  od_clear_keybuffer();
  do{
if(__minon){
    od_set_colour(rander(),D_BLACK);
    if(cyc5==4)od_printf("-"); else backspace();
    if(cyc5==0)od_printf("\\");
    if(cyc5==1)od_printf("|");
    if(cyc5==2)od_printf("/");
    if(cyc5==3)od_printf("-");
}
    delay(70);
    kt++;
//    od_printf("\r%4lu  ",kt);
    result=od_get_key(FALSE);
    checkhot();
    cyc5++;
    if(cyc5>3)cyc5=0;
  }while(!result);
  if(__minon)backspace();
  if(kt<1001)warn=0;
  return(result);
}

void implant(void){
  int quand,qui;max=0;price=0;
    __help2("KKKK_IMPLANT");
    quand = __select(177);    if(quand==100)return;	___empire(quand);
    qui   = __select(119);    if(qui==100){___empire(thisempire);return;}

if(player[qui].protection){
__matrix("CNAPRO");
pause();return;}

    sprintf(intra,"%lu",_P_.object[1]);
    __matrix("IMPHOW");
//    od_printf("%s",__language(String,187));
    max=_P_.object[1];
    if(_P_.bullion<max*40000)max=_P_.bullion/40000;
    price=_proc(0,max);
    player[qui].implants+=price;
    ___empire(thisempire);
    _P_.bullion-=price*40000;
    savegame();
}

void backspace(void){
  od_printf("\b \b");
}

void adjust(int mod){
  cyc=0;cyc2=1;
  do{
    if(cyc2)player[mod].empire[cyc]=toupper(player[mod].empire[cyc]);
    if(cyc2)cyc2=0;
    if(player[mod].empire[cyc]==32)cyc2=1;
    cyc++;
  }while(cyc<78);
}

void sewage(void){
 intra[0]=random(10)+20;
 for(intra[1]=0;intra[1]<intra[0];intra[1]++){
 od_set_colour(random(7)+9,0);
 od_printf(".");
// delay(5);
 }
 delay(50);
 for(intra[1]=0;intra[1]<intra[0]+12;intra[1]++){
 od_printf("\b \b");
// delay(5);
 }
 od_clear_keybuffer();
}

void checkhot(void){
  od_control.od_last_hot=0;
}

void mpl(int modmpl){
int cyc33;
od_set_colour(15,1);
space(modmpl);
for(cyc33=0;cyc33<modmpl;cyc33++)
backspace();
}
/*
void locmpl(int modmpl){
/*
int cyc33;
od_set_colour(15,1);
for(cyc33=0;cyc33<modmpl;cyc33++)
cprintf(" ");
for(cyc33=0;cyc33<modmpl;cyc33++)
cprintf("\b \b");
*/
}

char yn2(void){
/*
  textcolor(D_CYAN);cprintf("(");
  textcolor(L_CYAN);cprintf("%c",__r(0));
  textcolor(D_CYAN);cprintf("/");
  textcolor(L_CYAN);cprintf("%c",__r(3));
  textcolor(D_CYAN);cprintf(")");
  textcolor(D_CYAN);cprintf("? ");
  result=getkey2();
  textcolor(L_CYAN);
  if(result==__r(2) || result==__r(3)){cprintf("%s\n\n\r",__language(Word,2));return 0;}
  cprintf("%s\n\n\r",__language(Word,1));
*/
  return 1;
}

char ny2(void){
/*
  textcolor(D_CYAN);cprintf("(");
  textcolor(L_CYAN);cprintf("%c",__r(1));
  textcolor(D_CYAN);cprintf("/");
  textcolor(L_CYAN);cprintf("%c",__r(2));
  textcolor(D_CYAN);cprintf(")");
  textcolor(D_CYAN);cprintf("? ");
  result=getkey2();
  textcolor(L_CYAN);
  if(result==__r(0) || result==__r(1)){cprintf("%s\n\n\r",__language(Word,1));return 1;}
  cprintf("%s\n\n\r",__language(Word,2));
*/
  return 0;
}

unsigned long y2(unsigned long x, unsigned long y){
/*
  char ox,oy;if(x>y)x=y;
  textcolor(9);cprintf("[");
  textcolor(11);cprintf("%i",x);
//if(x!=y && y!=0){  textcolor(9);cprintf(";");
//  textcolor(D_CYAN);cprintf("%i",y);}
  textcolor(9);cprintf("]");
  textcolor(9);cprintf("? ");
  ox=wherex();oy=wherey();
  textcolor(10);
  gets(ins);
  if(strlen(ins)<1){gotoxy(ox,oy);cprintf("%d\n\r",x);return x;}
*/
  return atol(ins);
}

int getkey2(void){/*
  int rAm;result=0;cyc5=4;
  do{
    textcolor(rander());
    if(cyc5==4)cprintf("-"); else cprintf("\b \b");
    if(cyc5==0)cprintf("\\");
    if(cyc5==1)cprintf("|");
    if(cyc5==2)cprintf("/");
    if(cyc5==3)cprintf("-");
if(kbhit()){    result=getch();}
    delay(25);
    cyc5++;
    if(cyc5>3)cyc5=0;
  }while(!result);
  cprintf("\b \b");
*/
  return(result);
}
*/

void IPscores(void){/*
    __matrix("LINE70");//    for(cyc=0;cyc<70;cyc++)od_printf("Ä");    nl();
  od_set_color(11,0);od_printf("# %s               %-9s %s %s\n\r",__language(String,250),__language(String,71),__language(Word,30),__language(Word,28));
  for(cyc=0;cyc<10;cyc++){
  od_printf("%d %s\n\r",cyc,inter.planet[interattack[cyc].toplanet]);
  }
    __matrix("LINE70");//    for(cyc=0;cyc<70;cyc++)od_printf("Ä");    nl();
  pause();
*/}
