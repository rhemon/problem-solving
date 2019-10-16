#include <iostream>
#include <vector>
#include <algorithm>
// #include <fstream>

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

    void destroy() {
        free(front);
        free(back);
    }

    bool empty() {
        return n == 0;
    }

    int size() {
        return n;
    }
};

int main() {
    // ifstream cin;
    // ofstream cout;
    // cin.open("f.txt");
    // cout.open("o.txt");
    int n;
    while (cin >> n) {
        vector<int> arr;
        dl_list queue;
        dl_list stack;
        queue.init();
        stack.init();
        int op, val, front_val, back_val;
        int is_queue = 1, is_stack = 1, is_pqueue = 1;
        for (int i = 0; i < n; i++) {
            cin >> op >> val;
            if (op == 1) {
                arr.push_back(val);
                sort(arr.begin(), arr.end());
                stack.push_back(val);
                queue.push_back(val);
            } else if (op == 2) {
                if (arr.size() > 0) {
                    if (val != arr[arr.size()-1]) {
                        is_pqueue = 0;
                    } else if (is_pqueue){
                        arr.pop_back();
                    }
                } else {
                    is_pqueue = 0;
                }

                if (is_stack) {
                    if (stack.empty()) {
                        is_stack = 0;
                    } else {
                        back_val = stack.pop_back();
                        if (val != back_val) {
                            is_stack = 0;
                        }
                    }
                }

                if (is_queue) {
                    if (queue.empty()) {
                        is_queue = 0;
                    } else {
                        front_val = queue.pop_front();
                        if (val != front_val) {
                            is_queue = 0;
                        }
                    }
                }
            }
        }
        if ((is_stack+is_queue+is_pqueue) == 0) {
            cout << "impossible" << endl;
        } else if ((is_stack+is_queue+is_pqueue) > 1) {
            cout << "not sure" << endl;
        } else if (is_stack) {
            cout << "stack" << endl;
        } else if (is_queue) {
            cout << "queue" << endl;
        } else if (is_pqueue) {
            cout << "priority queue" << endl;
        }
        stack.destroy();
        queue.destroy();
    }
}
