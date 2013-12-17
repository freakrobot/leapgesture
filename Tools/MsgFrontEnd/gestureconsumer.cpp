#include "gestureconsumer.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Server::Server(QObject* parent): QObject(parent)
{
  connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));

  server.listen(QHostAddress::LocalHost, 15501);
}

Server::~Server()
{
  client->close();
  server.close();
}

void Server::acceptConnection()
{
  cerr << "get a link!" << endl;
  client = server.nextPendingConnection();

  connect(client, SIGNAL(readyRead()),
    this, SLOT(startRead()));
}

void Server::startRead()
{
  cerr << "get msg!" << endl;
  char *buffer = (char*)malloc(2048*sizeof(char));
  client->read(buffer,2048);
  cerr << *buffer << endl;
}
