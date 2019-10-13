void __line6(int xx, int cu){int con=0;
if(xx==1) { gotoxy(3,1 +con); cprintf(" Install Program...                 "); /*cprintf("%-35s",toggle6[1]);*/}
if(xx==2) { gotoxy(3,2 +con); cprintf(" Update Version...                  "); /*cprintf("%-35s",toggle6[2]);*/}
if(xx==3) { gotoxy(3,3 +con); cprintf(" Reconfigure Program...             "); /*cprintf("%-35s",toggle6[3]);*/}
if(xx==4) { gotoxy(3,4 +con); cprintf("                                    "); /*cprintf("%-35s",toggle6[4]);*/}
if(xx==5) { gotoxy(3,5 +con); cprintf(" Initialize New Game...             "); /*cprintf("%-35s",toggle6[5]);*/}
if(xx==6) { gotoxy(3,6 +con); cprintf(" Register Program...                "); /*cprintf("%-35s",toggle6[6]);*/}
if(xx==7) { gotoxy(3,7 +con); cprintf("                                    "); /*cprintf("%-35s",toggle6[7]);*/}
if(xx==8) { gotoxy(3,8 +con); cprintf(" Printer Forms...                   "); /*cprintf("%-35s",toggle6[8]);*/}
if(xx==9) { gotoxy(3,9 +con); cprintf("                                    "); /*cprintf("%-35s",toggle6[9]);*/}
if(xx==10){ gotoxy(3,10+con); cprintf(" Exit...                            "); /*cprintf("%-35s",toggle6[10]);*/}
}
void __line5(int xx, int cu){int con=0;
if(xx==1) { gotoxy(3,1 +con); cprintf(" Program Name        "); cprintf("%-35s",toggle5[1]);}
if(xx==2) { gotoxy(3,2 +con); cprintf(" Target Directory    "); cprintf("%-35s",toggle5[2]);}
if(xx==3) { gotoxy(3,3 +con); cprintf(" Source Directory    "); cprintf("%-35s",toggle5[3]);}
if(xx==4) { gotoxy(3,4 +con); cprintf("                     "); cprintf("%-35s",toggle5[4]);}
if(xx==5) { gotoxy(3,5 +con); cprintf(" Install First Disk  "); cprintf("%-35s",toggle5[5]);}
if(xx==6) { gotoxy(3,6 +con); cprintf(" Install Bonus Disk  "); cprintf("%-35s",toggle5[6]);}
if(xx==7) { gotoxy(3,7 +con); cprintf("                     "); cprintf("%-35s",toggle5[7]);}
if(xx==8) { gotoxy(3,8 +con); cprintf("                     "); cprintf("%-35s",toggle5[8]);}
if(xx==9) { gotoxy(3,9 +con); cprintf("                     "); cprintf("%-35s",toggle5[9]);}
if(xx==10){ gotoxy(3,10+con); cprintf(" Proceed...          "); cprintf("%-35s",toggle5[10]);}
}
void __line(int xx, int cu){int con=0;
if(xx==1) { gotoxy(3,1 +con); cprintf(" Program Directory   "); cprintf("%-35s",toggle[1]);}
if(xx==2) { gotoxy(3,2 +con); cprintf(" BBS Directory       "); cprintf("%-35s",toggle[2]);}
if(xx==3) { gotoxy(3,3 +con); cprintf(" Drop File           "); cprintf("%-35s",toggle[3]);}
if(xx==4) { gotoxy(3,4 +con); cprintf(" Write Batch File To "); cprintf("%-35s",toggle[4]);}
if(xx==5) { gotoxy(3,5 +con); cprintf("                     "); cprintf("%-35s",toggle[5]);}
if(xx==6) { gotoxy(3,6 +con); cprintf("    Monitor Window   "); cprintf("%-35s",toggle[6]);}
if(xx==7) { gotoxy(3,7 +con); cprintf("    Language Default "); cprintf("%-35s",toggle[7]);}
if(xx==8) { gotoxy(3,8 +con); cprintf("    Spinning Cursor  "); cprintf("%-35s",toggle[8]);}
if(xx==9) { gotoxy(3,9 +con); cprintf("                     "); cprintf("%-35s",toggle[9]);}
if(xx==10){ gotoxy(3,10+con); cprintf(" Proceed...          "); cprintf("%-35s",toggle[10]);}
}
void __line3(int xx, int cu){
if(xx==0) { gotoxy(3,1 ); cprintf("                     "); cprintf("%-35s",toggle3[1]);}
if(xx==1) { gotoxy(3,1 ); cprintf(" Turns / Cycle       "); cprintf("%-35s",toggle3[1]);}
if(xx==2) { gotoxy(3,2 ); cprintf(" Turns / Immunity    "); cprintf("%-35s",toggle3[2]);}
if(xx==3) { gotoxy(3,3 ); cprintf(" Cycle length (Days) "); cprintf("%-35s",toggle3[3]);}
if(xx==4) { gotoxy(3,4 ); cprintf("                     "); cprintf("%-35s",toggle3[4]);}
if(xx==5) { gotoxy(3,5 ); cprintf(" Commence            "); cprintf("%-35s",toggle3[5]);}
if(xx==6) { gotoxy(3,6 ); cprintf("   Day   / Jour      "); cprintf("%-35s",toggle3[6]);}
if(xx==7) { gotoxy(3,7 ); cprintf("   Month / Mois      "); cprintf("%-35s",toggle3[7]);}
if(xx==8) { gotoxy(3,8 ); cprintf("   Year  / An        "); cprintf("%-35s",toggle3[8]);} //37
if(xx==9) { gotoxy(3,9 ); cprintf("                     "); cprintf("%-35s",toggle3[9]);}
if(xx==10){ gotoxy(3,10); cprintf(" Proceed...          "); cprintf("%-35s",toggle3[10]);}
}
void __line2(int xx, int cu){
if(xx==0) { gotoxy(3,1 ); cprintf(" Individule Nom      "); cprintf("%-35s",toggle2[1]);}
if(xx==1) { gotoxy(3,1 ); cprintf(" Individule Nom      "); cprintf("%-35s",toggle2[1]);}
if(xx==2) { gotoxy(3,2 ); cprintf(" Serialle            "); cprintf("%-35s",toggle2[2]);}
if(xx==3) { gotoxy(3,3 ); cprintf(" Specification       "); cprintf("%-35s",toggle2[3]);}
if(xx==4) { gotoxy(3,4 ); cprintf(" Definition          "); cprintf("%-35s",toggle2[4]);}
if(xx==5) { gotoxy(3,5 ); cprintf(" Ambiance            "); cprintf("%-35s",toggle2[5]);}
if(xx==6) { gotoxy(3,6 ); cprintf(" Devior              "); cprintf("%-35s",toggle2[6]);}
if(xx==7) { gotoxy(3,7 ); cprintf("                     "); cprintf("%-35s",toggle2[7]);}
if(xx==8) { gotoxy(3,8 ); cprintf(" Expires             "); cprintf("%-35s",toggle2[8]);} //37
if(xx==9) { gotoxy(3,9 ); cprintf(" Verify...           "); cprintf("%-35s",toggle2[9]);}
if(xx==10){ gotoxy(3,10); cprintf(" Save...             "); cprintf("%-35s",toggle2[10]);}
}
void __line7(int xx, int cu){int con=0;
if(xx==1) { gotoxy(3,1 +con); cprintf(" Tasmanian Strategical Manual...    "); /*cprintf("%-35s",toggle7[1]);*/}
if(xx==2) { gotoxy(3,2 +con); cprintf(" Order Form...                      "); /*cprintf("%-35s",toggle7[2]);*/}
if(xx==3) { gotoxy(3,3 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[3]);*/}
if(xx==4) { gotoxy(3,4 +con); cprintf(" Proceed...                         "); /*cprintf("%-35s",toggle7[4]);*/}
//if(xx==5) { gotoxy(3,5 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[5]);*/}
//if(xx==6) { gotoxy(3,6 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[6]);*/}
//if(xx==7) { gotoxy(3,7 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[7]);*/}
//if(xx==8) { gotoxy(3,8 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[8]);*/}
//if(xx==9) { gotoxy(3,9 +con); cprintf("                                    "); /*cprintf("%-35s",toggle7[9]);*/}
//if(xx==10){ gotoxy(3,10+con); cprintf(" Exit...                            "); /*cprintf("%-35s",toggle7[10]);*/}
}



