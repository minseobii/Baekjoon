#include <iostream>
using namespace std;
long long x[5];
long long y[5];
long long v[5];
int ans[5];

int answer = 0;

long long cal(long long a, long long b, long long c) {
    return ((x[a]-x[b])*(y[a]-y[c]))-((x[a]-x[c])*(y[a]-y[b]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> x[1] >> y[1] >> x[2] >> y[2];
    cin >> x[3] >> y[3] >> x[4] >> y[4];

    v[1] = cal(1,3,4);
    v[2] = cal(2,3,4);
    v[3] = cal(3,1,2);
    v[4] = cal(4,1,2);

    int zerocount = 0;

    for (int i=1;i<=4;i++) {
        if (v[i] > 0) ans[i] = 1;
        else if (v[i] < 0) ans[i] = -1;
        else {
            zerocount++;
        }
    }

    if (ans[1]*ans[2] == -1 && ans[3]*ans[4] == -1) {
        answer = 1;
    }
    else if (zerocount == 1) {
        if (ans[1]*ans[2] == -1 || ans[3]*ans[4] == -1) {
            answer = 1;
        }
    }
    else if (zerocount > 1) {
        int xmin1;
        int xmax1;
        if (x[3] > x[4]) {
            xmin1 = x[4];
            xmax1 = x[3];
        }
        else {
            xmin1 = x[3];
            xmax1 = x[4];
        }

        int ymin1;
        int ymax1;
        if (y[3] > y[4]) {
            ymin1 = y[4];
            ymax1 = y[3];
        }
        else {
            ymin1 = y[3];
            ymax1 = y[4];
        }



        int xmin2;
        int xmax2;
        if (x[1] > x[2]) {
            xmin2 = x[2];
            xmax2 = x[1];
        }
        else {
            xmin2 = x[1];
            xmax2 = x[2];
        }

        int ymin2;
        int ymax2;
        if (y[1] > y[2]) {
            ymin2 = y[2];
            ymax2 = y[1];
        }
        else {
            ymin2 = y[1];
            ymax2 = y[2];
        }

        if ((x[1] >= xmin1 && x[1] <= xmax1) || (x[2] >= xmin1 && x[2] <= xmax1)) {
            if ((y[1] >= ymin1 && y[1] <= ymax1) || (y[2] >= ymin1 && y[2] <= ymax1)) {
                answer = 1;
            }
        }

        if ((x[3] >= xmin2 && x[3] <= xmax2) || (x[4] >= xmin2 && x[4] <= xmax2)) {
            if ((y[3] >= ymin2 && y[3] <= ymax2) || (y[4] >= ymin2 && y[4] <= ymax2)) {
                answer = 1;
            }
        }
    }
    cout << answer << endl;
    return 0;
}
