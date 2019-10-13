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
#define PRINTERNOTHERE    // Allow Printer Spooling
#define ENCRYPTON         // Encryption Mode
#define DISABLE_LAN       // Default Language Base
#define DISABLE_LANGUAGE  // Save/Write/Etc Functions

void __retrieve(int inpcur2, int inpcur3){ char inpstr[81],temp2[81]; int inpcot,inpcon,cyc509; unsigned long invent;
			fscanf(__dxxfile,"%1s",inpstr);
			inpcot=inpstr[0]-'0';invent=0;
			       if(inpcot==0) {
						fscanf(__dxxfile,"%2s",inpstr);
						inpcot=((inpstr[0]-'0')*10+(inpstr[1]-'0'));
						       if(inpcot== 1) invent=player[inpcur3].turns;
						  else if(inpcot== 2) invent=player[inpcur3].bullion;
						  else if(inpcot== 3) invent=player[inpcur3].bank;
						  else if(inpcot== 4) invent=player[inpcur3].population;
						  else if(inpcot== 5) invent=player[inpcur3].taxrate;
						  else if(inpcot== 6) invent=player[inpcur3].draftrate;
						  else if(inpcot== 7) invent=player[inpcur3].approval;
						  else if(inpcot== 8) invent=player[inpcur3].food;
						  else if(inpcot== 9) invent=player[inpcur3].morale;
						  else if(inpcot==10) invent=_inf_1;
						  else if(inpcot==11) invent=_inf_2;
						  else if(inpcot==12) invent=player[inpcur3].protection;
						  else if(inpcot==13) {for(cyc=0;cyc<10;cyc++)invent+=player[inpcur3].area[cyc];}
						  else if(inpcot==14) invent=player[inpcur3].investment;
					     }
			  else if(inpcot==1) invent=player[inpcur3].condition[inpcur2];
			  else if(inpcot==2) invent=player[inpcur3].area[inpcur2];
			  else if(inpcot==3) invent=player[inpcur3].efficiency[inpcur2];
			  else if(inpcot==4) invent=player[inpcur3].industry[inpcur2];
			  else if(inpcot==5) invent=player[inpcur3].military[inpcur2];
			  else if(inpcot==6) invent=player[inpcur3].fortress[inpcur2];
			  else if(inpcot==7) if(inpcur2==9)invent=100-player[inpcur3].gouvernment;else invent=player[inpcur3].gouvernment;
			  else if(inpcot==8) if(inpcur2==9)invent=100-player[inpcur3].biosphere;  else invent=player[inpcur3].biosphere;
			  else if(inpcot==9) invent=player[inpcur3].object[inpcur2];
			  sprintf(temp2,"%s",_parsemoney(invent));
			fscanf(__dxxfile,"%2s",inpstr);
			inpcot=((inpstr[0]-'0')*10+(inpstr[1]-'0'));
			inpcon=(strlen(temp2));
			cyc509=(inpcot-inpcon);
			space(cyc509);
			od_printf("%s",temp2);
}


void __matrix(char matrix[20]){
  char inpstr[81],temp[81],usemat[20],open_stop=1,to_printer=0,auto_pause=0,a_p=0;
  int inpcol,inpcur,eomatr,inpcot,inpcon,cyc509;
  od_clear_keybuffer();
   inpcot=strlen(usemat);usemat[inpcot+1]=0;eomatr=0;
   if(!FRENCH)sprintf(usemat,"û%sE",matrix);
   if(FRENCH) sprintf(usemat,"û%sF",matrix);
#ifdef ENCRYPTOFF
   if((__dxxfile=fopen(__DXXFILE__,"r"))==NULL){   od_printf("Unable to open %s (ATX)\n\rJ'ai ne peuv‚ pas ouvrer %s\n\n\r",__DXXFILE__);   od_exit(1,FALSE);}
#else
   if((__dxxfile=fopen(__DYYFILE__,"r"))==NULL){   od_printf("Unable to open %s (ATX)\n\rJ'ai ne peuv‚ pas ouvrer %s\n\n\r",__DYYFILE__);   od_exit(1,FALSE);}
#endif
    do{
      strset(inpstr,0);strset(temp,0);
      fgets(inpstr,80,__dxxfile);

	if(!strnicmp(inpstr,usemat,strlen(usemat)))
	  {
	    do{
	      fscanf(__dxxfile,"%1s",inpstr);
		if(inpstr[0]=='~')
		  {
		    fscanf(__dxxfile,"%4s",inpstr);
		    inpcur=(inpstr[1]-'0')*100+(inpstr[2]-'0')*10+(inpstr[3]-'0');
		      if(inpstr[0]=='i')__retrieve(inpcur,thisuserno);
		      else {od_printf("þ%cþ%dþ\n\r",inpstr[0],inpcur);sound(100);sleep(10);nosound();}
//		      if(inpstr[0]=='s') od_printf("%s",__language(String,inpcur));
//		      if(inpstr[0]=='l'){od_printf("%s",__language(Line,inpcur));od_printf("%s %d\n\n\r",matrix,inpcur);}
//		      if(inpstr[0]=='w') od_printf("%s",__language(Word,inpcur));
//		      if(inpstr[0]=='S'){
//			fscanf(__dxxfile,"%2s",inpstr);
//			inpcot=(inpstr[0]-'0')*10+(inpstr[1]-'0');
//			sprintf(temp,"%s",__language(String,inpcur));
//			inpcon=strlen(temp);
//			space(inpcot-inpcon);
//			od_printf("%s",temp);
//		      }
		  }
		else
		if(inpstr[0]=='^')
		  {
		    fscanf(__dxxfile,"%2s",inpstr);
		    inpcol=(inpstr[0]-'0')*10+(inpstr[1]-'0');
		    od_set_colour(inpcol,0);
		  }
		else if(inpstr[0]=='ü')
		       {
			 fscanf(__dxxfile,"%2s",inpstr);
			 inpcur=(inpstr[0]-'0')*10+(inpstr[1]-'0');
			 od_printf("%s",intrav[inpcur]);
		       }
		else if(inpstr[0]=='÷')
		       {
			 fscanf(__dxxfile,"%2s",inpstr);
			 inpcur=(inpstr[0]-'0')*10+(inpstr[1]-'0');
			 if(!yen[inpcur])
			   do{
			     fscanf(__dxxfile,"%1s",inpstr);
			   }while(inpstr[0]!='ù' && inpstr[0]!='þ');
		       }
		else if(inpstr[0]=='û'){
					nl();
					od_set_colour(15,0);
					space(40);
					delay(100);
				       }
#ifdef PRINTERHERE
		else if(inpstr[0]=='ù'){
					nl();
					if(auto_pause){
					  a_p++;
					  if(a_p>21)
					  {
					    od_set_colour(15,0);
					    od_printf(">\r");
					    getkey();
					    a_p=0;
					  }
					}
					bbsinkey=od_get_key(FALSE);
					if(bbsinkey!=0 && open_stop)eomatr=1;
					if(to_printer)fprintf(stdprn,"\n\r",inpstr);
				       }
#else
		else if(inpstr[0]=='ù'){
					nl();
					if(auto_pause){
					  a_p++;
					  if(a_p>21)
					  {
					    od_set_colour(15,0);
					    od_printf(">\r");
					    getkey();
					    a_p=0;
					  }
					}
					bbsinkey=od_get_key(FALSE);
					if(bbsinkey!=0 && open_stop)eomatr=1;
				       }
#endif
#ifdef PRINTERHERE
		else if(inpstr[0]=='ú'){space(1);if(to_printer)fprintf(stdprn," ",inpstr);}
		else if(inpstr[0]=='ì' && to_printer==0)to_printer=1;
		else if(inpstr[0]=='ì' && to_printer==1)to_printer=0;
		else if(inpstr[0]=='ž'){od_printf("]");if(to_printer)fprintf(stdprn,"]",inpstr);}
#else
		else if(inpstr[0]=='ì');
		else if(inpstr[0]=='ú')space(1);
		else if(inpstr[0]=='ž')od_printf("]");
#endif
		else if(inpstr[0]=='á')sleep(3);
		else if(inpstr[0]=='ï')od_printf("%s",UserName);
		else if(inpstr[0]=='æ')od_printf("%s",__version);
		else if(inpstr[0]=='')od_printf("%s",ins);
		else if(inpstr[0]=='ð')od_printf("%s",intra);
		else if(inpstr[0]=='î')od_printf("þ");
		else if(inpstr[0]=='ä')open_stop=0;
		else if(inpstr[0]=='ò' && !eomatr)od_clr_scr();
		else if(inpstr[0]=='ó' && !eomatr)od_exit(1,FALSE);
		else if(inpstr[0]=='ø' && !eomatr){getkey();od_clr_line();od_disp_str("\r         \r");}
		else if(inpstr[0]=='ø' &&  eomatr)delay(300);
		else if(inpstr[0]=='ñ' && !eomatr)eomatr=2;
		else if(inpstr[0]=='ñ' &&  eomatr)eomatr=1;
		else if(inpstr[0]=='þ' && !eomatr)eomatr=1;
		else if(inpstr[0]=='þ' &&  eomatr)delay(100);
		else if(inpstr[0]=='ë' && !eomatr)auto_pause=1;
		else
#ifdef ENCRYPTOFF
		od_printf("%s",inpstr);
#else
		  if(inpstr[0]>57+1 && inpstr[0]<154+1)
		    {
		      inpstr[0]-=1;
		      od_printf("%s",inpstr);
#ifdef PRINTERHERE
		      if(to_printer)fprintf(stdprn,"%s",inpstr);
#endif
		    }
		  else
		    {
		      od_printf("%s",inpstr);
#ifdef PRINTERHERE
		      if(to_printer)fprintf(stdprn,"%s",inpstr);
#endif
		    }
#endif
	    }while(!eomatr || eomatr==2);
	  }
    }while(!feof(__dxxfile));

    fclose(__dxxfile);
}









