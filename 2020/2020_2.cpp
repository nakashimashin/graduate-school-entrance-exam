#include <iostream>
using namespace std;
int main(void){
    int decimal, binary;

    cout << "10進数 = ";
    cin >> decimal;
    /* （解答用紙に記入すること） */
    int digit = 1;
    binary = 0;
    while(decimal > 0) {
        binary += (decimal % 2) * digit;
        decimal = decimal / 2;
        digit = digit * 10;
    }
    cout << "2進数 = " << binary << endl;

    return 0;
}
