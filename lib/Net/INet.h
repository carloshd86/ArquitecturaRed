#ifndef ___NET_H___
#define ___NET_H___

class INet
{
  public:

    virtual bool sendAndReceive(unsigned char *pOut, unsigned ulenOut, unsigned char *&pIn, unsigned int &uLenIn) = 0;
};

#endif