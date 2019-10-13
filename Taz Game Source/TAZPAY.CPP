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





void paybills(void){
/*Initiate*/ unsigned long payup=0,u1,u2,u3,original;
/*Initiate*/ char muffit,ins2[80];__rc=15;
/*Initiate*/ nl();

price=__outqty(String,129,100,_P_.object[0]+_P_.object[1]*2,random(2)+4,300,Word,15);max=_P_.bullion;if(max>price)max=price;
payup=__outta(String,130,1,price,max);
if(price){
_P_.object[0]=(100*_P_.object[0]*.80+100*payup/price*_P_.object[0]*.20)/100;
_P_.object[1]=(100*_P_.object[1]*.80+100*payup/price*_P_.object[1]*.20)/100;
_P_.morale   =(100*_P_.morale   *.80+100*payup/price*_P_.morale   *.20)/100;
_P_.bullion -=payup;
nl();
}

/*
/*Troops  */ if(_P_.object[0]<10)_P_.object[0]++;
/*Troops  */  u1=random(2)+1; u2=random(3)+4; u3=1;
/*Troops  */  _toke=_P_.object[0]*u1*u3+_P_.object[1]*u2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,129),ins2,__language(Word,15));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(String,130));
/*Troops  */ original=_toke;
/*Troops  */  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke;
/*Troops  */ payup=_proc(_toke,_toke2);
/*Troops  */ _toke=original;
/*Troops  */ _P_.object[0]=(100*_P_.object[0]*.80+100*payup/_toke*_P_.object[0]*.20)/100;
/*Troops  */ _P_.object[1]=(100*_P_.object[1]*.80+100*payup/_toke*_P_.object[1]*.20)/100;
/*Troops  */ u3=_P_.morale*80+payup/_toke*_P_.morale*20;
/*Troops  */ if(u3>10000)u3=10000;
/*Troops  */ _P_.morale=u3/100;
/*Troops  */ _P_.bullion-=payup;nl();}
*/

price=__outqty(String,131,100,_P_.object[2],random(5)+30,250,Word,15);max=_P_.bullion;if(max>price)max=price;
payup=__outta(Word,19,1,price,max);
if(price){
_P_.object[2]=(100*_P_.object[2]*.80+100*payup/price*_P_.object[2]*.20)/100;
_P_.approval =(100*_P_.approval *.90+100*payup/price*_P_.approval *.10)/100;
_P_.bullion -=payup;
nl();
}

/*
/*Defense */  u1=random(2)+8;
/*Defense */  _toke=_P_.object[2]*u1;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,131),ins2,__language(Word,15));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,19));
/*Defense */ //SiT od_set_colour(7,0);od_printf("Defense requires %s bullion.\n\r",ins2);
/*Defense */ //od_set_colour(7,0);od_printf("Send ");
/*Defense */ original=_toke;
/*Defense */  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke;
/*Defense */ payup=_proc(_toke,_toke2);
/*Defense */ _toke=original;
/*Defense */ _P_.object[2]=(100*_P_.object[2]*.80+100*payup/_toke*_P_.object[2]*.20)/100;
/*Defense */ _P_.approval=(100*_P_.approval*.90+100*payup/_toke*_P_.approval*.10)/100;
/*Defense */ if(_P_.approval<0)/*Defense */   _P_.approval=0;
/*Defense */ _P_.bullion-=payup;nl();}
*/

price=__outqty(String,132,100,_P_.object[3]+_P_.object[4]*2,random(3)+8,250,Word,15);max=_P_.bullion;if(max>price)max=price;
payup=__outta(Word,19,1,price,max);
if(price){
_P_.object[3]=(100*_P_.object[3]*.80+100*payup/price*_P_.object[3]*.20)/100;
_P_.object[4]=(100*_P_.object[4]*.80+100*payup/price*_P_.object[4]*.20)/100;
_P_.approval =(100*_P_.approval *.90+100*payup/price*_P_.approval *.10)/100;
_P_.bullion -=payup;
nl();
}

/*
/*Militair*/  u1=random(5); u2=random(8)+3;
/*Militair*/  _toke=_P_.object[3]*u1+_P_.object[4]*u2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,132),ins2,__language(Word,15));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,19));
/*Militair*/ //SiT od_set_colour(7,0);od_printf("Millitary forces require %s bullion.\n\r",ins2);
/*Militair*/ //od_set_colour(7,0);od_printf("Send ");
/*Militair*/ original=_toke;
/*Militair*/  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke;
/*Militair*/ payup=_proc(_toke,_toke2);
/*Militair*/ _toke=original;
/*Militair*/ _P_.object[3]=(100*_P_.object[3]*.80+100*payup/_toke*_P_.object[3]*.20)/100;
/*Militair*/ _P_.object[4]=(100*_P_.object[4]*.80+100*payup/_toke*_P_.object[4]*.20)/100;
/*Militair*/ _P_.approval=(100*_P_.approval*.90+100*payup/_toke*_P_.approval*.10)/100;
/*Militair*/ if(_P_.approval<0)/*Militair*/   _P_.approval=0;
/*Militair*/ _P_.bullion-=payup;nl();}
*/

