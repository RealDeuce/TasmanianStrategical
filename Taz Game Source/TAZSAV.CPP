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

#include"\bc\taz\tazdef.h"
#include<stream.h>




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
