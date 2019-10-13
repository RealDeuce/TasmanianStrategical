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
/*     TAZLOCAL.EXE Ver 1.0                                                */
/*     TAZLOCAL.EXE Ver 1.0                                                */
/*     TAZLOCAL.EXE Ver 1.0                                                */
/*                                                                         */
/***************************************************************************/

#define UNDEFINED
#define NOOPEN
#include"tazdef.h"
#include"tazver.h"

void __RST__main2(int _force);

void NEWS_main(char ar[80]);
void NEWD_main(char ar[80]);
void NWDR_main(char ar[80]);

char _current[80];

void main(int argc,char **argv){
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
  if(argc>1 && strnicmp(argv[1],"CONVE",5)==0) __CNV__main();
//if(argc>1 && strnicmp(argv[1],"RESET",5)==0) __RST__main2(0);
//if(argc>1 && strnicmp(argv[1],"NOUVE",5)==0) __RST__main2(0);
//if(argc>1 && strnicmp(argv[1],"FORCE",5)==0) __RST__main2(1);
  if(argc>1 && strnicmp(argv[1],"RESET",5)==0)   NEWD_main(ar);
  if(argc>1 && strnicmp(argv[1],"NOUVE",5)==0)   NEWD_main(ar);
  if(argc>1 && strnicmp(argv[1],"FORCE",5)==0)   NEWD_main(ar);
//if(argc>1 && strnicmp(argv[1],"SETUP",5)==0) __SET__main();
  if(argc>1 && strnicmp(argv[1],"SETUP",5)==0)   NEWS_main(ar);
//if(argc>1 && strnicmp(argv[1],"REGIS",5)==0) __REG__main();
  if(argc>1 && strnicmp(argv[1],"REGIS",5)==0)   NWDR_main(ar);
//if(argc>1 && strnicmp(argv[1],"FREG" ,4)==0) __REG__main();
  if(argc>1 && strnicmp(argv[1],"FREG" ,4)==0)   NWDR_main(ar);
}