buy=0;for(cyc=0;cyc<15;cyc++)buy+=_P_.area[cyc];
price=__outqty(String,133,100,buy,random(11)+90,20000,Word,15);max=_P_.bullion;if(max>price)max=price;
payup=__outta(Word,19,1,price,max);
if(price){
_P_.approval =(100*_P_.approval *.90+100*payup/price*_P_.approval *.10)/100;
_P_.bullion -=payup;
nl();
}

/*
/*Regional*/  u1=0;for(cyc=0;cyc<19;cyc++)u1+=_P_.area[cyc];u2=random(90)+11;
/*Regional*/  _toke=u1*u2*25;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,133),ins2,__language(Word,15));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,19));
/*Regional*/ //SiT od_set_colour(7,0);od_printf("Regional maintenance costs %s total.\n\r",ins2);
/*Regional*/ //od_set_colour(7,0);od_printf("Send ");
/*Regional*/ original=_toke;
/*Regional*/  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke;
/*Regional*/ payup=_proc(_toke,_toke2);
/*Regional*/ _toke=original;
/*Militair*/ _P_.approval=(_P_.approval*.90+payup/_toke*_P_.approval*.10);
/*Regional*/ //_P_.approval-=payup/_toke*_P_.approval*.1;
/*Regional*/ if(_P_.approval<0)/*Regional*/   _P_.approval=0;
/*Regional*/ _P_.bullion-=payup;nl();}
*/

price=__outqty(String,134,100,_P_.object[8],random(100)+900,1,Word,15);max=_P_.bullion;if(max>price)max=price;
payup=__outta(Word,19,1,price,max);
if(price){
_P_.object[8]=(100*_P_.object[8]*.90+100*payup/price*_P_.object[8]*.10)/100;
_P_.approval =(100*_P_.approval *.90+100*payup/price*_P_.approval *.10)/100;
_P_.bullion -=payup;
nl();
}

/*
/*Outposts*/  u1=_P_.object[8];u2=random(711)+299;
/*Outposts*/  _toke=u1*u2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,134),ins2,__language(Word,15));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,19));
/*Outposts*/ //SiT od_set_colour(7,0);od_printf("Installation maintenance costs %s total.\n\r",ins2);
/*Outposts*/ //od_set_colour(7,0);od_printf("Send ");
/*Outposts*/ original=_toke;
/*Outposts*/  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke;
/*Outposts*/ payup=_proc(_toke,_toke2);
/*Outposts*/ _toke=original;
/*Outposts*/ _P_.approval=(100*_P_.approval*.90+100*payup/_toke*_P_.approval*.10)/100;
/*Outposts*/ if(_P_.approval<0)
/*Outposts*/   _P_.approval=0;
/*Outposts*/ _P_.bullion-=payup;nl();}
*/

price=__outqty(String,135,100,(100-_P_.i_crime)+100*(100-_P_.i_approval)+100*(100-_P_.approval)+(100-_P_.morale)*100,random(11)+40,20,Word,15);max=_P_.bullion;if(max>price)max=price;
payup=__outta(Word,20,1,price,max);
if(price){
_P_.approval+=     (100*payup/price)*.10;
_P_.i_approval+=   (100*payup/price)*.05;
_P_.i_punishment+= (100*payup/price)*.10;
_P_.i_enforcement+=(100*payup/price)*.05;
_P_.i_security+=   (100*payup/price)*.05;
_P_.morale    +=   (100*payup/price)*.05;
max=_I_*.80;
if(_I_ && max<1)max=1;
_I_-=max;
if(_P_.approval>100)     _P_.approval=100;
if(_P_.i_approval>100)   _P_.i_approval=100;
if(_P_.i_punishment>100) _P_.i_punishment=100;
if(_P_.i_enforcement>100)_P_.i_enforcement=100;
if(_P_.i_security>100)   _P_.i_security=100;
if(_P_.morale>100)       _P_.morale=100;
_P_.bullion -=payup;
nl();
}

