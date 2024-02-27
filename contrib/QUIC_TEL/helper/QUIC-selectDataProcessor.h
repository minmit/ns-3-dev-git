#include "../model/QUIC-Context.h"
#include "../model/QUIC-Event.h"
#include "QUIC_TEL-Frame.h"
#include "QUIC-Stream.h"
#include "QUIC_TEL-Iterm_out.h"

#include "ns3/mt-event.h"
#include "ns3/mt-eventprocessor.h"
#include "ns3/mt-state.h"
#include "ns3/node.h"

#include <ctime> // std::time_t
#include <deque>
#include <map>
#include <vector>

namespace ns3
{

class QUICFrame;
class QUICPacketBuffer;
class Packet;

/**
 * \brief The class for a QUIC selectDataProcessor
 */
// QUIC selectDataProcessor
class selectDataProcessor : public MTEventProcessor
{
public:
    selectDataProcessor();
    ~selectDataProcessor();

    EventProcessorOutput* Process(MTEvent* e, EventProcessorOutput* epOut);
    bool IsValidEvent(MTEvent* e);

    void own_Process(SendEvent* e, QUICContext ctx, std::vector<QUICEvent *> events, iterm_out out);
};

} // namespace ns3
