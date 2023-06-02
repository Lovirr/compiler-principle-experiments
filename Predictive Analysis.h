#ifndef CPLUS_LIBRARY_PREDICTIVE_ANALYSIS_H
#define CPLUS_LIBRARY_PREDICTIVE_ANALYSIS_H
#endif //CPLUS_LIBRARY_PREDICTIVE_ANALYSIS_H

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

//用来存储用户输入的字符串，最长为20个字符
string inputString;
//使用vector模拟栈
vector<char> stack;
//用来存放7个终结符
const unordered_set<char> VT = {'i', '+', '*', '-', '/', '(', ')'};
//用来存放预测分析表M[A,a]中的一条产生式
string chanShengShi;
//用来存放用户输入串的第一个元素的下标，如果a匹配产生式，则每次firstCharIndex 自增 1
int firstCharIndex = 0;

/*
    若预测分析表M[A,a]中存在产生式，
    则将该产生式赋给字符数组chanShengShi，并返回 1，
    若M[A,a]中无定义产生式则返回 0
*/
bool M(char A, char a) {
    if (A == 'E' && a == 'i') {
        chanShengShi = "Te$";
        return true;
    }
    if (A == 'E' && a == '(') {
        chanShengShi = "Te$";
        return true;
    }
    if (A == 'e' && a == '+') {
        chanShengShi = "+Te$";
        return true;
    }
    if (A == 'e' && a == '-') {
        chanShengShi = "-Te$";
        return true;
    }
    if (A == 'e' && a == ')' || a == '$') {
        chanShengShi = "$";
        return true;
    }
    if (A == 'T' && a == 'i') {
        chanShengShi = "Ft$";
        return true;
    }
    if (A == 'T' && a == '(') {
        chanShengShi = "Ft$";
        return true;
    }
    if (A == 't' && a == '+' || a == '-' || a == ')' || a == '#') {
        chanShengShi = "$";
        return true;
    }
    if (A == 't' && a == '*') {
        chanShengShi = "*Ft$";
        return true;
    }
    if (A == 't' && a == '/') {
        chanShengShi = "/Ft$";
        return true;
    }
    if (A == 'F' && a == 'i') {
        chanShengShi = "i$";
        return true;
    }
    if (A == 'F' && a == '(') {
        chanShengShi = "(E)$";
        return true;
    } else
        return false;
}//预测分析表，根据分析栈顶的非终结符 A 和当前输入符号 a，在预测分析表中查找合适的产生式，返回该产生式的右部。

//打印栈内元素
void Print_Stack() {
    for (int i = 1; i < (int) stack.size(); i++)
        cout << stack[i];
    cout << "\t\t";
}

//打印输入串
void Print_inputString() {
    for (int i = firstCharIndex; i < (int) inputString.size() && inputString[i] != '#'; i++)
        cout << inputString[i];
    cout << "\t\t";
}

bool Predict() {
    char X;// X变量存储每次弹出的栈顶元素
    char a;// a变量存储用户输入串的第一个元素
    int counter = 1; //该变量记录语法分析的步骤数

    //初始化栈，文法开始符号和终止符入栈
    stack.emplace_back('#');
    stack.emplace_back('E');
    cout << "Step\t\tStack\t\tInput\t\tAction" << endl;
    while (true) {
        cout << counter << "\t\t";
        Print_Stack();
        X = stack.back();//栈顶元素赋值给X并出栈
        stack.pop_back();
        Print_inputString();
        //在终结符集合VT中查找变量X的值
        if (!VT.count(X)) {
            if (X == '#') {
                //栈已经弹空，语法分析结果正确
                cout << "True" << endl;
                return true;
            } else {
                a = inputString[firstCharIndex];
                //a是读头符号，查看预测分析表M[A,a]是否存在产生式，存在返回1，不存在返回0
                if (M(X, a) == 1) {
                    //'$'为产生式的结束符,找出该产生式的最后一个元素的下标
                    for (int i = chanShengShi.find('$') - 1; i >= 0; i--)
                        stack.emplace_back(chanShengShi[i]);
                    cout << "Deduce";//推导
                } else {
                    cout << "M[A,a] not exist,Error" << endl;
                    return false;
                }
            }
        } else {
            //终结符
            if (X == inputString[firstCharIndex]) {
                //读头符号与栈顶元素匹配
                firstCharIndex++;
                cout << "Match";
            } else {
                cout << "Not match,Error" << endl;
                return false;
            }
        }
        counter++;
        cout << endl;
    }
}

