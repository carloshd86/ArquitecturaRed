#ifndef __MESSAGES_H__
#define __MESSAGES_H__


#include <stdint.h>


inline bool writeInt32(unsigned char *&pBuffer, unsigned int &iBufferFreeSpace, uint32_t value)
{
	bool bRet = false;

	if (iBufferFreeSpace >= sizeof(uint32_t))
	{
#ifdef BIG_ENDIAN
		*((uint32_t*)pBuffer) = INT_SWAP(value); 
#else
		*((uint32_t*)pBuffer) = value;
#endif 
		pBuffer          += sizeof(uint32_t);
		iBufferFreeSpace -= sizeof(uint32_t);
		bRet = true;
	}
	return bRet;
}

inline bool readInt32(unsigned char *&pBuffer, unsigned int &iBufferSize, uint32_t &value)
{
	bool bRet = false;

	if (iBufferSize >= sizeof(uint32_t))
	{
#ifdef BIG_ENDIAN
		value = INT_SWAP(*((uint32_t*)(pBuffer)) );
#else // #ifdef BIG_ENDIAN
		value = *((uint32_t*)(pBuffer));
#endif // #ifdef BIG_ENDIAN
		pBuffer     += sizeof(uint32_t);
		iBufferSize -= sizeof(uint32_t);
		bRet = true;
	}
	return bRet;
}


#endif
