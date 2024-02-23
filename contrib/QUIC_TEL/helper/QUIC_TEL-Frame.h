#ifndef QUIC_TEL_FRAME
#define QUIC_TEL_FRAME

#include <vector>

namespace ns3
{
    class Frame
    {public:
        int data_length;
        int stream_id;
        int offset;
        std::vector<char> data;//stream data;  
        Frame(int data_length, int stream_id, int offset);
    };
} // namespace ns3

#endif