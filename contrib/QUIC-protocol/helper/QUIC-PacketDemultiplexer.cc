#include "ns3/mt-state.h"
#include "ns3/ipv4-l3-protocol.h"
#include "ns3/node.h"

#include "QUIC-PacketDemultiplexer.h"
#include "QUIC-IntermediateOutput.h"
#include "QUIC-Header.h"

#include "../model/QUIC-Event.h"
#include "../model/QUIC-Context.h"

#include <vector>
#include <utility>   // std::pair
#include <algorithm> // std::min, std::max
#include <iostream>

namespace ns3
{

class Packet;
class ModularTransport;


QUICPacketDemultiplexer::QUICPacketDemultiplexer():
MTEventProcessor()
{}
bool
QUICPacketDemultiplexer::IsValidEvent(MTEvent* e)
{
    return true;
}

EventProcessorOutput* QUICPacketDemultiplexer::Process(MTEvent* e, EventProcessorOutput* epOut){
    ReceivePacketEvent* rpe = static_cast<ReceivePacketEvent*>(e);
    recvPacket = rpe->receivered;
    std::cout << recvPacket->GetSize() << std::endl;

    demultiplexePacket();

    //update the context if needed
    QUICContext* newContext = static_cast<QUICContext*>(epOut->context);

    //add any new events (e.g. application wants to terminate connection)
    std::vector<MTEvent*> newEvents;

    //update packet to be send (e.g. connection termination, state change)
    std::vector<Packet> packetTobeSend;

    QUICIntermediateOutput* intermOutput = new QUICIntermediateOutput;
    intermOutput->PacketDemultiplexerOut = FrameToStream;

    std::cout << "FrameToStream Size: " << FrameToStream.size() << std::endl;
    EventProcessorOutput *Output = new EventProcessorOutput;
        Output->newEvents=newEvents;
        Output->context=newContext;
        Output->packetToSend=packetTobeSend;
        Output->intermOutput = intermOutput;
    return Output;
}

void QUICPacketDemultiplexer::demultiplexePacket() {
    while (recvPacket->GetSize() > 0 ){ 
        QUICFrameHeader header;
        uint32_t res = recvPacket->RemoveHeader(header);
        
        uint8_t buffer[header.length];
        recvPacket->CopyData(buffer, header.length);

        std::string currentData;
        for (auto a : buffer ){
            currentData += a;
        }
        std::cout << currentData << std::endl;

        recvPacket->RemoveAtStart( header.length );


        // restructure:::::
        // new pair of <QUICFrameHeader, frameData>
        std::pair<QUICFrameHeader, std::string> currentPair = std::make_pair<QUICFrameHeader, std::string>( std::move(header), std::move(currentData) );
        
        // add to FrameToStream
        FrameToStream.push_back( currentPair );
    }
    return;
}
} // namespace ns3