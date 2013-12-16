/******************************************************************************\
* Copyright 2013 Chen Cheng & Huang Weichao

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
\******************************************************************************/
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
			WSADATA _lc_WSAData;
			SOCKET _sock;
			struct sockaddr_in _ServerAddr;
	};
}