char *__language(int mode, int mod){
  char _fname[15];
  int __userhandle, bytes=0;

if(mode==99){__resetlanguage();mode=3;}

if(mode==13){
    __mess(6);
    __matrix("B-VENUEN");
/*
     nl();
     od_set_colour( 7,0);od_printf("%s v%s",fullname,__version);
     od_set_colour(15,0);od_printf(" þ ");
     od_set_colour( 7,0);od_printf("V.O.\n\r");
     od_set_colour( 7,0);od_printf("Programm‚ par %s\n\r",__author);
     nl();
*/
  res = __menu("LANGUAGE") - '0';
  if(res==1) FRENCH=1; else FRENCH=0;
  mode=4;
     nl();
     __matrix("CURSS");
//     od_set_colour(7,0);od_printf("%s",__language(String,115));
     if(config.parameter[8])__minon=yn();
     if(!config.parameter[8])__minon=ny();
     nl();
}

// if(ENGLISH) sprintf(_____lang.string[5],"Shareware");
// if(FRENCH)  sprintf(_____lang.string[5],"Shareware");
// if(ENGLISH) sprintf(_____lang.line[2],"(C) Copyright 1994 þ Laurence Maar þ No Fee May Be Charged For This Software");
// if(FRENCH)  sprintf(_____lang.line[2],"(C) Copyright 1994 þ Laurence Maar þ No Fee May Be Charged For This Software");

if(mode==String){
  if(mod>STRINGS__){od_printf("þ%dþ%dþ\n\n\r",mode,mod);sound(100);sleep(5);nosound();od_exit(0,FALSE);}
  return(_____lang.string[mod]);
}
if(mode==Word){
  if(mod>WORDS__){od_printf("þ%dþ%dþ\n\n\r",mode,mod);sound(100);sleep(5);nosound();od_exit(0,FALSE);}
  return(_____lang.word[mod]);
}

if(mode==Line){
  if(mod>LINES__){od_printf("þ%dþ%dþ\n\n\r",mode,mod);sound(100);sleep(5);nosound();od_exit(0,FALSE);}
  return(_____lang.line[mod]);
}

#ifdef ENABLE_LANGUAGE
if(mode==7){
     nl();
     od_set_colour(10,0);
     for(cyc=0;cyc<LINES__;cyc++){
       if(_____lang.line[cyc][0]==0)cyc=LINES__; else{
	 fprintf(stdprn,"%2d:%s\n\r",cyc,_____lang.line[cyc]);
	 od_printf("%2d:%s\n\r",cyc,_____lang.line[cyc]);
	 delay(15);
	 }
       }
     od_set_colour(11,0);
     for(cyc=0;cyc<STRINGS__;cyc++){
       if(_____lang.string[cyc][0]==0)cyc=STRINGS__; else{
	 fprintf(stdprn,"%2d:%s\n\r",cyc,_____lang.string[cyc]);
	 od_printf("%2d:%s\n\r",cyc,_____lang.string[cyc]);
	 delay(15);
	 }
       }
     fprintf(stdprn,"\f");
     od_set_colour(13,0);
     for(cyc=0;cyc<WORDS__;cyc++){
       if(_____lang.word[cyc][0]==0)cyc=WORDS__; else{
	 fprintf(stdprn,"%2d:%s\n\r",cyc,_____lang.word[cyc]);
	 od_printf("%2d:%s\n\r",cyc,_____lang.word[cyc]);
	 delay(15);
	 }
       }
     fprintf(stdprn,"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\r");
     od_set_colour(12,0);
     for(cyc=0;cyc<10;cyc++){
	 fprintf(stdprn,"%3d:%c\n\r",cyc,_____lang.letter[cyc]);
	 od_printf("%3d:%c\n\r",cyc,_____lang.letter[cyc]);
	 delay(15);
       }
       nl();
       nl();
   fprintf(stdprn,"\f");
   return 0;}
if(mode==3){
     if(ENGLISH){sprintf(_fname,__LNGFILE__);sound(1000);pause();nosound();}
     if(FRENCH) {sprintf(_fname,__FRNFILE__);sound(100);pause();nosound();}
    if ((__userhandle = open(_fname, O_WRONLY | O_BINARY | O_CREAT, S_IREAD | S_IWRITE)) == -1) __errormessage(10,_fname);
    if ((bytes = write(__userhandle, (void *)&_____lang, sizeof(langrec))) != sizeof(langrec)) __errormessage(11,_fname);
    close(__userhandle);
   return 0;}
#endif
if(mode==4){
     if(ENGLISH)sprintf(_fname,__LNGFILE__);
     if(FRENCH) sprintf(_fname,__FRNFILE__);
     if ((__userhandle=open(_fname, O_RDONLY | O_BINARY, S_IWRITE | S_IREAD)) == -1) __errormessage(12,_fname);
     if ((bytes = read(__userhandle, (void *)&_____lang, sizeof(langrec))) == -1) __errormessage(13,_fname);
     close(__userhandle);
   return 0;}
}


void __resetlanguage(void){
__resetlanguage_1();
__resetlanguage_2();
}

void checkkey(void)                                              /* Main program function */
   {
   FILE *fp;                           /* File pointer for REGISTER.KEY file */
   struct date d;
   getdate(&d);
   unsigned long supplied_yer;                       /* Key supplied by user */
   unsigned long supplied_mon;                       /* Key supplied by user */
   unsigned long correct_year;                       /* Key supplied by user */
   unsigned long correct_mont;                       /* Key supplied by user */
   unsigned long supplied_amb;                       /* Key supplied by user */
   unsigned long supplied_dev;                       /* Key supplied by user */
   unsigned long correct_amb;                        /* Key supplied by user */
   unsigned long correct_dev;                        /* Key supplied by user */
   unsigned long supplied_key;                       /* Key supplied by user */
   unsigned long correct_key;                    /* Correct registration key */

   if((fp=fopen(__REGFILE__,"r"))!=NULL)              /* Try to open file */
      {                                                     /* If successful */
      fgets(registered_name,200,fp);                  /* read name from file */
      if(registered_name[strlen(registered_name)-1]=='\n')
	 registered_name[strlen(registered_name)-1]='\0';

      fscanf(fp,"%lu",&supplied_key);                  /* read key from file */
      fscanf(fp,"%lu",&supplied_yer);                  /* read key from file */
      fscanf(fp,"%lu",&supplied_mon);                  /* read key from file */
      fscanf(fp,"%lu",&supplied_amb);                  /* read key from file */
      fscanf(fp,"%lu",&supplied_dev);                  /* read key from file */

      fclose(fp);                                              /* Close file */

      bp(registered_name,12111);        /* Calculate correct key */
      correct_key=rcount;

      if(correct_key==supplied_key)       /* Compare correct & supplied keys */
	 {                                          /* If they are identical */
	 registeredxx=1;           /* Then switch program into registered mode */
	 }
      }

   // Laurence Maar - October 12, 2019
   // This forces the game to always be registered
   registeredxx=1;
   statis=1;
   statis_amb=1;
   statis_dev=1;
   supplied_yer=1977*511;

   if(registeredxx==1){
     statis=1;                                   /* If registered mode */
     if(supplied_yer!=1977*511){
     correct_year=supplied_yer/511;
     correct_mont=supplied_mon/453;
     correct_amb=supplied_amb;
     correct_dev=supplied_dev;
     if(correct_amb==15*registered_name[0]+registered_name[1]+registered_name[2]+registered_name[3])statis_amb=1;
     if(correct_dev==17*registered_name[0]+registered_name[1]+registered_name[2]+registered_name[3])statis_dev=1;
     if(correct_year==d.da_year && correct_mont==d.da_mon)registeredxx=9;
     if(correct_year<1993 || correct_mont>12 || correct_mont<1) statis=0;
     if(correct_year<d.da_year || correct_year==d.da_year && correct_mont<d.da_mon)
       {
       statis=0;registeredxx=9;
       }
     }
   }

   // Laurence Maar - October 12, 2019
   // This forces the game to always be registered
   registeredxx=1;
   statis=1;
   statis_amb=1;
   statis_dev=1;
   supplied_yer=1977*511;
}

