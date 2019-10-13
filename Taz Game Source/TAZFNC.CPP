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




void accept(void){
  char ins2[80];
  ___empire(thisempire);
   cyc  = (ins[1]-'0')*10+ins[2]-'0';
   cyc2 = (ins[3]-'0')*10+ins[4]-'0';
   cyc3 = (ins[5]-'0')*10+ins[6]-'0';
   cyc4 = _P_.relation[cyc2];if(!cyc4)cyc4=8;
   ___empire(cyc2);
    od_set_colour(11,0);od_printf("%s",player[cyc3].empire);
    od_set_colour(3,0); od_printf("%s",__language(Word,45));
    od_set_colour(11,0);od_printf("%s",_E_[__empire]);
    od_set_colour(3,0); od_printf("%s%s\n\r[%s] "
    ,__language(String,12)
    ,__language(String,12+cyc)
    ,__language(String,12+cyc4));
  if(cyc>1){
    od_printf("%s ",__language(Word,44));
      if(ny()){
	__matrix("ACCPT");  //	od_printf("%s\n\r",__language(String,110));
	player[cyc3].relation[thisempire]=cyc;
	___empire(thisempire);_P_.relation[cyc2]=cyc;
	sprintf(ins2,"%s :: [%s]",_P_.empire,__language(String,12+cyc));
	__log(ins2,cyc2,cyc3);
      } else __matrix("NACCPT"); //od_printf("%s\n\r",__language(String,209));
  }  else {
	__matrix("ACCPT");  //	od_printf("%s\n\r",__language(String,110));
  player[cyc3].relation[thisempire]=cyc;
  ___empire(thisempire);_P_.relation[cyc2]=cyc; }
    __matrix("LINE70");//    for(cyc=0;cyc<70;cyc++)od_printf("Ä");    nl();
}










void colormess(void){
  cyc=(ins[1]-'0')*10+ins[2]-'0';
    if(ins[3]=='@')
      cyc2=1;
    else
      cyc2=0;
  od_set_colour(cyc,0);
  for(cyc=4;cyc<80;cyc++){
    od_printf("%c",ins[cyc]);
    if(ins[cyc]==0)
      cyc=80;
  }
  nl();
  if(cyc2){
    __matrix("LINE70");//    for(cyc=0;cyc<70;cyc++)od_printf("Ä");    nl();
  }
}



char *__NEWFILE__(char a,char b){
  sprintf(ins,"%s%02d%02d.DAT",filename,a,b);
  return(ins);
}

void __readnew(char a, char b){
  FILE *stream;int x[10];__NEWFILE__(a,b);
    stream=fopen(ins,"r+");
      __matrix("EMPNEWS");
//      od_set_colour(13,0);for(cyc=0;cyc<70;cyc++)od_printf("Ä");
//      od_printf("\r%s\n\r",__language(String,192));
      do{
	fscanf(stream,"%2s",ins);	x[2]=atoi(ins);
	fscanf(stream,"%2s",ins);	x[3]=atoi(ins);
	fscanf(stream,"%4s",ins);	x[4]=atoi(ins);
	fgets(ins,80,stream);
	if(ins[0]=='#' && x[2]>0)
	  accept();
	  else
	if(ins[0]=='@' && x[2]>0)
	  colormess();
	  else if(x[2]>0){
	od_set_colour(7,0);od_printf("%s\n\r",ins);
    __matrix("LINE70");//    for(cyc=0;cyc<70;cyc++)od_printf("Ä");    nl();
	}
      }while(!feof(stream));
    fclose(stream);
    pause();
__NEWFILE__(a,b);stream=fopen(ins,"w+");fclose(stream);
}










void __log(char ins4[160],char a,char b){
  FILE *stream;
  struct date d;
  getdate(&d);
      if(a==99)
	stream=fopen(__LOGFILE__,"a+");
      else
	{
	  __NEWFILE__(a,b);
	  stream=fopen(ins,"a+");
	}
	sprintf(ins,"%02d%02d%04d",d.da_day,d.da_mon,d.da_year);
	fprintf(stream,"%-8.8s%-80.80s",ins,ins4);
      fclose(stream);
}





