/************************************************************************************************
    Task 4:
        In many real-world scenarios, actions happen in a sequence, but sometimes there are
        alternate paths. For example, when using an ATM, you may either enter a correct PIN
        and proceed, or enter an incorrect PIN and retry. Similarly, when filling out an online
        form, you might submit it successfully or cancel it midway.

        Your task is to implement an Event Sequencer that models such sequential processes with
        optional alternate paths.

        Each event represents a step in a process and contains:
            • A description of what happens at this step.
            • A pointer to the next event in the sequence.
            • An optional alternate path (if an event can lead to a different outcome).
        The sequencer will allow:
            • Moving to the next event in the sequence.
            • Choosing an alternate path when available.
            • Getting the current event's description.
        Implement the following classes:
            Event:
                • Members:
                    1. description: The event message.
                    2. next: Pointer to the next event.
                    3. alternate: An optional alternative event path.
                • Methods:
                    1. void setNext(Event* e) – Sets the next event.
                    2. void setAlternate(Event* e) – Sets the alternate event.
                    3. std::string getDescription() – Returns the event description.
            EventSequencer:
                • Members:
                    1. head – The starting event.
                    2. current – The current event in sequence.
                • Methods:
                    1. void start(Event* e) – Initializes the sequencer with an event.
                    2. void next() – Moves to the next event (if available).
                    3. void chooseAlternate() – Moves to the alternate event (if available).
                    4. std::string getCurrentEvent() – Returns the current event description.
************************************************************************************************/

#include <iostream>
#include <string>

class Event {
    std::string description;
    Event* next;
    Event* alternate;

public:
    Event(std::string description) : description(description), next(nullptr), alternate(nullptr) {}

    void setNext(Event* e) { next = e; }

    void setAlternate(Event* e) { alternate = e; }

    std::string getDescription() { return description; }

    Event* getNext() { return next; }

    Event* getAlternate() { return alternate; }
};

class EventSequencer {
    Event* head;
    Event* current;

public:
    EventSequencer() : head(nullptr), current(nullptr) {}

    void start(Event* e) {
        head = current = e;
    }

    void next() {
        if (current != nullptr) current = current->getNext();
    }

    void chooseAlternate() {
        if (current != nullptr) current = current->getAlternate();
    }

    std::string getCurrentEvent() {
        return current != nullptr ? current->getDescription() : "No event";
    }
};

int main() {

    Event e1("You arrive at the bank at midnight.");
    Event e2("You pick the lock and enter the bank.");
    Event e3("You open the vault and grab the money.");
    Event e4("An alarm goes off! Do you run or hide? ");
    Event e5("The police arrive and arrest you.");
    Event e6("You escape successfully with the money!");
    Event e7("You hide in a closet until morning and sneak out.");

    // Setting up the sequence
    e1.setNext(&e2);
    e2.setNext(&e3);
    e3.setNext(&e4);
    e4.setNext(&e5);       // Default action: Running away (successful escape)
    e4.setAlternate(&e7);  // Alternate choice: Hiding instead of running
    e7.setNext(&e6);       // Hiding fails, leading to arrest

    // Using the sequencer
    EventSequencer seq;
    seq.start(&e1);

    std::cout << seq.getCurrentEvent() << std::endl;  // "You arrive at the bank at midnight."
    seq.next();
    std::cout << seq.getCurrentEvent() << std::endl;  // "You pick the lock and enter the bank."
    seq.next();
    std::cout << seq.getCurrentEvent() << std::endl;  // "You open the vault and grab the money."
    seq.next();
    std::cout << seq.getCurrentEvent();  // "An alarm goes off! Do you run or hide?"

    std::string choice;
    std::cin >> choice;

    if (choice == "run") {
        seq.next();
        std::cout << seq.getCurrentEvent() << std::endl;  // "You escape successfully with the money!"
    }
    else if (choice == "hide") {
        seq.chooseAlternate();
        std::cout << seq.getCurrentEvent() << std::endl;  // "You hide in a closet until morning and sneak out."
        seq.next();
        std::cout << seq.getCurrentEvent() << std::endl;  // "The police arrive and arrest you."
    }

    return 0; // Return 0 to indicate successful completion
}