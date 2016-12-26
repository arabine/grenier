
#include "DeimosEvent.h"


DeimosMessageEvent::DeimosMessageEvent() : QEvent( (QEvent::Type)DeimosMessage )
{

}

DeimosDataEvent::DeimosDataEvent() : QEvent( (QEvent::Type)DeimosData )
{

}



//=============================================================================
// Fin du fichier
//=============================================================================
