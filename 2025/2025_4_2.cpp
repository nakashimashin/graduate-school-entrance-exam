#include <iostream>
using namespace std;

int check2(int dice[36000]) {
    int count[6][6] = {0};  // 全要素を0に初期化（2連続出目のカウント用）
    int flag = 0;           // 偏りフラグを0に初期化

    // ここに該当するプログラムを記入しなさい。
    for (int i = 0; i < 35999; i++)
    {
        count[dice[i] - 1][dice[i + 1] - 1]++;
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << count[i][j] << endl;
            if (count[i][j] >= 1100 || count[i][j] <= 900) {  // 偏りがある場合
                flag = 1;  // 偏りフラグに1を代入
            }
        }
    }

    cout << endl;
    return flag;
}

int main() {
    int dice[36000];  // サイコロの目

    for (int i = 0; i < 36000; i++) {
        dice[i] = rand() % 6 + 1;  // サイコロの目を代入（1から6の一様乱数）
    }

    if (check2(dice) == 1) {  // 戻り値（偏りフラグ）が1の場合
        cout << "偏りあり" << endl;
    } else {
        cout << "偏りなし" << endl;
    }

    return 0;
}