/*
/*Stabiliz*/  _P_.i_crime=(_P_.i_punishment+_P_.i_enforcement+_P_.i_security)/3;
/*Stabiliz*/  u1=40+random(11);
/*Stabiliz*/  u2=u1*(100-_P_.i_crime)+100*(100-_P_.i_approval)+100*(100-_P_.approval)+(100-_P_.morale)*100;_toke=u2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,135),ins2,__language(Word,15));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,20));
/*Stabiliz*/ //SiT od_set_colour(7,0);od_printf("Stabilizing discontent would cost %s bullion.\n\r",ins2);
/*Stabiliz*/ //od_set_colour(7,0);od_printf("Fund ");
/*Stabiliz*/ original=_toke;
/*Stabiliz*/  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke;
/*Stabiliz*/ payup=_proc(_toke,_toke2);
/*Stabiliz*/ _toke=original;
/*Stabiliz*/ _P_.approval+=     (100*payup/_toke)*.10;
/*Stabiliz*/ _P_.i_approval+=   (100*payup/_toke)*.05;
/*Stabiliz*/ _P_.i_punishment+= (100*payup/_toke)*.10;
/*Stabiliz*/ _P_.i_enforcement+=(100*payup/_toke)*.05;
/*Stabiliz*/ _P_.i_security+=   (100*payup/_toke)*.05;
/*Stabiliz*/ _P_.morale    +=   (100*payup/_toke)*.05;
/*Stabiliz*/ max=_I_*.85;if(_I_ && max<1)max=1; _I_-=max;
/*Stabiliz*/ if(_P_.approval>100)/*Stabiliz*/ _P_.approval=100;
/*Stabiliz*/ if(_P_.i_approval>100)   _P_.i_approval=100;
/*Stabiliz*/ if(_P_.i_punishment>100) _P_.i_punishment=100;
/*Stabiliz*/ if(_P_.i_enforcement>100)_P_.i_enforcement=100;
/*Stabiliz*/ if(_P_.i_security>100)   _P_.i_security=100;
/*Stabiliz*/ if(_P_.morale>100)       _P_.morale=100;
/*Stabiliz*/ _P_.bullion-=payup;nl();}
*/

buy=0;for(cyc=0;cyc<19;cyc++)buy+=_P_.area[cyc];
price=__outqty(String,136,100,(random(10)+20+100-_P_.i_crime)*buy,random(5)+25,100,Word,15);max=_P_.bullion;if(max>price)max=price;
payup=__outta(Word,20,1,price,max);
if(price){
_P_.approval=(_P_.approval*.90+payup/price*_P_.approval*.10);
_P_.i_approval=(100*_P_.i_approval*.80+100*payup/price*_P_.i_approval*.20)/100;
_P_.i_punishment-=(1000-(1000*payup/price))*.015;
_P_.i_enforcement-=(1000-(1000*payup/price))*.020;
_P_.i_security-=(1000-(1000*payup/price))*.010;
max=_I_*.10;
if(_I_ && max<1)max=1;
_I_-=max;
if(_P_.approval<0)       _P_.approval=0;
if(_P_.i_punishment<0)   _P_.i_punishment=0;
if(_P_.i_enforcement<0)  _P_.i_enforcement=0;
if(_P_.i_security<0)     _P_.i_security=0;
_P_.bullion -=payup;
nl();
}

/*
/*Internal*/  u1=0;for(cyc=0;cyc<19;cyc++)u1+=_P_.area[cyc];
/*Internal*/  u2=20+random(10)+5*(100-_P_.i_crime);_toke=u1*u2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,136),ins2,__language(Word,15));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,20));
/*Internal*/ //SiT od_set_colour(7,0);od_printf("Internal affairs asks %s bullion.\n\r",ins2);
/*Internal*/ //od_set_colour(7,0);od_printf("Fund ");
/*Internal*/ original=_toke;
/*Internal*/  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke;
/*Internal*/ payup=_proc(_toke,_toke2);
/*Internal*/  _toke=original;
/*Militair*/ _P_.approval=(_P_.approval*.90+payup/_toke*_P_.approval*.10);
/*Internal*/ //_P_.approval=(100*_P_.approval*.90+100*payup/_toke*_P_.approval*.10)/100;
/*Internal*/ _P_.i_approval=(100*_P_.i_approval*.80+100*payup/_toke*_P_.i_approval*.20)/100;
/*Internal*/ _P_.i_punishment-=(1000-(1000*payup/_toke))*.015;
/*Internal*/ _P_.i_enforcement-=(1000-(1000*payup/_toke))*.020;
/*Internal*/ _P_.i_security-=(1000-(1000*payup/_toke))*.010;
/*Stabiliz*/ max=_I_*.10;if(_I_ && max<1)max=1; _I_-=max;
/*Internal*/ if(_P_.approval<0)/*Internal*/   _P_.approval=0;
/*Internal*/ if(_P_.i_punishment<0)   _P_.i_punishment=0;
/*Internal*/ if(_P_.i_enforcement<0)  _P_.i_enforcement=0;
/*Internal*/ if(_P_.i_security<0)/*Internal*/ _P_.i_security=0;
/*Internal*/ _P_.bullion-=payup;nl();}
*/

if(_P_.area[0]>0){
  intra[0]=random(3);
  intra[1]=random(10);
  if(_P_.protection>0 && intra[0]==1 || _P_.protection==config.parameter[6]-1 || intra[1]==1) __matrix("DEVELOP");
}

