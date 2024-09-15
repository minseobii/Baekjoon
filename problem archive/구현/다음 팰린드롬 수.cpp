#include <iostream>
using namespace std;
int arr[55];
int l;

void add(int idx, int num) {
    while(arr[idx]+num > 9) {
        arr[idx] = arr[idx]+num-10;
        idx++;
        num = 1;
    }
    if (idx == l) l++;
    arr[idx] += num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    l = s.length();
    int j = 0;
    for (int i=l-1;i>=0;i--) {
        arr[j++] = s[i]-'0';
    }
    add(0,1);

    int idx = 0;
    while(idx <= (l-1)/2) {
        if (arr[idx] != arr[l-1-idx]) {
            //cout << idx << ' ' << arr[idx] << ' ' << arr[l-1-idx] << endl;
            if (arr[idx] < arr[l-1-idx]) arr[idx] = arr[l-1-idx];
            else {
                add(idx,10+arr[l-1-idx]-arr[idx]);
                idx = 0;
            }
        }
        else idx++;
    }

    for (int i=l-1;i>=0;i--) {
        cout << arr[i];
    }
    return 0;
}
