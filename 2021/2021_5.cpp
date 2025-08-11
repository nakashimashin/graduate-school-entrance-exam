#include <iostream>
using namespace std;

class Node {
public:
    int num;
    Node* next;
};

int main() {
    Node* list_head;            // 先頭ノードのアドレス
    Node* list_tail;            // 末尾ノードのアドレス
    list_head = new Node();     // 最初に作る先頭ノード
    Node* current = list_head;  // 現在ノードのアドレス

    for (int i = 0; i < 10; i++) {
        cin >> current->num;
        current->next = new Node();
        current = current->next;
    }

    current->num = -1;
    current->next = NULL;
    list_tail = current;

    Node* prev = NULL;
    current = list_head;

    while (current != list_tail) {
        if (current->num % 2 != 0) {
            if (prev == NULL) {
                list_head = current->next;
                delete current;
                current = list_head;
            } else {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        } else {
            prev = current;
            current = current->next;
        }
    }



    cout << "奇数のみを削除したリスト：";
    current = list_head;        // 現在ノードのアドレス
    while (current != list_tail) {
        cout << current->num << ", ";
        current = current->next;
    }

    return 0;
}