void bp(char *registration_string, unsigned int security_code){
char tempstring[201];int cyc;
    strset(tempstring,0);
      sprintf(tempstring,"%s",registration_string);
      for(cyc=0;cyc<strlen(tempstring);cyc++){
      rcount=rcount+tempstring[cyc]*security_code;
      }
    rcount+=12111;
}

void __resetlanguage_1(void){
#ifdef ENABLE_LAN
if(ENGLISH){
  sprintf(_____lang.letter,"YyNn");
  sprintf(_____lang.word[0],"Quit ");
  sprintf(_____lang.word[1],"Yes");
  sprintf(_____lang.word[2],"No");
  sprintf(_____lang.word[3],"Hangup");
  sprintf(_____lang.word[4],"Chat");
  sprintf(_____lang.word[5],"P");
  sprintf(_____lang.word[6],"au");
  sprintf(_____lang.word[7],"sed");
  sprintf(_____lang.word[8],"UNKNOWN");
  sprintf(_____lang.word[9],"Aborted ");
  sprintf(_____lang.word[10],"Month ");
  sprintf(_____lang.word[11],"Day ");
  sprintf(_____lang.word[12],"Year ");
  sprintf(_____lang.word[13],"continue");
  sprintf(_____lang.word[14],"You have");
  sprintf(_____lang.word[15],"bullion");
  sprintf(_____lang.word[16],"and");
  sprintf(_____lang.word[17],"turns");
  sprintf(_____lang.word[18],"million");
  sprintf(_____lang.word[19],"Send");
  sprintf(_____lang.word[20],"Fund");
  sprintf(_____lang.word[21],"PCB");
  sprintf(_____lang.word[22],"DAY");
  sprintf(_____lang.word[23],"Withdraw");
  sprintf(_____lang.word[24],"Deposit");
  sprintf(_____lang.word[25],"Purchase");
  sprintf(_____lang.word[26],"Sell");
  sprintf(_____lang.word[27],"EXPIRED!!");
  sprintf(_____lang.word[28],"Statis");
  sprintf(_____lang.word[29],"Money");
  sprintf(_____lang.word[30],"Members");
  sprintf(_____lang.word[31],"Home");
  sprintf(_____lang.word[32],"War");
  sprintf(_____lang.word[33],"DEAD");
  sprintf(_____lang.word[34],"Value");
  sprintf(_____lang.word[35],"Stat");
  sprintf(_____lang.word[36],"Name");
  sprintf(_____lang.word[37],"Upgrade");
  sprintf(_____lang.word[38],"Prob");
  sprintf(_____lang.word[39],"Level");
  sprintf(_____lang.word[40],"Repair");
  sprintf(_____lang.word[41],"militia");
  sprintf(_____lang.word[42],"supplies");
  sprintf(_____lang.word[43],"Bullion");
  sprintf(_____lang.word[44],"Deal?");
  sprintf(_____lang.word[45]," of ");
  sprintf(_____lang.word[46],"SETUP");
  sprintf(_____lang.word[47],"ATZ");
  sprintf(_____lang.word[48],"Name ");
  sprintf(_____lang.word[49],"is almost");         // is almost
  sprintf(_____lang.word[50],"est");               // est
  sprintf(_____lang.word[51]," lost ");
  sprintf(_____lang.word[52]," units.");
  sprintf(_____lang.word[53],"Enter ");
  sprintf(_____lang.word[54],"Ambiance");
  sprintf(_____lang.word[55],"Devior");
  sprintf(_____lang.word[56],"Tax: ");
  sprintf(_____lang.word[57],"Draft: ");
  sprintf(_____lang.word[58],"List");
  sprintf(_____lang.word[59],"Retreat? ");
/*
  sprintf(_____lang.word[60],"");
  sprintf(_____lang.word[61],"");
  sprintf(_____lang.word[62],"");
  sprintf(_____lang.word[63],"");
  sprintf(_____lang.word[64],"");
  sprintf(_____lang.word[65],"");
  sprintf(_____lang.word[66],"");
  sprintf(_____lang.word[67],"");
  sprintf(_____lang.word[68],"");
  sprintf(_____lang.word[69],"");
*/
  sprintf(_____lang.string[0],"Toggle Player Monitor Window");
  sprintf(_____lang.string[1],"Drop to BBS");
  sprintf(_____lang.string[2],"Program Information");
/*
  sprintf(_____lang.string[3],"Name your empire: ");
*/

  sprintf(_____lang.string[3],"Warzone forces have overtaken ");
  sprintf(_____lang.string[4],"Shareware");
  sprintf(_____lang.string[5],"Registered");
  sprintf(_____lang.string[6]," territories.");
  sprintf(_____lang.string[7],"Bullion: ");
  sprintf(_____lang.string[8]," has conquered the warzone.");
  sprintf(_____lang.string[9],"The bloodshed has ended!!!!!!!!!!!!!!!");

/*
  sprintf(_____lang.string[7],"Name already in use.");
  sprintf(_____lang.string[8],"Sorry, game full.");
  sprintf(_____lang.string[9],"Welcome to ");
*/
    sprintf(_____lang.string[10],"aided opposition forces!!!");
    sprintf(_____lang.string[11],"Opposition forces overrun ");
    sprintf(_____lang.string[12]," proposes a ");
    sprintf(_____lang.string[13],"Neutrality Agreement");
    sprintf(_____lang.string[14],"Peace Treaty");
    sprintf(_____lang.string[15],"Trooper Defense Pact");
    sprintf(_____lang.string[16],"Infantry Defense Pact");
    sprintf(_____lang.string[17],"Bomber Strike Defense Pact");
    sprintf(_____lang.string[18],"Mobilization Agreement");
    sprintf(_____lang.string[19],"Rapid Deployment Protection Act");

    sprintf(_____lang.string[20],"No relations");
/*  sprintf(_____lang.string[21],"n'Acceptez pas.");*/
    sprintf(_____lang.string[21],"Rioting citizens have overthrown ");
    sprintf(_____lang.string[22],"The warzone is overloaded, try later.");
    sprintf(_____lang.string[23],"1 day until deployment is complete.");
    sprintf(_____lang.string[24],"2 days until deployment is complete.");
    sprintf(_____lang.string[25],"Troops will deploy tonight by default.");
    sprintf(_____lang.string[26],"Rapid warzone auto-deployment begun.");
    sprintf(_____lang.string[27]," declared war on you!");
    sprintf(_____lang.string[28],"You must begin rapid deployment!!!!!");
    sprintf(_____lang.string[29],"Warzone overloaded, declare later.");

    sprintf(_____lang.string[30]," entered the warzone!");
    sprintf(_____lang.string[31],"You are currently: ");
    sprintf(_____lang.string[32],"Defending Homeland");
    sprintf(_____lang.string[33],"In The Warzone");
    sprintf(_____lang.string[34],"Invading Enemy");
    sprintf(_____lang.string[35],"Annexed");
   sprintf(_____lang.string[36],"Banked: ");
    sprintf(_____lang.string[37],"Population: ");
      sprintf(_____lang.string[38],"Million");
      sprintf(_____lang.string[39]," has conquered the warzone.");
      sprintf(_____lang.string[40],"The bloodshed has ended!!!!!!!!!!!!!!");
      sprintf(_____lang.string[41],"Approval: ");
      sprintf(_____lang.string[42],"Supplies: ");
  sprintf(_____lang.string[43],"Militia: ");
  sprintf(_____lang.string[44],"Morale: ");
  sprintf(_____lang.string[45],"Units");
   sprintf(_____lang.string[46],"Internal Affairs: ");
     sprintf(_____lang.string[47],"Security: ");
     sprintf(_____lang.string[48],"Punishment: ");
     sprintf(_____lang.string[49],"Enforcement: ");
     sprintf(_____lang.string[50],"Crime: ");

   sprintf(_____lang.string[51],"Military: ");
     sprintf(_____lang.string[52],"Terminators");
     sprintf(_____lang.string[53],"Launchers");
     sprintf(_____lang.string[54],"Bombers");
     sprintf(_____lang.string[55],"Tanks");
     sprintf(_____lang.string[56],"Transport");
     sprintf(_____lang.string[57],"Saboteur");
     sprintf(_____lang.string[58],"Territory");
     sprintf(_____lang.string[59],"Outposts");

    sprintf(_____lang.string[60],"Shipments Arrived in ");
    sprintf(_____lang.string[61]," was corrupted.");
    sprintf(_____lang.string[62],"Bombings were a success in ");
/*
  sprintf(_____lang.string[60],"Palaces");
  sprintf(_____lang.string[61],"Command Center: ");
    sprintf(_____lang.string[62],"Efficiency: ");
*/
    sprintf(_____lang.string[63],"Territories: ");
      sprintf(_____lang.string[64],"Barren");
      sprintf(_____lang.string[65],"Biosphere");
      sprintf(_____lang.string[66],"Commercial");
      sprintf(_____lang.string[67],"Disorder");
      sprintf(_____lang.string[68],"Fortress");
      sprintf(_____lang.string[69],"Government");
      sprintf(_____lang.string[70],"Industrial");
      sprintf(_____lang.string[71],"Military");
      sprintf(_____lang.string[72],"Residential");
      sprintf(_____lang.string[73],"Terraforming");
      sprintf(_____lang.string[74],"Wasteland");

    sprintf(_____lang.string[75]," was pushed back into home territory");
    sprintf(_____lang.string[76]," survived and escaped the brutality!!");
    sprintf(_____lang.string[77],"*****WARZONE UPDATE!!!*****");
    sprintf(_____lang.string[78]," was annihlated by the WARZONE!");
    sprintf(_____lang.string[79],"Loose Knit");
    sprintf(_____lang.string[80],"Stable");
    sprintf(_____lang.string[81],"Untouchable");
    sprintf(_____lang.string[82],"Frontline: ");

    sprintf(_____lang.string[83],"Purchase how many");
    sprintf(_____lang.string[84],"Insufficient bullion.");
    sprintf(_____lang.string[85],"Cannot be sold.");
    sprintf(_____lang.string[86],"Sell how many");
    sprintf(_____lang.string[87],"Nothing to sell.");
    sprintf(_____lang.string[88],"Inflation Levels");
    sprintf(_____lang.string[89],"Land value: ");

    sprintf(_____lang.string[90],"Continue? ");
    sprintf(_____lang.string[91],"Out of turns");
    sprintf(_____lang.string[92],"Militia");
    sprintf(_____lang.string[93],"Production");
    sprintf(_____lang.string[94]," forces crush "); //l'Argent
    sprintf(_____lang.string[95],"Supplies");
    sprintf(_____lang.string[96],"Upgrade Complete");
    sprintf(_____lang.string[97],"Upgrade Failed");
    sprintf(_____lang.string[98],"Palace Repaired");
    sprintf(_____lang.string[99],"earned");

    sprintf(_____lang.string[100],"produced");
    sprintf(_____lang.string[101],"manufactured");
    sprintf(_____lang.string[102],"trade");
    sprintf(_____lang.string[103],"territories");
    sprintf(_____lang.string[104],"Government efforts recruited");
    sprintf(_____lang.string[105],"Factory sales produced");
    sprintf(_____lang.string[106],"Factories manufactured");
    sprintf(_____lang.string[107],"Tax collectors produced");
    sprintf(_____lang.string[108]," holds back a massive attack by ");//supplies
    sprintf(_____lang.string[109],"Send to who: ");//milice

    sprintf(_____lang.string[110],"Accepted.");//tanks
    sprintf(_____lang.string[111],"Doing daily maintenance...");
    sprintf(_____lang.string[112],"Standing by...");
    sprintf(_____lang.string[113],"Done...");
    sprintf(_____lang.string[114],"Total empire production of");
    sprintf(_____lang.string[115],"Spinning cursor ");
    sprintf(_____lang.string[116],"Population increased ");
    sprintf(_____lang.string[117],"Population is at a standstill.");
    sprintf(_____lang.string[118],"Population decreased ");
    sprintf(_____lang.string[119],"Attack who: ");

    sprintf(_____lang.string[120]," denies surrender to rebels lead by ");
    sprintf(_____lang.string[121],"Opposition attacks were aided by ");
    sprintf(_____lang.string[122]," territories in disorder.");
    sprintf(_____lang.string[123],"Military surplus earned ");
    sprintf(_____lang.string[124],"Fortress surplus earned ");
    sprintf(_____lang.string[125],"Modify Production Levels ");
    sprintf(_____lang.string[126],"Industrial Production Totals:");
    sprintf(_____lang.string[127],"Military Production Totals:");
    sprintf(_____lang.string[128],"Fortress Production Totals:");
    sprintf(_____lang.string[129],"Troop wages total");

    sprintf(_____lang.string[130],"Pay troops");
    sprintf(_____lang.string[131],"Defense requires");
    sprintf(_____lang.string[132],"Military forces require");
    sprintf(_____lang.string[133],"Regional maintenance costs");
    sprintf(_____lang.string[134],"Installation maintenance costs");
    sprintf(_____lang.string[135],"Stabilizing discontent would cost");
    sprintf(_____lang.string[136],"Internal affairs asks");
    sprintf(_____lang.string[137],"Regional Development costs");
    sprintf(_____lang.string[138],"Terraforming requires");
    sprintf(_____lang.string[139],"Disorder causes");

    sprintf(_____lang.string[140]," in damage");
    sprintf(_____lang.string[141],"Wastelands need");
    sprintf(_____lang.string[142]," for detoxification");
    sprintf(_____lang.string[143],"Turns of protection ");
    sprintf(_____lang.string[144],"Logging in at ");
    sprintf(_____lang.string[145],"Please register me . . .");
/*
    sprintf(_____lang.string[146],"Default Language?");
    sprintf(_____lang.string[147],"0=English 1=French");
    sprintf(_____lang.string[148],"Select spinning cursor default");
    sprintf(_____lang.string[149],"First Interplanetary Bank of Tasmania");
*/
    sprintf(_____lang.string[146]," lead a strike against ");
    sprintf(_____lang.string[147]," launched a major attack at ");
    sprintf(_____lang.string[148]," continued a volley with ");
    sprintf(_____lang.string[149]," battled against ");

    sprintf(_____lang.string[150],"You have a balance of ");
    sprintf(_____lang.string[151],"Investments are worth ");
    sprintf(_____lang.string[152],"You lose ");
    sprintf(_____lang.string[153]," territory to opposition groups!");
    sprintf(_____lang.string[154],"Opposition bombings were widespread!");
    sprintf(_____lang.string[155],"You developed ");
    sprintf(_____lang.string[156],"Military forces seized ");
    sprintf(_____lang.string[157],"Terraforming was completed on ");
    sprintf(_____lang.string[158],"Detoxification produced ");
    sprintf(_____lang.string[159]," territories.");

    sprintf(_____lang.string[160]," holdings from opposition groups.");
    sprintf(_____lang.string[161]," usuable territories");
    sprintf(_____lang.string[162],"Interplanetary menu ");
    sprintf(_____lang.string[163],"Warzone menu ");
    sprintf(_____lang.string[164],"View all empire scores ");
    sprintf(_____lang.string[165],"View team scores ");
    sprintf(_____lang.string[166],"Designation");
    sprintf(_____lang.string[167],"Peace");
    sprintf(_____lang.string[168],"Coup d'Terre");
    sprintf(_____lang.string[169],"Wastelands");

    sprintf(_____lang.string[170],"Full-Scale War");
    sprintf(_____lang.string[171],"Declare membership to who (0-9)? [0] ");
    sprintf(_____lang.string[172],"Sorry, no more openings there.\n\r");
    sprintf(_____lang.string[173],"Sovreign Tasmania");
    sprintf(_____lang.string[174],"Independent");
    sprintf(_____lang.string[175],"You have selected an 'Independent' Team");
    sprintf(_____lang.string[176],"Designate your Team name:");
    sprintf(_____lang.string[177],"Select team: ");
    sprintf(_____lang.string[178],"Efficiency");
    sprintf(_____lang.string[179],"territories to designate.");

    sprintf(_____lang.string[180],"You lost ");
    sprintf(_____lang.string[181],"They lost ");
    sprintf(_____lang.string[182]," allied units had engaged.");
    sprintf(_____lang.string[183],"Designate how many ");
    sprintf(_____lang.string[184],"The people require");
    sprintf(_____lang.string[185],"It'll cost you ");
    sprintf(_____lang.string[186]," territories were nuked!");
    sprintf(_____lang.string[187],"Implant how many terminators ");
    sprintf(_____lang.string[188],"Terminator implants have been found!!!");
    sprintf(_____lang.string[189],"Planetary News Summary ]");

    sprintf(_____lang.string[190],"Abdicate? ");
    sprintf(_____lang.string[191],"Rioting citizens have overthrown ");
    sprintf(_____lang.string[192],"Empire News Summary ]");
    sprintf(_____lang.string[193],"thrashed you in battle!!!");
    sprintf(_____lang.string[194]," territories lost.");
    sprintf(_____lang.string[195],"You fended of a massive attack by ");
/*
    sprintf(_____lang.string[196],"New Tax Rate ");
    sprintf(_____lang.string[197],"New Draft Rate ");
    sprintf(_____lang.string[198],"aided opposition forces!!!");
    sprintf(_____lang.string[199],"Opposition forces overrun ");
*/
/*
    sprintf(_____lang.string[200]," proposes a ");
    sprintf(_____lang.string[201],"Neutrality Agreement");
    sprintf(_____lang.string[202],"Peace Treaty");
    sprintf(_____lang.string[203],"Trooper Defense Pact");
    sprintf(_____lang.string[204],"Infantry Defense Pact");
    sprintf(_____lang.string[205],"Bomber Strike Defense Pact");
    sprintf(_____lang.string[206],"Mobilization Agreement");
    sprintf(_____lang.string[207],"Rapid Deployment Protection Act");
    sprintf(_____lang.string[208],"No relations");
    sprintf(_____lang.string[209],"n'Acceptez pas.");

    sprintf(_____lang.string[210],"The warzone is overloaded, try later.");
    sprintf(_____lang.string[211],"1 day until deployment is complete.");
    sprintf(_____lang.string[212],"2 days until deployment is complete.");
    sprintf(_____lang.string[213],"Troops will deploy tonight by default.");
    sprintf(_____lang.string[214],"Rapid warzone auto-deployment begun.");
    sprintf(_____lang.string[215]," declared war on you!");
    sprintf(_____lang.string[216],"You must begin rapid deployment!!!!!");
    sprintf(_____lang.string[217],"Warzone overloaded, declare later.");
    sprintf(_____lang.string[218]," entered the warzone!");
    sprintf(_____lang.string[219],"You are currently: ");

    sprintf(_____lang.string[220],"Defending Homeland");
    sprintf(_____lang.string[221],"In The Warzone");
    sprintf(_____lang.string[222],"Invading Enemy");
    sprintf(_____lang.string[223],"Annexed");
*/
/*
    sprintf(_____lang.string[224],"*****");
    sprintf(_____lang.string[225],"years of Attack Immunity remain.");
    sprintf(_____lang.string[226],"Deploying Forces");
    sprintf(_____lang.string[227],"You have to join or declare war first!");
    sprintf(_____lang.string[228],"There's nothing to join!??!?!");
    sprintf(_____lang.string[229],"Modem Init Line for Interplanetary");
*/
/*
    sprintf(_____lang.string[230]," lead a strike against ");
    sprintf(_____lang.string[231]," launched a major attack at ");
    sprintf(_____lang.string[232]," continued a volley with ");
    sprintf(_____lang.string[233]," battled against ");
    sprintf(_____lang.string[234],"Your Sysop's 1 Year Registration ");
    sprintf(_____lang.string[235]," expired!");
    sprintf(_____lang.string[236],"Enter Serialle: ");
    sprintf(_____lang.string[237],"Enter Specification: ");
    sprintf(_____lang.string[238],"Enter Definition: ");
    sprintf(_____lang.string[239]," invaded the homeland of ");
*/
/*
    sprintf(_____lang.string[240],"Which empire: ");
    sprintf(_____lang.string[241],"Results will be available tommorrow\n\n\r");
    sprintf(_____lang.string[242],"You can only do so much.\n\n\r");
    sprintf(_____lang.string[243],"Mission Complete.\n\n\r");
    sprintf(_____lang.string[244],"Shipments Arrived in ");
    sprintf(_____lang.string[245]," was corrupted.");
    sprintf(_____lang.string[246],"Bombings were a success in ");
    sprintf(_____lang.string[247],"Sabotage operation failed.");
    sprintf(_____lang.string[248],"Your fragile empire cannot afford war.");
    sprintf(_____lang.string[249],"Besides, you are still in protection.");
*/
/*
    sprintf(_____lang.string[250],"Destination");
    sprintf(_____lang.string[251],"Planet ");
    sprintf(_____lang.string[252],"Empire ");
    sprintf(_____lang.string[253],"Select Planet: ");
    sprintf(_____lang.string[254],"Select Empire: ");
    sprintf(_____lang.string[255],"Planet Nonexistant");
    sprintf(_____lang.string[256],"All");
*/
/*
    sprintf(_____lang.string[257],"");
    sprintf(_____lang.string[258],"");
    sprintf(_____lang.string[259],"");
*/
  sprintf(_____lang.line[0],"1. Reserved ### þ 2. Reserved ### þ 3. Reserved DDMMYYYY\n\r");
/*
  sprintf(_____lang.line[0],"You are about to reset ");
  sprintf(_____lang.line[1],"Enter Directory Containing BBS Program (No Trailing Backslash)");
  sprintf(_____lang.line[3],"Enter Directory Containing THIS Program (No Trailing Backslash)");
  sprintf(_____lang.line[4],"       Thank your SysOp for registering me!");
  sprintf(_____lang.line[5],"Door Info File  : CHAIN.TXT/DOOR.SYS etc must be in current dir");
  sprintf(_____lang.line[6],"The version of the save file is obsolete.");
  sprintf(_____lang.line[7],"1. Reserved ### þ 2. Reserved ### þ 3. Reserved DDMMYYYY\n\r");

  sprintf(_____lang.line[ 8],"Your state of internal affairs are a disasterous.\n\r");
  sprintf(_____lang.line[ 9],"Chaos breeds within your internal affairs.\n\r");
  sprintf(_____lang.line[10],"Internal affairs are a laughable.\n\r");
  sprintf(_____lang.line[11],"The empire pitys your internal affairs.\n\r");
  sprintf(_____lang.line[12],"Internal affairs are a stable.\n\r");
  sprintf(_____lang.line[13],"Internal security is inpenatrable.\n\r");

  sprintf(_____lang.line[14],"Your militia has suicidally low morale.\n\r");
  sprintf(_____lang.line[15],"Your militia is on the verge of desertion.\n\r");
  sprintf(_____lang.line[16],"Your militia is incapable of defending your installations.\n\r");
  sprintf(_____lang.line[17],"Militia firepower lacks maintenance and funding.\n\r");
  sprintf(_____lang.line[18],"Local defense soldiers are content.\n\r");
  sprintf(_____lang.line[19],"Militia forces are very secure.\n\r");

  sprintf(_____lang.line[20],"Massive riots devastate your empire.\n\rYour empire crumbles!\n\r");
  sprintf(_____lang.line[21],"Riots erupt under your rule.\n\r");
  sprintf(_____lang.line[22],"Government opposition groups are emerging.\n\r");
  sprintf(_____lang.line[23],"You have failed as a leader.\n\rThe people want you dead.\n\r");
  sprintf(_____lang.line[24],"Your people are content under your rule.\n\r");
  sprintf(_____lang.line[25],"Your people worship your very name.\n\r");
  sprintf(_____lang.line[26],"Your empire has crumbled. Call back tommorow.\n\n\r");

  sprintf(_____lang.line[27],"The commonwealth would disapprove attacking a newly founded empire.");
*/
/*
  sprintf(_____lang.line[28],"");
  sprintf(_____lang.line[29],"");
*/
}
#endif
}

