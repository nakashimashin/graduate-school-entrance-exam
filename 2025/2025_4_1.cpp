#include <iostream>
using namespace std;

int check1(int dice[36000]) {
    int count[6] = {0};   // サイコロの目をカウントする配列の要素を0で初期化
    int flag = 0;         // 偏りフラグ（偏りなし：1、偏りなし：0）

    for (int i = 0; i < 36000; i++) {// 36000回のサイコロの目をカウント
        count[dice[i] - 1]++;
    }

    for (int i = 0; i < 6; i++) {
        cout << i + 1 << "の回数" << count[i] << endl;  // 出た目の回数を表示
        if (count[i] >= 6600 || count[i] <= 5400) {     // 回数に偏りがある場合
            flag = 1;                                   // 偏りフラグを1にする
        }
    }

    return flag;
}

int main() {
    int dice[36000];  // サイコロの目

    for (int i = 0; i < 36000; i++) {
        dice[i] = rand() % 6 + 1;  // サイコロの目を代入（1から6の一様乱数）
    }

    if (check1(dice) == 1) {  // 戻り値（偏りフラグ）が1の場合
        cout << "偏りあり" << endl;
    } else {
        cout << "偏りなし" << endl;
    }

    return 0;
}
