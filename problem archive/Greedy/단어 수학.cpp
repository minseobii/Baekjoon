#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,ans;
int num = 9;

pair<int,int> arr[26];
int subarr[8] = {1,10,100,1000,10000,100000,1000000,10000000};
int alpha[26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i=0;i<26;i++) {
        arr[i].second = i;
    }

    for (int i=0;i<N;i++) {
        string s;
        cin >> s;

        int idx = 0;
        for (int j=s.length()-1;j>=0;j--) {
            arr[s[idx++]-'A'].first += subarr[j];
        }
    }   

    sort(arr,arr+26,greater<>());

    for (int i=0;i<10;i++) {
        alpha[arr[i].second] = num;
        ans += arr[i].first * num;

        num--;
    }

    cout << ans << endl;
    return 0;
}
