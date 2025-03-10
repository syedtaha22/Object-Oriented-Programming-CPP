/***********************************************************************************************
Task 3: Simulating Packet Transmission and Memory Management
In network communications, packets are sent and received dynamically, requiring careful memory management to prevent resource leaks. This task involves simulating the transmission of network packets while ensuring that all allocated memory is properly deallocated.
Your task is to implement a Packet base class that represents a network packet containing dynamically allocated data. Two derived classes, TCPSegment and UDPSegment, will extend this functionality. The TCPSegment class must include an additional dynamically allocated integer array to simulate a packet header, while the UDPSegment class will store a floating-point array representing simulated metadata.
Inside main, initialize a std::queue<Packet*> and populate it with randomly generated TCPSegment and UDPSegment instances. Then, simulate network transmission by dequeuing the segments one by one. Each time a packet is dequeued, it should be properly deleted to free memory.
Ensure that all dynamically allocated memory is freed correctly.

***********************************************************************************************/

#include <iostream>
#include <queue>
#include <cstdlib>

#include "MemoryTracker.hpp"

class Packet {
    char* data;
public:
    Packet() {
        std::cout << "Creating Packet: ";
        data = new char[1024];
    }
    virtual ~Packet() {
        std::cout << "Removing Packet" << std::endl;
        delete[] data;
    }

};

class TCPSegment : public Packet {
    int* header;
public:
    TCPSegment() {
        std::cout << "TCPSegment" << std::endl;
        header = new int[10];
    }
    ~TCPSegment() {
        std::cout << "TCPSegment: ";
        delete[] header;
    }
};

class UDPSegment : virtual public Packet {
    float* metadata;
public:
    UDPSegment() {
        std::cout << "UDPSegment" << std::endl;
        metadata = new float[10];
    }

    ~UDPSegment() {
        std::cout << "UDPSegment: ";
        delete[] metadata;
    }
};

int main() {

    {
        std::queue<Packet*> packetQueue;

        std::cout << "Adding packets to the queue" << std::endl;
        for (int i = 0; i < 10; i++) {
            std::cout << "\t";
            if (rand() % 2 == 0) packetQueue.push(new TCPSegment());
            else packetQueue.push(new UDPSegment());
        }

        std::cout << "Sending packets" << std::endl;
        while (!packetQueue.empty()) {
            Packet* packet = packetQueue.front();
            packetQueue.pop();
            std::cout << "\t";
            delete packet;
        }
    }

    MemoryTracker::report();

    return 0;
}