price=__outqty(String,137,100,_P_.area[0],random(211)+800,750,Word,15);max=price*10;if(max>_P_.bullion)max=_P_.bullion;
payup=__outta(Word,20,1,price,max);
if(price){
  if(payup){
    u1=0;
    u2=price/_P_.area[0]; if(!u2)u2=1;
    u3=payup/u2*.10;
    if(u3>_P_.area[0])u3=_P_.area[0];
    _P_.area[u1]-=u3;
    develop+=u3;
    u1=u3/3;u3-=u1;
    u2=u3/3;u3-=u2;
  //u3=u3;
    _P_.area[2]+=u1;  // Commercial  33%
    _P_.area[8]+=u2;  // Residential 44%
    _P_.area[6]+=u3;  // Industrial  22%
  }
  _P_.bullion -=payup;
  nl();
}

/*
/*Barren  */  u1=_P_.area[0];
/*Barren  */  u2=800+random(211);_toke=u1*u2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,137),ins2,__language(Word,15));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,20));
/*Barren  */ //SiT od_set_colour(7,0);od_printf("Regional development costs %s bullion.\n\r",ins2);
/*Barren  */ //od_set_colour(7,0);od_printf("Fund ");
/*Barren  */ original=_toke;
/*Barren  */  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke*10;
/*Barren  */  if(_toke2>_P_.bullion)_toke2=_P_.bullion;
/*Barren  */ payup=_proc(_toke,_toke2);
/*Barren  */ _toke=original;
/*Barren  */ if(payup){
/*Barren  */ 	 u1=0;
/*Barren  */ 	 u3=payup/u2/10;
/*Barren  */ 	 if(u3<3)u3+=3;
/*Barren  */ 	 if(u3>_P_.area[0])u3=_P_.area[0];
/*Barren  */ 	 _P_.area[u1]-=u3;                    develop+=u3;
/*Barren  */ 	 u1=u3/3;u3-=u1;
/*Barren  */ 	 u2=u3/3;u3-=u2;
/*Barren  */ 	 _P_.area[2]+=u1;  // Commercial  33%
/*Barren  */ 	 _P_.area[8]+=u2;  // Residential 44%
/*Barren  */ 	 _P_.area[6]+=u3;  // Industrial  22%
/*Barren  */ }
/*Barren  */_P_.bullion-=payup;nl();}
*/

price=__outqty(String,138,100,_P_.area[9],random(1111)+4000,750,Word,15);max=price*10;if(max>_P_.bullion)max=_P_.bullion;
payup=__outta(Word,20,1,price,max);
if(price){
  if(payup){
    u1=0;
    u2=price/_P_.area[9]; if(!u2)u2=1;
    u3=payup/u2*.10;
    if(u3>_P_.area[9])u3=_P_.area[9];
    _P_.area[9]-=u3;
    terraform+=u3;
     u1=u3*.50;u3-=u1;
     u2=u3*.25;u3-=u2;
   //u3=u3;
     _P_.area[0]+=u1;  // Barren      50%
     _P_.area[1]+=u2;  // Biosphere   12%
     _P_.area[8]+=u3;  // Residential 38%
  }
  _P_.bullion -=payup;
  nl();
}

/*
/*Terrafor*/  u1=_P_.area[9];
/*Terrafor*/  u2=8000+random(2111);_toke=u1*u2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,138),ins2,__language(Word,15));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,20));
/*Terrafor*/ //SiT od_set_colour(7,0);od_printf("Terraforming requires %s bullion.\n\r",ins2);
/*Terrafor*/ //od_set_colour(7,0);od_printf("Fund ");
/*Terrafor*/ original=_toke;
/*Terrafor*/  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke*10;
/*Terrafor*/  if(_toke2>_P_.bullion)_toke2=_P_.bullion;
/*Terrafor*/ payup=_proc(_toke,_toke2);
/*Terrafor*/ _toke=original;
/*Terrafor*/ if(payup){
/*Terrafor*/ 	 u1=9;
/*Terrafor*/ 	 u3=payup/u2/10;
/*Terrafor*/ 	 if(u3<3)u3++;
/*Terrafor*/ 	 if(u3>_P_.area[u1])u3=_P_.area[u1];
/*Terrafor*/ 	 _P_.area[u1]-=u3;                    terraform+=u3;
/*Barren  */ 	 u1=u3*.50;u3-=u1;
/*Barren  */ 	 u2=u3*.75;u3-=u2;
/*Barren  */ 	 _P_.area[0]+=u1;  // Barren      50%
/*Barren  */ 	 _P_.area[8]+=u2;  // Residential 37%
/*Barren  */ 	 _P_.area[1]+=u3;  // Biosphere   13%
/*Terrafor*/ }_P_.bullion-=payup;nl();}
*/

