#include <iostream>
#include <queue>
#include <string>
using namespace std;
int T;
char dc[4] = {'D','S','L','R'};

struct PAIR {
    int a;
    string v;
};

int main() {
    cin >> T;
    int arr[10000][4];
    for (int n=0;n<10000;n++) {
        arr[n][0] = (n * 2) % 10000;
        if (n) {
            arr[n][1] = n-1;
        }
        else {
            arr[n][1] = 9999;
        }
        arr[n][2] = ((n*10) % 10000) + n / 1000;
        arr[n][3] = (n / 10) + (n % 10) * 1000;
    }
    while (T--) {
        int A, B;
        cin >> A >> B;

        int visit[10000] = {0,};
        queue<PAIR> q; 
        string v;
        PAIR pair = {A, v};
        q.push(pair);

        visit[A] = 1;

        bool find = false;

        while (!q.empty() && !find) {
            int na;
            int a = q.front().a;
            string command = q.front().v;
            q.pop();

            for (int i=0;i<4;i++) {
                na = arr[a][i];
                if (na == B) {
                    cout << command + dc[i] <<'\n';
                    find = true;
                    break;
                }
                else if (visit[na] == 0) {
                    string newcommand = command + dc[i];
                    visit[na] = 1;
                    PAIR newpair = {na, newcommand};
                    q.push(newpair);
                }
            }
        }
    }
    return 0;
}