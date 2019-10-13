[FOSSIL.TXT]


 NOTICE! Tasmanian S. REQUIRES a fossil driver to operate::

 Included in this version of Tasmanian Strategical is the fossil driver BNU.
 This must either be installed as a DEVICE in CONFIG.SYS (BNU.SYS) or run in
 your AUTOEXEC.BAT (BNU.COM) or else your system may crash or simply not work.

 If problems develop with your fossil driver use X00 (instructions for X00
 are included in this manual)

 *****

 FOSSIL Does NOT apply to SYNCHRONET VERSION!!!

 (Make sure you have the Synchronet Version, and not the Standard Version.
  The Synchronet version will allow you to use the Synchronet command
  keys from inside the game!!! BE WARNED!)

NOTE: BNU is copyright and property of it's respective holder(s).


[END TEXT]


[FOSSIL-2.TXT]

 |_|_|_|_|_|  |_|_|_|_|_|  |_|_|_|_|_|  |_|_|_|_|_|  |_|_|_|_|_|  |_|_|_|_|_|
     |_|_|_|_|_| X00 INSTRUCTIONS (ALTERNATIVE FOSSIL DRIVER) |_|_|_|_|_|
 |_|_|_|_|_|  |_|_|_|_|_|  |_|_|_|_|_|  |_|_|_|_|_|  |_|_|_|_|_|  |_|_|_|_|_|

  The following instructions are for the installation of X00 ONLY as an
  alternative to the BNU FOSSIL DRIVER. (Written by Kevin 'Viroman' Ross)

***** ***** ***** ***** *****
  USE 'X00' IN PLACE OF 'BNU' IF ANY PROBLEMS DEVELOP.
***** ***** ***** ***** *****

 Find a place that carries the fossil driver and Download it. Create a
 directory on your hard drive and label it XOO.  Ok, now copy the zip file
 into the directory and Unzip it.  No here comes the fun part, edit
 your AUTOEXEC.BAT and do the following:

---> AUTOEXEC.BAT (Example) :

PROMPT $p$g
PATH = C:\DOS;C:\SBBS;C:\QEMM;C:\XOO; <--- Add XOO to path
SET TEMP=C:\DOS
XU DV:ON           <----- Add this...
XU PORT:0:ON       <----- Add this line it turns on the Fossil driver for
			  Port 0 (Which is COM 1 <--- ATTENTION!!).
XU Set:0:19200:8N1 <----- This Command line sets the port
			  FORMAT ---> XU SET:A:XXXXX:PNS
			  A     Stands for which XOO port number
			  XXXXX Stands for the baud rate (Speed of your modem)
			  PNS   Stands for parity et al. (Use 8N1 as default)

To calculate the PORT NUMBER, take your COM PORT NUMBER and subject ONE from
that, Thus ---> COM 5 is Fossil PORT 4, etc.. (Refer below for more info..)

  Port 0 is: Com 1          Port 4 is: Com 5
  Port 1     Com 2          Port 5     Com 6
  Port 2     Com 3          Port 6     Com 7
  Port 3     Com 4          Port 7     Com 8

---> CONFIG.SYS (Add the following line ALSO) :

DEVICE=C:\XOO\X00.SYS E 0=3f8,IRQ4 <----- Now this is Self-Expl., but...
					  '0'  is the Fossil Port number
					  3f8  is the Address Port for COM 1
					  IRQ4 is the IRQ port for COM 1

  Port  ADDR  IRQ           Port  ADDR  IRQ  <----- This is a listing of all
  COM1  3f8   IRQ4          COM3  3e8   IRQ5        standard COM Port w/
  COM2  2f8   IRQ3          COM4  2e8   IRQ3        Address Port and IRQs

Once you add those lines reset you machine and away you go the Drivers load
and you are now in the great world of Fossil Drivers!!!

NOTE: BNU and X00 are both property of their respective holder(s).


[END TEXT]



Plug and play!
-- Laurence Maar

