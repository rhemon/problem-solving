#include <iostream>
using namespace std;

struct Node {
    int val;
    struct Node* next;
    struct Node* prev;
};

struct dl_list {
    int n;
    Node* front;
    Node* back;
    bool reversed;

    void init() {
        n = 0;
        reversed = false;
        front = (Node*)malloc(sizeof(Node));
        back = (Node*)malloc(sizeof(Node));
        front->next = back;
        back->prev = front;
        front->prev = NULL;
        back->next = NULL;
    }

    void to_front(int val) {
        Node* p = (Node*)malloc(sizeof(Node));
        p->val = val;
        n++;
        Node* first_item;
        if (reversed) {
            p->next = back;
            back->prev->next = p;
            p->prev = back->prev;
            back->prev = p;
        } else {
            p->next = front->next;
            front->next = p;
            p->prev = front;
            p->next->prev = p;
        }
    }

    void push_back(int val) {
        Node* p = (Node*)malloc(sizeof(Node));
        p->val = val;
        n++;
        if (reversed) {
            p->prev = front;
            p->next = front->next;
            front->next = p;
            p->next->prev = p;
        } else {
            p->prev = back->prev;
            back->prev = p;
            p->next = back;
            p->prev->next = p;
        }
    }

    void reverse() {
        reversed = !reversed;
    }

    int pop_front() {
        int val;
        Node* p;
        if (!reversed) {
            p = front->next;
            val = front->next->val;
            front->next = front->next->next;
            front->next->prev = front;
        } else {
            p = back->prev;
            val = back->prev->val;
            back->prev = back->prev->prev;
            back->prev->next = back;
        }
        free(p);
        n--;
        return val;
    }

    int pop_back() {
        int val;
        Node* p;
        if (!reversed) {
            p = back->prev;
            val = back->prev->val;
            back->prev = back->prev->prev;
            back->prev->next = back;
        } else {
            p = front->next;
            val = front->next->val;
            front->next = front->next->next;
            front->next->prev = front;
        }
        free(p);
        n--;
        return val;
    }

    bool empty() {
        return n == 0;
    }
};

int main() {
    int n;
    cin >> n;
    dl_list queue;
    queue.init();
    for (int i = 0; i < n; i++) {
        string order;
        int val;
        cin >> order;
        if (order == "toFront" || order == "push_back") {
            cin >> val;
        }
        if (order == "toFront") {
            queue.to_front(val);
        } else if (order == "push_back") {
            queue.push_back(val);
        } else if (order == "back") {
            if (!queue.empty())
                cout << queue.pop_back() << endl;
            else
                cout << "No job for Ada?" << endl;
        } else if (order == "front") {
            if (!queue.empty())
                cout << queue.pop_front() << endl;
            else
                cout << "No job for Ada?" << endl;
        } else if (order == "reverse") {
            queue.reverse();
        }
    }
}
