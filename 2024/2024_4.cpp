#include <iostream>
using namespace std;

int main() {
    int array_before[10][10] = {
        {1, 7, 4, 0, 9, 4, 8, 8, 2, 4},
        {5, 5, 1, 7, 1, 1, 5, 2, 7, 6},
        {1, 4, 2, 3, 2, 2, 1, 6, 8, 5},
        {7, 6, 1, 8, 9, 2, 7, 9, 5, 4},
        {3, 1, 2, 3, 3, 4, 1, 1, 3, 8},
        {7, 4, 2, 7, 7, 9, 3, 1, 9, 8},
        {6, 5, 0, 2, 8, 6, 0, 2, 4, 8},
        {6, 5, 0, 9, 0, 0, 6, 1, 3, 8},
        {9, 3, 4, 4, 6, 0, 6, 6, 1, 8},
        {4, 9, 6, 3, 7, 8, 8, 2, 9, 1}
    };

    int array_after[10][10] = { 0 };
    int N;
    cout << "エッジ長 N : ";
    cin >> N;
    cout << endl;

    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            // array_before[y][x] = rand() % 10;  // 乱数を代入
            cout << array_before[y][x];
        }
        cout << endl;
    }
    cout << endl;

    // ここの部分のソースコードを回答しなさい。
    for (int y = 0; y < 10 - N; y++){
        for (int x = 0; x < 9; x++){
            int min_left = array_before[y][x];
            int max_left = array_before[y][x];
            int min_right = array_before[y][x+1];
            int max_right = array_before[y][x+1];
            // for (int i = 0; i < N; i++){
            //     if (min_left > array_before[y+i][x]){
            //         min_left = array_before[y+i][x];
            //     }
            //     if (max_left < array_before[y+i][x]){
            //         max_left = array_before[y+i][x];
            //     }
            // }
            // for (int i = 0; i < N; i++){
            //     if (min_right > array_before[y+i][x+1]){
            //         min_right = array_before[y+i][x+1];
            //     }
            //     if (max_right < array_before[y+i][x+1]){
            //         max_right = array_before[y+i][x+1];
            //     }
            // }
            for (int i = 0; i < N; i++) {
                min_left = min(min_left, array_before[y+i][x]);
                max_left = max(max_left, array_before[y+i][x]);
                min_right = min(min_right, array_before[y+i][x+1]);
                max_right = max(max_right, array_before[y+i][x+1]);
            }
            if ((min_left > max_right) || (max_left < min_right)){
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
