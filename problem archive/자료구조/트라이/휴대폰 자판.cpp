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
int N;

struct Trie {
    bool finish;
    map<char,Trie*> next;

    void insert(string s) {
        Trie* now = this;
        for (int i=0;i<s.length();i++) {
            char cur = s[i];
            if (now->next.find(cur) == now->next.end()) now->next[cur] = new Trie;
            now = now->next[cur];

            if (i == s.length()-1) now->finish = true;
        }
    }

    int typing(string s) {
        int count = 1;
        Trie* cur = next[s[0]];
        for (int i=1;i<s.length();i++) {
            if (cur->finish || cur->next.size() > 1) count++;
            cur = cur->next[s[i]];
        }
        return count;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout.precision(2);
    cout << fixed;

    while(cin >> N) {
        int ans = 0;
        vector<string> v;
        Trie* root = new Trie;
        for (int i=0;i<N;i++) {
            string str;
            cin >> str;
            v.push_back(str);
            root->insert(str);
        }

        for (int i=0;i<N;i++) {
            ans += root->typing(v[i]);
        }
        cout << double(ans) / N << '\n';
    }
    return 0;
}
