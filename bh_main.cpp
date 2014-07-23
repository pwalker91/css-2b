#include "binaryheap.h"
#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main() {
    binheap *bin = new binheap();
    char ans = 'a';
    while(tolower(ans) != 'q') {
        cout << "OPTIONS: (i) insert   (r) remove   (p) print   (q) quit" << endl;
        cin >> ans; ans = tolower(ans);
        if(ans == 'i') {
            int inp; cout<<"num--> "; cin >> inp;
            bin->insert(inp);
        }
        else if(ans == 'r') bin->remove();
        else if(ans == 'p') bin->print();
    }
}