void __readlog(char day, char month, int year){
  FILE *stream;
  int x[10];
    stream=fopen(__LOGFILE__,"r+");
    __matrix("PLANEWS");
      do{
	fscanf(stream,"%2s",ins);
				x[2]=atoi(ins);
	fscanf(stream,"%2s",ins);
				x[3]=atoi(ins);
	fscanf(stream,"%4s",ins);
				x[4]=atoi(ins);
	fgets(ins,80,stream);
	if(ins[0]=='@' && x[2]==day && x[3]==month && x[4]==year)
	  colormess();
	else
	if(x[2]==day && x[3]==month && x[4]==year){
	  if(ins[1]=='&' || ins[1]=='!')ins[1]='\b';
	  if(ins[0]=='!')
	    od_set_colour(3,0);
	  else
	  if(ins[0]=='&')
	    od_set_colour(11,0);
	  else
	    od_set_colour(7,0);
	  od_printf("%s\n\r",ins);
	  if(ins[0]!='&'){
    __matrix("LINE70-B");//    for(cyc=0;cyc<70;cyc++)od_printf("Ä");    nl();
	  }
	}
      }while(!feof(stream));
    fclose(stream);pause();
}







char *_dinput(int mode){
  char temp[80];int maxer=10;cyc=0;strset(ins,0);if(mode==2)maxer=2;
   od_set_colour(__rc,0);
    do {      ins[cyc]=0;
      do{
	ins[cyc]=od_get_key(FALSE);checkhot();
      }while(ins[cyc]==0);
	if(ins[cyc]==8 && cyc>0){backspace();ins[cyc]=0;cyc--;ins[cyc]=0;}
	else if(ins[cyc]==13){ins[cyc]=0;bbsexit=2;}
	else if(ins[cyc]=='?' && maxer==2)
	  {
	    od_printf("\n\n\r");
	    IPscores();
	    __header(253);
	    od_set_colour(__rc,0);
	    for(cyc5=0;cyc5<cyc;cyc5++)
	      od_printf("%c",ins[cyc5]);
	  }
	else if(ins[cyc]<=47 || ins[cyc]>=58);
	else if(cyc<maxer){od_printf("%c",ins[cyc]);cyc++;}
	else ins[cyc]=0;
	if(mode==1 && (ins[cyc-1]<=47 || ins[cyc-1]>=58))cyc--;
      if(cyc<0)cyc=0;
    } while (bbsexit!=2);
   bbsexit=1;sprintf(temp,"%s",ins);result=strlen(temp);
  return(temp);
}













unsigned long _proc(unsigned long x, unsigned long y){
  unsigned long xyz;char deux[80],trois[80],quatre[80],ins2[80];
  if(x>y)x=y;
  od_set_colour(9,0);od_printf("[");
	sprintf(quatre,"%s",_parsemoney(x));
  od_set_colour(11,0);od_printf("%s",quatre);
	sprintf(quatre,"%s",_parsemoney(y));
    if(x!=y && y!=0){  od_set_colour(9,0);od_printf(";");
      od_set_colour(D_CYAN,0);od_printf("%s",quatre);    }
	  od_set_colour(9,0);od_printf("]");
	  od_set_colour(9,0);od_printf("? ");
	  od_set_colour(__rc,0);  sprintf(ins,"%s",_dinput(1));
    if(strlen(ins)>9 && ins[0]>'4'){ins[0]='3';ins[1]='9';}
  xyz=atol(ins);
  sprintf(deux,"%lu",y);
  sprintf(trois,"%lu",xyz);
	if(xyz>y || strlen(trois)>strlen(deux))xyz=y;
	if(strlen(ins)<1)xyz=x;
  sprintf(ins,"%lu",xyz);
  for(cyc=0;cyc<result;cyc++)backspace();
  sprintf(ins2,"%s\n\r",_parsemoney(atol(ins)));
  od_printf("%s",ins2);
  od_set_colour(__rc2,0);
  return (atol(ins));
}

