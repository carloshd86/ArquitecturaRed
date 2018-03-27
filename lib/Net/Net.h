#ifndef ___CNET____
#define ___CNET____

#include "INet.h"
#include "enet/enet.h"

#define MAX_IP_SIZE 16

class CNet : public INet
{
  public:
    CNet();
    ~CNet();

    bool init();

    // FROM INet
    virtual bool sendAndReceive(unsigned char *pOut, unsigned ulenOut, unsigned char *&pIn, unsigned int &uLenIn);

  private:
    bool initAddressInfo();
    bool initEnet       ();
    bool initServer     ();
    bool initClient     ();
    bool waitConnection ();

    bool m_bIsServer;
    char m_strRemoteIP[MAX_IP_SIZE];
    int  m_iPort;

    ENetHost *m_pHost;
    ENetPeer *m_pConnection;
};

#endif