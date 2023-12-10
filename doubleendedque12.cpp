#include <iostream>
#include <deque>

using namespace std;

void displayDengue(const deque<int>& dengue) {
    if (dengue.empty()) {
        cout << "Dengue is empty." << endl;
        return;
    }

    cout << "Current Dengue Status: ";
    for (size_t i = 0; i < dengue.size(); ++i){
    	cout << dengue[i] << "  ";
	}
    cout << endl;
}

int main() {
    deque<int> dengue;

    while (true) {
        cout << "\nDengue Simulation Menu:\n";
        cout << "1. Insert from Front\n";
        cout << "2. Insert from Rear\n";
        cout << "3. Pop from Front\n";
        cout << "4. Pop from Rear\n";
        cout << "5. Display Dengue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int patient;
                cout << "Enter patient number to insert from front: ";
                cin >> patient;
                dengue.push_front(patient);
                break;
            }
            case 2: {
                int patient;
                cout << "Enter patient number to insert from rear: ";
                cin >> patient;
                dengue.push_back(patient);
                break;
            }
            case 3: {
                if (!dengue.empty()) {
                    cout << "Patient " << dengue.front() << " popped from front." << endl;
                    dengue.pop_front();
                } else {
                    cout << "Dengue is already empty." << endl;
                }
                break;
            }
            case 4: {
                if (!dengue.empty()) {
                    cout << "Patient " << dengue.back() << " popped from rear." << endl;
                    dengue.pop_back();
                } else {
                    cout << "Dengue is already empty." << endl;
                }
                break;
            }
            case 5: {
                displayDengue(dengue);
                break;
            }
            case 6: {
                cout << "Exiting Dengue Simulation." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
            }
        }
    }

    return 0;
}

