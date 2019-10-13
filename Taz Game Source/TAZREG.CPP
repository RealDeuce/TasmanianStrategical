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
#include<stream.h>
#include<dos.h>



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


   // Laurence Maar - October 12, 2019
   // I commented out the code which opens the registration file.
   // This forces the game to always be registered

//   if((fp=fopen(__REGFILE__,"r"))!=NULL)              // Try to open file
//      {                                                     // If successful
//      fgets(registered_name,200,fp);                  // read name from file
//      if(registered_name[strlen(registered_name)-1]=='\n')
//	 registered_name[strlen(registered_name)-1]='\0';

//      fscanf(fp,"%lu",&supplied_key);                  // read key from file
//      fscanf(fp,"%lu",&supplied_yer);                  // read key from file
//      fscanf(fp,"%lu",&supplied_mon);                  // read key from file
//      fscanf(fp,"%lu",&supplied_amb);                  // read key from file
//      fscanf(fp,"%lu",&supplied_dev);                  // read key from file

//      fclose(fp);                                              // Close file

	  sprintf(registered_name,"Freeware via Laurence Maar GPLv2 as of October 11, 2019");
      bp(registered_name,12111);        // Calculate correct key
      correct_key=rcount;

//      if(correct_key==supplied_key)       // Compare correct & supplied keys
//	 {                                          // If they are identical
//	 registeredxx=1;           // Then switch program into registered mode
//	 }
//      }

   // Laurence Maar - October 12, 2019
   // This forces the game to always be registered
   registeredxx=1;
   statis=1;
   statis_amb=1;
   statis_dev=1;
   supplied_yer=1977*511;

   /*
   if(registeredxx==1){
     statis=1;                                   // If registered mode
     if(supplied_yer!=1977*511){
     correct_year=supplied_yer/511;
     correct_mont=supplied_mon/453;
     correct_amb=supplied_amb;
     correct_dev=supplied_dev;
     if(correct_amb==15*registered_name[0]+registered_name[1]+registered_name[2]+registered_name[3])statis_amb=1;
     if(correct_dev==17*registered_name[0]+registered_name[1]+registered_name[2]+registered_name[3])statis_dev=1;
     if(correct_year==d.da_year && correct_mont==d.da_mon)registeredxx=9;
     if(correct_year<1993 || correct_mont>12 || correct_mont<1) statis=0;
     if(correct_year>d.da_year || correct_year==d.da_year && correct_mont<d.da_mon)
       {
       statis=0;registeredxx=9;
       }
     }
   }
   */

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
