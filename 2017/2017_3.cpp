#include <iostream>
using namespace std;

int orthogonal (double V_a[], double V_b[]){
    double seki = 0;
    for(int i=0; i<3; i++){
        seki += V_a[i]*V_b[i];
    }
    if(seki == 0){
        return 0;
    }else{
        return 1;
    }
}


int main() {
    double V_a[3], V_b[3];

    for(int i=0; i<3; i++){
        cin >> V_a[i];
    }

    for(int i=0; i<3; i++){
        cin >> V_b[i];
    }

    int check = orthogonal(V_a, V_b);


    if(check == 0){
        cout << "直行する" << endl;
    }else{
        cout << "直行しない" << endl;
    }
}