price=__outqty(String,139,100,_P_.area[3],random(2111)+8000,750,Word,15);max=price*10;if(max>_P_.bullion)max=_P_.bullion;
payup=__outta(Word,20,1,price,max);
if(price){
  if(payup){
    u1=0;
    u2=price/_P_.area[3]; if(!u2)u2=1;
    u3=payup/u2*.10;
    if(u3>_P_.area[3])u3=_P_.area[3];
    _P_.area[3]-=u3;
    recover+=u3;
    u1=u3*.50;u3-=u1;
    u2=u3*.80;u3-=u2;
  //u3=u3;
    _P_.area[0]+=u1;  // Barren      50%
    _P_.area[8]+=u2;  // Residential 40%
    _P_.area[7]+=u3;  // Military    10%
    _P_.approval =(100*_P_.approval *.90+100*payup/price*_P_.approval *.10)/100;
  }
  _P_.bullion -=payup;
  nl();
}

/*
/*Disorder*/  u1=_P_.area[3];
/*Disorder*/  u2=8000+random(2111);_toke=u1*u2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s%s.\n\r",__language(String,139),ins2,__language(Word,15),__language(String,140));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,20));
/*Disorder*/ //SiT od_set_colour(7,0);od_printf("Disorder causes %s bullion in damage.\n\r",ins2);
/*Disorder*/ //od_set_colour(7,0);od_printf("Fund ");
/*Disorder*/ original=_toke;
/*Disorder*/  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke*10;
/*Disorder*/  if(_toke2>_P_.bullion)_toke2=_P_.bullion;
/*Disorder*/ payup=_proc(_toke,_toke2);
/*Disorder*/ _toke=original;
/*Disorder*/ if(payup){
/*Disorder*/ 	 u1=3;
/*Disorder*/ 	 u3=payup/u2/10;
/*Disorder*/ 	 if(u3<3)u3++;
/*Disorder*/ 	 if(u3>_P_.area[u1])u3=_P_.area[u1];
/*Disorder*/ 	 _P_.area[u1]-=u3;                    recover+=u3;
/*Barren  */ 	 u1=u3*.50;u3-=u1;
/*Barren  */ 	 u2=u3*.80;u3-=u2;
/*Barren  */ 	 _P_.area[0]+=u1;  // Barren      50%
/*Barren  */ 	 _P_.area[8]+=u2;  // Residential 40%
/*Barren  */ 	 _P_.area[7]+=u3;  // Military    10%
/*Militair*/ _P_.approval=(_P_.approval*.90+payup/_toke*_P_.approval*.10);
/*Disorder*/ //_P_.approval=(100*_P_.approval*.90+100*payup/_toke*_P_.approval*.10)/100;
/*Disorder*/ if(_P_.approval<0)_P_.approval=0;
/*Disorder*/ _P_.bullion-=payup;}nl();}
*/

price=__outqty(String,141,100,_P_.area[10],random(2111)+8000,750,String,142);max=price*10;if(max>_P_.bullion)max=_P_.bullion;
payup=__outta(Word,20,1,price,max);
if(price){
  if(payup){
    u1=0;
    u2=price/_P_.area[10]; if(!u2)u2=1;
    u3=payup/u2*.10;
    if(u3>_P_.area[10])u3=_P_.area[10];
    _P_.area[10]-=u3;
    detox+=u3;
	 u1=u3*.80;u3-=u1;
	 u2=u3*.50;u3-=u2;
       //u3=u3;
	 _P_.area[0]+=u1;  // Barren    80%
	 _P_.area[4]+=u2;  // Fortress  10%
	 _P_.area[7]+=u3;  // Millitary 10%
  _P_.approval =(100*_P_.approval *.90+100*payup/price*_P_.approval *.10)/100;
  }
  _P_.bullion -=payup;
  nl();
}

/*
/*Wastelan*/  u1=_P_.area[10];
/*Wastelan*/  u2=400+random(111);_toke=u1*u2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s%s.\n\r",__language(String,141),ins2,__language(Word,15),__language(String,142));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,20));
/*Wastelan*/ //SiT od_set_colour(7,0);od_printf("Wastelands need %s bullion for detoxification.\n\r",ins2);
/*Wastelan*/ //od_set_colour(7,0);od_printf("Fund ");
/*Wastelan*/ original=_toke;
/*Wastelan*/  if(_toke>_P_.bullion){_toke2=_P_.bullion;_toke=_P_.bullion;}else _toke2=_toke*10;
/*Wastelan*/  if(_toke2>_P_.bullion)_toke2=_P_.bullion;
/*Wastelan*/ payup=_proc(_toke,_toke2);
/*Wastelan*/ _toke=original;
/*Wastelan*/  	 u1=10;
/*Wastelan*/  	 u3=payup/u2/10;
/*Wastelan*/  	 if(u3<3)u3++;
/*Wastelan*/  	 if(u3>_P_.area[u1])u3=_P_.area[u1];
/*Wastelan*/  	 _P_.area[u1]-=u3;                     detox=u3;
/*Barren  */ 	 u1=u3*.80;u3-=u1;
/*Barren  */ 	 u2=u3*.50;u3-=u2;
/*Barren  */ 	 _P_.area[0]+=u1;  // Barren    80%
/*Barren  */ 	 _P_.area[7]+=u2;  // Millitary 10%
/*Barren  */ 	 _P_.area[4]+=u3;  // Fortress  10%
/*Militair*/ _P_.approval=(_P_.approval*.90+payup/_toke*_P_.approval*.10);
/*Wastelan*/ //_P_.approval=(100*_P_.approval*.90+100*payup/_toke*_P_.approval*.10)/100;
/*Wastelan*/ if(_P_.approval<0)/*Wastelan*/    _P_.approval=0;
/*Wastelan*/ _P_.bullion-=payup;nl();}
*/

