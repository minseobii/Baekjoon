#include <iostream>
using namespace std;
int N,M,B;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;
    int arr[257] = {0,};
    int AnsTime[257] = {0,};
    int MaxHeight = 0;

    int same = -1;
    int flag = 1;

    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            int temp;
            cin >> temp;
            if (same == -1) {
                same = temp;
            }
            else {
                if (same != temp) {
                    flag = 0;
                }
            }
            MaxHeight = max(MaxHeight, temp);
            arr[temp]++;
        }
    }

    for (int h=256;h>=0;h--) {
            int Block = B;
            int DigHeight = MaxHeight;

            while (DigHeight > h) { //Dig
                Block += arr[DigHeight] * (DigHeight-h);
                AnsTime[h] += arr[DigHeight] * (DigHeight-h) * 2;
                do {
                    DigHeight--;
                } while (arr[DigHeight] == 0);
            }

            for (int i=0;i<h;i++) {
                if (arr[i]) {
                    Block -= arr[i] * (h-i);
                    AnsTime[h] += arr[i] * (h-i);
                    if (Block < 0) {
                        AnsTime[h] = 0;
                        break;
                    }
                }
            }
    }

    int time = -1;
    int height = -1;
    if (flag) {
        time = 0;
        height = same;
    }
    else {
        for (int i=0;i<=256;i++) {
            if (AnsTime[i] == 0) {
                continue;
            }
            else {
                if (time == -1) {
                    time = AnsTime[i];
                    height = i;
                }
                else {
                    if (time > AnsTime[i]) {
                        time = AnsTime[i];
                        height = i;
                    }
                    else if (time == AnsTime[i]) {
                        height = max(height, i);
                    }
                }
            }
        }
    }
    cout << time << ' ' << height << '\n';
    return 0;
}
