class listNode {
public:
    int val;
    listNode* next;
    listNode* prev;

    listNode(int val) {
        this->val = val;
        this->prev = NULL;
        this->next = NULL;
    }
};

class FrontMiddleBackQueue {
public:
public:
    listNode* head = nullptr;
    listNode* tail = nullptr;
    int current_size;

    FrontMiddleBackQueue() { current_size = 0; }

    void pushFront(int val) {
        listNode* node_to_insert = new listNode(val);
        current_size++;

        if (head == nullptr) {
            head = tail = node_to_insert;

            return;
        }

        head->prev = node_to_insert;
        node_to_insert->next = head;
        head = node_to_insert;
    }

    void pushMiddle(int val) {
        listNode* node_to_insert = new listNode(val);

        if (head == nullptr) {
            current_size++;
            head = tail = node_to_insert;

            return;
        }

        int position_to_reach;

        if (current_size % 2 == 0) {
            position_to_reach = current_size / 2;
        } else {
            position_to_reach = (current_size + 1) / 2;
        }

        listNode* cralwer = head;

        for (int i = 1; i < position_to_reach; i++) {
            cralwer = cralwer->next;
        }

        node_to_insert->prev = cralwer;
        node_to_insert->next = cralwer->next;

        if (cralwer->next != nullptr) {
            node_to_insert->next->prev = node_to_insert;
        } else {
            tail = node_to_insert;
        }

        cralwer->next = node_to_insert;
        current_size++;
    }

    void pushBack(int val) {
        listNode* node_to_insert = new listNode(val);
        current_size++;

        if (tail == nullptr) {
            head = tail = node_to_insert;
            return;
        }

        tail->next = node_to_insert;
        node_to_insert->prev = tail;
        tail = node_to_insert;
    }

    int popFront() {
        if (current_size == 0) {
            return -1;
        }

        if (current_size == 1) {
            current_size--;
            int value_to_return = head->val;
            head = tail = nullptr;
            return value_to_return;
        }

        current_size--;

        listNode* node_to_delete = head;
        head = head->next;

        head->prev = nullptr;
        node_to_delete->next = nullptr;

        int value_to_return = node_to_delete->val;
        delete node_to_delete;
        return value_to_return;
    }

    int popMiddle() {
        if (current_size == 0) {
            return -1;
        }

        if (current_size == 1) {
            current_size--;
            int value_to_return = head->val;
            head = tail = nullptr;
            return value_to_return;
        }

        int position_to_reach;

        if (current_size % 2 == 0) {
            position_to_reach = current_size / 2;
        } else {
            position_to_reach = (current_size + 1) / 2;
        }

        listNode* cralwer = head;

        for (int i = 1; i < position_to_reach; i++) {
            cralwer = cralwer->next;
        }

        listNode* node_to_delete = cralwer->next;

        if (node_to_delete == head) {
            delete node_to_delete;
            return popFront();
        } else if (node_to_delete == tail) {
            delete node_to_delete;
            return popBack();
        }

        int value_to_return = node_to_delete->val;

        cralwer->next = node_to_delete->next;
        node_to_delete->next->prev = cralwer;
        node_to_delete->next = nullptr;
        node_to_delete->prev = nullptr;

        delete node_to_delete;

        current_size--;
        return value_to_return;
    }

    int popBack() {
        if (current_size == 0) {
            return -1;
        }

        if (current_size == 1) {
            current_size--;
            int value_to_return = tail->val;
            head = tail = nullptr;
            return value_to_return;
        }

        current_size--;

        listNode* node_to_delete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        node_to_delete->prev = nullptr;

        int value_to_return = node_to_delete->val;
        delete node_to_delete;
        return value_to_return;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */

 /*Unable to locate the error of above approach*/