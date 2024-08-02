#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M,C,H;
vector<pair<int,int>> Chicken;
vector<pair<int,int>> House;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<=N;j++) {
            int a;
            cin >> a;
            if (a == 2) {
                C++;
                Chicken.push_back({i,j});
            }
            else if (a == 1) {
                H++;
                House.push_back({i,j});
            }
        }
    }

    int subarr[C];
    for (int i=0;i<C;i++) {
        if (i < M) {
            subarr[i] = 1;
        }
        else {
            subarr[i] = 0;
        }
    }

    int MinSum = 100000;
    do { 
        int Dis[H] = {0,};
        int TempSum = 0;
        for (int i=0;i<C;i++) {
            if (subarr[i]) {
                for (int j=0;j<H;j++) {
                    if (Dis[j] == 0) {
                        Dis[j] = abs(Chicken[i].first - House[j].first)+abs(Chicken[i].second - House[j].second);
                        continue;
                    }
                    else {
                        Dis[j] = min(Dis[j], abs(Chicken[i].first - House[j].first)+abs(Chicken[i].second - House[j].second));
                    }   
                }
            }
        }
        for (int i=0;i<H;i++) {
            TempSum += Dis[i];
        }
        MinSum = min(MinSum, TempSum);
    } while(prev_permutation(subarr,subarr+C));
    cout << MinSum << endl;
    return 0;
}