price=__outqty(String,184,100,_P_.population,1,100,Word,42);max=_P_.food;if(max>price)max=price;
payup=__outta(Word,19,1,price,max);
if(price){
_P_.object[0]=(100*_P_.object[0]*.90+100*payup/price*_P_.object[0]*.10)/100;
_P_.object[1]=(100*_P_.object[1]*.90+100*payup/price*_P_.object[1]*.10)/100;
_P_.approval =(100*_P_.approval *.80+100*payup/price*_P_.approval *.20)/100;
_P_.morale   =(100*_P_.morale   *.90+100*payup/price*_P_.morale   *.10)/100;
_P_.food -=payup;
nl();
}

/*
/*Populace*/  _toke=_P_.population;sprintf(ins2,"%s",_parsemoney(_toke));
/*Populace*/ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,184),ins2,__language(Word,42));
/*Populace*/ od_set_colour(7,0);od_printf("%s ",__language(Word,19));
/*Populace*/ original=_toke;
/*Populace*/  if(_toke>_P_.food){_toke2=_P_.food;_toke=_P_.food;}else _toke2=_toke;
/*Populace*/ payup=_proc(_toke,_toke2);
/*Populace*/ _toke=original;
/*Populace*/ _P_.object[0]=(100*_P_.object[0]*.80+100*payup/_toke*_P_.object[0]*.20)/100;
/*Populace*/ _P_.object[1]=(100*_P_.object[1]*.80+100*payup/_toke*_P_.object[1]*.20)/100;
/*Populace*/ u3=_P_.morale*80+payup/_toke*_P_.morale*20;
/*Populace*/ if(u3>10000)u3=10000;
/*Populace*/ _P_.morale=u3/100;
/*Populace*/ _P_.food-=payup;nl();}
*/

price=__outqty(String,131,100,_P_.object[0]*5+_P_.object[1],1,100,Word,42);max=_P_.food;if(max>price)max=price;
payup=__outta(Word,19,1,price,max);
if(price){
_P_.object[0]=(100*_P_.object[0]*.80+100*payup/price*_P_.object[0]*.20)/100;
_P_.object[1]=(100*_P_.object[1]*.90+100*payup/price*_P_.object[1]*.10)/100;
_P_.approval =(100*_P_.approval *.90+100*payup/price*_P_.approval *.10)/100;
_P_.morale   =(100*_P_.morale   *.80+100*payup/price*_P_.morale   *.20)/100;
_P_.food -=payup;
nl();
}

/*
/*Troops  */  _toke=_P_.object[0]*5+_P_.object[1]*2;sprintf(ins2,"%s",_parsemoney(_toke));
/*Troops  */ SiT od_set_colour(7,0);od_printf("%s %s %s.\n\r",__language(String,131),ins2,__language(Word,42));
/*Troops  */ od_set_colour(7,0);od_printf("%s ",__language(Word,19));
/*Troops  */ original=_toke;
/*Troops  */  if(_toke>_P_.food){_toke2=_P_.food;_toke=_P_.food;}else _toke2=_toke;
/*Troops  */ payup=_proc(_toke,_toke2);
/*Troops  */ _toke=original;
/*Troops  */ _P_.object[0]=(100*_P_.object[0]*.80+100*payup/_toke*_P_.object[0]*.20)/100;
/*Troops  */ _P_.object[1]=(100*_P_.object[1]*.80+100*payup/_toke*_P_.object[1]*.20)/100;
/*Troops  */ u3=_P_.morale*80+payup/_toke*_P_.morale*20;
/*Troops  */ if(u3>10000)u3=10000;
/*Troops  */ _P_.morale=u3/100;
/*Troops  */ _P_.food-=payup;nl();}
*/

if(_P_.bullion<1 && (_P_.protection>0 || _P_.protection==config.parameter[6]-1 || random(10)==1))__matrix("MONEYTIP");

__rc=10;
}






