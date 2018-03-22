#include "WakeOnLan.h"
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
 
namespace WakeOnLan
{
	void SendMagicPacket(const unsigned char *macaddress)
	{
		int sock;
	 	struct sockaddr_in addr;
		int yes = 1;

		char packet[102];
		memset(packet,0xFF,6);
		for(int i=0;i<16;i++)
			memcpy(&packet[(i+1)*6],macaddress,6);

		sock = socket(AF_INET, SOCK_DGRAM, 0);

		addr.sin_family = AF_INET;
		addr.sin_port = htons(12345);
		addr.sin_addr.s_addr = inet_addr("255.255.255.255");

		setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (char *)&yes, sizeof(yes));

		sendto(sock, packet, 102, 0, (struct sockaddr *)&addr, sizeof(addr));

		close(sock);
	}
}
