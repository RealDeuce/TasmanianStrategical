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

#define UNDEFINED
#define NOTLIVE
#define SPECIAL_NO
#include"tazdef.h"
#include"tazver.h"

main(int argc,char **argv){ int stat; char *sp; price=0;
     if(argc>1 && strnicmp(argv[1],"BNU",3)==0)system("BNU");
     if(argc>1 && strnicmp(argv[1],"X00",3)==0)system("X00");
     registered=TRUE;
     directvideo=0;
     __loadconfiguration();
     FRENCH=config.parameter[7];                      __language(4,0);
     if(argc>1 && strnicmp(argv[1],"DAY",3)==0)       price=1;
//     FRENCH=config.parameter[7];                      __language(4,0);
     loadgame();
     helloworld();

#ifdef SPECIAL_YES
     __matrix("PREREL");
#endif

     menu_initiate();
}


void menu_initiate(void){
 __NEWFILE__(thisempire,thisuserno);
 stream=fopen(ins,"a+");
 fclose(stream);
 menu_main();
 savegame();
 od_exit(0,FALSE);
}












void menu_main(void){
  char bbsin4[10],a,b,ins2[80];int numba,c;struct date d;getdate(&d);od_control.od_before_exit=savegame;
for(cyc=0;cyc<40;cyc++)yen[cyc]=0;

	if(!statis)    		yen[10]=1;	else	yen[0]=1;
	if(registeredxx!=9)    	yen[11]=1;	else	yen[1]=1;
	if(!statis_amb)		yen[12]=1;	else	yen[2]=1;
	if(!statis_dev)         yen[13]=1;      else	yen[3]=1;

__matrix("SETI");

    do{
      ___empire(thisempire);
      bbsinkey=__menu("MENU_LOGON");
	switch(bbsinkey){
	  case '1':playgame();break;
	  case '2':displaystatus();pause();break;
	  case '3':menu_diplomacy();break;
	  case '4':savegame();allscores();pause();warscores();pause();scores();pause();break;
	  case '5':od_set_colour(2,0);__rc2=2;a=__outta(Word,11,0,d.da_day,31);b=__outta(Word,10,0,d.da_mon,12);c=__outta(Word,12,0,d.da_year,2100);__readlog(a,b,c);break;
	  case '6':__matrix("ABON");
	    if(ny())
	    {
	      _P_.statis=1;
	      savegame();
	      sprintf(ins2,"%s%s!!!",__language(String,21),_P_.empire);
	      __log(ins2,99,99);
	      newplayer(0);
	    }
	    break;
	  case '7':menu_2();break;
	  case '8':menu_1();break;
	  case '9':break;
	  case '*':menu_sysop();break;
	  case '0':savegame();od_set_colour(D_CYAN,D_BLACK);od_printf("\n\r%s",__language(Word,0));if(_P_.turns<1)res=yn();else res=ny();if(res){bbsexit=0;od_control.user_screen_length=23;}break;
	}
  }while(bbsexit!=0);

#ifdef SPECIAL_YES
  __matrix("TESTQUESTION");
  stream=fopen("TAZERR.NFO","a+");
  fprintf(stream,"\n\r%sþ%s [%d.%d.%d]\n\r",_P_.empire,_P_.name,d.da_day,d.da_mon,d.da_year);
    do{
      __matrix("TESTPROMPT");
      od_input_str(ins,75,32,167);
      fprintf(stream,"%s\n\r",ins);
    }while(strlen(ins));
  fclose(stream);
#endif

if(!statis)__matrix("PLEA");
od_exit(0,FALSE);
}







void menu_sysop(void){
#ifdef LIVE
  do{
  bbsinkey=__menu("MENU_SYSOP");
	switch(bbsinkey){
	  case '1':__language(7,0);case '2':case '3':case '4':case '5':
	  case '6':__language(3,0);break;
	  case '9':__language(99,0);break;
	  case '-':__currentlanguage=0;__language(4,0);break;
	  case '=':__currentlanguage=1;
	  case '7':__language(4,0);break;
	  case '0':return;break;
	}
  }while(bbsinkey!=0);
#else
  __matrix("TEST");
#endif
}


void menu_systeme(void){
  do{
    bbsinkey=__menu("MENU_SYSTEME");
      switch(bbsinkey){
	case '1':__matrix("SETTAX");_P_.taxrate=_proc(_P_.taxrate,100);break;
	case '2':__matrix("SETDRAFT");_P_.draftrate=_proc(_P_.draftrate,100);break;
	case '3':menu_diplomacy();break;
	case '4':menu_sabo();break;
	case '5':menu_1();break;
	case '6':menu_2();break;
	case '7':setproduction();break;
	case '8':displaystatus();pause();break;
	case '9':savegame();allscores();pause();scores();pause();break;
	case 'A':ratings();pause();break;
	case 'B':bank();break;
	default :return;
      }
  }while(bbsexit!=0);
}

