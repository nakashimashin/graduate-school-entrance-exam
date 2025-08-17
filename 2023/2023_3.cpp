#include <iostream>
using namespace std;

int main(){
    double x,y;
    cin >> x >> y;
    if((-6<x && x<2) && (-5<y && y<0) && ((x+3)*(x+3)+y*y < 25)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }
}