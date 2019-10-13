/***************************************************************************/
/*                                                                         */
/*     TAZLOCAL.EXE Ver 1.0                                                */
/*     TAZLOCAL.EXE Ver 1.0                                                */
/*     TAZLOCAL.EXE Ver 1.0                                                */
/*                                                                         */
/***************************************************************************/

#define UNDEFINED
#define NOOPEN
#include"install.h"
#include"..\taz\tazver.h"

void __RST__main2(int _force);







void NEWS_main(char ar[80]);
void NEWD_main(char ar[80]);
void NWDR_main(char ar[80]);
void INST_main(char ar[80]);

void MAIN_main(char ar[80]);
void MAIN_prnt(char ar[80]);

char _current[80];int aar=0,i78=0;











void main(int argc,char **argv){
FILE *iii;
char ar[80];
sprintf(ar,"%s",argv[0]);
int x=79;
sprintf(_current,"%s",argv[0]);
do {
 _current[x]=0;
 x--;
}while(_current[x]!='\\');
_current[x]=0;
clrscr();
system("TYPE TAZENN.NFO");
system("TYPE TAZFNN.NFO");
directvideo=0;

//	NEWS_main();
//	NEWD_main();
//	NWDR_main();
//	INST_main();
//	MAIN_main(ar);

if ((iii = fopen("TAZINS.NFO", "rt")) == NULL)
{
 INST_main(ar);
 NEWS_main(ar);
 NEWD_main(ar);

 iii = fopen("TAZINS.NFO", "w+");
 fclose(iii);
 i78=255;
} else {
 fclose(iii);
}

 MAIN_main(ar);

/*
  if(argc>1 && strnicmp(argv[1],"CONVE",5)==0) __CNV__main();   else
//if(argc>1 && strnicmp(argv[1],"RESET",5)==0) __RST__main2(0); else
//if(argc>1 && strnicmp(argv[1],"NOUVE",5)==0) __RST__main2(0); else
//if(argc>1 && strnicmp(argv[1],"FORCE",5)==0) __RST__main2(1); else
  if(argc>1 && strnicmp(argv[1],"RESET",5)==0)   NEWD_main(ar); else
  if(argc>1 && strnicmp(argv[1],"NOUVE",5)==0)   NEWD_main(ar); else
  if(argc>1 && strnicmp(argv[1],"FORCE",5)==0)   NEWD_main(ar); else
//if(argc>1 && strnicmp(argv[1],"SETUP",5)==0) __SET__main();   else
  if(argc>1 && strnicmp(argv[1],"SETUP",5)==0)   NEWS_main(ar); else
//if(argc>1 && strnicmp(argv[1],"REGIS",5)==0) __REG__main();   else
  if(argc>1 && strnicmp(argv[1],"REGIS",5)==0)   NWDR_main(ar); else
//if(argc>1 && strnicmp(argv[1],"FREG" ,4)==0) __REG__main();   else
  if(argc>1 && strnicmp(argv[1],"FREG" ,4)==0)   NWDR_main(ar); else
  if(argc>1 && strnicmp(argv[1],"UPGRA",5)==0)  {aar=1;INST_main(ar);} else
  INST_main(ar);
*/
}