void menu_spending(void){char _intern;__matrix("BUYMOD");
  do {bbsinkey=__menu("MENU_SPENDING");_typo=0;_intern=0;
	switch(bbsinkey){
	  case '1':price=1000+inflation.object[0];break;
	  case '2':price=2000+inflation.object[1];break;
	  case '3':price=4000+inflation.object[2];break;
	  case '4':price=8000+inflation.object[3];break;
	  case '5':price=5000+inflation.object[4];break;
	  case '6':price=1000+inflation.object[5];break;
	  case '7':price=10000+inflation.object[6];break;
	  case '8':price=1000+inflation.object[19];_typo=1;break;
	  case '9':price=500000+inflation.object[8];break;
	  case '0':price=1000000+inflation.object[9];_intern=1;break;
	  case '.':palais();price=0;break;
	  case '*':menu_systeme();price=0;break;
	  case '-':menu_selling();_intern=2;price=0;break;
	  case '?':__matrix("HELP_SPENDING");_intern=2;break;
	  default :return;break;
	}
if(price>0){
if(_intern<2){
    max=_P_.bullion/price;
	if(max<1)
	__matrix("NOARGENT");//	od_printf("\n\r%s\n\n\r",__language(String,84));
	else if(_typo==1)menu_territory();
	else{
	  if(_intern){ _P_.condition[9]+=5; _P_.bullion-=price; if(_P_.condition[9]>100)_P_.condition[9]=100;}
      else{
	_typo=bbsinkey-'0';
	  if(_typo==0)_typo=9;
	  else _typo--;
	od_set_colour(15,0);
	od_printf("\r%s ",__language(String,83));
	buy=_proc(0,max);od_printf("\n\n\r");
	_P_.object[_typo]+=buy;
	_P_.bullion-=buy*price;
      }}}}
  } while(bbsexit!=0);
}

void menu_territory(void){int ar=10000;
  do {top:;
    bbsinkey=__menu("MENU_TERRITORE");      price=0;
	switch(bbsinkey){
	  case 'A':bbsinkey='1';price=1000   +inflation.area[0];break;
	  case 'B':bbsinkey='2';price=100000 +inflation.area[1];break;
	  case 'C':bbsinkey='3';price=100000 +inflation.area[2];break;
	  case 'D':bbsinkey='4';price=1000   +inflation.area[3];break;
	  case 'F':bbsinkey='5';price=1000000+inflation.area[4];break;
	  case 'G':bbsinkey='6';price=100000 +inflation.area[5];break;
	  case 'I':bbsinkey='7';price=100000 +inflation.area[6];break;
	  case 'M':bbsinkey='8';price=500000 +inflation.area[7];break;
	  case 'R':bbsinkey='9';price=10000  +inflation.area[8];break;
	  case 'T':bbsinkey='0';price=1000   +inflation.area[9];break;
	  case '?':__matrix("NEWSTRUCT");goto top;
	  default :return;break;
	}
    max=_P_.bullion/price;if(max>ar)max=ar;
    if(max<1)
	__matrix("NOARGENT");
//	od_printf("\n\r%s\n\n\r",__language(String,84));
    else{
      _typo=bbsinkey-'0';
    if(_typo==0)
	  _typo=9;
    else
      _typo--;
      od_set_colour(15,0);od_printf("\r%s ",__language(String,83));
      buy=_proc(0,max);od_printf("\n\n\r");
      _P_.area[_typo]+=buy;ar-=buy;
      _P_.bullion-=buy*price;
    }
  } while(bbsexit!=0 && _P_.bullion>=1000);
}






