#include <stdio.h>
#include "WakeOnLan.h"

void printUsage()
{
	printf("Usage example: wol 01:23:45:67:89:ab\n");
}

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printUsage();
		return 1;
	}

	unsigned char address[6];
	if(sscanf(argv[1],"%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",address,address+1,address+2,address+3,address+4,address+5)!=6)
	{
		printUsage();
		return 1;
	}

	WakeOnLan::SendMagicPacket(address);
}
