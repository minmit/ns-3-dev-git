#include "mt-dispatcher.h"
#include "TCP-dispatcher.h"
#include "mt-event.h"
#include "TCP-event.h"
#include "mt-eventprocessor.h"
#include "TCP-eventprocessor.h"
namespace ns3{
TCPDispatcher::TCPDispatcher(){}

//#TODO modify dispatcher for ACK base on type
MTEventProcessor* TCPDispatcher::dispatch(MTEvent anything){
    MTEventProcessor* ChosenProcessor = new SendIfPossible();
    return ChosenProcessor;
}
//TODO: Add dispatch(TCPeventtype)
}
