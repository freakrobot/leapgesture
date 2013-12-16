#include "LeapComm.h"

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

