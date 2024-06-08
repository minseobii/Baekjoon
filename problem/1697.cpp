#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N,K;
int arr[100001];
queue <pair<int,int>> q;

int main() {
    cin >> N >> K;
    
    if (N == K) {
        cout << 0;
        return 0;
    }

    q.push(pair<int,int>(N,0));

    while(!q.empty()) {
        int num = q.front().first;
        int depth = q.front().second;
        q.pop();
        if (2*num == K || num+1 == K || num-1 == K) {
            cout << depth+1;
            break;
        }

        else {
            if (num <= 50000 && !arr[2*num]) {
                q.push(pair<int,int>(2*num, depth+1));
                arr[2*num] = 1;
            }

            if (num < 100000 && !arr[num+1]) {
                q.push(pair<int,int>(num+1, depth+1));
                arr[num+1] = 1;
            }

            if (num > 0 && !arr[num-1]) {
                q.push(pair<int,int>(num-1, depth+1));
                arr[num-1] = 1;
            }
        }
    
    }

    return 0;
}