void menu_sabo(void){int quand,qui;char ins2[80];
  do{
	gen:;
	bbsinkey=__menu("MENU_SABO");bbsexit=1;
      switch(bbsinkey){
	case '1':price=10000;break;
	case '2':price=100000;break;
	case '3':price=100000;break;
	case '4':price=200000;break;
	case '5':price=500000;break;
	case '6':price=1000000;break;
	case '7':price=2000000;break;
	case '8':price=5000000;break;
	case '9':price=10000000;break;
	case '0':price=20000000;break;
	case 'A':price=100000000;break;
	case '?':__matrix("HELP_SABO");goto gen;
	default :return;
      }
	od_set_colour(11,0);
	if(_P_.bullion<price){
	__matrix("NOARGENT2");
//	od_printf("\n\r%s\n\n\r",__language(String,84));
//	pause();
	break;}
	if(bbsinkey=='2'){
	for(cyc=0;cyc<50;cyc++){
	  if(_W_[cyc].statis){
	    ___empire(_W_[cyc].empire);
		 sprintf(ins,"%s\n\r",player[_W_[cyc].player].empire);
		 sprintf(intrav[0],"%s",_parsemoney(_W_[cyc].object[0]));
		 sprintf(intrav[1],"%s",_parsemoney(_W_[cyc].object[1]));
		 sprintf(intrav[2],"%s",_parsemoney(_W_[cyc].object[2]));
		 sprintf(intrav[3],"%s",_parsemoney(_W_[cyc].object[3]));
		 sprintf(intrav[4],"%s",_parsemoney(_W_[cyc].object[4]));
		 sprintf(intrav[5],"%s",_parsemoney(_W_[cyc].object[6]));
		 __matrix("INTSPY");
	  }
		 __matrix("INTALL");
	}
	___empire(thisempire);	} else {
	quand = __select(177);    if(quand==100){___empire(thisempire);break;} ___empire(quand);
	qui   = __select(240);    if(qui==100)  {___empire(thisempire);break;} ___empire(quand);	}
	if(bbsinkey=='1'){
		 sprintf(ins,"%s\n\r",player[qui].empire);
		 sprintf(intrav[0],"%s",_parsemoney(player[qui].object[0]));
		 sprintf(intrav[1],"%s",_parsemoney(player[qui].object[1]));
		 sprintf(intrav[2],"%s",_parsemoney(player[qui].object[2]));
		 sprintf(intrav[3],"%s",_parsemoney(player[qui].object[3]));
		 sprintf(intrav[4],"%s",_parsemoney(player[qui].object[4]));
		 sprintf(intrav[5],"%s",_parsemoney(player[qui].object[6]));
		 __matrix("INTSPY");
	}
	if(bbsinkey=='3'){
		 sprintf(ins,"%s\n\r",player[qui].empire);
		 sprintf(intrav[1],"%lu%%",player[qui].approval);
		 sprintf(intrav[0],"%lu%%",player[qui].morale);
		 sprintf(intrav[2],"%lu%%",player[qui].i_security);
		 sprintf(intrav[3],"%lu%%",player[qui].i_punishment);
		 sprintf(intrav[4],"%lu%%",player[qui].i_enforcement);
		 sprintf(intrav[5],"%lu%%",player[qui].i_approval);
		 __matrix("JARSPY");
	}
	if(bbsinkey=='4'){
	  player[qui].i_security*=.90;
	  player[qui].i_approval*=.80;
	  player[qui].approval*=.85;
	  sprintf(ins2,"%s%s",__language(String,60),player[qui].empire);
	  __log(ins2,thisempire,thisuserno);
	  __matrix("TCRPT");
	}
	if(bbsinkey=='5'){
//	  player[qui].i_security*=.95;
//	  player[qui].i_approval*=.95;
//	  player[qui].approval*=.75;
	  price=player[qui].area[2]*=.1;
	  player[qui].area[2]-=price;
	  player[qui].area[3]+=price;
	  sprintf(ins2,"%s%s",player[qui].empire,__language(String,61));
	  __log(ins2,thisempire,thisuserno);
	  __matrix("TCRPT");
	}
	if(bbsinkey=='6'){
//	  player[qui].i_security*=.90;
//	  player[qui].i_approval*=.90;
//	  player[qui].i_enforcement*=.90;
//	  player[qui].i_punishment*=.90;
	  player[qui].approval*=.90;
	  price=player[qui].area[8]*=.1;
	  player[qui].area[8]-=price;
	  player[qui].area[3]+=price;
	  sprintf(ins2,"%s%s",__language(String,62),player[qui].empire);
	  __log(ins2,thisempire,thisuserno);
	  __matrix("TCRPT");
	}
	if(bbsinkey=='7'){
//	  player[qui].i_security*=.70;
//	  player[qui].i_approval*=.50;
//	  player[qui].i_enforcement*=.70;
//	  player[qui].i_punishment*=.50;
	  player[qui].approval*=.50;
	  player[qui].morale*=.70;
	  price=player[qui].area[8]*=.1;
	  player[qui].area[8]-=price;
	  player[qui].area[3]+=price;
	  price=player[qui].area[2]*=.05;
	  player[qui].area[2]-=price;
	  player[qui].area[3]+=price;
	  price=player[qui].area[7]*=.05;
	  player[qui].area[7]-=price;
	  player[qui].area[3]+=price;
	  sprintf(ins2,"%s%s",__language(String,60),player[qui].empire);
	  __log(ins2,thisempire,thisuserno);
	  __matrix("TCRPT");
	}
	if(bbsinkey=='8'){
	  player[qui].i_security*=.80;
	  player[qui].i_approval*=.40;
	  player[qui].i_enforcement*=.80;
	  player[qui].i_punishment*=.80;
	  player[qui].approval*=.35;
	  player[qui].morale*=.70;
	  price=player[qui].area[8]*=.03;
	  player[qui].area[8]-=price;
	  player[qui].area[3]+=price;
	  price=player[qui].area[2]*=.03;
	  player[qui].area[2]-=price;
	  player[qui].area[3]+=price;
	  price=player[qui].area[6]*=.20;
	  player[qui].area[6]-=price;
	  player[qui].area[3]+=price;
	  sprintf(ins2,"%s%s",__language(String,62),player[qui].empire);
	  __log(ins2,thisempire,thisuserno);
	  __matrix("TCRPT");
	}
	if(bbsinkey=='9'){
	  player[qui].i_security*=.50;
	  player[qui].i_approval*=.50;
	  player[qui].i_enforcement*=.50;
	  player[qui].i_punishment*=.50;
	  player[qui].approval*=.50;
	  player[qui].morale*=.50;
	  price=player[qui].area[8]*=.05;
	  player[qui].area[8]-=price;
	  player[qui].area[3]+=price;
	  price=player[qui].area[7]*=.10;
	  player[qui].area[7]-=price;
	  player[qui].area[3]+=price;
	  price=player[qui].area[6]*=.05;
	  player[qui].area[6]-=price;
	  player[qui].area[3]+=price;
	  sprintf(ins2,"%s%s",__language(String,62),player[qui].empire);
	  __log(ins2,thisempire,thisuserno);
	  __matrix("TCRPT");
	}
	___empire(thisempire);break;
  }while(bbsexit!=0);
}


