#include <iostream>
using namespace std;

int main() {
    int array_before[10][10] = { 0 };
    int array_after[10][10] = { 0 };

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            array_before[y][x] = rand() % 10;
            cout << array_before[y][x];
        }
        cout << endl;
    }

    cout << endl;

    // ここに部分のソースコードを回答しなさい。
    for (int y = 1; y < 9; y++){
        for (int x = 1; x < 9; x++){
            if (array_before[y-1][x] < array_before[y][x] &&
                array_before[y+1][x] < array_before[y][x] &&
                array_before[y][x-1] < array_before[y][x] &&
                array_before[y][x+1] < array_before[y][x]) {
                array_after[y][x] = 1;
            }
        }
    }

    // 結果を表示
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            cout << array_after[y][x];
        }
        cout << endl;
    }

    cout << endl;

    return 0;
}
