#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    vector<pair<int, int>> v;
    int arr[N];

    for (int i=0;i<N;i++) {
        int input;
        cin >> input;
        pair<int,int> new_pair = {input, i};
        v.push_back(new_pair);
    }
    sort(v.begin(),v.end());

    int count = 0;
    for (int i=0;i<N;i++) {
        if (i==0) {
            arr[i] = 0;
        }
        else {
            if (v[i].first == v[i-1].first) {
                arr[i] = arr[i-1]; 
                count++;
            }
            else {
                arr[i] = i-count;
            }
        }
    }

    for (int i=0;i<N;i++) {
        v[i].first = v[i].second;
        v[i].second = arr[i];
    }

    sort(v.begin(),v.end());

    for (int i=0;i<N;i++) {
        cout << v[i].second << ' ';
    }
    cout << '\n';

    return 0;
}
