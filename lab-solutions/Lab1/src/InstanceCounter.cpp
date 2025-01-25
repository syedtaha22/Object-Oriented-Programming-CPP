#include "../headers/InstanceCounter.hpp"

int InstanceCounter::count = 0; // Initialize the static member variable

// Constructor to increment count
InstanceCounter::InstanceCounter() {
    count++;
}

// Method to return the current value of count
int InstanceCounter::getCount() {
    return count;
}