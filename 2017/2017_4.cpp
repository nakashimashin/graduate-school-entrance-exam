#include <iostream>
using namespace std;

int max(int num[]) {
    int count[6] = {0};
    for (int i = 0; i < 5; ++i) {
        ++count[num[i]];
    }
    int ans = 1;
    for (int v = 2; v <= 5; ++v) {
        if (count[v] > count[ans] || (count[v] == count[ans] && v > ans)) {
            ans = v;
        }
    }
    return ans;
}


int main(){
    int num[5];

    for(int i = 0; i<5; i++){
        cin >> num[i];
    }

    return max(num);
}