void __resetlanguage_2(void){
#ifdef ENABLE_LAN
if(FRENCH){
//  for(cyc=0;cyc<STRINGS__;cyc++)strset(_____lang.string[cyc],0);
//  for(cyc=0;cyc<WORDS__;cyc++)strset(_____lang.word[cyc],0);
//  for(cyc=0;cyc<LINES__;cyc++)strset(_____lang.line[cyc],0);
//  strset(_____lang.letter,0);
  sprintf(_____lang.letter,"OoNn");
  sprintf(_____lang.word[0],"Quitte ");
  sprintf(_____lang.word[1],"Oui");
  sprintf(_____lang.word[2],"Non");
  sprintf(_____lang.word[3],"Hangup");
  sprintf(_____lang.word[4],"Parle");
  sprintf(_____lang.word[5],"P");
  sprintf(_____lang.word[6],"au");
  sprintf(_____lang.word[7],"sed");
  sprintf(_____lang.word[8],"UNKNOWN");
  sprintf(_____lang.word[9],"Aborted ");
  sprintf(_____lang.word[10],"Mois ");
  sprintf(_____lang.word[11],"Jour ");
  sprintf(_____lang.word[12],"An ");
  sprintf(_____lang.word[13],"continuez");
  sprintf(_____lang.word[14],"Vous avez");
  sprintf(_____lang.word[15],"l'argent");
  sprintf(_____lang.word[16],"et");
  sprintf(_____lang.word[17],"turns");
  sprintf(_____lang.word[18],"million");
  sprintf(_____lang.word[19],"Envoyez");
  sprintf(_____lang.word[20],"Fondez");
  sprintf(_____lang.word[21],"PCB");
  sprintf(_____lang.word[22],"JOUR");
  sprintf(_____lang.word[23],"Retirez");
  sprintf(_____lang.word[24],"Deposez");
  sprintf(_____lang.word[25],"Achetez");
  sprintf(_____lang.word[26],"Vendez");
  sprintf(_____lang.word[27],"EXPIR�!");
  sprintf(_____lang.word[28],"Statis");
  sprintf(_____lang.word[29],"--$--");
  sprintf(_____lang.word[30],"Members");
  sprintf(_____lang.word[31],"Home");
  sprintf(_____lang.word[32],"War");
  sprintf(_____lang.word[33],"DEAD");
  sprintf(_____lang.word[34],"Value");
  sprintf(_____lang.word[35],"Stat");
  sprintf(_____lang.word[36],"s'appelle");
  sprintf(_____lang.word[37],"Upgrade");
  sprintf(_____lang.word[38],"Prob");
  sprintf(_____lang.word[39],"Level");
  sprintf(_____lang.word[40],"Repair");
  sprintf(_____lang.word[41],"milice");
  sprintf(_____lang.word[42],"supplies");
  sprintf(_____lang.word[43],"l'Argent");
  sprintf(_____lang.word[44],"d'Accord?");
  sprintf(_____lang.word[45]," d(e)'");
  sprintf(_____lang.word[46],"SETUP");
  sprintf(_____lang.word[47],"ATZ");
  sprintf(_____lang.word[48],"Nom ");
  sprintf(_____lang.word[49],"is almost");
  sprintf(_____lang.word[50],"est");
  sprintf(_____lang.word[51]," perdu ");
  sprintf(_____lang.word[52]," units.");
  sprintf(_____lang.word[53],"Entrez ");
  sprintf(_____lang.word[54],"Ambiance");
  sprintf(_____lang.word[55],"Devior");
  sprintf(_____lang.word[56],"Tax: ");
  sprintf(_____lang.word[57],"Draft: ");
  sprintf(_____lang.word[58],"List");
  sprintf(_____lang.word[59],"Retreat? ");
/*
  sprintf(_____lang.word[60],"");
  sprintf(_____lang.word[61],"");
  sprintf(_____lang.word[62],"");
  sprintf(_____lang.word[63],"");
  sprintf(_____lang.word[64],"");
  sprintf(_____lang.word[65],"");
  sprintf(_____lang.word[66],"");
  sprintf(_____lang.word[67],"");
  sprintf(_____lang.word[68],"");
  sprintf(_____lang.word[69],"");
*/
  sprintf(_____lang.string[0],"Toggle Player Monitor Window");
  sprintf(_____lang.string[1],"Hangup");
  sprintf(_____lang.string[2],"Renseignements de Programme");
/*
  sprintf(_____lang.string[3],"Coment s'appelle ta empire: ");
*/

  sprintf(_____lang.string[3],"Zone forces etait caputrent ");
  sprintf(_____lang.string[4],"Shareware");
  sprintf(_____lang.string[5],"Registr‚");
  sprintf(_____lang.string[6]," territoiries.");
  sprintf(_____lang.string[7],"Combien de l'argent: ");
  sprintf(_____lang.string[8]," … captur‚ la zone guerre.");
  sprintf(_____lang.string[9],"Le carnage est finis!!!!!!!!!!!");

    sprintf(_____lang.string[10],"a aid‚ l'opposition!");
    sprintf(_____lang.string[11],"l'Opposition captur‚ ");
    sprintf(_____lang.string[12]," propos‚ un ");
    sprintf(_____lang.string[13],"Trait‚ de Neutralit‚");
    sprintf(_____lang.string[14],"Trait‚ de Pacifiste");
    sprintf(_____lang.string[15],"D‚fense Soldat");
    sprintf(_____lang.string[16],"D‚fense Infanterie");
    sprintf(_____lang.string[17],"D‚fense Bombardier");
    sprintf(_____lang.string[18],"D‚fense de Mobiliser");
    sprintf(_____lang.string[19],"Pacte de D‚fense Plien");

    sprintf(_____lang.string[20],"Ne pas de rapport");
/*  sprintf(_____lang.string[21],"n'Acceptez pas.");*/
    sprintf(_____lang.string[21],"�meutiers captur‚ ");
    sprintf(_____lang.string[22],"La zone est plien.");
    sprintf(_____lang.string[23],"D‚ployer en 1 jour.");
    sprintf(_____lang.string[24],"D‚ployer en 2 jour.");
    sprintf(_____lang.string[25],"Soldats vais aller … la zone ce soir.");
    sprintf(_____lang.string[26],"La zone guerre … commenc‚.");
    sprintf(_____lang.string[27]," d‚clar‚ guerre … toi!");
    sprintf(_____lang.string[28],"Il faut que vouce commencez d‚ployer.");
    sprintf(_____lang.string[29],"La zone est plien!");

    sprintf(_____lang.string[30]," a entr‚ la Zone Guerre!");
    sprintf(_____lang.string[31],"Vous etes maintenant: ");
    sprintf(_____lang.string[32],"Defendez la territoire");
    sprintf(_____lang.string[33],"… la Zone Guerre");
    sprintf(_____lang.string[34],"Attaquez l'‚n‚mies");
    sprintf(_____lang.string[35],"a Annex‚");
   sprintf(_____lang.string[36],"en Banque: ");
    sprintf(_____lang.string[37],"Population: ");
      sprintf(_____lang.string[38],"Million");
      sprintf(_____lang.string[39]," has conquered the warzone.");
      sprintf(_____lang.string[40],"la Carnage est finis!!!!!!!!!!!!!!!");
      sprintf(_____lang.string[41],"Approval: ");
      sprintf(_____lang.string[42],"Supplies: ");
  sprintf(_____lang.string[43],"Milice: ");
  sprintf(_____lang.string[44],"Morale: ");
  sprintf(_____lang.string[45],"Units");
   sprintf(_____lang.string[46],"Internal Affairs: ");
     sprintf(_____lang.string[47],"Security: ");
     sprintf(_____lang.string[48],"Punishment: ");
     sprintf(_____lang.string[49],"Enforcement: ");
     sprintf(_____lang.string[50],"Crime: ");

   sprintf(_____lang.string[51],"Militaire: ");
     sprintf(_____lang.string[52],"Terminateurs");
     sprintf(_____lang.string[53],"Launchers");
     sprintf(_____lang.string[54],"Bombers");
     sprintf(_____lang.string[55],"Blind‚s");
     sprintf(_____lang.string[56],"Transport");
     sprintf(_____lang.string[57],"Saboteur");
     sprintf(_____lang.string[58],"Territoire");
     sprintf(_____lang.string[59],"Forteresse");

    sprintf(_____lang.string[60],"Cargaisons arriv‚ … ");
    sprintf(_____lang.string[61]," etait corrompu.");
    sprintf(_____lang.string[62],"Rbombarder … finis … ");
/*
  sprintf(_____lang.string[60],"Palais");
  sprintf(_____lang.string[61],"Centre d'Ordre: ");
    sprintf(_____lang.string[62],"Efficiency: ");
*/

    sprintf(_____lang.string[63],"Territoire: ");
      sprintf(_____lang.string[64],"Infertile");
      sprintf(_____lang.string[65],"BiosphŠre");
      sprintf(_____lang.string[66],"Commercial");
      sprintf(_____lang.string[67],"D‚sordre");
      sprintf(_____lang.string[68],"Fortress");
      sprintf(_____lang.string[69],"Gouvernement");
      sprintf(_____lang.string[70],"Industriel");
      sprintf(_____lang.string[71],"Militaire");
      sprintf(_____lang.string[72],"R‚sidentiel");
      sprintf(_____lang.string[73],"Terraforming");
      sprintf(_____lang.string[74],"Radioactifs");

    sprintf(_____lang.string[75]," was pushed back into home territory");
    sprintf(_____lang.string[76]," survived and escaped the brutality!!");
    sprintf(_____lang.string[77],"*****METTRE … JOUR!!!*****");
    sprintf(_____lang.string[78]," a annihil‚ … la Zone Guerre!");
/*
    sprintf(_____lang.string[75],"Crumbling");
    sprintf(_____lang.string[76],"Chaotique");
    sprintf(_____lang.string[77],"Tr‚s Unstable");
    sprintf(_____lang.string[78],"Unstable");
*/
    sprintf(_____lang.string[79],"Loose Knit");
    sprintf(_____lang.string[80],"Stable");
    sprintf(_____lang.string[81],"Untouchable");
    sprintf(_____lang.string[82],"La Front:  ");

    sprintf(_____lang.string[83],"Achetez combien");
    sprintf(_____lang.string[84],"Tu n'as pas de l'argent.");
    sprintf(_____lang.string[85],"Cannot be sold.");
    sprintf(_____lang.string[86],"Vendez combien");
    sprintf(_____lang.string[87],"Ne rien pour vendre.");
    sprintf(_____lang.string[88],"Gonflement");
    sprintf(_____lang.string[89],"Valuer de terre: ");

    sprintf(_____lang.string[90],"Continuez? ");
    sprintf(_____lang.string[91],"Tu n'as pas turns");
    sprintf(_____lang.string[92],"Milice");
    sprintf(_____lang.string[93],"Production");
    sprintf(_____lang.string[94]," forces ‚crasment "); //l'Argent
    sprintf(_____lang.string[95],"Vivres");
    sprintf(_____lang.string[96],"Upgrade Complete");
    sprintf(_____lang.string[97],"Upgrade Failed");
    sprintf(_____lang.string[98],"Palace Repaired");

    sprintf(_____lang.string[ 99],"revenu");
    sprintf(_____lang.string[100],"a produit");
    sprintf(_____lang.string[101],"a frabriqu‚");
    sprintf(_____lang.string[102],"commerce");
    sprintf(_____lang.string[103],"territoires");
    sprintf(_____lang.string[104],"Gouverenment a recrut‚");
    sprintf(_____lang.string[105],"Vendre de usine a produit");
    sprintf(_____lang.string[106],"Usines a produit");
    sprintf(_____lang.string[107],"Collectionneurs de tax a produit");
    sprintf(_____lang.string[108]," holds back a massive attack by ");//supplies
    sprintf(_____lang.string[109],"Send to who: ");//milice

    sprintf(_____lang.string[110],"Accepted.");//tanks
    sprintf(_____lang.string[111],"Doing daily maintenance...");
    sprintf(_____lang.string[112],"Standing by...");
    sprintf(_____lang.string[113],"Finis...");
    sprintf(_____lang.string[114],"Tout … productien d'empire");
    sprintf(_____lang.string[115],"Spinning cursor ");
    sprintf(_____lang.string[116],"Population increased ");
    sprintf(_____lang.string[117],"Population is at a standstill.");
    sprintf(_____lang.string[118],"Population decreased ");
    sprintf(_____lang.string[119],"Attack qui: ");
    sprintf(_____lang.string[120]," captur‚ rebelles de ");
    sprintf(_____lang.string[121],"Rebelle guerre aid‚ … ");
    sprintf(_____lang.string[122]," territoires en d‚sordre.");
    sprintf(_____lang.string[123],"Militaire surplus a produit ");
    sprintf(_____lang.string[124],"Fortress surplus a produit ");
    sprintf(_____lang.string[125],"Modify Levels de Productien ");
    sprintf(_____lang.string[126],"Production Industriel …:");
    sprintf(_____lang.string[127],"Tout … Productien de Militaire:");
    sprintf(_____lang.string[128],"Tout … Productien de Fortress:");
    sprintf(_____lang.string[129],"Soldat salaire …");

    sprintf(_____lang.string[130],"Paie soldats");
    sprintf(_____lang.string[131],"Defense requires");
    sprintf(_____lang.string[132],"Military forces require");
    sprintf(_____lang.string[133],"Regional maintenance est");
    sprintf(_____lang.string[134],"Installation maintenance est");
    sprintf(_____lang.string[135],"Stabilizing discontent would est");
    sprintf(_____lang.string[136],"Internal affairs est");
    sprintf(_____lang.string[137],"Regional Development est");
    sprintf(_____lang.string[138],"Terraforming requires");
    sprintf(_____lang.string[139],"D‚sordre causes");

    sprintf(_____lang.string[140]," en damage");
    sprintf(_____lang.string[141],"Wastelands faut");
    sprintf(_____lang.string[142]," for detoxification");
    sprintf(_____lang.string[143],"Turns of protection ");
    sprintf(_____lang.string[144],"Logging sur … ");
    sprintf(_____lang.string[145],"Registre moi s'il vous plaŒt");
/*
    sprintf(_____lang.string[146],"Default Langue?");
    sprintf(_____lang.string[147],"[0] Anglais þ [1] Fran‡ais");
    sprintf(_____lang.string[148],"Select spinning cursor default");
    sprintf(_____lang.string[149],"First Interplanetary Bank of Tasmania");
*/
    sprintf(_____lang.string[146]," a attaqu‚ ");
    sprintf(_____lang.string[147]," a attaqu‚ ");
    sprintf(_____lang.string[148]," a attaqu‚ ");
    sprintf(_____lang.string[149]," a attaqu‚ ");

    sprintf(_____lang.string[150],"Tu as un balance de ");
    sprintf(_____lang.string[151],"Investments ont worth ");
    sprintf(_____lang.string[152],"You lose ");
    sprintf(_____lang.string[153]," territoire to opposition groups!");
    sprintf(_____lang.string[154],"Opposition bombings were widespread!");
    sprintf(_____lang.string[155],"You developed ");
    sprintf(_____lang.string[156],"Military forces seized ");
    sprintf(_____lang.string[157],"Terraforming was completed on ");
    sprintf(_____lang.string[158],"Detoxification produced ");
    sprintf(_____lang.string[159]," territoires.");

    sprintf(_____lang.string[160]," holdings from opposition groups.");
    sprintf(_____lang.string[161]," usuable territoires");
    sprintf(_____lang.string[162],"Interplanetary menu ");
    sprintf(_____lang.string[163],"Warzone menu ");
    sprintf(_____lang.string[164],"View empire scores ");
    sprintf(_____lang.string[165],"View continnental scores ");
    sprintf(_____lang.string[166],"Designation");
    sprintf(_____lang.string[167],"Paix ");
    sprintf(_____lang.string[168],"Coup d'Terre");
    sprintf(_____lang.string[169],"Radioactifs");

    sprintf(_____lang.string[170],"Full-Scale War");
    sprintf(_____lang.string[171],"Declare membership to qui (0-9)? [0] ");
    sprintf(_____lang.string[172],"Sorry, no more openings there.\n\r");
    sprintf(_____lang.string[173],"Sovreign Tasmania");
    sprintf(_____lang.string[174],"Independent");
    sprintf(_____lang.string[175],"You have selected an 'Independent' Team");
    sprintf(_____lang.string[176],"Designate your Team name:");
    sprintf(_____lang.string[177],"Select team: ");
    sprintf(_____lang.string[178],"Efficiency");
    sprintf(_____lang.string[179],"territoires … designate.");

    sprintf(_____lang.string[180],"Vous perdu ");
    sprintf(_____lang.string[181],"Ils perdu ");
    sprintf(_____lang.string[182]," allied units … attaqu‚.");
    sprintf(_____lang.string[183],"Designate combien ");
    sprintf(_____lang.string[184],"The people faut");
    sprintf(_____lang.string[185],"C'est ");
    sprintf(_____lang.string[186]," territoires a nuk‚!");
    sprintf(_____lang.string[187],"Implant how many terminators ");
    sprintf(_____lang.string[188],"Terminator implants have been found!!!");
    sprintf(_____lang.string[189],"Planetary News Summary ]");

    sprintf(_____lang.string[190],"Abdicate? ");
    sprintf(_____lang.string[191],"Rioting citizens have overthrown ");
    sprintf(_____lang.string[192],"Empire News Summary ]");
    sprintf(_____lang.string[193],"thrashed you in battle!!!");
    sprintf(_____lang.string[194]," territoires perdu.");
    sprintf(_____lang.string[195],"Tu fended un attaque par ");
/*
    sprintf(_____lang.string[196],"New Tax Rate ");
    sprintf(_____lang.string[197],"New Draft Rate ");
    sprintf(_____lang.string[198],"aided opposition forces!!!");
    sprintf(_____lang.string[199],"Opposition forces overrun ");
*/
/*
    sprintf(_____lang.string[200]," proposes un ");
    sprintf(_____lang.string[201],"Neutrality Agreement");
    sprintf(_____lang.string[202],"Peace Treaty");
    sprintf(_____lang.string[203],"Soldat Defense Pact");
    sprintf(_____lang.string[204],"Infantry Defense Pact");
    sprintf(_____lang.string[205],"Bomber Strike Defense Pact");
    sprintf(_____lang.string[206],"Mobilization Agreement");
    sprintf(_____lang.string[207],"Rapid Deployment Protection Act");
    sprintf(_____lang.string[208],"No relations");
    sprintf(_____lang.string[209],"N'acceptez pas.");

    sprintf(_____lang.string[210],"The warzone is overloaded, try later.");
    sprintf(_____lang.string[211],"1 day until deployment is complete.");
    sprintf(_____lang.string[212],"2 days until deployment is complete.");
    sprintf(_____lang.string[213],"Troops will deploy tonight by default.");
    sprintf(_____lang.string[214],"Rapid warzone auto-deployment begun.");
    sprintf(_____lang.string[215]," declared war on you!");
    sprintf(_____lang.string[216],"You must begin rapid deployment!!!!!");
    sprintf(_____lang.string[217],"Warzone overloaded, declare later.");
    sprintf(_____lang.string[218]," entered the warzone!");
    sprintf(_____lang.string[219],"You are currently: ");

    sprintf(_____lang.string[220],"Defending Homeland");
    sprintf(_____lang.string[221],"In The Warzone");
    sprintf(_____lang.string[222],"Invading Enemy");
    sprintf(_____lang.string[223],"Annexed");
*/
/*
    sprintf(_____lang.string[224],"*****");
    sprintf(_____lang.string[225],"years of Attack Immunity remain.");
    sprintf(_____lang.string[226],"Deploying Forces");
    sprintf(_____lang.string[227],"You have to join or declare war first!");
    sprintf(_____lang.string[228],"There's nothing to join!??!?!");
    sprintf(_____lang.string[229],"Modem Init Line for Interplanetary");
*/
/*
    sprintf(_____lang.string[230]," lead a strike against ");
    sprintf(_____lang.string[231]," launched a major attack at ");
    sprintf(_____lang.string[232]," continued a volley with ");
    sprintf(_____lang.string[233]," battled against ");
    sprintf(_____lang.string[234],"Your Sysop's 1 Year Registration ");
    sprintf(_____lang.string[235]," expired!");
    sprintf(_____lang.string[236],"Entrez Serialle: ");
    sprintf(_____lang.string[237],"Entrez Specification: ");
    sprintf(_____lang.string[238],"Entrez Definition: ");
    sprintf(_____lang.string[239]," invaded the homeland of ");
*/
/*
    sprintf(_____lang.string[240],"Which empire: ");
    sprintf(_____lang.string[241],"Result will be available tommorrow\n\n\r");
    sprintf(_____lang.string[242],"You can only do so much.\n\n\r");
    sprintf(_____lang.string[243],"Mission Complete.\n\n\r");
    sprintf(_____lang.string[244],"Shipments Arrived in ");
    sprintf(_____lang.string[245]," was corrupted.");
    sprintf(_____lang.string[246],"Bombings were a success in ");
    sprintf(_____lang.string[247],"Sabotage operation failed.");
    sprintf(_____lang.string[248],"Your fragile empire cannot afford war.");
    sprintf(_____lang.string[249],"Besides, you are still in protection.");
*/
/*
    sprintf(_____lang.string[250],"Destination");
    sprintf(_____lang.string[251],"Planet ");
    sprintf(_____lang.string[252],"Empire ");
    sprintf(_____lang.string[253],"Select Planet: ");
    sprintf(_____lang.string[254],"Select Empire: ");
    sprintf(_____lang.string[255],"Planet Nonexistant");
    sprintf(_____lang.string[256],"Tout la monde");
*/
/*
    sprintf(_____lang.string[257],"");
    sprintf(_____lang.string[258],"");
    sprintf(_____lang.string[259],"");
*/
  sprintf(_____lang.line[0],"1. R‚serv‚ ### þ 2. R‚serv‚ ### þ 3. R‚serv‚ DDMMYYYY\n\r");
/*
  sprintf(_____lang.line[0],"Tu est about to reset ");
  sprintf(_____lang.line[1],"Entrez Directory Containing BBS Program (No Trailing Backslash)");
  sprintf(_____lang.line[3],"Entrez Directory Containing THIS Program (No Trailing Backslash)");
  sprintf(_____lang.line[4],"Envoyez un mot de remerciements pour registration!");
  sprintf(_____lang.line[5],"Door Info File  : CHAIN.TXT/DOOR.SYS etc must be in current dir");
  sprintf(_____lang.line[6],"The version of the save file is obsolete.");
  sprintf(_____lang.line[7],"1. Reserved ### þ 2. Reserved ### þ 3. Reserved DDMMYYYY\n\r");

  sprintf(_____lang.line[ 8],"Your state of internal affairs are a disasterous.\n\r");
  sprintf(_____lang.line[ 9],"Chaos breeds within your internal affairs.\n\r");
  sprintf(_____lang.line[10],"Internal affairs are a laughable.\n\r");
  sprintf(_____lang.line[11],"The empire pitys your internal affairs.\n\r");
  sprintf(_____lang.line[12],"Internal affairs are a stable.\n\r");
  sprintf(_____lang.line[13],"Internal security is inpenatrable.\n\r");

  sprintf(_____lang.line[14],"Your militia has suicidally low morale.\n\r");
  sprintf(_____lang.line[15],"Your militia is on the verge of desertion.\n\r");
  sprintf(_____lang.line[16],"Your militia is incapable of defending your installations.\n\r");
  sprintf(_____lang.line[17],"Militia firepower lacks maintenance and funding.\n\r");
  sprintf(_____lang.line[18],"Local defense soldiers are content.\n\r");
  sprintf(_____lang.line[19],"Militia forces are very secure.\n\r");

  sprintf(_____lang.line[20],"Massive riots devastate your empire.\n\rYour empire crumbles!\n\r");
  sprintf(_____lang.line[21],"Riots erupt under your rule.\n\r");
  sprintf(_____lang.line[22],"Government opposition groups are emerging.\n\r");
  sprintf(_____lang.line[23],"Tu as failed as a leader.\n\rThe people want you dead.\n\r");
  sprintf(_____lang.line[24],"Ta people are content under your rule.\n\r");
  sprintf(_____lang.line[25],"Tout la monde worship your very name.\n\r");
  sprintf(_____lang.line[26],"Ta empire has crumbled. Call back tommorow.\n\n\r");

  sprintf(_____lang.line[27],"The commonwealth would disapprove attacking a newly founded empire.");
*/
/*
  sprintf(_____lang.line[28],"");
  sprintf(_____lang.line[29],"");
*/
}
#endif
}
