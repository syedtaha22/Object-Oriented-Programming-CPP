#include<iostream>
#include<string>
#include<cmath>


template<typename T>
class Operation {
public:
    virtual T apply(T input) = 0;
    virtual std::string name() = 0;
    virtual ~Operation() {}
};

template<typename T>
class Add : public Operation<T> {
    int value;
public:
    Add(int v) : value(v) {}
    T apply(T input) override { return input + value; }
    std::string name() override { return "Add"; }
};

template<typename T>
class Multiply : public Operation<T> {
    T value;
public:
    Multiply(T v) : value(v) {}
    T apply(T input) override { return input * value; }
    std::string name() override { return "Multiply"; }
};

// Expensive operation that takes time to compute, implement caching
template<typename T>
class Power : public Operation<T> {
    T exponent;
    T cached_input;
    T cached_output;

    // Handle negative exponent and positve both, not aalloed to use std::pow
    T compute_power(T input, int _exponent_) {
        if (_exponent_ == 0) return 1;
        if (_exponent_ == 1) return input;
        if (_exponent_ < 0) return 1 / compute_power(input, -_exponent_);
        return input * compute_power(input, _exponent_ - 1);
    }

public:
    Power(T exp) : exponent(exp), cached_input(0), cached_output(0) {}

    T apply(T input) override {
        if (input != cached_input) {
            cached_output = compute_power(input, exponent);
            cached_input = input;
        }
        return cached_output;
    }

    std::string name() override { return "Power"; }
};


template<typename T>
class CachedSine : public Operation<T> {
    T cached_input;
    T cached_output;
public:
    CachedSine() : cached_input(0), cached_output(0) {}

    T apply(T input) override {
        if (input != cached_input) {
            cached_output = sin(input);
            cached_input = input;
        }
        return cached_output;
    }

    std::string name() override { return "CachedSine"; }
};

template<typename T>
class CachedAdd : public Operation<T> {
    T cached_output;
public:
    CachedAdd() : cached_output(0) {}

    T apply(T input) override {
        cached_output += input;
        return cached_output;
    }

    std::string name() override { return "CachedAdd"; }
};

template<typename T>
class CachedMultiply : public Operation<T> {
    T cached_output;
public:
    CachedMultiply() : cached_output(1) {}

    T apply(T input) override {
        cached_output *= input;
        return cached_output;
    }

    std::string name() override { return "CachedMultiply"; }
};

template<typename T>
class OperationNode {
    Operation<T>* operation;
    OperationNode* next;
public:
    OperationNode(Operation<T>* op) : operation(op), next(nullptr) {}

    void setNext(OperationNode* nextNode) { next = nextNode; }

    T apply(T input) { return operation->apply(input); }

    OperationNode* getNext() { return next; }

    std::string name() { return operation->name(); }

    void clear() {
        if (operation) delete operation;
        operation = nullptr;
    }

};

template<typename T>
class OperationChain {
    OperationNode<T>* head;
    OperationNode<T>* tail;
public:
    OperationChain() : head(nullptr), tail(nullptr) {}

    void addOperation(Operation<T>* operation) {
        OperationNode<T>* newNode = new OperationNode<T>(operation);
        if (!head) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->setNext(newNode);
            tail = newNode;
        }
    }

    T apply(T input, bool verbose = true) {
        OperationNode<T>* current = head;
        if (verbose) std::cout << input;
        while (current) {
            input = current->apply(input);
            current = current->getNext();
            if (verbose) std::cout << " -> " << input;
        }
        if (verbose) std::cout << std::endl;
        return input;
    }

    void printOperations() {
        OperationNode<T>* current = head;
        while (current) {
            std::cout << current->name() << " -> ";
            current = current->getNext();
        }
        std::cout << "End" << std::endl;
    }

    ~OperationChain() {
        OperationNode<T>* current = head;
        while (current) {
            OperationNode<T>* next = current->getNext();
            current->clear(); // Clear the operation
            delete current;
            current = next;
        }
    }
};


int main() {
    OperationChain<float> chain;

    // Using new here is probably a bad idea....but left as is for simplicity
    chain.addOperation(new Add<float>(5));
    chain.addOperation(new Multiply<float>(2));
    chain.addOperation(new Power<float>(3));
    chain.addOperation(new CachedSine<float>());
    chain.addOperation(new CachedAdd<float>());
    chain.addOperation(new CachedMultiply<float>());

    std::cout << "Operations in the chain:" << std::endl;
    chain.printOperations();
    std::cout << std::endl;

    int input = 3;
    std::cout << "Input: " << input << std::endl;
    std::cout << "Result: ";
    chain.apply(input, true);


    std::cout << "\nApplying operations again to see caching in action:" << std::endl;
    std::cout << "Results:\n";
    chain.apply(input, true);
    chain.apply(input, true);
    chain.apply(input, true);

    return 0;
}