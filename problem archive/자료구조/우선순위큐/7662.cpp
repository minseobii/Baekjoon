#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>

using namespace std;
int T;
priority_queue<int, vector<int>, greater<int>> MinHeap;
priority_queue<int, vector<int>, less<int>> MaxHeap;
map <int,int> m;

void PushMaxHeap(int input) {
    MaxHeap.push(input);
}

void PushMinHeap(int input) {
    MinHeap.push(input);
}


void PopMinHeap() {
    m[MinHeap.top()]--;
    MinHeap.pop();
}

void PopMaxHeap() {
    m[MaxHeap.top()]--;
    MaxHeap.pop();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        m.clear();
        while (!MaxHeap.empty()) {
            MaxHeap.pop();
        }
        while (!MinHeap.empty()) {
            MinHeap.pop();
        }

        while (N--) {
            char order;
            int num;
            cin >> order >> num;

            if (order == 'I') {
                m[num]++;
                PushMaxHeap(num);
                PushMinHeap(num);
            }
            else if (order == 'D') {
                if (num == 1) {
                    if (!MaxHeap.empty()) {
                        PopMaxHeap();
                    }
                }
                else if (num == -1) {
                    if (!MaxHeap.empty()) {
                        PopMinHeap();
                    }
                }
            }
            while (!MinHeap.empty() && m[MinHeap.top()] == 0) {
                MinHeap.pop();
            }
            while (!MaxHeap.empty() && m[MaxHeap.top()] == 0) {
                MaxHeap.pop();
            }
        }
        if (MaxHeap.empty() || MinHeap.empty()) {
            cout << "EMPTY" << '\n';
        }
        else {
            cout << MaxHeap.top() << ' ' << MinHeap.top() << '\n';
        }
    }
    return 0;
}

