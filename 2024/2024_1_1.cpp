#include <iostream>
using namespace std;

int main() {
    char data[4][4] = {
        {'a','b','c','d'},
        {'e','f','g','h'},
        {'i','j','k','l'},
        {'m','n','o','p'}};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) // 9行目
            cout << data[(3-j)%2][3-i];
        cout << endl;
    }
    cout << endl;
}