unsigned long __outqty(int _y,int _i,unsigned long _z,unsigned long _t,unsigned long _l,unsigned long _d,int autt,int autre){
unsigned long _r,_j;
char ins2[80];
_j=random(11)+95;
_r=_z*_d*.00000007*((_j*_l*_t*.01)*((_P_.approval+_P_.i_approval)*.45+10));
_r*=1.5;
if(!_r)return(0);
sprintf(ins2,"%s",_parsemoney(_r));od_set_colour(7,0);
if(_i==999)               	       od_printf("%s ",ins);
else if(strlen(__language(_y,_i))<13)  od_printf("  %-12.12s ",__language(_y,_i));
else if(_i==123 || _i==124)            od_printf("%s",__language(_y,_i));
else                                   od_printf("%s ",__language(_y,_i));
od_set_colour(11,0);
if(!autre)
  od_printf("%s\n\r",ins2);
else{od_printf("%s ",ins2);  od_set_colour(7,0);  od_printf("%s\n\r",__language(autt,autre));}
od_set_colour(7,0);
return(_r);
}

void production(void){
/*Initiate*/ unsigned long _toker=0,u1,u2,u3,rm;char ins2[80];int hit=0,imod=_P_.approval+_P_.i_approval;imod=imod/2;
/*Initiate*/ od_printf("\n\n\n\r");
/*Initiate*/ od_set_colour(12,0);
__matrix("LINE70-B");//for(cyc=0;cyc<70;cyc++)od_printf("Ä");nl();
od_set_colour(7,0);

sprintf(ins,"%ss %s",__language(String,65),__language(String,100));
_toker+=__outqty(999,999,100-_P_.biosphere,_P_.area[1],random(1111)+6000,1000,Word,15);
///*Biospher*/ u1=_P_.area[1]; u2=random(200)+1000; u3=random(1111)+5000; rm=u2*u1;_toke=rm+u3*u1;_toke*=(100-_P_.biosphere)*.01;
///*Biospher*/ SiT od_printf("%ss %s ",__language(String,65),__language(String,100));
///*Biospher*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Biospher*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

sprintf(ins,"%s %s %s",__language(String,66),__language(String,102),__language(String,100));
_toker+=__outqty(999,999,100,_P_.area[2],random(5111)+12000,1000,Word,15);
///*Commerci*/ u1=_P_.area[2];u2=random(500)+2000; u3=random(5111)+10000; rm=u2*u1;_toke=rm+u3*u1;
///*Commerci*/ SiT od_printf("%s %s %s ",__language(String,66),__language(String,102),__language(String,100));
///*Commerci*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Commerci*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

_toker+=__outqty(String,105,_P_.industry[9],_P_.area[6],random(111)+500,1000,Word,15);
///*Factorys*/ u1=_P_.area[6]; u2=random(20)+10; u3=random(111)+500; rm=u2*u1;_toke=rm+u3*u1;_toke*=_P_.industry[9]*.01;
///*Factorys*/ SiT od_printf("%s ",__language(String,105));
///*Factorys*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Factorys*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

_toker+=__outqty(String,123,_P_.military[9],_P_.area[7],random(1111)+6000,1000,Word,15);
///*Militair*/ u1=_P_.area[7]; u2=random(200)+1000; u3=random(1111)+5000; rm=u2*u1;_toke=rm+u3*u1;_toke*=_P_.military[9]*.01;
///*Militair*/ SiT od_printf("%s",__language(String,123));
///*Militair*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Militair*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

_toker+=__outqty(String,124,_P_.fortress[9],_P_.area[4],random (11111)+500000,1000,Word,15);
///*Fortress*/ u1=_P_.area[4]; u2=random(20000)+100000; u3=random(111111)+400000; rm=u2*u1;_toke=rm+u3*u1;_toke*=_P_.fortress[9]*.01;
///*Fortress*/ SiT od_printf("%s",__language(String,124));
///*Fortress*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Fortress*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

sprintf(ins,"%s %s",__language(String,69),__language(String,100));
_toker+=__outqty(999,999,100-_P_.gouvernment,_P_.area[1],random(1111)+5000,1000,Word,15);
///*Gouvrnmt*/ u1=_P_.area[1]; u2=random(200)+1000; u3=random(1111)+5000; rm=u2*u1;_toke=rm+u3*u1;_toke*=(100-_P_.gouvernment)*.01;
///*Gouvrnmt*/ SiT od_printf("%s %s ",__language(String,69),__language(String,100));
///*Gouvrnmt*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Gouvrnmt*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

_toker+=__outqty(String,107,_P_.taxrate,_P_.population,100,25000,Word,15);
///*Populati*/ _toke=_P_.population*_P_.taxrate*100;
///*Populati*/  SiT od_printf("%s ",__language(String,107));
///*Populati*/  od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*Populati*/  od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

sprintf(ins,"%s %s %s",__language(String,64),__language(String,103),__language(String,99));
_toker+=__outqty(999,999,100,_P_.area[0],random(111)+300,3500,Word,15);
///*Wastelan*/  u1=_P_.area[0]; u2=random(100)+100; u3=random(100)+300; rm=u2*u1;_toke=rm+u3*u1;
///*Wastelan*/  SiT od_printf("%s %s %s ",__language(String,64),__language(String,103),__language(String,99));sprintf(ins2,"%s",_parsemoney(_toke));
///*Wastelan*/  od_set_colour(11,0);od_printf("%s ",ins2);
///*Wastelan*/  od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));_toker+=_toke;}

/*TOTALS  */ if(_toker){__matrix("TOTPROD");
/*TOTALS  */ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toker));od_printf("%s ",ins2);
/*TOTALS  */ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,15));}
/*TOTALS  */ _P_.bullion+=_toker;

