#include <iostream>
#include <queue>
using namespace std;

class Patient {
public:
    string name;
    int priority;

    // Overloading the comparison operator
    bool operator<(const Patient& other) const {
        return priority < other.priority;
    }
};

int main() {
    priority_queue<Patient> hospitalQueue;

    // Adding patients to the queue
    hospitalQueue.push({"John", 1});  // Serious
    hospitalQueue.push({"Alice", 2}); // Non-serious
    hospitalQueue.push({"Bob", 3});   // General Checkup
	
    // Serving patients based on priority
    while (!hospitalQueue.empty()) {
        Patient patient = hospitalQueue.top();
        hospitalQueue.pop();

        cout << "Serving patient: " << patient.name << " (Priority: " << patient.priority << ")" << endl;
    }

    return 0;
}