void menu_selling(void){unsigned long _i_;__matrix("SELLMOD");
  do {
    bbsinkey=__menu("MENU_SELLING");_typo=0;max=0;
	switch(bbsinkey){
	  case '1':price=25   +inflation.object[0]*.03;break;
	  case '2':price=50   +inflation.object[1]*.03;break;
	  case '3':price=100  +inflation.object[2]*.03;break;
	  case '4':price=200  +inflation.object[3]*.03;break;
	  case '5':price=125  +inflation.object[4]*.03;break;
	  case '6':price=25   +inflation.object[5]*.03;break;
	  case '7':price=250  +inflation.object[6]*.03;break;
	  case '8':_typo=1;break;
	  case '9':price=12500+inflation.object[8]*.03;break;
	  default :return;break;
	}
    max=_P_.object[bbsinkey-49];
    if(_typo){for(cyc3=0;cyc3<20;cyc3++)max+=_P_.area[cyc3];}
    if(max<1)
      od_printf("\r%s\n\n\r",__language(String,87));
    else if(_typo==1)menu_selling2();
    else{
	val=2500000000-_P_.bullion;
	_i_=val/price;
	if(max>_i_)max=_i_;
	if(max<1)__matrix("O25BILL");
	_typo=bbsinkey-'0';
	  if(_typo==0)_typo=9;
	  else _typo--;
	od_set_colour(15,0);
	od_printf("\r%s ",__language(String,86));
	buy=_proc(0,max);od_printf("\n\n\r");
	_P_.object[_typo]-=buy;
	_P_.bullion+=buy*price;
    }
  } while(bbsexit!=0);
}




void menu_selling2(void){unsigned long _i_;
  do {
    bbsinkey=__menu("MENU_TERRE");      price=(inflation.object[19]*.0005+1000)*.2;
	switch(bbsinkey){
	  case 'A':bbsinkey=0;break;
	  case 'B':bbsinkey=1;break;
	  case 'C':bbsinkey=2;break;
	  case 'D':bbsinkey=3;break;
	  case 'F':bbsinkey=4;break;
	  case 'G':bbsinkey=5;break;
	  case 'I':bbsinkey=6;break;
	  case 'M':bbsinkey=7;break;
	  case 'R':bbsinkey=8;break;
	  case 'T':bbsinkey=9;break;
	  default :return;break;
	}
    max=_P_.area[bbsinkey];
    if(max<1)
      od_printf("\r%s\n\n\r",__language(String,87));
    else{
	val=2500000000-_P_.bullion;
	_i_=val/price;
	if(max>_i_)max=_i_;
	if(max<1)__matrix("O25BILL");
      od_set_colour(15,0);od_printf("\r%s ",__language(String,86));
      buy=_proc(0,max);od_printf("\n\n\r");
      _P_.area[bbsinkey]-=buy;
      _P_.bullion+=buy*price;
    }
  } while(bbsexit!=0 && _P_.bullion>=1000);
}









