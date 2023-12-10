#include<iostream>
#include<cstring>
using namespace std;

struct node {
    string name;
    int time;
    struct node *next;
    struct node *prev;
};

class App {
    struct node *head, *p, *temp, *q;
    int size = 0;

public:
    App() {
        head = NULL;
        p = NULL;
        temp = NULL;
    }

    void bookappointment() {
        if (p == NULL) {
            p = new (struct node);
            cout << "Enter your name: ";
            cin >> p->name;
            cout << "Enter slot time: ";
            cin >> p->time;
            p->next = NULL;
            p->prev = NULL;
            head = p;
        } else {
            temp = new (struct node);
            cout << "Enter your name: ";
            cin >> temp->name;
            cout << "Enter slot time: ";
            cin >> temp->time;
            if (p->next != NULL)
                p = p->next;
            temp->prev = p;
            p->next = temp;
            temp->next = NULL;
        }
        size += 1;
    }

    void freeslot() {
        int h = 12, x;
        cout << "\n";
        while (h <= 18) {
            p = head;
            x = 0;
            while (p != NULL) {
                if (p->time == h)
                    x = 1;
                p = p->next;
            }
            if (x == 0)
                cout << "Time slot " << h << " is free\n";
            h++;
        }
    }

    void cancelappointment() {
        cout << "\nEnter your name to cancel your appointment: ";
        string n;
        cin >> n;
        p = head;
        while (p != NULL) {
            if (p->name == n) {
                if (p == head) {
                    head = p->next;
                    if (head != NULL)
                        head->prev = NULL;
                } else if (p->next == NULL) {
                    temp = p->prev;
                    if (temp != NULL)
                        temp->next = NULL;
                } else {
                    p->next->prev = p->prev;
                    p->prev->next = p->next;
                }
                size -= 1;
                cout << "Appointment cancelled successfully!!\n";
                delete (p);
                break;
            }
            p = p->next;
        }
        if (p == NULL)
            cout << "No name found. Try entering a proper name\n";
    }

    void display() {
    int t;
    string s;
    struct node *sort = head;

    for (int i = 0; i < size; i++) {
        struct node *current = sort;
        while (current->next != NULL) {
            if (current->time < current->next->time) {
                t = current->time;
                current->time = current->next->time;
                current->next->time = t;
                s = current->name;
                current->name = current->next->name;
                current->next->name = s;
            }
            current = current->next;
        }
    }

    cout << "\n";
    while (sort != NULL) {
        cout << sort->name << " has an appointment at " << sort->time << " PM\n";
        sort = sort->prev;
    }
}

};

int main() {
    App d;
    int ch;
    char opt;
    do {
        cout << "\n******** DOCTOR APPOINTMENT *******\n";
        cout << "1. Book appointment\n2. Freeslots\n3. Cancel Appointment\n4. Display appointment list\n";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch) {
            case 1:
                cout << "\nEnter slots from 12PM to 18PM and each slot is of one hour\n";
                d.bookappointment();
                break;
            case 2:
                d.freeslot();
                break;
            case 3:
                d.cancelappointment();
                break;
            case 4:
                d.display();
                break;
        }
        cout << "\nDo you want to continue? [Y/n] ";
        cin >> opt;
    } while (opt == 'y' || opt == 'Y');

    return 0;
}