char *_parsemoney(unsigned long mod){
  int triplets=0,stlen=0,cyc65;char ins2[80],ins3[2],ins8[80];
    sprintf(ins8,"%lu",mod);
    stlen=strlen(ins8);
      while(stlen>3){
	if(stlen>3){
	  stlen-=3;
	  triplets++;
	}
      };
    sprintf(ins2,"");
    if(stlen>=1){sprintf(ins3,"%c",ins8[0]);strcat(ins2,ins3);}
    if(stlen>=2){sprintf(ins3,"%c",ins8[1]);strcat(ins2,ins3);}
    if(stlen>=3){sprintf(ins3,"%c",ins8[2]);strcat(ins2,ins3);}
    if(stlen>=0 && ENGLISH)strcat (ins2,",");
    if(stlen>=0 && FRENCH)strcat (ins2,".");
    for(cyc65=0;cyc65<triplets;cyc65++){
      sprintf(ins3,"%c",ins8[stlen+0+cyc65*3]);strcat(ins2,ins3);
      sprintf(ins3,"%c",ins8[stlen+1+cyc65*3]);strcat(ins2,ins3);
      sprintf(ins3,"%c",ins8[stlen+2+cyc65*3]);strcat(ins2,ins3);
      if(FRENCH)strcat(ins2,".");if(ENGLISH)strcat(ins2,",");}
    stlen=strlen(ins2);
    ins2[stlen-1]=0;
  return(ins2);
}









