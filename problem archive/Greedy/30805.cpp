#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N,M;
int A[100];
int B[100];
vector<int> v[101];
vector<pair<int,int>> sv;
int ans;

bool compare1(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> A[i];
        sv.push_back({A[i], i});
    }
    cin >> M;
    for (int i=0;i<M;i++) {
        cin >> B[i];
    }

    for (int i=0;i<M;i++) {
        v[B[i]].push_back(i);
    }

    sort(sv.begin(),sv.end(),compare1);

    vector<int> ans;
    int idx1 = -1;
    int idx2 = -1;
    for (int i=0;i<N;i++) {
        int x = sv[i].first;
        int index = sv[i].second;

        if (v[x].empty()) {
            continue;
        }
        for (int k=0;k<v[x].size();k++) {
            if (idx1 < index && idx2 < v[x][k]) {
                ans.push_back(x);
                idx1 = index;
                idx2 = v[x][k];
                v[x].erase(v[x].begin()+k);
                break;
            } 
        }
    }

    cout << ans.size() << '\n';
    for (int i=0;i<ans.size();i++) {
        cout << ans[i] <<' ';
    }
    cout << '\n';
    return 0;
}
