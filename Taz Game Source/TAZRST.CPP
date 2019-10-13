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





void __resetlanguage(void){
#ifdef ENABLE_LANGUAGE
  for(cyc=0;cyc<STRINGS__;cyc++)strset(_____lang.string[cyc],0);
  for(cyc=0;cyc<WORDS__;cyc++)strset(_____lang.word[cyc],0);
  for(cyc=0;cyc<LINES__;cyc++)strset(_____lang.line[cyc],0);
  strset(_____lang.letter,0);
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
  sprintf(_____lang.word[25],"Invest");
  sprintf(_____lang.word[26],"Retreive");
  sprintf(_____lang.word[27],"*****");
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

  sprintf(_____lang.string[0],"Toggle Player Monitor Window");
  sprintf(_____lang.string[1],"Drop To BBS");
  sprintf(_____lang.string[2],"Program Information");
  sprintf(_____lang.string[3],"Name your empire: ");
  sprintf(_____lang.string[4],"Registered to: ");
  sprintf(_____lang.string[5],"Shareware");
  sprintf(_____lang.string[6],"Registered");
  sprintf(_____lang.string[7],"Name already in use.");
  sprintf(_____lang.string[8],"Sorry, game full.");
  sprintf(_____lang.string[9],"Welcome to ");
  sprintf(_____lang.string[10],"Name your empire ");
  sprintf(_____lang.string[11],"Turns per cycle ");
  sprintf(_____lang.string[12],"Cycle length in days ");
  sprintf(_____lang.string[13],"Enter game stating date ");
  sprintf(_____lang.string[14],"Select Door Information File Format");
  sprintf(_____lang.string[15],"C:\\BBS");
  sprintf(_____lang.string[16],"1=Yes or 0=No");
  sprintf(_____lang.string[17],"You are about to reset ");
  sprintf(_____lang.string[18],"Is this a PCBoard system?");
  sprintf(_____lang.string[19],"Enable User Monitor Window?");
  sprintf(_____lang.string[20],"By");
  sprintf(_____lang.string[21],"Standardized Setup Program");
  sprintf(_____lang.string[22],"Initial Game Setup");
  sprintf(_____lang.string[23],"Reroll Current Game");
  sprintf(_____lang.string[24],"Local SysOp Menu");
  sprintf(_____lang.string[25],"Convert Save Game Type");
  sprintf(_____lang.string[26],"Register Game");
  sprintf(_____lang.string[27],"*** WARNING! ***");
  sprintf(_____lang.string[28],"Tell your SYSOP to run ");
  sprintf(_____lang.string[29],"All");
  sprintf(_____lang.string[30],"RESET");
  sprintf(_____lang.string[31],"SYSOP");
  sprintf(_____lang.string[32],"CNV");
  sprintf(_____lang.string[33],"REGISTER");

  sprintf(_____lang.string[34],"Turns Remaining: ");
   sprintf(_____lang.string[35],"Bullion: ");
   sprintf(_____lang.string[36],"Banked: ");
    sprintf(_____lang.string[37],"Population: ");
      sprintf(_____lang.string[38],"Million");
      sprintf(_____lang.string[39],"Tax: ");
      sprintf(_____lang.string[40],"Draft: ");
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

  sprintf(_____lang.string[60],"Palaces");
  sprintf(_____lang.string[61],"Command Center: ");
    sprintf(_____lang.string[62],"Efficiency: ");

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

    sprintf(_____lang.string[75],"Crumbling");
    sprintf(_____lang.string[76],"Chaotic");
    sprintf(_____lang.string[77],"Very Unstable");
    sprintf(_____lang.string[78],"Unstable");
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
    sprintf(_____lang.string[109],"Propose to who: ");//milice

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
    sprintf(_____lang.string[146],"Default Language?");
    sprintf(_____lang.string[147],"0=English 1=French");
    sprintf(_____lang.string[148],"Select spinning cursor default");
    sprintf(_____lang.string[149],"First Interplanetary Bank of Tasmania");

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
    sprintf(_____lang.string[162],"Intercontinnental menu ");
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
    sprintf(_____lang.string[182]," units.");
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
    sprintf(_____lang.string[196],"New Tax Rate ");
    sprintf(_____lang.string[197],"New Draft Rate ");
    sprintf(_____lang.string[198],"aided opposition forces!!!");
    sprintf(_____lang.string[199],"Opposition forces overrun ");

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
    sprintf(_____lang.string[224],"That player has attack immunity.");
    sprintf(_____lang.string[225],"years of Attack Immunity remain.");
    sprintf(_____lang.string[226],"");
    sprintf(_____lang.string[227],"");
    sprintf(_____lang.string[228],"");
    sprintf(_____lang.string[229],"");

    sprintf(_____lang.string[230],"");
    sprintf(_____lang.string[231],"");
    sprintf(_____lang.string[232],"");
    sprintf(_____lang.string[233],"");
    sprintf(_____lang.string[234],"");
    sprintf(_____lang.string[235],"");
    sprintf(_____lang.string[236],"");
    sprintf(_____lang.string[237],"");
    sprintf(_____lang.string[238],"");
    sprintf(_____lang.string[239],"");

  sprintf(_____lang.line[0],"You are about to reset ");
  sprintf(_____lang.line[1],"Enter Directory Containing BBS Program (No Trailing Backslash)");
  sprintf(_____lang.line[3],"Enter Directory Containing THIS Program (No Trailing Backslash)");
  sprintf(_____lang.line[4],"       Thank your SysOp for registering me!");
  sprintf(_____lang.line[5],"Door Info File  : CHAIN.TXT/DOOR.SYS etc must be in current dir");
  sprintf(_____lang.line[6],"The version of the save file is obsolete.");
  sprintf(_____lang.line[7],"1. Reserved ###\n\r2. Reserved ###\n\r3. Last Ran Date DDMMYYYY\n\r");

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
}
if(FRENCH){
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
  sprintf(_____lang.word[13],"continuer");
  sprintf(_____lang.word[14],"Vous avez");
  sprintf(_____lang.word[15],"l'argent");
  sprintf(_____lang.word[16],"et");
  sprintf(_____lang.word[17],"turns");
  sprintf(_____lang.word[18],"million");
  sprintf(_____lang.word[19],"Envoyez");
  sprintf(_____lang.word[20],"Fund");
  sprintf(_____lang.word[21],"PCB");
  sprintf(_____lang.word[22],"JOUR");
  sprintf(_____lang.word[23],"Withdraw");
  sprintf(_____lang.word[24],"Deposit");
  sprintf(_____lang.word[25],"Invest");
  sprintf(_____lang.word[26],"Retreive");
  sprintf(_____lang.word[27],"*****");
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

  sprintf(_____lang.string[0],"Toggle Player Monitor Window");
  sprintf(_____lang.string[1],"Hangup");
  sprintf(_____lang.string[2],"Renseignements de Program");
  sprintf(_____lang.string[3],"Coment s'appelle ta empire: ");
  sprintf(_____lang.string[4],"Registered …: ");
  sprintf(_____lang.string[5],"Shareware");
  sprintf(_____lang.string[6],"Registered");
  sprintf(_____lang.string[7],/*"Un nom d‚j… dans use."*/"Un nom ne libre pas.");
  sprintf(_____lang.string[8],"D‚sol‚, un jeu est plein.");
  sprintf(_____lang.string[9],"Beinvenue … ");
  sprintf(_____lang.string[10],"Il s'appelle ");
  sprintf(_____lang.string[11],"Turns par cycle ");
  sprintf(_____lang.string[12],"Cycle length … jours ");
  sprintf(_____lang.string[13],"Enter Jeu stating date ");
  sprintf(_____lang.string[14],"Choisissez Door Information File Format");
  sprintf(_____lang.string[15],"C:\\BBS");
  sprintf(_____lang.string[16],"[1] Oui þ [0] Non");
  sprintf(_____lang.string[17],"Tu es about to reset ");
  sprintf(_____lang.string[18],"Vous faites avec PCBoard?");
  sprintf(_____lang.string[19],"Vous voulez User Monitor Window?");
  sprintf(_____lang.string[20],"Par");
  sprintf(_____lang.string[21],"Standardized Setup Program");
  sprintf(_____lang.string[22],"Initial Jeu Setup");
  sprintf(_____lang.string[23],"Reroll Current Jeu");
  sprintf(_____lang.string[24],"Local SysOp Menu");
  sprintf(_____lang.string[25],"Convert Save Jeu Type");
  sprintf(_____lang.string[26],"Register Jeu");
  sprintf(_____lang.string[27],"*** PROBLŠME ***");
  sprintf(_____lang.string[28],"Tell ta Sysop fait ");
  sprintf(_____lang.string[29],"Tout la monde");
  sprintf(_____lang.string[30],"RESET");
  sprintf(_____lang.string[31],"SYSOP");
  sprintf(_____lang.string[32],"CNV");
  sprintf(_____lang.string[33],"REGISTER");

  sprintf(_____lang.string[34],"Turns Remaining: ");
   sprintf(_____lang.string[35],"Combien de l'Argent: ");
   sprintf(_____lang.string[36],"en Banque: ");
    sprintf(_____lang.string[37],"Population: ");
      sprintf(_____lang.string[38],"Million");
      sprintf(_____lang.string[39],"Tax: ");
      sprintf(_____lang.string[40],"Draft: ");
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
     sprintf(_____lang.string[59],"Outposts");

  sprintf(_____lang.string[60],"Palais");
  sprintf(_____lang.string[61],"Centre d'Ordre: ");
    sprintf(_____lang.string[62],"Efficiency: ");

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

    sprintf(_____lang.string[75],"Crumbling");
    sprintf(_____lang.string[76],"Chaotique");
    sprintf(_____lang.string[77],"Tr‚s Unstable");
    sprintf(_____lang.string[78],"Unstable");
    sprintf(_____lang.string[79],"Loose Knit");
    sprintf(_____lang.string[80],"Stable");
    sprintf(_____lang.string[81],"Untouchable");
    sprintf(_____lang.string[82],"Frontline: ");

    sprintf(_____lang.string[83],"Achetez combien");
    sprintf(_____lang.string[84],"Tu n'as pas de l'argent.");
    sprintf(_____lang.string[85],"Cannot be sold.");
    sprintf(_____lang.string[86],"Sell combien");
    sprintf(_____lang.string[87],"Ne rien pour sell.");
    sprintf(_____lang.string[88],"Inflation Levels");
    sprintf(_____lang.string[89],"Land value: ");

    sprintf(_____lang.string[90],"Continuez? ");
    sprintf(_____lang.string[91],"Tu n'as pas turns");
    sprintf(_____lang.string[92],"Militia");
    sprintf(_____lang.string[93],"Production");
    sprintf(_____lang.string[94]," forces crush "); //l'Argent
    sprintf(_____lang.string[95],"Supplies");
    sprintf(_____lang.string[96],"Upgrade Complete");
    sprintf(_____lang.string[97],"Upgrade Failed");
    sprintf(_____lang.string[98],"Palace Repaired");

    sprintf(_____lang.string[ 99],"earned");
    sprintf(_____lang.string[100],"produced");
    sprintf(_____lang.string[101],"manufactured");
    sprintf(_____lang.string[102],"trade");
    sprintf(_____lang.string[103],"territoires");
    sprintf(_____lang.string[104],"Government efforts recruited");
    sprintf(_____lang.string[105],"Factory sales produced");
    sprintf(_____lang.string[106],"Factories manufactured");
    sprintf(_____lang.string[107],"Tax collectors produced");
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
    sprintf(_____lang.string[120]," denies surrender to rebels lead by ");
    sprintf(_____lang.string[121],"Opposition attacks were aided by ");
    sprintf(_____lang.string[122]," territories in disorder.");
    sprintf(_____lang.string[123],"Militaire surplus earned ");
    sprintf(_____lang.string[124],"Fortress surplus earned ");
    sprintf(_____lang.string[125],"Modify Levels de Productien ");
    sprintf(_____lang.string[126],"Industrial Production Totals:");
    sprintf(_____lang.string[127],"Tout … Productien de Militaire:");
    sprintf(_____lang.string[128],"Tout … Productien de Fortress:");
    sprintf(_____lang.string[129],"Troop wages total");

    sprintf(_____lang.string[130],"Pay soldats");
    sprintf(_____lang.string[131],"Defense requires");
    sprintf(_____lang.string[132],"Military forces require");
    sprintf(_____lang.string[133],"Regional maintenance costs");
    sprintf(_____lang.string[134],"Installation maintenance costs");
    sprintf(_____lang.string[135],"Stabilizing discontent would cost");
    sprintf(_____lang.string[136],"Internal affairs asks");
    sprintf(_____lang.string[137],"Regional Development costs");
    sprintf(_____lang.string[138],"Terraforming requires");
    sprintf(_____lang.string[139],"D‚sordre causes");

    sprintf(_____lang.string[140]," in damage");
    sprintf(_____lang.string[141],"Wastelands need");
    sprintf(_____lang.string[142]," for detoxification");
    sprintf(_____lang.string[143],"Turns of protection ");
    sprintf(_____lang.string[144],"Logging sur … ");
    sprintf(_____lang.string[145],"Please register moi . . .");
    sprintf(_____lang.string[146],"Default Langue?");
    sprintf(_____lang.string[147],"[0] Anglais þ [1] Fran‡ais");
    sprintf(_____lang.string[148],"Select spinning cursor default");
    sprintf(_____lang.string[149],"First Interplanetary Bank of Tasmania");

    sprintf(_____lang.string[150],"Tu as un balance de ");
    sprintf(_____lang.string[151],"Investments ont worth ");
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
    sprintf(_____lang.string[162],"Intercontinnental menu ");
    sprintf(_____lang.string[163],"Warzone menu ");
    sprintf(_____lang.string[164],"View empire scores ");
    sprintf(_____lang.string[165],"View continnental scores ");
    sprintf(_____lang.string[166],"Designation");
    sprintf(_____lang.string[167],"Peace");
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
    sprintf(_____lang.string[179],"territories to designate.");

    sprintf(_____lang.string[180],"Tu lost ");
    sprintf(_____lang.string[181],"Vous lost ");
    sprintf(_____lang.string[182]," units.");
    sprintf(_____lang.string[183],"Designate combien ");
    sprintf(_____lang.string[184],"The people require");
    sprintf(_____lang.string[185],"Ce'st cost toi ");
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
    sprintf(_____lang.string[196],"New Tax Rate ");
    sprintf(_____lang.string[197],"New Draft Rate ");
    sprintf(_____lang.string[198],"aided opposition forces!!!");
    sprintf(_____lang.string[199],"Opposition forces overrun ");

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
    sprintf(_____lang.string[224],"That player has attack immunity.");
    sprintf(_____lang.string[225],"years of Attack Immunity remain.");
    sprintf(_____lang.string[226],"");
    sprintf(_____lang.string[227],"");
    sprintf(_____lang.string[228],"");
    sprintf(_____lang.string[229],"");

    sprintf(_____lang.string[230],"");
    sprintf(_____lang.string[231],"");
    sprintf(_____lang.string[232],"");
    sprintf(_____lang.string[233],"");
    sprintf(_____lang.string[234],"");
    sprintf(_____lang.string[235],"");
    sprintf(_____lang.string[236],"");
    sprintf(_____lang.string[237],"");
    sprintf(_____lang.string[238],"");
    sprintf(_____lang.string[239],"");

  sprintf(_____lang.line[0],"Tu est about to reset ");
  sprintf(_____lang.line[1],"Enter Directory Containing BBS Program (No Trailing Backslash)");
  sprintf(_____lang.line[3],"Enter Directory Containing THIS Program (No Trailing Backslash)");
  sprintf(_____lang.line[4],"Envoyez un mot de remerciements pour registration!");
  sprintf(_____lang.line[5],"Door Info File  : CHAIN.TXT/DOOR.SYS etc must be in current dir");
  sprintf(_____lang.line[6],"The version of the save file is obsolete.");
  sprintf(_____lang.line[7],"1. Reserved ###\n\r2. Reserved ###\n\r3. Last Ran Date DDMMYYYY\n\r");

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
}
#endif
}
