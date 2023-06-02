#ifndef CPLUS_LIBRARY_RECURSIVE_DESCENT_H
#define CPLUS_LIBRARY_RECURSIVE_DESCENT_H

#include <iostream>
#include <string>
using namespace std;

string code;
char sym;
int i;

void E();
void e();
void T();
void t();
void F();
void Scaner();
void Error();

void Scaner() {
    sym = code[i];
    i++;
}

void Error() {
    cout << "Error" << endl;
    system("pause");
    exit(0);
}

void E() {
    T();
    e();
}

void e() {
    if (sym == '+'||sym == '-') {
        Scaner();
        T();
        e();
    } else if ((sym != ')') && (sym != '#'))
        Error();

}

void T() {
    F();
    t();
}

void t() {
    if (sym == '*'||sym == '/') {
        Scaner();
        F();
        t();
    } else if (sym != '+' && sym != ')' && sym != '#'&& sym != '-')
        Error();
}

void F() {
    if (sym == '(') {
        Scaner();
        E();
        if (sym == ')')
            Scaner();
        else
            Error();
    } else if (sym == 'i')
        Scaner();
    else
        Error();
}

#endif //CPLUS_LIBRARY_RECURSIVE_DESCENT_H
