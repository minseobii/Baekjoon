#include <iostream>
#include <queue>
using namespace std;
queue<int> q;
string str, bomb;
int ans;

bool check(int start) {
    int idx = start;
    for (int i=0;i<bomb.length();i++) {
        if (str[idx] == '.') {
            idx++;
            i--;
            continue;
        }
        if (str[idx] == bomb[i]) {
            idx++;
            continue;
        }
        return false;
    }
    for (int i=0;i<bomb.length();i++) {
        if (str[start] == '.') {
            start++;
            i--;
            continue;
        }
        str[start] = '.';
        start++;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> str >> bomb;
    int Bomblen = bomb.length();
    for (int i=0;i<str.size();i++) {
        if (str[i] != '.') {
            if (check(i)) {
                q.push(i);
            }
        }
    }

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i=max(0,x-Bomblen);i<x;i++) {
            if (str[i] != '.') {
                if (check(i)) {
                    q.push(i);
                }
            }
        }
    }

    bool find = false;
    for (int i=0;i<str.size();i++) {
        if (str[i] == '.') {
            continue;
        }
        find = true;
        cout << str[i];
    }
    if (find == false) {
        cout << "FRULA" << endl;
    }
    else {
        cout << endl;
    }
    return 0;
}