char __menu(char menufile[20]){
  FILE *_menufile;char res2=0,ins2[80],off[20],*endptr,c6,c7,menucomm[20][40],tnons,nons,typz,prcs,_header[40],menuline[81],menucommand[20],ccol,clen;int _functiens,c1,c2,c3,c4,c5,_default,percentile,cyc9;unsigned long prce[20],tote,infla;cyc5=0;
  od_clear_keybuffer();

  for(cyc9=0;cyc9<20;cyc9++) off[cyc9]=0;

   if(FRENCH){
     menufile[0]='F';
     menufile[1]='R';
     menufile[2]='N';}

   if((_menufile=fopen(__DATFILE__,"r"))==NULL){   od_printf("Unable to open %s (MENU)\n\rJ'ai ne peuv‚ pas ouvrer %s\n\n\r",__DATFILE__);   od_exit(1,FALSE);}
       do{
      strset(menuline,0);
      fgets(menuline,80,_menufile);cyc5=0;
	if(strnicmp(menuline,menufile,strlen(menufile))==0) {
	  fgets(menuline,80,_menufile);
  _functiens=(menuline[4]-'0')*10+(menuline[5]-'0');
  ccol=(menuline[0]-'0')*10+(menuline[1]-'0');
  clen=(menuline[2]-'0')*10+(menuline[3]-'0')+6;
  c1=(menuline[6]-'0')*10+(menuline[7]-'0');
  c2=(menuline[8]-'0')*10+(menuline[9]-'0');
  c3=(menuline[10]-'0')*10+(menuline[11]-'0');
  c4=(menuline[12]-'0')*10+(menuline[13]-'0');
  c5=(menuline[14]-'0')*10+(menuline[15]-'0');
  prcs=(menuline[16]-'0');
  typz=(menuline[17]-'0');
  nons=(menuline[18]-'0');
  tnons=(menuline[19]-'0');
  c6=(menuline[20]-'0')*10+(menuline[21]-'0');
  c7=(menuline[22]-'0')*10+(menuline[23]-'0');
  _default=(menuline[24]);

  fgets(menuline,80,_menufile);
  percentile=(menuline[0]-'0')*10+(menuline[1]-'0');

  fgets(menuline,80,_menufile);
  fgets(_header,80,_menufile);
  nl();
  od_set_colour(ccol,0);
  for(cyc=0;cyc<clen;cyc++)od_printf("Ä");
  od_printf("\rÄÄÄÄ");
      cyc3=strlen(_header);
      _header[cyc3-1]=0;
  od_set_colour(c5,0);od_printf("[");
  od_set_colour(c4,0);od_printf("%s",_header);
  od_set_colour(c5,0);od_printf("]");
  nl();
      for(cyc=0;cyc<_functiens;cyc++){
      menucommand[cyc]=menuline[cyc];
      }
	for(cyc=0;cyc<_functiens;cyc++){
	  fgets(menuline,80,_menufile);
	  if(menuline[0]=='@')off[cyc]=1; // Interior Debugging
	  if(menuline[0]=='#')off[cyc]=2; // Not Available
	  if(menuline[0]=='$')off[cyc]=3; // Interplanetary
      cyc3=strlen(menuline);
      menuline[cyc3-1]=0;
	  sprintf(menucomm[cyc],"%s",menuline);
	}
if(prcs){for(cyc=0;cyc<_functiens;cyc++){
	  fgets(menuline,80,_menufile);
      cyc3=strlen(menuline);
      menuline[cyc3-1]=0;
	  prce[cyc]=atol(menuline);
//	  prce[cyc]=strtoul(menuline, &endptr, 10);
	}}
	for(cyc=0;cyc<_functiens;cyc++){
if(off[cyc]==0){
if(menucommand[cyc]==32){
  od_set_colour(8,0);od_printf("    ");
} else {
	  od_set_colour(c1,0);od_printf("[");
	  od_set_colour(c2,0);od_printf("%c",menucommand[cyc]);
	  od_set_colour(c1,0);od_printf("] ");
}
	  od_set_colour(c3,0);
	  if(typz!=4)od_printf("%-17s ",menucomm[cyc]);
	  else       od_printf("%-28.28s ",menucomm[cyc]);
cyc2=_functiens-nons;
if(prcs){
	od_set_colour(c6,0);
if(cyc<cyc2){
	  infla=0;
	  if(typz==1 && cyc==7)	  		infla=inflation.object[19];
	  else if(typz==2 && cyc==7)   		infla=inflation.object[19]*.0005;
	  else if(typz==1 && cyc==8) 		infla=inflation.object[8];
	  else if(typz==2 && cyc==8) 		infla=inflation.object[8]*.03;
	  else if(typz==1 && cyc==10) 	   	infla=inflation.object[7];
	  else if(typz==1)             		infla=inflation.object[cyc];
	  else if(typz==2)             		infla=inflation.object[cyc]*.03;
	  else if(typz==6)              	infla=inflation.area[cyc];
		if(typz==1 && cyc==7)	  {prce[cyc]=1000+infla;infla=0;}
	  else  if(typz==2 && cyc==7)	  {prce[cyc]=(1000+infla)*.2;infla=0;}
	  else	if(typz==2)prce[cyc]*=.05;

	  sprintf(ins2,"%s",_parsemoney(prce[cyc]+infla));
//	  if(typz!=3)od_printf("%13lu",prce[cyc]+infla);
	  if(typz!=3 && typz!=7)od_printf("%13.13s",ins2);
	}
	else if(typz!=3 && typz!=7)space(13);

	od_set_colour(c7,0);
	  if(cyc==percentile && cyc!=0)
	    od_printf("%10d%%",_P_.condition[cyc]);

	  else if((typz==1 ||typz==2) && cyc==7){tote=0;
	    for(cyc3=0;cyc3<20;cyc3++)tote+=_P_.area[cyc3];
	    sprintf(ins2,"%s",_parsemoney(tote));
	    od_printf("%11.11s",ins2);
/*	    od_printf("%11lu",tote);*/}

	  else if((typz==1 || typz==2) && cyc==8){
	    sprintf(ins2,"%s",_parsemoney(_P_.object[8]));
	    od_printf("%11.11s",ins2);
/*	    od_printf("%11lu",_P_.object[8]);*/}

	  else if(typz==1 && cyc==10){
	    sprintf(ins2,"%s",_parsemoney(_P_.object[7]));
	    od_printf("%11.11s",ins2);
/*	    od_printf("%11lu",_P_.object[7]);*/}

	  else if((typz==6 || typz==3 || typz==7) && cyc<_functiens-tnons){
	    sprintf(ins2,"%s",_parsemoney(_P_.area[cyc]));
	    od_printf("%11.11s",ins2);
/*	    od_printf("%11lu",_P_.area[cyc]);*/}

	  else if((typz==1 || typz==2) && cyc<_functiens-tnons){
	    sprintf(ins2,"%s",_parsemoney(_P_.object[cyc]));
	    od_printf("%11.11s",ins2);
/*	    od_printf("%11lu",_P_.object[cyc]);*/}
}
	  nl();}
	res2=od_get_key(FALSE);
	if(res2==32)
	{
	  od_clear_keybuffer();
	  goto get8ous;
	}
	  }
	  do{
	  fgets(menuline,80,_menufile);
	    if(strnicmp(menuline,"##C",3)==0){
	      od_set_colour((menuline[3]-'0')*10+(menuline[4]-'0'),D_BLACK);
	      for(cyc9=0;cyc9<5;cyc9++)menuline[cyc9]=32;
	      }
	    if(strnicmp(menuline,"__END__",7)==0)
	      cyc5=1;
	    else
	  od_printf("%s\n\r",menuline);
	  }while(cyc5==0);
  od_set_colour(ccol,0);
  for(cyc=0;cyc<clen;cyc++)
  od_printf("Ä");
	}
       }while(feof(_menufile)==0);
get8ous:;
   fclose(_menufile);
nl();
    if(typz==1 || typz==2 || typz==3 || typz==6){
      od_set_colour(7,0);od_printf("%s ",__language(Word,14));sprintf(ins2,"%s",_parsemoney(_P_.bullion));
      od_set_colour(11,0);od_printf("%s",ins2);
      od_set_colour(7,0);od_printf(" %s",__language(Word,15));
	if(typz==1 || typz==2){
	  od_set_colour(7,0);od_printf(" %s ",__language(Word,16));
	  od_set_colour(11,0);od_printf("%d",_P_.turns);
	  od_set_colour(7,0);od_printf(" %s",__language(Word,17));
	}
      od_set_colour(7,0);od_printf(".");
	if(typz==3){
	  od_printf("\n\r%s",__language(String,89));sprintf(ins2,"%s",_parsemoney((inflation.object[19]*.0005+1000)*.2));
	  od_set_colour(11,0);od_printf("%s",ins2);}
	nl();
    }
    if(typz==7){
      sprintf(ins2,"%s",_parsemoney(max));
      od_set_colour(11,0);
      od_printf("%s ",ins2);
      od_set_colour(7,0);
      od_printf("%s",__language(String,179));
    nl();
    }
    if(typz==8){
      if(_P_.warzone!=100){
	od_set_colour(3,0);
	if(__W.statis==4)od_printf("%s",__language(String,23));
	else if(__W.statis==5)od_printf("%s",__language(String,24));
	else if(__W.statis==6)od_printf("%s",__language(String,25));
	else if(__W.statis==7)od_printf("%s",__language(String,28));
	else {
	  od_set_colour(12,0);
	  od_printf("%s",__language(String,31));
	  if(__W.statis==1)od_printf("%s",__language(String,34));
	  if(__W.statis==2)od_printf("%s",__language(String,33));
	  if(__W.statis==3)od_printf("%s",__language(String,32));
	}
	nl();
      }
    }
nl();
od_set_colour(14,0);      od_printf("[");
od_set_colour(12,0);      od_printf("%s",programname);
od_set_colour(14,0);      od_printf("] ");
  if(typz==9 && _P_.turns<1){_default='0';menucommand[0]='þ';}
  od_set_colour(7,0);od_printf("[");
  od_set_colour(15,0);od_printf("%c",_default);
  od_set_colour(7,0);od_printf("] ");
od_set_colour(D_CYAN,0);  od_printf(": ");
  cyc4=0;
    do{
//nosound();
      bbsinkey=getkey();
//sound(100);

//      od_printf("<<<%d>>> ",bbsinkey);

      result=toupper(bbsinkey);

//      od_printf("(%d)%d-%s [%d] --> ",_default,result,menucommand,_functiens);

	   if(result==13 || result==32) result=_default;
	   if(result=='û'){__matrix("BUGDOWN");od_send_file("TAZERR.NFO");}
	   if(result=='ü'){system("del tazerr.nfo");}
	   for(cyc=0;cyc<_functiens;cyc++)
	     if(menucommand[cyc]==result && off[cyc]==0)
	       {
		 od_set_colour(15,0);
		 od_printf("%s\n\n\r",menucomm[cyc]);
		 cyc4=1;
	       }

//      od_printf("%d ",result);

    }while(cyc4==0);
//nosound();
return(result);
}



