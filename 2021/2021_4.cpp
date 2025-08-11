#include <iostream>
using namespace std;

int main() {
    double P1, P2, P3, P4;
    bool flag = false;
    int i=0, j=0, k=0;
    for (int day = 0; day < 100; day++) {
        cin >> P1 >> P2 >> P3 >> P4;


        if (P1 >= 1 && P2 >= 1 && P3 >= 1){
            i++;
        }
        else {
            i = 0;
        }

        if (P2 < 1 && P3 < 1 && P4 < 1) {
            j++;
        }
        else {
            j =0;
        }

        if(i >= 2){
            flag = true;
        }

        if(j >= 3){
            flag = false;
        }


        if (flag == true) {
            cout << "緊急事態宣言発令" << endl;
        }
        else {
            cout << "緊急事態宣言解除" << endl;
        }
    }
}
