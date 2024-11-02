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
vector<int> v;

struct Trie {
    bool finish;
    map<char,Trie*> next;

    void insert(string s) {
        Trie* now = this;
        for (int i=0;i<s.length();i++) {
            char cur = s[i];
            if (now->next.find(cur) == now->next.end()) now->next[cur] = new Trie();
            now = now->next[cur];

            if (i == s.length()-1) now->finish = true;
        }
    }

    void color_query(string s) {
        Trie* now = this;
        for (int i=0;i<s.length();i++) {
            char cur = s[i];
            if (now->next.find(cur) == now->next.end()) continue;

            now = now->next[cur];
            if (now->finish && i+1 < s.length()) v.push_back(i+1);
        }
    }

    bool name_query(string s, int idx) {
        Trie* now = this;
        for (int i=idx;i<s.length();i++) {
            char cur = s[i];
            if (i == s.length()-1 && now->next[cur]->finish) break;
            if (now->next.find(cur) == now->next.end()) return false;
            now = now->next[cur];
        }
        return true; 
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> C >> N;
    Trie* color_root = new Trie();
    Trie* name_root = new Trie();
    
    for (int i=0;i<C;i++) {
        string s;
        cin >> s;
        color_root->insert(s);
    }
    for (int i=0;i<N;i++) {
        string s;
        cin >> s;
        name_root->insert(s);
    }
    
    cin >> Q;
    for (int i=0;i<Q;i++) {
        string s;
        cin >> s;

        v.clear();
        color_root->color_query(s);

        bool ans = false;
        for (int idx : v) {
            if (name_root->name_query(s,idx)) {
                ans = true;
                break;
            }
        }
        if (ans) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
