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
#include "include/LeapComm.h"

using namespace LeapClient;

LeapComm::LeapComm(void)
{
	if(WSAStartup(MAKEWORD(2,0),&lc_WSAData)==SOCKET_ERROR)
	{
		std::cerr << "Socket initialize failed!" << std::endl;
		return;
	}
	
	sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if ( sock == SOCKET_ERROR)
	{
		std::cerr << "Socket create failed!" << std::endl;
		WSACleanup();
		return;
	}

	ServerAddr.sin_family=AF_INET;  
	ServerAddr.sin_port=htons(LC_PORT);  
	ServerAddr.sin_addr.s_addr=inet_addr(LC_IPADDR);
	memset(ServerAddr.sin_zero, 0x00, 8);
	if(connect(sock,(LPSOCKADDR)&ServerAddr,sizeof(ServerAddr))==SOCKET_ERROR)
	{
		std::cerr << "Connect failed!" << std::endl;
		std::cerr<<"Connect Error::"<<GetLastError()<<std::endl;
		closesocket(sock);
		WSACleanup();
		return;
	}
}


LeapComm::~LeapComm(void)
{
	closesocket(sock);
	WSACleanup();
	return;
}

int LeapComm::lc_send(char* lc_msg_buf)
{
	send(sock,lc_msg_buf,2048,0);
	std::cerr << "send execute" << std::endl;

	return 0;
}

