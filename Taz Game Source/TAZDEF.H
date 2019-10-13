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

#ifndef BYTE
#define BYTE
typedef unsigned char byte;
#endif
#define ENABLE_LANGUAGE
#ifndef NOOPEN
#include<opendoor.h>
#endif
#include<process.h>
#include<dos.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<io.h>
#include<fcntl.h>
#include<sys\stat.h>
#define ENGLISH !__currentlanguage
#define FRENCH __currentlanguage
#define String 40
#define Word 10
#define Line 80
#define LETTERS__  10 //      10
#define STRINGS__ 196 // 257 270
#define WORDS__    60 //      70
#define LINES__     1 //   8  30
#define _P_ player[thisuserno]
#define _W_ warzone
#define _E_ empire.empire
#define _I_ _P_.implants
#define __W warzone[_P_.warzone]
#define __P inflation
#define __E remaining
#define __T total
#define SiT if(_toke){





/***************************************************************************/
/***************************************************************************/

		typedef struct {                /***/
	  char  statis          ;               /***/  // 2-Live/1-Dead/0-Empty
	  char  warzone         ;               /***/  // int
	  char  turns           ;               /***/  // int
	  char  protection      ;               /***/  // int
	  char  ReSeRvEd2xxxxxxx;               /***/  // int
	  char  name        [40];        	/***/  // str
	  char  empire      [40];        	/***/  // str
	  char  relation    [10];       	/***/  // yN  -Allies...Enemies
	  char  taxrate         ;        	/***/  //  %  -Population
	  char  draftrate       ;        	/***/  //  %  -Population
 unsigned long	food            ;               /***/  // Qty -Food
 unsigned long	bullion         ;               /***/  // Qty -Bullion
 unsigned long	bank            ;     	        /***/  // Qty -Bullion
 unsigned long  investment      ;               /***/  // Qty -Investment
 unsigned long	object      [20];       	/***/  // Qty -Tanks...Jets
 unsigned long	condition   [10];         	/***/  //  %  -Tanks...Jets
 unsigned long	population      ;	     	/***/  // Qty -Population
 unsigned long  i_security      ;	     	/***/  //  %  -Population
 unsigned long  i_punishment    ;	     	/***/  //  %  -Population
 unsigned long  i_enforcement   ;	     	/***/  //  %  -Population
 unsigned long  i_approval      ;	     	/***/  //  %  -Population
 unsigned long  i_crime         ;	     	/***/  //  %  -Population
 unsigned long  approval        ;	     	/***/  //  %  -Population
 unsigned long  morale          ;	     	/***/  //  %  -Population
 unsigned long  area        [20];        	/***/  // Qty -Planets...Regions
 unsigned long  efficiency  [10];        	/***/  //  %  -Planets...Regions
 unsigned long  industry    [10];               /***/  //  %  -Production
 unsigned long  military    [10];               /***/  //  %  -Production
 unsigned long  fortress    [10];               /***/  //  %  -Production
 unsigned long  biosphere       ;               /***/  //  %  -Production
 unsigned long  gouvernment     ;               /***/  //  %  -Production
 unsigned long	implants        ;               /***/  // Qty -Terminators
						/***/  } userrec;

		typedef struct {                /***/
	  char	saveday         ;               /***/
	  char	savemon         ;               /***/
	  char	saveyear        ;               /***/
						/***/  } saverec;

		typedef struct {                /***/
	  char	version         ;               /***/
	  char	versiondec      ;               /***/
	  char	mode_inter      ;               /***/
	  char	mode_1          ;               /***/
	  char	mode_2          ;               /***/
	  char	mode_3          ;               /***/
	  char	mode_4          ;               /***/
	  char	mode_5          ;               /***/
						/***/  } specrec;

		typedef struct {                /***/
	  char	statis      [50];               /***/
	  char	planet  [50][25];               /***/
	  char	members     [50];               /***/
 unsigned long	bullion     [50];               /***/
 unsigned long	militaire   [50];               /***/
 unsigned long	territiore  [50];               /***/
						/***/  } interrec;

		typedef struct {                /***/
 unsigned  int	destination     ;               /***/
 unsigned  int	sender          ;               /***/
 unsigned  int	unit            ;               /***/
 unsigned  int	section         ;               /***/
 unsigned  int	subsection      ;               /***/
	  char	label       [40];               /***/
	  char	textpack   [160];               /***/
 unsigned long  parcel      [10];               /***/
						/***/  } commrec;

		typedef struct {                /***/
	  char	statis          ;               /***/
	  char	toplanet        ;               /***/
	  char	toqui           ;               /***/
	  char	fromplanet      ;               /***/
	  char	fromqui     [10];               /***/
	  char	proportion  [10];               /***/
 unsigned long	returnval       ;               /***/
 unsigned long	unit        [10];               /***/
						/***/  } grparec;

		typedef struct {                /***/
	  char	empire  [10][25];               /***/
						/***/  } contrec;

		typedef struct {                /***/
	  char	empire          ;       	/***/
	  char	player          ;       	/***/
	  char	statis          ;       	/***/
	  char  morale          ;	     	/***/
	  char  approval        ;	     	/***/
 unsigned long	object      [10];       	/***/
						/***/  } battrec;

		typedef struct {                /***/
 unsigned long  relation    [26];               /***/
 unsigned long  object      [10];               /***/
 unsigned long  area        [10];		/***/
						/***/  } mntnrec;

		typedef struct {                /***/
 unsigned long  object      [20];               /***/
 unsigned long  area        [20];		/***/
						/***/  } inflrec;

		typedef struct {                /***/
 unsigned long  serial;                         /***/
 unsigned char  name        [80];       	/***/
						/***/  } registration;

	typedef struct {                        /***/
	   unsigned long parameter[21];         /***/  // 0/1 BBs/Game
			char directory[80];         /***/  // 0-PCBoard
						/***/  } configrec;

		typedef struct {                /***/
	  char  letter[LETTERS__]     ;         /***/
	  char  word    [WORDS__] [10];       	/***/
	  char  string[STRINGS__] [40];       	/***/
	  char  line    [LINES__] [80];       	/***/
						/***/  } langrec;

