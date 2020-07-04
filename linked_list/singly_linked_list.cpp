#include <iostream>

using std::cin;
using std::cout;
using std::endl;

typedef struct node {
    int value;
    struct node *next;

    node(int value) : value(value) {}
} Node;

/* Single Linked List */
class SLL {
public:
    SLL() { head = nullptr; }

    void push_front(int value) { insert(0, value); }

    void push_back(int value) {
        // First Node
        if (head == nullptr) {
            insert(0, value);
            return;
        }

        Node *ptr = head;

        // Finds the last node
        for (; ptr->next != nullptr; ptr = ptr->next)
            ;

        Node *new_node = new Node(value);
        new_node->next = nullptr;
        ptr->next      = new_node;
    }

    void insert(int position, int value) {
        // Invalid Position
        if (position < 0) {
            cout << "Error: Out of range" << endl;
            return;
        }

        // First Node
        if (head == nullptr && position == 0) {
            Node *new_node = new Node(value);
            new_node->next = nullptr;
            head           = new_node;
            return;
        }

        Node *ptr = head;
        int count = 1;

        // Finds the position
        for (; ptr != nullptr && count < position; ptr = ptr->next, count++)
            ;

        // Invalid Position
        if (ptr == nullptr) {
            cout << "Error: Out of range" << endl;
            return;
        }

        // Inserts a new node into the list
        Node *new_node = new Node(value);

        // Insertion at the beginning of the list
        if (position == 0) {
            new_node->next = head;
            head           = new_node;
        } else {
            new_node->next = ptr->next;
            ptr->next      = new_node;
        }
    }

    void remove(int position) {
        // Invalid Position
        if (position < 0) {
            cout << "Error: Out of range" << endl;
            return;
        }

        // Empty List
        if (head == nullptr) {
            cout << "Error: Empty list" << endl;
            return;
        }

        // Deletes the head of the list
        if (position == 0) {
            Node *old_head = head;
            head           = old_head->next;
            delete old_head;
            return;
        }

        Node *ptr = head, *prev = head;
        int count = 0;

        // Finds the position
        for (; ptr != nullptr && count < position;
             prev = ptr, ptr = ptr->next, count++)
            ;

        if (ptr == nullptr) {
            cout << "Error: Out of range" << endl;
            return;
        }

        // Deletes a node from the list
        prev->next = ptr->next;
        delete ptr;
    }

    void selection_sort() {
        // Empty List
        if (head == nullptr) {
            cout << "Error: Empty list" << endl;
            return;
        }

        // Selection Sort
        for (Node *ptr1 = head; ptr1->next != nullptr; ptr1 = ptr1->next) {
            Node *min = ptr1;

            // Finds the smallest node starting from ptr1->next
            for (Node *ptr2 = ptr1->next; ptr2 != nullptr; ptr2 = ptr2->next)
                if (ptr2->value < min->value)
                    min = ptr2;

            // Swaps min with ptr1
            int tmp     = min->value;
            min->value  = ptr1->value;
            ptr1->value = tmp;
        }
    }

    void reverse() {
        // Empty List
        if (head == nullptr) {
            cout << "Error: Empty list" << endl;
            return;
        }

        Node *ptr = head->next, *prev = head;

        head->next = nullptr;
        while (ptr != nullptr) {
            Node *next = ptr->next;
            ptr->next  = prev;
            prev       = ptr;
            ptr        = next;
        }

        // Updates the head of the list
        head = prev;
    }

    void print() const {
        // Empty List
        if (head == nullptr) {
            cout << "Empty List" << endl;
            return;
        }

        for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
            cout << ptr->value << " ";
        cout << endl;
    }

    void clear() {
        // Empty List
        if (head == nullptr)
            return;

        Node *ptr = head;

        // Empties the list
        while (ptr != nullptr) {
            Node *next = ptr->next;
            delete ptr;
            ptr = next;
        }

        // Resets the head of the list
        head = nullptr;
    }

private:
    Node *head;
};

int main() {
    SLL sll;
    int pos, val;

    // Push Front
    while (cin >> val) {
        sll.push_front(val);
        sll.print();
    }

    // Push Back
    while (cin >> val) {
        sll.push_back(val);
        sll.print();
    }

    // Insert
    while (cin >> pos >> val) {
        sll.insert(pos, val);
        sll.print();
    }

    // Remove
    while (cin >> pos) {
        sll.remove(pos);
        sll.print();
    }

    // Selection Sort
    sll.selection_sort();
    sll.print();

    // Reverse
    sll.reverse();
    sll.print();

    // Clear
    sll.clear();
    sll.print();

    return 0;
}