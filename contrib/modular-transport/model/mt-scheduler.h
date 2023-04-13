//Schedular add generate events, and add them to queue?
#ifndef MT_SCHEDULER_H
#define MT_SCHEDULER_H
#include <string>
namespace ns3{
class MTEvent;
class MTEventQueue;
class MTHeader;
class MTScheduler{
    public:
    MTScheduler(){}
    // virtual void OpsBeforeSend(); // Compute Hash
   // virtual void OpsAfterRecieved(); //Verify Hash, then return a event
    //virtual MTEvent GenerateEventOnRecive(MTHeader); //Produce event to be added to EventQueue
    //virtual MTEvent GenerateEventOnInitate(MTHeader);
    virtual MTEvent* GetNextEvent()=0;
    virtual void AddEvent(MTEvent*)=0;
    virtual MTEvent* CreateSendEvent(int flow_id, long time)=0;
    virtual MTEvent* SendPacket(int flow_id, long time)=0;
    virtual MTEvent* AddData(int flow_id, long time, std::string text, int stream)=0;
    virtual MTEvent* ACKPacket(int flow_id, long time, int packetNum)=0;
    //#TODO ACK
    virtual bool isEmpty()=0;
};
}
#endif