typedef struct indx{
   byte com;    //4
   byte baud;   //38.4
   byte mode;   //8-n-1
   byte ansi;   //ansi
   byte hndshk; //no handshake
   byte lf;     //no linefeed
   byte echo;   //no local echo
   }indxrec;

/***************************************************************************/
/***************************************************************************/

#ifdef UNDEFINED
  indxrec indx = { 3, 2, 0, 1, 0, 0, 0 };
  interrec inter;
  specrec special;
  saverec savedata;
  grparec interattack[10];
  userrec player[27];
  battrec warzone[50];
  commrec segment;
  contrec empire;
  mntnrec maint;
  inflrec inflation;
  inflrec total;
  inflrec remaining;
  configrec config;
  langrec _____lang;

 char __r(int mod);
 char *__language(int mode, int mod);
 void __errormessage(int __ens__, char __enm__[10]);
 void __loadconfiguration(void);
 void __saveconfiguration(void);

  unsigned long price,max,buy,val,_inf_1,_inf_2;
  char _typo=0,__depeche=0,__empire=0,__minon=1,__theman=0,jones=0,cheat=0,__laboum=0,warsub=5;
  char ins[160],intra[41],intrav[10][15],yen[40],additional,bbsinkey,result,res,__currentlanguage=0,UserName[40];
  void space(int mod);
  void adjust(int mod);

  int statis,cyc,cyc2,cyc3,cyc4,cyc5,thisuserno=26,thisempire=0,thisplanet=0,inuser,bbsexit=1,__rc=10,__rc2=7,statis_amb=0,statis_dev=0;
  unsigned long develop,recover,terraform,detox;
  FILE *stream,*__dxxfile;
  unsigned long __outqty(int _y,int _i,unsigned long _z,unsigned long _t,unsigned long _l,unsigned long _d,int autt,int autre);
  void _dotak(unsigned long at,unsigned long ap,unsigned long a1,unsigned long a2,unsigned long a3,unsigned long a4,unsigned long a5,unsigned long _ins,unsigned long _ins3,unsigned long _tot3);
  void _detak(unsigned long at,unsigned long ap,unsigned long a1,unsigned long a2,unsigned long a3,unsigned long a4,unsigned long a5,unsigned long _ins,unsigned long _ins3,unsigned long _tot2);
  unsigned long __outta(int _t,int _n,int _z,unsigned long _i,unsigned long _m);
  void sewage(void);
  void __localfrench(void);
  char __ratepercent(int perc);
  void __matrix(char matrix[20]);
  void mpl(int modmpl);
  void locmpl(int modmpl);
  void homeroll(int awar, int dwar);
  void warroll(int awar, int dwar);
  void __receive(void);
  void __send(void);
  void __transmit(void);
  void __resetlanguage(void);
  void __resetlanguage_1(void);
  void __resetlanguage_2(void);
  void ___empire(int newter);
  char __select(int phrase);
  void __header(int phrase);
  char *_parsemoney(unsigned long mod);
  void __readnew(char a, char b);
  char *__NEWFILE__(char a, char b);
  void __log(char ins4[160],char a,char b);
  void __readlog(char day, char month, int year);
  void __scoreit(void);
  void IPscores(void);
  void warscores(void);
  void allscores(void);
  void warzoneit(int mode);
  void selectempire(int openings[10]);
  void __loadgame(void);
  void _loadgame(void);
  void __savegame(void);
  void _savegame(void);
  void bank(void);
  void invest(void);
  void palais(void);
  void centre(void);
  void news(void);
  void scores(void);
  void abdicate(void);
  void intercontinnental(void);
  void setproduction(void);
  void keyhit(void);
  void ratings(void);
  void population(void);
  void corrupt(void);
  void raid(void);
  void attack(void);
  void nuclear(void);
  void implant(void);
  void coup(void);
  char *_dinput(int mode);
  void production(void);
  void doinflation(void);
  void inflationreport(void);
  void paybills(void);
  void displayrelations(int mod);
  void playgame(void);
  void menu_initiate(void);
  void menu_sysop(void);
  void menu_spending(void);
  void menu_territory(void);
  void menu_sabo(void);
  void menu_selling(void);
  void menu_selling2(void);
  void menu_attack(void);
  void menu_diplomacy(void);
  void menu_1(void);
  void menu_2(void);
  void menu_3(void);
  void menu_4(void);
  void menu_5(void);
  char __menu(char menufile[20]);
  void __help(char menufile[40]);
  void __help2(char menufile[40]);
  void backspace(void);
  void checkhot(void);
  int getkey(void);
  void helloworld(void);
  void __mess(int x);
  void bp(char *registration_string, unsigned int security_code);
  unsigned long rcount=0;
  char registeredxx;
  char registered_name[201];
  void notdone(void);
  void mustregister(void);
  void registerme(void);
  void nl(void);
  void pause(void);
  void __BOX__(int mod);
  void checkkey(void);
  void titlescreen(void);
  void checkstatus(void);
  void menu_main(void);
  void displaystatus(void);
  void wrong(void);
  void tolocal(void);
  void wongame(void);
  void wingame(void);
  void writeBKD(void);
  void lastquote(void);
  void detectsave(void);
  void detectwin(void);
  void detectversion(void);
  int getkey2(void);
  char yn(void);
  char ny(void);
  char yn2(void);
  char ny2(void);
  unsigned long _proc(unsigned long x, unsigned long y);
  unsigned long y2(unsigned long x, unsigned long y);


  void newplayer(int mod);
  void savegame(void);
  void loadgame(void);
  void __NEW__main(void);
  void __CNV__main(void);
  void __DAY__main(void);
  void __SET__main(void);
  void __RST__main(void);
  void __REG__main(void);
  void __PCB__main(void);
  void __MNT__main(void);
  extern int registered;
