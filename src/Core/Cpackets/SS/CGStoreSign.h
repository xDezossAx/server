//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGStoreSign.h 
// Written By  :
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_STORE_SIGN_H__
#define __CG_STORE_SIGN_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGStoreSign;
//
//////////////////////////////////////////////////////////////////////

class CGStoreSign : public Packet
{
public:
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_CG_STORE_SIGN; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() { return szBYTE + m_Sign.size(); }

	// get packet name
	string getPacketName() const throw() { return "CGStoreSign"; }

	// get packet's debug string
	string toString() const throw();

	string	getSign() const { return m_Sign; }
	void	setSign(const string& sign) { m_Sign = sign; }

private :
	string	m_Sign;
};


//////////////////////////////////////////////////////////////////////
//
// class CGStoreSignFactory;
//
// Factory for CGStoreSign
//
//////////////////////////////////////////////////////////////////////

class CGStoreSignFactory : public PacketFactory {

public:
	
	// constructor
	CGStoreSignFactory() throw() {}
	
	// destructor
	virtual ~CGStoreSignFactory() throw() {}

	
public:
	
	// create packet
	Packet* createPacket() throw() { return new CGStoreSign(); }

	// get packet name
	string getPacketName() const throw() { return "CGStoreSign"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_CG_STORE_SIGN; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const throw() { return szBYTE + 80; }
};


//////////////////////////////////////////////////////////////////////
//
// class CGStoreSignHandler;
//
//////////////////////////////////////////////////////////////////////

class CGStoreSignHandler {

public:

	// execute packet's handler
	static void execute(CGStoreSign* pCGStoreSign, Player* pPlayer) throw(Error);

};

#endif