/*
  fprintf(stdprn,"\n\r==============================================================================\n\r");
  fprintf(stdprn,"||  Maartian Enterprises  ||  1415 Valeview Dr.  ||  Diamond Bar, CA 91765  ||\n\r");
  fprintf(stdprn,"==============================================================================\n\n\r");

  fprintf(stdprn,"  Product     Description  Version  Type             Price/e   Qty    Total \n\r");
  fprintf(stdprn,"  LMSC     o  Smurf Combat v1.3 [Reg+Latest Ver]        $9    _____ x _____ \n\r");
  fprintf(stdprn,"  LMSCSRC  o  Smurf Combat v1.3 [Source 'C']           $29    _____ x _____ \n\r");

  fprintf(stdprn,"  TAZBBS   o  Tasmanian Strategical [Reg+Latest]   SALE:$9    _____ x _____ \n\r");
  fprintf(stdprn,"  TAZSRC   o  Tasmanian Strategical [Source 'C']      CALL    _____ x _____ \n\r");
  fprintf(stdprn,"  TAZNODE  o *Taz 'Infinity' Registration Offer        $38    _____ x _____ \n\r");
  fprintf(stdprn,"  TAZNODE  o *Taz MultiNode Official License            $5    _____ x _____ \n\r");
  fprintf(stdprn,"  TAZINTER o *Taz Inter-BBS Official License            $5    _____ x _____ \n\n\r");

  fprintf(stdprn,"  =====----->                                     SubTotals   _____   _____ \n\r");
  fprintf(stdprn,"  ->                30% OFF SUBTOTAL during Nov-Dec of 1993   VOID DUE 2 SALE\n\r");
  fprintf(stdprn,"  ->                20% OFF SUBTOTAL during Nov-Dec of 1994   VOID DUE 2 SALE\n\r");
  fprintf(stdprn,"  ->          Add $1 for RUSH service  (24 Hour processing)           _____ \n\r");
  fprintf(stdprn,"  ->                       Add $3 for Shipping and Handling           _____ \n\r");
  fprintf(stdprn,"  ->  Add $3 for Cont. America Orders Outside United States           _____ \n\r");
  fprintf(stdprn,"  ->  Add $7 for Over Sea Orders  (Outside N. & S. America)           _____ \n\r");
  fprintf(stdprn,"  =====----->                                        TOTALS   _____   _____ \n\n\r");

  fprintf(stdprn,"  Registration Name: _______________________________________________________\n\n\r");

  fprintf(stdprn,"  BBS Name: _______________________ BBS Network & Address: _______ Nodes: __\n\n\r");

  fprintf(stdprn,"  Voice Number: ___________________ BBS Number: ____________________________\n\n\r");

  fprintf(stdprn,"  Ship to: _________________________________________________________________\n\n\r");

  fprintf(stdprn,"           _________________________________________________________________\n\n\r");

  fprintf(stdprn,"  Comments: ________________________________________________________________\n\n\r");

  fprintf(stdprn,"            ________________________________________________________________\n\n\r");

  fprintf(stdprn,"            ________________________________________________________________\n\n\r");

  fprintf(stdprn,"            ________________________________________________________________\n\n\r");

  fprintf(stdprn,"            ____________________________________ [ ] Withhold name if quoted\n\n\r");

  fprintf(stdprn,"==============================================================================\n\r");
  fprintf(stdprn,"Cash, Bank Money Orders, or Checks MUST be issued for U.S. CURRENCY.          \n\r");
  fprintf(stdprn,"\n\r");
  fprintf(stdprn,"Check/M.O. MUST be addressed to 'CASH' or 'Cecelia C. Maar' and depositable in\n\r");
  fprintf(stdprn,"any major U.S. bank.\n\r");
  fprintf(stdprn,"\n\r");
  fprintf(stdprn,"Any check addressed to an unauthorized person will be returned.               \n\r");
  fprintf(stdprn,"==============================================================================\n\r");
  fprintf(stdprn,"The author may be reached at 1-909-861-1616 in California, or if no answer, he\n\r");
  fprintf(stdprn,"can also be reached at work at 1-818-792-9988. Collect calls not accepted.    \n\r");
  fprintf(stdprn,"==============================================================================\n\r");
  fprintf(stdprn,"||  Maartian Enterprises  ||  1415 Valeview Dr.  ||  Diamond Bar, CA 91765  ||\n\r");
  fprintf(stdprn,"==============================================================================\n\n\r");

  fprintf(stdprn,"Any checks or money orders MUST be addressed to 'CASH' or 'Cecelia C. Maar'   \n\r");
  fprintf(stdprn,"Any checks or money orders MUST be addressed to 'CASH' or 'Cecelia C. Maar'   \n\r");
  fprintf(stdprn,"Any checks or money orders MUST be addressed to 'CASH' or 'Cecelia C. Maar'   \f");
*/
