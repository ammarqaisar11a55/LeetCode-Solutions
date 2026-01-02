class listNode {
public:
    int val;
    listNode* next;
    listNode* prev;

    listNode(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyCircularDeque {
public:
    listNode* head = nullptr;
    listNode* tail;
    int Current_size;
    int Max_size;

    MyCircularDeque(int k) {
        Max_size = k;
        Current_size = 0;
    }

    bool insertFront(int value) {

        if (Current_size < Max_size) {
            listNode* node_to_insert = new listNode(value);
            Current_size++;

            if (head == nullptr) {
                head = tail = node_to_insert;
            } else {
                head->prev = node_to_insert;
                node_to_insert->next = head;
                head = node_to_insert;
            }

            return true;
        }

        return false;
    }

    bool insertLast(int value) {

        if (Current_size < Max_size) {
            listNode* node_to_insert = new listNode(value);
            Current_size++;

            if (head == nullptr) {
                head = tail = node_to_insert;
            } else {
                node_to_insert->prev = tail;
                tail->next = node_to_insert;
                tail = node_to_insert;
            }

            return true;
        }

        return false;
    }

    bool deleteFront() {
        if (Current_size == 0) {
            return false;
        }

        if (Current_size == 1) {
            head = tail = nullptr;
            Current_size--;
            return true;
        }

        listNode* node_to_delete = head;
        head = head->next;
        head->prev = nullptr;
        node_to_delete->next = nullptr;
        delete node_to_delete;
        Current_size--;
        return true;
    }

    bool deleteLast() {
        if (Current_size == 0) {
            return false;
        }

        if (Current_size == 1) {
            head = tail = nullptr;
            Current_size--;
            return true;
        }

        listNode* node_to_delete = tail;
        tail = tail->prev;
        tail->next = nullptr;

        node_to_delete->prev = nullptr;

        delete node_to_delete;
        Current_size--;
        return true;
    }

    int getFront() { return head == nullptr ? -1 : head->val; }

    int getRear() { return tail == nullptr ? -1 : tail->val; }

    bool isEmpty() { return head == nullptr ? true : false; }

    bool isFull() { return Current_size == Max_size ? true : false; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */