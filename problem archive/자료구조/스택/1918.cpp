#include <iostream>
#include <stack>
#include <map>
using namespace std;

map<char, int> Map;
stack<char> Stack;
string str;

void StackPrint(int k) {
    while (!Stack.empty() && Map[Stack.top()] >= k) {
        cout << Stack.top();
        Stack.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str;

    Map['+'] = 1;
    Map['-'] = 1;
    Map['*'] = 2;
    Map['/'] = 2;
    Map['('] = 0;

    for (int i=0;i<str.length();i++) {
        if (isalpha(str[i])) {
           cout << str[i];
        }
        else if (str[i] == '+' || str[i] == '-') {
            if (!Stack.empty()) {
                if (Map[Stack.top()] >= Map[str[i]]) {
                    StackPrint(1);
                }
            }
            Stack.push(str[i]);
        }
        else if (str[i] == '*' || str[i] == '/') {
            if (!Stack.empty()) {
                if (Map[Stack.top()] == Map[str[i]]) {
                    StackPrint(2);
                }
            } 
            Stack.push(str[i]);
        }
        else if (str[i] == '(') {
            Stack.push(str[i]);
        }
        else if (str[i] == ')') {
            StackPrint(1);
            Stack.pop();
        }
    }
    StackPrint(0);

    return 0;
}