void __help2(char menufile[40]){
  FILE *_menufile;
  char cyc16=0,res2=0,_header[40],menuline[81],menucommand[20],ccol,clen;
  int _functiens,c1,c2,c3,c4,c5,cyc9;cyc5=0;

   if(FRENCH){
     menufile[0]='F';
     menufile[1]='R';
     menufile[2]='N';}

   if((_menufile=fopen(__DATFILE__,"r"))==NULL){   od_printf("Unable to open %s\n\rJ'ai ne peuv‚ pas ouvrer %s\n\n\r",__DATFILE__);   od_exit(1,FALSE);}
       mark:;
      strset(menuline,0);
      fgets(menuline,80,_menufile);cyc5=0;
	if(strnicmp(menuline,menufile,strlen(menufile))==0) {

  strset(menuline,0);
  fgets(menuline,80,_menufile);
  c1=(menuline[0]-'0')*10+(menuline[1]-'0');
  c2=(menuline[2]-'0')*10+(menuline[3]-'0');

  strset(menuline,0);
  fgets(menuline,80,_menufile);
  cyc3=strlen(menuline);
  menuline[cyc3-1]=0;
  od_set_colour(c1,0);
  od_printf("\r%s\n\r",menuline);
  od_set_colour(c2,0);

	  do{
      strset(menuline,0);
	  fgets(menuline,80,_menufile);
	    if(strnicmp(menuline,"#C",2)==0){
	      od_set_colour((menuline[2]-'0')*10+(menuline[3]-'0'),D_BLACK);
	      menuline[0]=' '; menuline[1]='\b';
	      menuline[2]=' '; menuline[3]='\b';
	      }
	    if(strnicmp(menuline,"__END__",7)==0)
	      cyc5=1;
	    else{
      cyc3=strlen(menuline);
      menuline[cyc3-1]=0;
	  od_printf("%s\n\r",menuline);cyc16++;if(cyc16>20){cyc16=0;pause();od_set_colour(c2,0); cyc5=0;}}
	res2=od_get_key(FALSE);
	if(res2!=0)cyc5=1;
	  }while(cyc5==0);
   }
       if(feof(_menufile)==0)goto mark;
       fclose(_menufile);if(cyc16)pause();
}










