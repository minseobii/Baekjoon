#include <iostream>
#include <stack>
using namespace std;
int N;
int ans = 2;
int arr[20][20];

void push2048(int k, int array[][20]) {
    // k : 1-Up, 2-Left, 3-Down, 4-Right
    bool find = false;
    if (k == 1) {
        for (int i=0;i<N;i++) {
            stack<int> st;
            for (int j=0;j<N;j++) {
                if (array[j][i]) {
                    if (find == false && !st.empty() && st.top() == array[j][i]) {
                        st.pop();
                        st.push(2*array[j][i]);
                        find = true;
                    }
                    else {
                        st.push(array[j][i]);
                        find = false;
                    }
                }
            }

            stack<int> st1;
            while(!st.empty()) {
                st1.push(st.top());
                st.pop();
            }

            for (int j=0;j<N;j++) {

                if (!st1.empty()) {
                    array[j][i] = st1.top();
                    st1.pop();
                }
                else {
                    array[j][i] = 0;
                }
            }
        }
    }
    else if (k == 2) {
        for (int i=0;i<N;i++) {
            stack<int> st;
            for (int j=0;j<N;j++) {
                if (array[i][j]) {
                    if (find == false && !st.empty() && st.top() == array[i][j]) {
                        st.pop();
                        st.push(2*array[i][j]);
                        find = true;
                    }
                    else {
                        st.push(array[i][j]);
                        find = false;
                    }
                }
            }

            stack<int> st1;
            while(!st.empty()) {
                st1.push(st.top());
                st.pop();
            }

            for (int j=0;j<N;j++) {
                if (!st1.empty()) {
                    array[i][j] = st1.top();
                    st1.pop();
                }
                else {
                    array[i][j] = 0;
                }
            }
        }
    }
    else if (k == 3) {
        for (int i=0;i<N;i++) {
            stack<int> st;
            for (int j=N-1;j>=0;j--) {
                if (array[j][i]) {
                    if (find == false && !st.empty() && st.top() == array[j][i]) {
                        st.pop();
                        st.push(2*array[j][i]);
                        find = true;
                    }
                    else {
                        st.push(array[j][i]);
                        find = false;
                    }
                }
            }

            stack<int> st1;
            while(!st.empty()) {
                st1.push(st.top());
                st.pop();
            }

            for (int j=N-1;j>=0;j--) {
                if (!st1.empty()) {
                    array[j][i] = st1.top();
                    st1.pop();
                }
                else {
                    array[j][i] = 0;
                }
            }
        }
    }
    else if (k == 4) {
        for (int i=0;i<N;i++) {
            stack<int> st;
            for (int j=N-1;j>=0;j--) {
                if (array[i][j]) {
                    if (find == false && !st.empty() && st.top() == array[i][j]) {
                        st.pop();
                        st.push(2*array[i][j]);
                        find = true;
                    }
                    else {
                        st.push(array[i][j]);
                        find = false;
                    }
                }
            }

            stack<int> st1;
            while(!st.empty()) {
                st1.push(st.top());
                st.pop();
            }

            for (int j=N-1;j>=0;j--) {
                if (!st1.empty()) {
                    array[i][j] = st1.top();
                    st1.pop();
                }
                else {
                    array[i][j] = 0;
                }
            }
        }
    }
}

void cal(int k, int array[][20]) {
    if (k == 5) {
        return;
    }

    for (int l=1;l<=4;l++) {
        int temp[20][20] = {0,};
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                temp[i][j] = array[i][j];
            }
        }
        push2048(l, temp);
        for (int i=0;i<N;i++) {
            for (int j=0;j<N;j++) {
                ans = max(ans,temp[i][j]); 
            }
        }
        cal(k+1,temp);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            cin >> arr[i][j];
        }
    }
    
    cal(0,arr);

    cout << ans << endl;
    return 0;
}
