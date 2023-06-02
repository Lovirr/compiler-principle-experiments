#include "Lexical analysis.h"//词法分析头文件
#include "Predictive Analysis.h"//预测分析头文件

int main() {
    cout << "The grammars supported by this program are:" << endl;
    cout << "E->Te" << endl;
    cout << "e->+Te | -Te | $" << endl;
    cout << "T->Ft" << endl;
    cout << "t->*Ft | /Ft | $" << endl;
    cout << "F->(E) | i" << endl;
    //读入文件11.c
    loadProperty();
    Finput();
    //将所有数字转化为终结符i
    for (auto &i: symbol) {
        if (i.code == 2)
            i.sign = "i";
        inputString += i.sign;
    }
    cout << "Expressions are converted to:" << endl << inputString << endl;
    Predict();
    return 0;
}