void __header(int phrase){
/*
    od_set_colour( 9,0);od_printf("(");
    od_set_colour(11,0);
  if(phrase==177 || phrase==109)od_printf("0");
  else if(phrase==253)od_printf("1");
  else od_printf("A");
    od_set_colour( 3,0);od_printf("-");
    od_set_colour(11,0);
  if(phrase==177 || phrase==109)od_printf("9");
  else if(phrase==253)od_printf("50");
  else od_printf("Z");
if(phrase!=177 && phrase!=119 && phrase!=240 && phrase!=253){
    od_set_colour( 3,0);od_printf(",");
    od_set_colour(11,0);od_printf("*");
    od_set_colour( 3,0);od_printf("=");
    od_set_colour(11,0);od_printf("%s",__language(String,256));
}
    od_set_colour( 3,0);od_printf(",");
    od_set_colour(11,0);od_printf("?");
    od_set_colour( 3,0);od_printf("=");
    od_set_colour(11,0);od_printf("%s",__language(Word,58));
    od_set_colour( 9,0);od_printf(")");
    od_set_colour( 7,0);od_printf(" %s",__language(String,phrase));
*/

     if(phrase==109)__matrix("JHED109");
else if(phrase==119)__matrix("JHED119");
else if(phrase==177)__matrix("JHED177");
else if(phrase==240)__matrix("JHED240");
else if(phrase==253)__matrix("JHED253");
else __errormessage(99,"DXX-DYY");
}







