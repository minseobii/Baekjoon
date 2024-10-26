#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
long double x[5], y[5];
int CCW[5], zerocount;

int cal(int a, int b, int c) {
    long long ll  = 1;
    long long ccw = ll * ((x[b]-x[a])*(y[c]-y[b])) - ((x[c]-x[b])*(y[b]-y[a]));
    if (ccw > 0) return 1;
    else if (ccw < 0) return -1;
    return 0;
}

void solve(int a, int b, int c, bool type) {
    if (type == false) {
        long double m = (y[a]-y[b])/(x[a]-x[b]);
        long double b = (y[a] - (m * x[a]));

        cout << 1 << '\n';
        cout << x[c] << ' ' << m*x[c] + b << '\n';
    }
    else if (type == true) {
        long double m = (y[a]-y[b])/(x[a]-x[b]);
        long double b = (y[a] - (m * x[a]));

        cout << 1 << '\n';
        cout << (y[c] - b) / m << ' ' << y[c] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<fixed;
    cout.precision(9);

    cin >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3] >> x[4] >> y[4];
    CCW[1] = cal(1,3,4);
    CCW[2] = cal(2,3,4);
    CCW[3] = cal(3,1,2);
    CCW[4] = cal(4,1,2);

    for (int i=1;i<=4;i++) if (CCW[i] == 0) zerocount++;

    //조건 분기 정답
    // 	ll ans1 = CCW(A, B, C) * CCW(A, B, D);
	// ll ans2 = CCW(C, D, A) * CCW(C, D, B);

	// if (ans1 == 0 && ans2 == 0) // 평행 혹은 양 끝점이 접촉해 있을 때
	// {
	// 	// pair 대소비교. 첫번째 인자가 같다면 두번째 인자 비교
	// 	if (A > B) swap(A, B);
	// 	if (C > D) swap(C, D);
		
	// 	if (A <= D && B >= C)
	// 	{
	// 		cout << 1 << '\n';
	// 		find_intersection(A, B, C, D);
	// 	}
	// 	else cout << 0 << '\n';
	// }
	// else 
	// {
	// 	// 교차 혹은 한 점이 선분 위에 있을 때(끝점 x)
	// 	if (ans1 <= 0 && ans2 <= 0)
	// 	{
	// 		cout << 1 << '\n';
	// 		find_intersection(v[0], v[1], v[2], v[3]);
	// 	}
	// 	else cout << 0 << '\n';
	// }

    if (CCW[1]*CCW[2] == -1 && CCW[3]*CCW[4] == -1) {
        long double m1,m2,b1,b2;
        if (x[1] == x[2]) solve(3,4,1,0);
        else if (x[3] == x[4]) solve(1,2,3,0);
        else if (y[1] == y[2]) {
            if (x[3] != x[4]) solve(3,4,1,1);
            else {
                cout << 1 << '\n';
                cout << x[3] << ' ' << y[1] << '\n';
                return 0;
            }
        }
        else if (y[3] == y[4]) {
            if (x[1] != x[2]) solve(1,2,3,1);
            else {
                cout << 1 << '\n';
                cout << x[1] << ' ' << y[3] << '\n';
                return 0;
            }
        }
        else {
            m1 = (y[1]-y[2])/(x[1]-x[2]);
            m2 = (y[3]-y[4])/(x[3]-x[4]);
            b1 = (y[1] - ((y[1]-y[2])/(x[1]-x[2]) * x[1]));
            b2 = (y[3] - ((y[3]-y[4])/(x[3]-x[4]) * x[3]));

            cout << 1 << '\n';
            cout << (b2-b1) / (m1 - m2) << ' ' << (b2-b1) / (m1 - m2) * m1 + b1 << '\n';
        }
    }
    else if (zerocount == 1 && (CCW[1]*CCW[2] == -1 || CCW[3]*CCW[4] == -1)) {
        for (int k=1;k<=4;k++) {
            if (CCW[k] == 0) {
                cout << 1 << '\n';
                cout << x[k] << ' ' << y[k] << '\n';
                break;
            }
        }
    }
    else if (zerocount == 2) {
        for (int k=1;k<=4;k++) {
            if (CCW[k] == 0) {
                cout << 1 << '\n';
                cout << x[k] << ' ' << y[k] << '\n';
                break;
            }
        }
    }
    else if (zerocount > 2) {
        bool ans = 0;
        if (x[1] > x[2]) {
          swap(x[1],x[2]);
          swap(y[1],y[2]);
        }
        else if (x[1] == x[2] && y[1] > y[2]) {
          swap(x[1],x[2]);
          swap(y[1],y[2]);
        }
        
        if (x[3] > x[4]) {
          swap(x[3],x[4]);
          swap(y[3],y[4]);
        }
        else if (x[3] == x[4] && y[3] > y[4]) {
          swap(x[3],x[4]);
          swap(y[3],y[4]);
        }

        if (x[2] == x[3] && y[2] == y[3]) {
            cout << 1 << '\n';
            cout << x[2] << ' ' << y[2] << '\n';
            return 0;
        }
        if (x[4] == x[1] && y[4] == y[1]) {
            cout << 1 << '\n';
            cout << x[1] << ' ' << y[1] << '\n';
            return 0;
        }

        if (x[1] < x[3] && x[2] > x[3]) ans = 1;
        else if (x[3] < x[1] && x[4] > x[1]) ans = 1;
        else if (x[1] == x[3]) {
            if (y[1] < y[3] && y[2] > y[3]) ans = 1;
            else if (y[3] < y[1] && y[4] > y[1]) ans = 1;
            else if (y[1] == y[3]) ans = 1;
        }

        cout << ans << '\n';
    }
    else cout << 0 << '\n';
    return 0;
}
