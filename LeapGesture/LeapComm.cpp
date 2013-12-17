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


namespace LeapClient {

char* LeapComm::LC_IPADDR = "127.0.0.1";
unsigned short LeapComm::LC_PORT = 15501;

LeapComm::LeapComm(void)
{
	
}


LeapComm::~LeapComm(void){
	closesocket(_sock);
	WSACleanup();
	return;
}

int LeapComm::lc_initialize()
{
	if(WSAStartup(MAKEWORD(2,0),&_lc_WSAData) == SOCKET_ERROR) {
		std::cerr << "Socket initialize failed!" << std::endl;
		return -1;
	}
	
	_sock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if ( _sock == SOCKET_ERROR){
		std::cerr << "Socket create failed!" << std::endl;
		WSACleanup();
		return -1;
	}

	_ServerAddr.sin_family = AF_INET;  
	_ServerAddr.sin_port = htons(LC_PORT);  
	_ServerAddr.sin_addr.s_addr = inet_addr(LC_IPADDR);
	memset(_ServerAddr.sin_zero, 0x00, sizeof(_ServerAddr.sin_zero));
	if(connect(_sock,(LPSOCKADDR)&_ServerAddr,sizeof(_ServerAddr)) == SOCKET_ERROR) {
		std::cerr << "Connect failed!" << std::endl;
		std::cerr << "Connect Error::" << GetLastError() << std::endl;
		closesocket(_sock);
		WSACleanup();
		return -1;
	}
}

int LeapComm::lc_send(char* lc_msg_buf){
	int ret = send(_sock,lc_msg_buf,2048,0);
	std::cerr << "send execute" << std::endl;

	if (ret == 0) {
		return sizeof(lc_msg_buf);
	}
	else {
		return -1;
	}
}

}