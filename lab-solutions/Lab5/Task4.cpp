/*********************************
    Task 4: Refer to Task4.md
*********************************/

#include<iostream>
#include<vector>
#include<string>

class State {
    bool isFinal;
    State* t0; // Transition on 0
    State* t1; // Transition on 1
public:

    // Constructor, sets the state as non-final and transitions as nullptr
    State() : isFinal(false), t0(nullptr), t1(nullptr) {}

    void setFinal() { isFinal = true; } // Set the state as final
    void setTransition0(State* s) { t0 = s; } // Set the transition on 0
    void setTransition1(State* s) { t1 = s; } // Set the transition on 1
    State* getTransition0() const { return t0; } // Get the transition on 0
    State* getTransition1() const { return t1; } // Get the transition on 1
    bool isFinalState() { return isFinal; } // Check if the state is final
};

class DFA {
    std::vector<State*> Q; // Set of states
    State* q0; // Start state

public:

    // Initialize the DFA with n states
    DFA(int n = 0) : q0(nullptr) { for (int i = 0; i < n; i++) Q.push_back(new State()); }

    ~DFA() { for (State* q : Q) delete q; } // Destructor
    void addState() { Q.push_back(new State()); } // Add a new state to the DFA

    // Add transition from state 'from' to state 'to' on character 'c'
    void addTransition(int from, char c, int to) {
        if (c == '0') Q[from]->setTransition0(Q[to]);
        else Q[from]->setTransition1(Q[to]);
    }

    void setFinalState(int i) { Q[i]->setFinal(); } // Set the state i as final
    void setStart(int i) { q0 = Q[i]; } // Set the start state

    // Check if the DFA is complete
    bool isComplete() const {
        bool complete = true;
        std::vector<std::string> errors;

        if (q0 == nullptr) {
            errors.emplace_back("Start state is not defined");
            complete = false;
        }

        for (size_t i = 0; i < Q.size(); i++) {
            if (!Q[i]->getTransition0())
                errors.emplace_back("Undefined Transition: " + std::to_string(i) + " x '0' = ?");
            if (!Q[i]->getTransition1())
                errors.emplace_back("Undefined Transition: " + std::to_string(i) + " x '1' = ?");
            if (!errors.empty()) complete = false;
        }

        for (const auto& error : errors) std::cout << error << std::endl;

        return complete;
    }

    bool accepts(const std::string& s) const {
        State* current = q0;
        for (char c : s) {
            if (c == '0') current = current->getTransition0();
            else current = current->getTransition1();
        }
        return current->isFinalState();
    }
};


template<int num_test_cases, int max_length>
class TestCaseGenerator {

    // Generate a string with 00 as substring
    std::string true_string() const {
        int length = rand() % max_length - 1; // lenght - 2 (for 00)
        std::string test_case = "00";

        for (int i = 0; i < length; i++) {
            char c = (rand() % 2) ? '0' : '1';
            if (rand() % 2) test_case = c + test_case;
            else test_case += c;
        }
        return test_case;
    }

    // Generate a random string
    std::string false_string() const {
        int length = rand() % max_length + 1;
        std::string test_case;
        char prev;
        for (int i = 0; i < length; i++) {
            if (prev == '0') prev = '1';
            else  prev = (rand() % 2) ? '0' : '1';
            test_case += prev;
        }
        return test_case;
    }

public:
    // Generate num_of_test_cases test cases, with lenght <= max_length
    std::vector<std::string> operator()(float true_ratio = 0.5) const {
        srand(time(0));
        std::vector<std::string> test_cases(num_test_cases);
        for (int i = 0; i < num_test_cases; i++)
            test_cases[i] = (rand() % 100 < true_ratio * 100) ? true_string() : false_string();
        return test_cases;
    }
};

int main() {
    // DFA that accepts strings with 00 as substring
    DFA dfa(3);

    dfa.addTransition(0, '0', 1);
    dfa.addTransition(0, '1', 0);
    dfa.addTransition(1, '0', 2);
    dfa.addTransition(1, '1', 0);
    dfa.addTransition(2, '0', 2);
    dfa.addTransition(2, '1', 2);

    dfa.setStart(0);
    dfa.setFinalState(2);

    if (dfa.isComplete()) {
        std::vector<std::string> test_cases = TestCaseGenerator<20, 20>()(0.5);
        for (const std::string& test_case : test_cases) {
            std::cout << test_case << ": " << std::boolalpha << dfa.accepts(test_case) << std::endl;
        }
    }

    return 0;
}