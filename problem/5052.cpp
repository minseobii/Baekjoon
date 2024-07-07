#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int T;

bool seperate(vector<string> v, int N) {
    sort(v.begin(),v.end());
    vector <string> numberstr[10];
    int number[10]={0,};
    
    for (int i=0;i<N;i++) {
        int j = v[i][0] - '0';
        numberstr[j].push_back(v[i]);
        number[j]++;
    }
    
    for (int i=0;i<10;i++) {
      if (number[i] < 2) {
        continue;
      }
        for (int j=0;j<number[i];j++) {
            if (numberstr[i][j][1] == 0) {
                if (number[i] > 1){
                    return true;
                }
                else {
                    continue;
                }
            }
            else {
                numberstr[i][j].erase(numberstr[i][j].begin());
            }
        }
        if (seperate(numberstr[i],number[i]) == true) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for (int t=0;t<T;t++) {
        int N;
        cin >> N;

        vector <string> v;

        for (int i=0;i<N;i++) {
            string temp;
            cin >> temp;
            v.push_back(temp);
        }

        if (seperate(v,N) == true) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