sprintf(ins,"%ss %s",__language(String,65),__language(String,101));
_P_.food+=__outqty(999,999,_P_.biosphere,_P_.area[1],random(1111)+8000,3500,Word,42);
///*BiosFood*/ u1=_P_.area[1]; u2=random(1111)+8000; u3=random(1111)+8000; _toke=(u2+u3)*u1; _toke*=(imod/90+.10);_toke*=_P_.biosphere*.01;
///*BiosFood*/ SiT od_printf("%ss %s ",__language(String,65),__language(String,101));
///*BiosFood*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*BiosFood*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,42));_P_.food+=_toke;}

_P_.object[0]+=__outqty(String,104,_P_.gouvernment,_P_.area[4],random(111)+700,1000,Word,41);
///*GouvMili*/ u1=_P_.area[4]; u2=random(11)+100; u3=random(100)+700; _toke=u2*u1+u3*u1; _toke=(_toke*(imod/90+.10));_toke*=_P_.gouvernment*.01;
///*GouvMili*/ SiT od_printf("%s ",__language(String,104));
///*GouvMili*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*GouvMili*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,41));_P_.object[0]+=_toke;}

_P_.object[0]+=__outqty(String,104,_P_.draftrate,_P_.population,100,100,Word,41);
///*GouvMili*/ u1=_P_.area[4]; u2=random(11)+100; u3=random(100)+700; _toke=u2*u1+u3*u1; _toke=(_toke*(imod/90+.10));_toke*=_P_.gouvernment*.01;
///*GouvMili*/ SiT od_printf("%s ",__language(String,104));
///*GouvMili*/ od_set_colour(11,0);sprintf(ins2,"%s",_parsemoney(_toke));od_printf("%s ",ins2);
///*GouvMili*/ od_set_colour( 7,0);od_printf("%s\n\r",__language(Word,41));_P_.object[0]+=_toke;}

/*Initiate*/ pause();
/*Initiate*/ od_set_colour(12,0);
__matrix("LINE70-B");	///*Initiate*/ for(cyc=0;cyc<70;cyc++)///*Initiate*/ od_printf("Ä");///*Initiate*/ nl();
od_set_colour(7,0);

/*FACTORIE*/ if(_P_.industry[9]<100 && _P_.area[6]){od_printf("%s\n\r",__language(String,126));hit=1;
_P_.object[2]+=__outqty(String,53,_P_.industry[2],_P_.area[6],random(111)+900, 250,0,0);
_P_.object[3]+=__outqty(String,54,_P_.industry[3],_P_.area[6],random(111)+900, 167,0,0);
_P_.object[4]+=__outqty(String,55,_P_.industry[4],_P_.area[6],random(111)+900, 200,0,0);
_P_.object[5]+=__outqty(String,56,_P_.industry[5],_P_.area[6],random(111)+900,1000,0,0);
_P_.food     +=__outqty(String,95,_P_.industry[7],_P_.area[6],random(111)+900,3000,0,0);
/*FACTORIE*/ }

/*MILITAIR*/ if(_P_.military[9]<100 && _P_.area[7]){od_printf("%s\n\r",__language(String,127));hit=1;
_P_.object[0]+=__outqty(String,92,_P_.military[0],_P_.area[7],random(111)+900, 500,0,0);
_P_.object[3]+=__outqty(String,54,_P_.military[3],_P_.area[7],random(111)+900, 835,0,0);
_P_.object[4]+=__outqty(String,55,_P_.military[4],_P_.area[7],random(111)+900,1000,0,0);
_P_.object[5]+=__outqty(String,56,_P_.military[5],_P_.area[7],random(111)+900,5000,0,0);
/*MILITAIR*/ }

/*FORTRESS*/ if(_P_.fortress[9]<100 && _P_.area[4]){od_printf("%s\n\r",__language(String,128));hit=1;
_P_.object[0]+=__outqty(String,92,_P_.fortress[0],_P_.area[4],random(111)+900,1000*15,0,0);
_P_.object[1]+=__outqty(String,52,_P_.fortress[1],_P_.area[4],random(111)+900, 500*15,0,0);
_P_.object[2]+=__outqty(String,53,_P_.fortress[2],_P_.area[4],random(111)+900, 250*15,0,0);
_P_.object[4]+=__outqty(String,55,_P_.fortress[4],_P_.area[4],random(111)+900, 200*15,0,0);
_P_.object[6]+=__outqty(String,57,_P_.fortress[6],_P_.area[4],random(111)+900,  10*15,0,0);
/*FORTRESS*/ }
/*Terminat*/ if(hit)pause();
}


