//////////////////////////////////////////////////////////////////////
//
// Filename    : GCRemoveStoreItemHandler.cc
// Written By  : reiot@ewestsoft.com
// Description :
//
//////////////////////////////////////////////////////////////////////

// include files
#include "GCRemoveStoreItem.h"

//////////////////////////////////////////////////////////////////////
//
// Ŭ���̾�Ʈ���� �����κ��� �޽����� �޾����� ����Ǵ� �޽���̴�.
//
//////////////////////////////////////////////////////////////////////
void GCRemoveStoreItemHandler::execute ( GCRemoveStoreItem * pPacket , Player * pPlayer )
	 throw ( ProtocolException , Error )
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
	
#ifdef __GAME_CLIENT__
	//cout << pPacket->toString() << endl;
#endif

	__END_DEBUG_EX __END_CATCH
}