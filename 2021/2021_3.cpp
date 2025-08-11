#include <iostream>
using namespace std;

int main() {
    int data[100];
    for (int i = 0; i < 100; i++) {
        cin >> data[i];
    }

    cout << "一度しか入力されなかった数字は以下の通りです" << endl;

    int count[100];
    for (int i = 0; i < 100; i++) {
        count[i] = 0;
        for (int j = 0; j < 100; j++) {
            if (data[i] == data[j]) count[i]++;
        }
    }


    int oneNums[100], oneCount = 0;
    for (int i = 0; i < 100; i++) {
        if (count[i] == 1) {
            oneNums[oneCount] = data[i];
            oneCount++;
        }
    }

    for (int i = 0; i < oneCount - 1; i++) {
        for (int j = 0; j < oneCount - 1 - i; j++) {
            if (oneNums[j] > oneNums[j + 1]) {
                int temp = oneNums[j];
                oneNums[j] = oneNums[j + 1];
                oneNums[j + 1] = temp;
            }
        }
    }

    // 表示
    for (int i = 0; i < oneCount; i++) {
        cout << oneNums[i] << endl;
    }

    return 0;
}
