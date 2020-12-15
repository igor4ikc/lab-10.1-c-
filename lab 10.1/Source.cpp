#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <stdio.h>

using namespace std;

bool Find(FILE* h);


bool Find(FILE* h) {
    char p = 0;
    char f;
    do {

        f = getc(h);
        if (f == 'A' && f == 'G' && f == 'A') return true;
        if (f == 'O' && f == 'G' && f == 'O') return true;
        p = f;
    } while (f != EOF);
    return false;
}
int main() {
    FILE* h;

    if (fopen_s(&h, "t.txt", "r") != 0) {
        cerr << "Error opening file 't.txt'" << endl;
        exit(1);
    }

    bool found = Find(h);
    if (found) {
        cout << "'AGA' or 'OGO' found successfully" << endl;
    }
    else {
        cout << " 'AGA' or 'OGO' NOT found" << endl;
    }

    fclose(h);

    return 0;
}