#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
};

struct Stack {
    int n;
    Node* front;
    Node* back;

    void init() {
        front = (Node*)malloc(sizeof(Node));
        back = (Node*)malloc(sizeof(Node));
        front->next = back;
        back->prev = front;
        n = 0;
    }
    int pop_front() {
        Node* p = front->next;
        int val = p->val;
        front->next = p->next;
        p->next->prev = front;
        free(p);
        n--;
        return val;
    }

    void push_back(int val) {
        Node* p = (Node*)malloc(sizeof(Node));
        p->val = val;
        p->prev = back->prev;
        back->prev = p;
        p->next = back;
        p->prev->next = p;
        n++;
    }

    int size() {
        return n;
    }
};

int main() {
    int n;
    while(cin >> n) {
        if (n == 0) {
            break;
        }
        Stack s;
        s.init();
        for (int i = 1; i <= n; i++) {
            s.push_back(i);
        }
        cout << "Discarded cards:";
        string output = " ";
        while (s.size() != 1) {
            output += to_string(s.pop_front()) + ", ";
            s.push_back(s.pop_front());
        }
        // cout << "outputsize " << output.size() << endl;
        int a = output.size();
        a -= 2;
        while (output.size() != max(a, 0)) {
            output.pop_back();
        }
        cout << output << endl;
        cout << "Remaining card: " << s.pop_front() << endl;
    }
}
