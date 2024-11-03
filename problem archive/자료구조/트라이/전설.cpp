#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int C,N,Q;
unordered_map<string,bool> name_set;

struct Trie {
    bool finish;
    map<char,Trie*> next;

    void insert(string s) {
        Trie* now = this;
        for (int i=0;i<s.length();i++) {
            char cur = s[i];
            if (!now->next[cur]) now->next[cur] = new Trie();
            now = now->next[cur];

            if (i == s.length()-1) now->finish = true;
        }
    }

    bool color_query(string s) {
        Trie* now = this;
        for (int i=0;i<s.length();i++) {
            char cur = s[i];
            if (!now->next[cur]) break;

            now = now->next[cur];
            if (now->finish && name_set[s.substr(i+1)] == true) return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> C >> N;
    Trie* color_root = new Trie();

    for (int i=0;i<C;i++) {
        string s;
        cin >> s;
        color_root->insert(s);
    }
    for (int i=0;i<N;i++) {
        string s;
        cin >> s;
        name_set[s] = true;
    }
    
    cin >> Q;
    for (int i=0;i<Q;i++) {
        string s;
        cin >> s;

        if (color_root->color_query(s)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
