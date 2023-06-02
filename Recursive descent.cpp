#include "Lexical analysis.h"//词法分析头文件
#include "Recursive descent.h"//递归下降分析头文件

int main() {
    //读入文件11.c并进行词法分析
    loadProperty();
    Finput();
    i = 0;//读头
    //将所有数字转化为终结符i
    for (auto &j: symbol) {
        if (j.code == 2)
            j.sign = "i";
        code += j.sign;
    }
    Scaner();
    E();
    if (sym == '#') {
        cout << "The string belongs to grammar!" << endl;
    } else
        cout << "Error!" << endl;
    return 0;
}