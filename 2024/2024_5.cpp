#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile || !outputFile) {
        cout << "ファイルエラー" << endl;
        return 1;
    }

    // 回答ここから
    char currentChar;
    int spaceCount = 0;
    int lineCount = 0;
    while (inputFile.get(currentChar)) {
        if (currentChar == ' '){
            spaceCount++;
            lineCount = 0;
            if (spaceCount >= 2){
                continue;
            }
        } else if (currentChar == '\n'){
            lineCount++;
            spaceCount = 0;
            if (lineCount >= 2){
                continue;
            }
        } else {
            spaceCount = 0;
            lineCount = 0;
        }
        outputFile << currentChar;
    }
    // 回答ここまで

    inputFile.close();
    outputFile.close();

    return 0;
}
