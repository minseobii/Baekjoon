#include <iostream>
#include <map>
using namespace std;
int N,ans;

struct NODE {
    map<string,NODE*> m;
};

void solve(NODE* node, int level) {
    for (auto iter : node->m) {
        for (int j=0;j<level;j++) {
            cout << "--";
        }
        cout << iter.first << '\n';

        solve(iter.second,level+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    NODE* root = new NODE;
    while(N--) {
        int k; 
        cin >> k;
        NODE* node = root;

        for (int i=0;i<k;i++) {
            string value; 
            cin >> value;

            if (node->m.find(value) == node->m.end()) {
                node->m[value] = new NODE;
            }
            node = node->m[value];
        }
    }

    solve(root,0);

    return 0;
}
