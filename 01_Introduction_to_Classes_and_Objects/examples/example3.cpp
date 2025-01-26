/*
    Example of Abstraction
*/

#include <iostream>


/*************************************** Backend Code ***************************************/
class SmartLight {
private:
    bool isOn; // Represents whether the light is on or off
public:
    SmartLight() { /* implementation */ } // Constructor to initialize the light state
    void turnOn() { /* implementation */ } // Function to turn on the light
    void turnOff() { /* implementation */ } // Function to turn off the light
    bool isLightOn() const { /* implementation */ } // Function to check if the light is on or off
};
/********************************************************************************************/


// What the user interacts with:
int main() {
    SmartLight light;

    /*
        The user does not need to know how the light turns on or off internally.
        They only know that inorder to turn on the light, they need to call the turnOn() function.
        and to turn off the light, they need to call the turnOff() function.

        This is much like in real life, where you don't need to know how the light switch works internally,
        you just need to know that flipping the switch down turns the light on and flipping it up turns it off.
    */

    light.turnOn();
    light.turnOff();
    light.turnOff();

    return 0;
}
