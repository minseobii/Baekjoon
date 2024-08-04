#include <iostream>
#include <queue>
#include <stack>
using namespace std;
stack<char> st;
string str, bomb;
int bombsize;
char bomblast;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str >> bomb;
    bombsize = bomb.length();
    bomblast = bomb[bombsize-1];

    for (int i=0;i<str.length();i++) {
        st.push(str[i]);
        if (str[i] == bomblast) {
            char tempstr[bombsize] = {0,};
            int len = bombsize;
            bool same = true;

            while(len) {
                len--;
                tempstr[len] = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
            }
            for (int j=0;j<bombsize;j++) {
                if (tempstr[j] != bomb[j]) {
                    same = false;
                    break;
                }
            }
            if (same == false) {
                while(len != bombsize) {
                    st.push(tempstr[len++]);
                }
            }
        }
    }

    stack<char> printst;

    while(!st.empty()) {
        printst.push(st.top());
        st.pop();
    }
    if (printst.empty()) {
        cout << "FRULA";
    }
    while(!printst.empty()) {
        cout << printst.top();
        printst.pop();
    }
    cout << endl;
    
    return 0;
}
