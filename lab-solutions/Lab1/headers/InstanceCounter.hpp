#ifndef INSTANCE_COUNTER_HPP
#define INSTANCE_COUNTER_HPP

// Define the InstanceCounter class
class InstanceCounter {
    static int count; // Private static member variable

public:
    // Constructor to increment count
    InstanceCounter();

    // Method to return the current value of count
    static int getCount();

};

#endif // INSTANCE_COUNTER_HPP