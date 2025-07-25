#include <iostream>
using namespace std;

int check3(int dice[36000], int WorL[36000][6]) {
    int count[2] = {0};  // count[0]: 負けた回数, count[1]: 勝った回数
    int flag = 0;        // 偏りフラグ（0: 偏りなし, 1: 偏りあり）

    for (int i = 0; i < 36000; i++) {
        count[WorL[i][dice[i] - 1]]++;

    }

    cout << count[0] << "," << count[1] << endl;

    // 勝ちが期待値（18000）より10%以上多ければ偏りありと判定
    if (count[1] > 19800) {
        flag = 1;
    }

    return flag;
}

int main() {
    int dice[36000];               // サイコロの目を格納
    int WorL[36000][6] = {{0}};    // 各試合の勝敗（Win:1, Lose:0）

    // 勝敗の入力とサイコロの目の初期化
    for (int i = 0; i < 36000; i++) {
        dice[i] = rand() % 6 + 1;  // 最初は1〜6のランダムな値
        for (int j = 0; j < 6; j++) {
            cin >> WorL[i][j];     // 各選手の勝敗を入力
        }
    }

    // 最後に勝った選手の番号を dice[i] にセット
    for (int i = 0; i < 36000; i++) {
        for (int j = 0; j < 6; j++) {
            // 勝者を後ろから探索（最後に勝った人）
            if (WorL[i][5 - j] == 1) {
                dice[i] = 6 - j;  // プレイヤー番号（1〜6）に変換
                break;
            }
        }
    }

    // 偏りチェック
    if (check3(dice, WorL) == 1) {
        cout << "偏りあり" << endl;
    } else {
        cout << "偏りなし" << endl;
    }

    return 0;
}
