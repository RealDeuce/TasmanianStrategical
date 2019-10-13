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

#include<stream.h>
#include<process.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

FILE *__dxxfile;
FILE *__dyyfile;

void main(void){
  char inpstr[81],temp[81],usemat[20],matrix[20];
  int inpcol,inpcur,eomatr,inpcot,inpcon,cyc509;
  unsigned long lax=0,rout=0;
  directvideo=0;eomatr=0;

   __dxxfile=fopen("TAZDXX.NFO","r");
   __dyyfile=fopen("TAZDYY.NFO","w");

   printf("Working...");

	    do{
	      fscanf(__dxxfile,"%1s",inpstr);
		     if(inpstr[0]=='~'){fprintf(__dyyfile,"%s",inpstr);fscanf(__dxxfile,"%1s",inpstr);fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='^'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='ü'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]==''){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='ð'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='á'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='ì'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='ï'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='æ'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='î'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='ä'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='ù'){fprintf(__dyyfile,"%s",inpstr);
			lax++;
			printf(".");
		}
		else if(inpstr[0]=='ú'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]==']'){fprintf(__dyyfile,"ž");}
		else if(inpstr[0]=='û'){fprintf(__dyyfile,"%s",inpstr);fgets(inpstr,80,__dxxfile);fprintf(__dyyfile,"%s\n",inpstr);
			rout++;
			printf("o");
		}
		else if(inpstr[0]=='ø'){fprintf(__dyyfile,"%s",inpstr);}
		else if(inpstr[0]=='þ'){fprintf(__dyyfile,"%s\n",inpstr);}
		else if(inpstr[0]=='ñ'){fprintf(__dyyfile,"%s\n",inpstr);}
		else if(inpstr[0]=='î'){fprintf(__dyyfile,"þ");}
		else if(inpstr[0]=='ì'){fprintf(__dyyfile,"ì");}
		else if(inpstr[0]=='ä'){fprintf(__dyyfile,"[OPEN_STOP_LOCKED]\n");}
		else if(inpstr[0]=='ý'){fprintf(__dyyfile,"%s\n",inpstr);eomatr=1;}
		else
		  if(inpstr[0]>57 && inpstr[0]<154)
		    {
		      inpstr[0]+=1;
		      fprintf(__dyyfile,"%s",inpstr);
		    }
		  else
		    {
		      fprintf(__dyyfile,"%s",inpstr);
		    }
	    }while(!eomatr && !feof(__dxxfile));

    fclose(__dxxfile);
    fclose(__dyyfile);
	      printf("\n\r%lu lines, %lu routines encrypted\n\n",lax,rout);
}