#else

/***************************************************************************/
/***************************************************************************/

  extern indxrec indx;
  extern interrec inter;
  extern specrec special;
  extern saverec savedata;
  extern userrec player[27];
  extern battrec warzone[50];
  extern commrec segment;
  extern contrec empire;
  extern mntnrec maint;
  extern inflrec inflation;
  extern inflrec total;
  extern inflrec remaining;
  extern grparec interattack[10];
  extern configrec config;
  extern langrec _____lang;

 extern char __r(int mod);
 extern char *__language(int mode, int mod);
 extern void __errormessage(int __ens__, char __enm__[10]);
 extern void __loadconfiguration(void);
 extern void __saveconfiguration(void);

  extern unsigned long price,max,buy,val,_inf_1,_inf_2;
  extern char _typo,__depeche,__empire,__minon,__theman,jones,cheat,__laboum,warsub;
  extern char ins[160],intra[41],intrav[10][15],yen[40],additional,bbsinkey,result,res,__currentlanguage,UserName[40];
  extern void space(int mod);
  extern void adjust(int mod);

  extern int statis,cyc,cyc2,cyc3,cyc4,cyc5,thisuserno,thisempire,thisplanet,inuser,bbsexit,__rc,__rc2,statis_amb,statis_dev;
  extern unsigned long develop,recover,terraform,detox;
  extern FILE *stream,*__dxxfile;
  extern unsigned long __outqty(int _y,int _i,unsigned long _z,unsigned long _t,unsigned long _l,unsigned long _d,int autt,int autre);
  extern void _dotak(unsigned long at,unsigned long ap,unsigned long a1,unsigned long a2,unsigned long a3,unsigned long a4,unsigned long a5,unsigned long _ins,unsigned long _ins3,unsigned long _tot3);
  extern void _detak(unsigned long at,unsigned long ap,unsigned long a1,unsigned long a2,unsigned long a3,unsigned long a4,unsigned long a5,unsigned long _ins,unsigned long _ins3,unsigned long _tot2);
  extern unsigned long __outta(int _t,int _n,int _z,unsigned long _i,unsigned long _m);
  extern void sewage(void);
  extern void __localfrench(void);
  extern char __ratepercent(int perc);
  extern void __matrix(char matrix[20]);
  extern void mpl(int modmpl);
  extern void locmpl(int modmpl);
  extern void homeroll(int awar, int dwar);
  extern void warroll(int awar, int dwar);
  extern void __transmit(void);
  extern void __receive(void);
  extern void __send(void);
  extern void __resetlanguage(void);
  extern void __resetlanguage_1(void);
  extern void __resetlanguage_2(void);
  extern void ___empire(int newter);
  extern char __select(int phrase);
  extern void __header(int phrase);
  extern char *_parsemoney(unsigned long mod);
  extern void __readnew(char a, char b);
  extern char *__NEWFILE__(char a, char b);
  extern void __log(char ins4[160],char a,char b);
  extern void __readlog(char day, char month, int year);
  extern void __loadgame(void);
  extern void _loadgame(void);
  extern void __savegame(void);
  extern void _savegame(void);
  extern void __scoreit(void);
  extern void IPscores(void);
  extern void warscores(void);
  extern void allscores(void);
  extern void warzoneit(int mode);
  extern void selectempire(int openings[10]);
  extern void bank(void);
  extern void invest(void);
  extern void palais(void);
  extern void centre(void);
  extern void news(void);
  extern void scores(void);
  extern void abdicate(void);
  extern void intercontinnental(void);
  extern void setproduction(void);
  extern void keyhit(void);
  extern void ratings(void);
  extern void population(void);
  extern void corrupt(void);
  extern void raid(void);
  extern void attack(void);
  extern void nuclear(void);
  extern void implant(void);
  extern void coup(void);
  extern void production(void);
  extern char *_dinput(int mode);
  extern void menu_initiate(void);
  extern void doinflation(void);
  extern void inflationreport(void);
  extern void paybills(void);
  extern void displayrelations(int mod);
  extern void playgame(void);
  extern void menu_sysop(void);
  extern char __menu(char menufile[20]);
  extern void __help(char menufile[40]);
  extern void __help2(char menufile[40]);
  extern void menu_spending(void);
  extern void menu_territory(void);
  extern void menu_sabo(void);
  extern void menu_selling(void);
  extern void menu_selling2(void);
  extern void menu_attack(void);
  extern void menu_diplomacy(void);
  extern void menu_1(void);
  extern void menu_2(void);
  extern void menu_3(void);
  extern void menu_4(void);
  extern void menu_5(void);
  extern void backspace(void);
  extern void checkhot(void);
  extern int getkey(void);
  extern void helloworld(void);
  extern void __mess(int x);
  extern void bp(char *registration_string, unsigned int security_code);
  extern unsigned long rcount;
  extern char registeredxx;
  extern char registered_name[201];
  extern void notdone(void);
  extern void mustregister(void);
  extern void registerme(void);
  extern void nl(void);
  extern void pause(void);
  extern void __BOX__(int mod);
  extern void checkkey(void);
  extern void titlescreen(void);
  extern void checkstatus(void);
  extern void menu_main(void);
  extern void displaystatus(void);
  extern void wrong(void);
  extern void tolocal(void);
  extern void wongame(void);
  extern void wingame(void);
  extern void writeBKD(void);
  extern void lastquote(void);
  extern void detectsave(void);
  extern void detectwin(void);
  extern void detectversion(void);
  extern int getkey2(void);
  extern char yn(void);
  extern char ny(void);
  extern char ny2(void);
  extern unsigned long _proc(unsigned long x, unsigned long y);
  extern unsigned long y2(unsigned long x, unsigned long y);

  extern programname[4];
  extern filename[9];
  extern fullname[40];

  extern void newplayer(int mod);
  extern void savegame(void);
  extern void loadgame(void);
  extern void __NEW__main(void);
  extern void __CNV__main(void);
  extern void __DAY__main(void);
  extern void __SET__main(void);
  extern void __RST__main(void);
  extern void __REG__main(void);
  extern void __PCB__main(void);
  extern void __MNT__main(void);
  extern int registered;
  extern char __author[40];
  extern char __version[6];
  extern char __vspace[6];
  extern char __saveversion[6];
  extern char __vnew[6];
  extern char __vnewsp[6];
  extern char __vday[6];
  extern char __vdaysp[6];
  extern char __vcnv[6];
  extern char __vcnvsp[6];
  extern char __vkey[6];
  extern char __vkeysp[6];
  extern char __vlog[6];
  extern char __vlogsp[6];
  extern char __vset[6];
  extern char __vsetsp[6];
  extern char __WARFILE__[11];
  extern char __LOGFILE__[11];
  extern char __REGFILE__[11];
  extern char __DATFILE__[11];
  extern char __DXXFILE__[11];
  extern char __DYYFILE__[11];
  extern char __BKDFILE__[11];
  extern char __LNGFILE__[11];
  extern char __FRNFILE__[11];
  extern char __SAVFILE__[10][11];
  extern char __CFGFILE__[11];
  extern char __SPCFILE__[11];
  extern char __SYNFILE__[11];
  extern char __TITLE__  [2][13];
  extern char __TITLE1__ [2][13];
  extern char __TITLE2__ [2][13];
#endif

/***************************************************************************/
/***************************************************************************/

#ifdef DATAMODULE
#endif

