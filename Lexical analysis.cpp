#include "Lexical analysis.h"

#include <iostream>

int main(int argc, char* argv[]) {
    if (argc >= 2)
        prefix = argv[1];
    loadProperty();
    Finput();
    cout << "result£º" << endl;
    for (int i = 0; i < (int)symbol.size(); i++) {
        cout << symbol[i].sign << " " << symbol[i].code << endl;
    }
    return 0;
}
