#include "code convert.h"

int main() {
    str.resize(100);
    //接收输入输出文件名
    string in;
    FILE *fin;
    cout << "input file name:";
    cin >> in;
    //判断输入文件名是否正确
    if ((fin = fopen(in.c_str(), "r")) == NULL) {
        cout << endl << "Error!" << endl;
    }
    cout << "The result:" << endl;
    //调用函数从文件中读入表达式
    scan(fin);
    //调用生成四元式的函数
    siyuanshi();
    //判断是否成功
    if (sum == 0)
        cout << "Success!" << endl;
    else
        cout << "Error!" << endl;
    fclose(fin);
    return 0;
}