char __select(int phrase){
  char olr,toggle[27],valid[27],temp[27],old=__empire;__matrix("VAITON");
      if(phrase==177 || phrase==109)
      {
	for(cyc=0;cyc<10;cyc++)
	{
	  total.object[cyc]=0;
	  ___empire(cyc);
	  for(cyc2=0;cyc2<26;cyc2++)
	  if(player[cyc2].statis>0) total.object[cyc]++;
	}
	___empire(thisempire);
      }
      for(cyc=0;cyc<26;cyc++)
	if(player[cyc].statis==2)
	  valid[cyc]=1;
	else
	  valid[cyc]=0;
    sewage();
    __header(phrase);
//      for(cyc=0;cyc<26;cyc++)
//	toggle[cyc]=0;
      strset(toggle,0);
      strset(temp,0);
      cyc=0;

      do{
	getkey();
	res=toupper(result);od_set_colour(15,0);
	  if(res=='*' && phrase!=119 && phrase!=177 && phrase!=109 && phrase!=240)
	  {
	    strset(temp,0);
	    for(cyc2=0;cyc2<cyc;cyc2++)backspace();
	    cyc=0;cyc3=0;
	    for(cyc2=0;cyc2<26;cyc2++)
	      if(valid[cyc2] && (cyc2!=thisuserno || cyc2==thisuserno && __empire!=thisempire))
	      {
		toggle[cyc2]=1;
		temp[cyc3]=cyc2+'A';
		od_printf("%c",temp[cyc3]);
		cyc3++;
	      }
	    cyc=cyc3;
	  }
	  else if(res=='*' && phrase==109)
	  {
	    __matrix("ALL");
//	    od_set_colour(15,0);
//	    od_printf("%s\n\r",__language(String,256));
	    return(99);
	  }
	  else if(res=='?')
	  {
	    if(phrase==177 || phrase==109)
	    {
	      nl();	olr=cyc;
	      scores();	cyc=olr;
	    } else {
	      nl();
	      __theman=1;
	      allscores();
	      __theman=0;
	    }
	    __header(phrase);
	    if(cyc)for(cyc3=0;cyc3<cyc;cyc3++)
	      od_printf("%c",temp[cyc3]);
	    ___empire(old);
	  }
	  else if(
	  res>='A' && res<='Z' &&
	  (res!=thisuserno+'A' || res==thisuserno+'A' && __empire!=thisempire) &&
	  (phrase==119 || phrase==240) ||
	  res>='0' && res<='9' &&
	  (res-'0'!=thisempire || res-'0'==thisempire &&
	  total.object[res-'0']>1) &&
	  (phrase==177 || phrase==109))
	  {
	    if(!toggle[res-'A'] && valid[res-'A'] &&
	      (phrase==119 || phrase==109 || phrase==240) ||
	      total.object[res-'0'] &&
	      (phrase==177))
	      {
		if(phrase!=119 && phrase!=177 && phrase!=109 && phrase!=240){
		  od_set_colour(15,0);
		  od_printf("%c",res);
		  temp[cyc]=res;
		  toggle[res-'A']=1;
		  cyc++;
		}
		if(phrase==119 || phrase==240){
		  od_set_colour(15,0);
		  temp[cyc]=res;
		  toggle[res-'A']=1;
		  od_printf("%s\n\r\n\r",player[res-'A'].empire);
		  return(res-'A');
		}
		if(phrase==177 || phrase==109){
		  od_set_colour(15,0);
		  ___empire(res-'0');
		  //loadgame();
		  od_printf("%s\n\r\n\r",_E_[__empire]);
		  ___empire(thisempire);
		  //loadgame();
		  return(res-'0');
		}
	      }
	    }
	    else if(res==8 && cyc){
	      cyc--;
	      toggle[temp[cyc]-'A']=0;
	      temp[cyc]=0;
	      backspace();
	    }
	    else if(res==13 && (phrase==119 || phrase==177 ||
				phrase==109 || phrase==240))
	    {
	      nl();
	      return(100);
	    }
	    else if(res==13 && !strlen(temp))
	    {
	      nl();
	      return(100);
	    }
	   else
	     if(res==13) {
	       sprintf(ins,"%s",temp);
	       bbsexit=2;
	     }
      }while(bbsexit!=2);
      nl();bbsexit=1;
return(0);
}

void checkstatus(void){
  char logname[13],in2[5],olddate[10],newdate[10];
  time_t t;
  struct date d;
    getdate(&d);
    sprintf(newdate,"%02d%02d%04d",d.da_day,d.da_mon,d.da_year);
      detectsave();
	if((stream = fopen(__SYNFILE__, "r+"))==NULL){
	  stream = fopen(__SYNFILE__, "w+");
	  fprintf(stream,"00000011111990");
	  fprintf(stream,"\n\r\n\r%s",__language(Line,0));
	  fclose(stream);
	}
	else
	  fclose(stream);
      stream = fopen(__SYNFILE__, "r+");
      fscanf(stream,"%3s",ins); // ReSerVeD
      fscanf(stream,"%3s",ins); // ReSerVeD
      fscanf(stream,"%8s",olddate);
      fclose(stream);
    stream = fopen(__SYNFILE__, "w+");
    fprintf(stream,"%03i",0);
    fprintf(stream,"%03i",0);
    fprintf(stream,"%8s",newdate);
    fprintf(stream,"\n\r\n\r%s",__language(Line,0));
    fclose(stream);
      if(strcmp(olddate,newdate)!=0 || price==1){
	  __matrix("VAITON");
	    __DAY__main();
	  sewage();
//	od_set_colour(11,D_BLACK);od_printf("\n\n\r þ ");od_set_colour( 3,D_BLACK);od_printf("%s\n\r",__language(String,111));
//	od_set_colour(11,D_BLACK);od_printf(" þ ");od_set_colour( 3,D_BLACK);od_printf("%s\n\r",__language(String,112));
//  	od_set_colour(11,D_BLACK);od_printf(" þ ");od_set_colour( 3,D_BLACK);od_printf("%s\n\n\r",__language(String,113));
//	pause();
      }
    srand((unsigned) time(&t));
    od_control.user_screen_length=999;
}

























