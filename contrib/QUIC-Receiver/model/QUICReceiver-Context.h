#ifndef QUICRECEIVER_CONTEXT_H
#define QUICRECEIVER_CONTEXT_H

#include <ctime> // std::time_t
#include <map>
#include <vector>
#include "ns3/ipv4-address.h"
#include "ns3/mt-state.h"
#include "../helper/QUICReceiver-Stream.h"


namespace ns3
{
class ModularTransport;

// QUIC context
class QUICContext: public MTContext
{ 
public:

    int flow_id;
    uint32_t max_data; // maximum amount of data that can be sent on the connection
    uint32_t max_stream_data; // maximum amount of data that can be sent on a stream
    std::vector<QUICStream> streams;

    QUICContext(int flow_id);

};
} // namespace ns3


#endif