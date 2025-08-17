#include <iostream>
using namespace std;

int cell[5][5];

int check_tateyoko(){
    int hit = 0;
        int x[5] = { 0 };
        int y[5] = { 0 };
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (cell[i][j] == 1) {
                    if (x[j] >= 1) hit++;
                    if (y[i] >= 1) hit++;

                    x[j]++;
                    y[i]++;
                }
            }
        }
        return hit;
}

int check_naname() {
    int hit = 0;
    int hidariue[10] = { 0 };
    int migisita[10] = { 0 };

    for (int y = 0; y < 5; y++) {         // /行 (y) ループ
        for (int x = 0; x < 5; x++) {     // /列 (x) ループ
            if (cell[y][x] == 1) {             // //駒が置かれているとき

                int d = x - y + 5;      // 左上がり斜め
                int s = x + y;           // 右上がり斜め

                if (hidariue[d] >= 1)         //左上がり斜めでぶつかるとき
                    ++hit;
                if (migisita[s] >= 1)         //右上がり斜めでぶつかるとき
                    ++hit;

                hidariue[d]++;                // その斜めに駒があることを記録
                migisita[s]++;
            }
        }
    }
    return hit;                           // 0 なら衝突なし
}

int main(){
    int flag = 0;
    for (int i=0; i<5; i++){
        int x, y;
        cin >> x >> y;
        // cell[y][x] = 1;
    }

    // flag += check_tateyoko();
    // flag += check_naname();

    if(flag == 0){
        cout << "true" << endl;
    }else {
        cout << "false" << endl;
    }
}