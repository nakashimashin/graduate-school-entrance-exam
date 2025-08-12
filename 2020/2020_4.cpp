#include <iostream>
using namespace std;
int main(void){
    int a, b, tmp;

    cin >> a >> b;

    while(a > 0){
        tmp = b % a;
        b = a;
        a = tmp;
    }
    if(b == 1){
        cout << "互いに素である";
    } else{
        cout << "互いに素でない";
    }

    return 0;
}
