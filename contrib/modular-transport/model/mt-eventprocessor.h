#ifndef MT_EVENTPROCESSOR_H
#define MT_EVENTPROCESSOR_H

#include <vector>
#include <utility> // std::pair

//mostly copied from eric's branch, though send if possible is mine
namespace ns3
{

class MTEvent;
class MTContext;
class Packet;
struct EventProcessorOutput{
     std::vector<MTEvent> newEvents;
     MTContext* updatedContext;
     std::vector<Packet> packetToSend;
 };
/**
 * \brief The base class for event processor. This is virtual class.
 */
struct EventProcessorOutput;
class MTEventProcessor
{
public:
    MTEventProcessor();

    /**
     * \brief Process the event and return the processed results.
     * \param e The input event to be processed.
     * \param c The context of the Mt connection.
     * \return The modified context and new generated event if exits.
     */
    virtual EventProcessorOutput* Process(MTEvent* e, MTContext* c) = 0;

    /**
     * \brief Check if the input event is valid event type for the processor.
     * \param e The input event to be processed.
     * \return True if input event type matches the processor type, false otherwise.
     */
    virtual bool IsValidEvent(MTEvent e) = 0;
};

} // namespace ns3

#endif
