class Node {
public:
    int val;
    Node* next;

    Node(int value) {
        val = value;
        next = nullptr;
    }
};

class MyLinkedList {
public:
    Node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        if (index < 0) return -1;
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            if (temp == nullptr) return -1;
            temp = temp->next;
        }
        return (temp == nullptr) ? -1 : temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index < 0) return;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            if (temp == nullptr) return;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || head == nullptr) return;

        if (index == 0) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            if (temp == nullptr || temp->next == nullptr) return;
            temp = temp->next;
        }

        if (temp->next == nullptr) return;

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
};
