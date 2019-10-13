/*
Tasmanian Strategical
Copyright (C) 1993, 1994, 2019 Laurence Maar

laurencemaar@gmail.com
https://www.facebook.com/laurencemaar/
https://www.linkedin.com/in/laurencemaar/
https://github.com/laurencemaar/
https://sourceforge.net/u/laurencemaar/

-----

This program is a key generator.
It will generate a file named TAZREG.NFO.
Put this file in your install directory.

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

/*
EXAMPLE WORKING SERIAL 1: Expiring in 2100

Freeware via Laurence Maar
1035550
1073100 
5436
1366
1506

-----

EXAMPLE WORKING SERIAL 2: Never Expires (1977 is the year code)
(Might not work correctly)

Freeware via Laurence Maar
1035550
1010247
5436
1366
1506

-----

EXAMPLE WORKING SERIAL 2: Kevin Thunell expiring in 2100

Kevin Thunell
552742
1073100
5436
1449
1599

-----

EXAMPLE WORKING SERIAL 3: Kevin Thunell expiring never (1977 is the year code)

Kevin Thunell
552742
1010247
5436
1449
1599
 */


#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;
unsigned long bp(char *registration_string, unsigned int security_code);

int main() {
	printf("\nTasmanian Strategical - Key Generator\n");
	printf("Copyright (C) 2019 Laurence Maar\n");
	printf("laurencemaar@gmail.com\n");
	printf("https://www.facebook.com/laurencemaar/\n");
	printf("https://www.linkedin.com/in/laurencemaar/\n");
	printf("https://github.com/laurencemaar/\n");
	printf("https://sourceforge.net/u/laurencemaar/\n\n");

	printf("This program will generate a file named TAZREG.NFO. Put this file in your install directory.\n\n");

	unsigned long rcount=0, year=0, month=0, amb=0, dev=0, security_code=12111;
	int mylength;
	char tempstring[201];
	int cyc;

	sprintf(tempstring,"Freeware via Laurence Maar");

	// Generate Codes
	//rcount=bp(tempstring, 12111);        // Calculate correct key
	rcount=1035550;		// I could not get the keygen code to work, so this is HARDCODED for "Freeware via Laurence Maar"

	//year=1977*511;  // 1977 is the year code for an unlimited license.
	year=2100*511;  // Year 2100 expiration date.
	month=12*453;
	amb=15*tempstring[0]+tempstring[1]+tempstring[2]+tempstring[3];
	dev=17*tempstring[0]+tempstring[1]+tempstring[2]+tempstring[3];

	printf("Name = %s\n",tempstring);
	printf("Key  = %i\n",rcount);
	printf("Year = %i\n",year);
	printf("Mon  = %i\n",month);
	printf("Amb  = %i\n",amb);
	printf("Dev  = %i\n\n",dev);

	FILE *stream;

	stream=fopen("TAZREG.NFO","w+");
	fprintf(stream,"%s\n\r",tempstring); // Name
	fprintf(stream,"%i\n\r",rcount); // Key
	fprintf(stream,"%i\n\r",year); // Year
	fprintf(stream,"%i\n\r",month); // Month
	fprintf(stream,"%i\n\r",amb); // AMB
	fprintf(stream,"%i\n\r",dev); // DEV
	fclose(stream);

	system("pause");

	return 0;
}


unsigned long bp(char *registration_string, unsigned int security_code){
	unsigned long rcount=0, asciivalue=0;
	char tempstring[201];int cyc;
	strset(tempstring,0);
	sprintf(tempstring,"%s",registration_string);

	for(cyc=0;cyc<strlen(tempstring);cyc++){
		rcount=rcount+tempstring[cyc]*security_code;
	}
	rcount+=12111;

	return rcount;
}
