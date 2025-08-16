#include <iostream>
using namespace std;

void leap_year(int year, int* day){
    if((year % 400 ==0) || (year % 100 != 0 && year % 4 == 0)){
        *day = 366;
    } else {
        *day = 365;
    }
}

int main() {
    int year, day;

    cin >> year;
    leap_year(year, &day);

    cout << year << "年は" << day << "日間です" << endl;
    return 0;
}