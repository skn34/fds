#include <iostream>

using namespace std;

const int MAX_ORDERS = 5; // Maximum capacity of the circular queue

class CircularQueue {
private:
    int front, rear, itemCount;
    int orders[MAX_ORDERS];

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        itemCount = 0;
    }

    bool isFull() {
        return (front == 0 && rear == MAX_ORDERS - 1) || (front == rear + 1);
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int order) {
        if (isFull()) {
            cout << "Sorry, the queue is full. Cannot accept more orders." << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % MAX_ORDERS;
        }
        orders[rear] = order;
        itemCount++;
        cout << "Order " << order << " has been placed successfully." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "No orders to dequeue. The queue is empty." << endl;
            return;
        }

        int removedOrder = orders[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_ORDERS;
        }
        itemCount--;
        cout << "Order " << removedOrder << " has been served and dequeued." << endl;
    }

    void displayOrders() {
        if (isEmpty()) {
            cout << "No orders to display. The queue is empty." << endl;
            return;
        }

        cout << "Current Orders in the Queue: ";
        int i = front;
        while (i != rear) {
            cout << orders[i] << " ";
            i = (i + 1) % MAX_ORDERS;
        }
        cout << orders[rear] << endl;
    }
};

int main() {
    CircularQueue pizzaQueue;

    while (true) {
        cout << "\nPizza Parlor Simulation Menu:\n";
        cout << "1. Place an Order\n";
        cout << "2. Serve and Dequeue an Order\n";
        cout << "3. Display Orders\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int orderNumber;
                cout << "Enter the order number: ";
                cin >> orderNumber;
                pizzaQueue.enqueue(orderNumber);
                break;
            }
            case 2: {
                pizzaQueue.dequeue();
                break;
            }
            case 3: {
                pizzaQueue.displayOrders();
                break;
            }
            case 4: {
                cout << "Exiting Pizza Parlor Simulation." << endl;
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

