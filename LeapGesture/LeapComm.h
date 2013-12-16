#pragma once
#include <winsock2.h>
#include <string>
#include <cstdlib>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")

namespace LeapClient
{
	static const char* LC_IPADDR = "127.0.0.1";
	static const unsigned short LC_PORT = 15501;
	class LeapComm
	{
		public:
			LeapComm(void);
			~LeapComm(void);

			int lc_send(char*);
			
		private:
			WSADATA lc_WSAData;
			SOCKET sock;
			struct sockaddr_in ServerAddr;
	};
}

