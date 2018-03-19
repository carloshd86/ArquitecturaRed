//#include "globals.h"
#include "Net.h"
#include <Windows.h>

#define PACKET_TIMEOUT      0
#define CONNECTION_TIME_OUT (5 * 60000)

// ****************************************************************************************
//
// ****************************************************************************************
CNet::CNet()
{
  m_bIsServer   = false;
  m_iPort       = 0;
  m_pHost       = nullptr;
  m_pConnection = nullptr;
}

// ****************************************************************************************
//
// ****************************************************************************************
CNet::~CNet()
{
  enet_deinitialize();
}

// ****************************************************************************************
//
// ****************************************************************************************
bool CNet::init()
{
  bool bRet = initAddressInfo();
  if (bRet)
    bRet = initEnet();

  return bRet;
}

// ****************************************************************************************
//
// ****************************************************************************************
bool CNet::sendAndReceive(unsigned char *pOut, unsigned int uLenOut, unsigned char *&pIn, unsigned int &uLen)
{
  bool bRet = false;

  if (uLenOut)
  {
    // Enviamos
    ENetPacket *pPacket = enet_packet_create(pOut, uLenOut, ENET_PACKET_FLAG_RELIABLE);
    // Conexión, channelId, paquete);
    enet_peer_send(m_pConnection, 0, pPacket);
  }
  
  // Recibimos
  ENetEvent tEvent;
  bool bReceived = false;
  //while (!bReceived)
  {
    int iRet = enet_host_service(m_pHost, &tEvent, PACKET_TIMEOUT);
    if ((iRet > 0) && (tEvent.type == ENET_EVENT_TYPE_RECEIVE))
    {
      pIn  = tEvent.packet->data;
      uLen = tEvent.packet->dataLength;
      bReceived = true;
      bRet = true;
    }
  }
  
  return bRet;
}


// ****************************************************************************************
// PRIVATE: initAddressInfo.
// ****************************************************************************************
bool CNet::initAddressInfo()
{
  bool bRet = false;
  LPWSTR lpwCommandLine = GetCommandLine();
  int iNumArgs = 0;
  LPWSTR *args = CommandLineToArgvW(lpwCommandLine, &iNumArgs);
  if (iNumArgs == 4)
  { // Es el cliente -> recibe como argumentos la direcicón IP del destino y el puerto
    m_bIsServer = false;
    wcstombs(m_strRemoteIP, args[2], MAX_IP_SIZE);
    m_iPort = (int)wcstol(args[3], nullptr, 10);
    bRet = true;
  } else
  { // Esl servidor -> recibe como argumento el puerto local de escucha
     m_bIsServer = true;
     m_iPort = (int)wcstol(args[2], nullptr, 10);
     bRet = true;
  }
  LocalFree(args);
  return bRet;
}

// ****************************************************************************************
// PRIVATE: initEnet.
// ****************************************************************************************
bool CNet::initEnet()
{
  bool bRet = false;

  if (!enet_initialize())
    bRet = m_bIsServer ? initServer() : initClient();

  return bRet;
}

// ****************************************************************************************
// PRIVATE: initEnet.
// ****************************************************************************************
bool CNet::initServer()
{
  bool bRet = false;

  ENetAddress tAddress;
  tAddress.host = ENET_HOST_ANY;
  tAddress.port = m_iPort;

  // Dirección, número máximo de conexiones, numero máximo de canales, ancho de bande de entrada, ancho de banda de salida
  m_pHost = enet_host_create(&tAddress, 1, 1, 0, 0);

  // Esperamos la llegada de una conexión
  if (m_pHost != nullptr)
    bRet = waitConnection();

  return bRet;
}

// ****************************************************************************************
// PRIVATE: initEnet.
// ****************************************************************************************
bool CNet::initClient()
{
  // Dirección, número máximo de conexiones, numero máximo de canales, ancho de bande de entrada, ancho de banda de salida
  m_pHost = enet_host_create(nullptr, 1, 1, 0, 0);

  // Conectamos con el servidor.
  ENetAddress tAddress;
  enet_address_set_host(&tAddress, m_strRemoteIP);
  tAddress.port = m_iPort;

  // Cliente, destino, número de canales, datos iniciales
  m_pConnection = enet_host_connect(m_pHost, &tAddress, 1, 0);

  ENetEvent tEvent;
  bool bConnected = false;
  while (!bConnected)
  {
    int iRet = enet_host_service(m_pHost, &tEvent, 100);
    if ((iRet > 0) && tEvent.type == ENET_EVENT_TYPE_CONNECT)
    {
      bConnected = true;
      OutputDebugStringA("Connected");
      int sync = 0;
      ENetPacket *pPacket = enet_packet_create(&sync, sizeof(sync), ENET_PACKET_FLAG_RELIABLE);
      enet_peer_send(m_pConnection, 0, pPacket);
      enet_host_flush(m_pHost);
    }
  }

  return (m_pConnection != nullptr);
}

// ****************************************************************************************
// PRIVATE: connect.
// ****************************************************************************************
bool CNet::waitConnection()
{
  bool bRet = false;

  ENetEvent tEvent;
  int iRet = enet_host_service(m_pHost, &tEvent, CONNECTION_TIME_OUT);
  if ((iRet > 0) && (tEvent.type == ENET_EVENT_TYPE_CONNECT))
  {
    m_pConnection = tEvent.peer;
    bRet = true;
  }

  return bRet;
}