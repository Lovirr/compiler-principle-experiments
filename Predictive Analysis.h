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

//�����洢�û�������ַ������Ϊ20���ַ�
string inputString;
//ʹ��vectorģ��ջ
vector<char> stack;
//�������7���ս��
const unordered_set<char> VT = {'i', '+', '*', '-', '/', '(', ')'};
//�������Ԥ�������M[A,a]�е�һ������ʽ
string chanShengShi;
//��������û����봮�ĵ�һ��Ԫ�ص��±꣬���aƥ�����ʽ����ÿ��firstCharIndex ���� 1
int firstCharIndex = 0;

/*
    ��Ԥ�������M[A,a]�д��ڲ���ʽ��
    �򽫸ò���ʽ�����ַ�����chanShengShi�������� 1��
    ��M[A,a]���޶������ʽ�򷵻� 0
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
}//Ԥ����������ݷ���ջ���ķ��ս�� A �͵�ǰ������� a����Ԥ��������в��Һ��ʵĲ���ʽ�����ظò���ʽ���Ҳ���

//��ӡջ��Ԫ��
void Print_Stack() {
    for (int i = 1; i < (int) stack.size(); i++)
        cout << stack[i];
    cout << "\t\t";
}

//��ӡ���봮
void Print_inputString() {
    for (int i = firstCharIndex; i < (int) inputString.size() && inputString[i] != '#'; i++)
        cout << inputString[i];
    cout << "\t\t";
}

bool Predict() {
    char X;// X�����洢ÿ�ε�����ջ��Ԫ��
    char a;// a�����洢�û����봮�ĵ�һ��Ԫ��
    int counter = 1; //�ñ�����¼�﷨�����Ĳ�����

    //��ʼ��ջ���ķ���ʼ���ź���ֹ����ջ
    stack.emplace_back('#');
    stack.emplace_back('E');
    cout << "Step\t\tStack\t\tInput\t\tAction" << endl;
    while (true) {
        cout << counter << "\t\t";
        Print_Stack();
        X = stack.back();//ջ��Ԫ�ظ�ֵ��X����ջ
        stack.pop_back();
        Print_inputString();
        //���ս������VT�в��ұ���X��ֵ
        if (!VT.count(X)) {
            if (X == '#') {
                //ջ�Ѿ����գ��﷨���������ȷ
                cout << "True" << endl;
                return true;
            } else {
                a = inputString[firstCharIndex];
                //a�Ƕ�ͷ���ţ��鿴Ԥ�������M[A,a]�Ƿ���ڲ���ʽ�����ڷ���1�������ڷ���0
                if (M(X, a) == 1) {
                    //'$'Ϊ����ʽ�Ľ�����,�ҳ��ò���ʽ�����һ��Ԫ�ص��±�
                    for (int i = chanShengShi.find('$') - 1; i >= 0; i--)
                        stack.emplace_back(chanShengShi[i]);
                    cout << "Deduce";//�Ƶ�
                } else {
                    cout << "M[A,a] not exist,Error" << endl;
                    return false;
                }
            }
        } else {
            //�ս��
            if (X == inputString[firstCharIndex]) {
                //��ͷ������ջ��Ԫ��ƥ��
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

