#include<iostream>
#include<string.h>
using namespace std;

class Member {
public:
    int prn;
    char name[20];
    Member* next;

    Member() {
        next = NULL;
    }
};

class Club {
    Member* root;
    Member* curr;
    Member* prev;

public:
    Club() {
        root = NULL;
        curr = NULL;
        prev = NULL;
    }

    Member* GetRoot() {
        return root;
    }

   void AddMembers() {
    while (true) {
        curr = new Member();
        cout << "\nEnter PRN No (enter 0 to stop): ";
        cin >> curr->prn;
        
        if (curr->prn == 0) {
            delete curr;
            break;
        }

        cout << "Enter Member Name: ";
        cin >> curr->name;

        if (root == NULL) {
            root = curr;
            prev = curr;
        }
        else {
            prev->next = curr;
            prev = curr;
        }
    }
}


    void DisplayMembers() {
        curr = root;
        while (curr != NULL) {
            printf("(%d) %s --> ", curr->prn, curr->name);
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    void CountMembers() {
        int c = 0;
        curr = root;
        while (curr != NULL) {
            c++;
            curr = curr->next;
        }
        cout << c;
    }

    void DisplayMembersReverse(Member* r) {
        if (r == NULL) return;
        DisplayMembersReverse(r->next);
        printf("(%d) %s --> ", r->prn, r->name);
    }

    void DeleteMembers() {
        int prn;
        cout << "\nEnter PRN No. To Delete: ";
        cin >> prn;

        curr = root;
        prev = NULL;

        while (curr != NULL) {
            if (prn == curr->prn) {
                if (curr == root) {
                    root = root->next;
                    delete curr;
                    break;
                }
                else if (curr->next == NULL) {
                    prev->next = NULL;
                    delete curr;
                    break;
                }
                else {
                    prev->next = curr->next;
                    delete curr;
                    break;
                }
            }
            prev = curr;
            curr = curr->next;
        }
    }

    Club operator+(const Club& c2) {
        Club c3;
        Member* r1 = root;
        Member* r2 = c2.root;

        while (r1 != NULL) {
            c3.curr = new Member();
            c3.curr->prn = r1->prn;
            strcpy(c3.curr->name, r1->name);
            c3.curr->next = NULL;

            if (c3.root == NULL) {
                c3.root = c3.curr;
                c3.prev = c3.curr;
            }
            else {
                c3.prev->next = c3.curr;
                c3.prev = c3.curr;
            }
            r1 = r1->next;
        }

        while (r2 != NULL) {
            c3.curr = new Member();
            c3.curr->prn = r2->prn;
            strcpy(c3.curr->name, r2->name);
            c3.curr->next = NULL;

            if (c3.root == NULL) {
                c3.root = c3.curr;
                c3.prev = c3.curr;
            }
            else {
                c3.prev->next = c3.curr;
                c3.prev = c3.curr;
            }
            r2 = r2->next;
        }
        return c3;
    }
};

int main() {
    Club c1, c2, c3;
    int op = -1;

    while (op != 0) {
        cout << "\n\n1. Add Members";
        cout << "\n2. Display Members";
        cout << "\n3. Display Reverse";
        cout << "\n4. Count Members";
        cout << "\n5. Delete Members";
        cout << "\n6. Concatenate List Using Operator Overloading";
        cout << "\n0. Exit";
        cout << "\n\n*** Select Option *** -> ";
        cin >> op;

        switch (op) {
        case 1:
            cout << "\n\n*** Add To Club 1 ***\n";
            c1.AddMembers();
            cout << "\n\n*** Add To Club 2 ***\n";
            c2.AddMembers();
            break;
        case 2:
            cout << "\n\n*** Display Members - Club 1 ***\n\n";
            c1.DisplayMembers();
            cout << "\n\n*** Display Members - Club 2 ***\n\n";
            c2.DisplayMembers();
            cout << "\n";
            break;
        case 3:
            cout << "\n\n*** Display Members Reverse - Club 1 ***\n\n";
            c1.DisplayMembersReverse(c1.GetRoot());
            cout << "\n\n*** Display Members Reverse - Club 2 ***\n\n";
            c2.DisplayMembersReverse(c2.GetRoot());
            cout << "\n";
            break;
        case 4:
            cout << "\n\nTotal Members Of Club 1 Are ";
            c1.CountMembers();
            cout << "\n\nTotal Members Of Club 2 Are ";
            c2.CountMembers();
            cout << "\n";
            break;
        case 5:
            cout << "\n\n*** Delete Members - Club 1 ***\n";
            c1.DeleteMembers();
            cout << "\n\n*** Delete Members - Club 2 ***\n";
            c2.DeleteMembers();
            cout << "\n";
            break;
        case 6:
            cout << "\n\n*** Concatenating - Club 1 & Club 2***\n";
            c3 = c1 + c2;
            cout << "\n*** Display Members - Club 3 ***\n\n";
            c3.DisplayMembers();
            cout << "\n";
            break;
        case 0:
            break;
        }
    }

    return 0;
}