void menu_attack(void){
  do{ price=0;
    bbsinkey=__menu("MENU_ATTACK");
      switch(bbsinkey){
	case '1':case '2':case '3':case '4':case '5':if(_P_.protection>0){__matrix("PROTED");break;}
	if(bbsinkey=='1'){attack();if(price)return;else break;}
	if(bbsinkey=='2'){nuclear();if(price)return;else break;}
	if(bbsinkey=='3'){implant();if(price)return;else break;}
	if(bbsinkey=='5'){coup();if(price)return;else break;}
	case '?':__help2("HELP_ATTACK");break;
	default :return;
      }
    ___empire(thisempire);
  }while(bbsexit!=0);
}





void menu_diplomacy(void){__matrix("NODIPLO");/*
  int quand,qui;char ins2[8];
  do{
    bbsinkey=__menu("MENU_DIPLO");
      switch(bbsinkey){
	case '1':case '2':case '3':case '4':case '5':case '6':case '7':
	___empire(thisempire);
	quand=__select(109);nl();if(quand==100)break;
	if(quand==99){
	for(cyc2=0;cyc2<10;cyc2++){___empire(cyc2);for(cyc=0;cyc<26;cyc++){sprintf(ins2,"#%02d%02d%02d",bbsinkey-'0',thisempire,thisuserno);if((cyc!=thisuserno || cyc==thisuserno && cyc2!=thisempire) && player[cyc].statis==2){__log(ins2,cyc2,cyc);quand=random(9)+7;od_set_colour(quand,0);od_printf(".");}}}od_printf("\n\n\r");
	} else {
	___empire(quand);sprintf(ins2,"#%02d%02d%02d",bbsinkey-'0',thisempire,thisuserno);for(cyc=0;cyc<26;cyc++)if(cyc!=thisuserno || cyc==thisuserno && quand!=thisempire)__log(ins2,quand,cyc);
	}
	___empire(thisempire);	break;
	case '?':__matrix("HELP_DIPLO");break;
	default :return;
      }
  }while(bbsexit!=0);
*/}

void menu_1(void){__matrix("NOINT");/*
  do{
    bbsinkey=__menu("MENU_INTER");
      switch(bbsinkey){
	case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':
	intercontinnental();break;
	case '?':__help2("HELP_INTER");break;
	default :return;break;
      }
  }while(bbsexit!=0);
*/}









void menu_2(void){
  do{
    bbsinkey=__menu("MENU_WARZONE");
      switch(bbsinkey){
	case '1':case '2':case '3':case '4':case '5':
	od_set_colour(3,0);
	if(_P_.protection>0){__matrix("PROTED");break;}
	warzoneit(bbsinkey-'0');___empire(thisempire);break;
	case '7':if(_P_.warzone==100){
       __matrix("DECLR1ER");
//	od_printf("\n\r%s\n\n\r",__language(String,227));pause();
	break;}nl();
		 sprintf(intrav[1],"%s",_parsemoney(__W.object[0]));
		 sprintf(intrav[2],"%s",_parsemoney(__W.object[1]));
		 sprintf(intrav[3],"%s",_parsemoney(__W.object[2]));
		 sprintf(intrav[4],"%s",_parsemoney(__W.object[3]));
		 sprintf(intrav[5],"%s",_parsemoney(__W.object[4]));
		 sprintf(intrav[6],"%s",_parsemoney(__W.object[6]));
		 __matrix("ZONEZATS");
		 break;
	case '9':warscores();pause();break;
	case '?':__help2("HELP_WARZONE");break;
	default :return;break;
      }
  }while(bbsexit!=0);
}















/*/*
void menu_3(void){
  do{
    bbsinkey=__menu("MENU_PRoBL‚Me");
      switch(bbsinkey){
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	default :return;
      }
  }while(bbsexit!=0);
}
*/

/*
void menu_4(void){
  do{
    bbsinkey=__menu("MENU_PRoBL‚Me");
      switch(bbsinkey){
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	default :return;
      }
  }while(bbsexit!=0);
}
*/

/*
void menu_5(void){
  do{
    bbsinkey=__menu("MENU_PRoBL‚Me");
      switch(bbsinkey){
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	default :return;
      }
  }while(bbsexit!=0);
}
*/
*/

















