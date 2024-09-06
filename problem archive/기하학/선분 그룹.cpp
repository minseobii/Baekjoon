#include <iostream>
#include <algorithm>
using namespace std;
int N;
int ans[2];
int arr[3000][4];
int parent[3000];
int ran[3000];

int x[5];
int y[5];
int v[5];

int cal(int a,int b,int c) {
    return ((x[a]-x[b])*(y[a]-y[c]))-((x[a]-x[c])*(y[a]-y[b]));
}

bool iscross(int a ,int b) {
    x[1] = arr[a][0];
    y[1] = arr[a][1];
    x[2] = arr[a][2];
    y[2] = arr[a][3];
    x[3] = arr[b][0];
    y[3] = arr[b][1];
    x[4] = arr[b][2];
    y[4] = arr[b][3];

    v[1] = cal(1,3,4);
    v[2] = cal(2,3,4);
    v[3] = cal(3,1,2);
    v[4] = cal(4,1,2);

    int zerocount = 0;
    bool answer = false;
    int ans_arr[5] = {0,};

    for (int i=1;i<=4;i++) {
        if (v[i] > 0) ans_arr[i] = 1;
        else if (v[i] < 0) ans_arr[i] = -1;
        else {
            zerocount++;
        }
    }

    if (ans_arr[1]*ans_arr[2] == -1 && ans_arr[3]*ans_arr[4] == -1) {
        answer = true;
    }
    else if (zerocount == 1) {
        if (ans_arr[1]*ans_arr[2] == -1 || ans_arr[3]*ans_arr[4] == -1) {
            answer = true;
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
                answer = true;
            }
        }

        if ((x[3] >= xmin2 && x[3] <= xmax2) || (x[4] >= xmin2 && x[4] <= xmax2)) {
            if ((y[3] >= ymin2 && y[3] <= ymax2) || (y[4] >= ymin2 && y[4] <= ymax2)) {
                answer = true;
            }
        }
    }

    return answer;
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return;

    if (ran[v] > ran[u]) swap(u,v);
    ran[u] += ran[v];
    ran[v] = 0;

    parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
        parent[i] = i;
        ran[i] = 1;
    }

    for (int i=0;i<N;i++) {
        for (int j=0;j<i;j++) {
            if (iscross(i,j)) {
                merge(i,j);
            }
        }
    }

    for (int i=0;i<N;i++) {
        if (ran[i]) {
            ans[0]++;
            ans[1] = max(ans[1],ran[i]);
        }
    }

    cout << ans[0] << '\n' << ans[1] << '\n';
    return 0;
}
