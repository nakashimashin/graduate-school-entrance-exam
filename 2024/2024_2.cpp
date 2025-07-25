#include <iostream>
using namespace std;

int convert(int num_10, int num_N) {
    int ans = 0;
    int place = 1;
    
    while(num_10 > 0) {
        int A = num_10 % num_N;
        ans += A * place;
        num_10 /= num_N;
        place *= 10;
    }
    return ans;

}


int main() {
    int decimal_10, base, decimal_N;

    cout << "10進数を入力：";
    cin >> decimal_10;
    cout << endl;

    cout << "何進数に変換しますか？(2以上10未満)：";
    cin >> base;
    cout << endl;

    // “base進数” に変換します。
    if (2 <= base && base < 10) {
        decimal_N = convert(decimal_10, base);
    } else {
        // 範囲外の base が入力された時の例外処理
        cout << "エラー";
        return 1;
    }

    cout << base << "進数の" << decimal_10 << "：";
    cout << decimal_N << endl;
}
