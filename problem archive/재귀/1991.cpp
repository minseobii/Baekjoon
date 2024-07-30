#include <iostream>
using namespace std;
int N;
char arr[30][3];

void PreorderTraversal(char a) {
    cout << a;
    int idx = a-'A';
    if (arr[idx][1] != '.') {
        PreorderTraversal(arr[idx][1]);
    }
    if (arr[idx][2] != '.') {
        PreorderTraversal(arr[idx][2]);
    }
}

void InorderTraversal(char a) {
    int idx = a-'A';
    if (arr[idx][1] != '.') {
        InorderTraversal(arr[idx][1]);
    }
    cout << a;
    if (arr[idx][2] != '.') {
        InorderTraversal(arr[idx][2]);
    }
}

void PostorderTraversal(char a) {
    int idx = a-'A';
    if (arr[idx][1] != '.') {
        PostorderTraversal(arr[idx][1]);
    }
    if (arr[idx][2] != '.') {
        PostorderTraversal(arr[idx][2]);
    }
    cout << a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        char c;
        int idx;
        cin >> c;
        idx = c - 'A';

        arr[idx][0] = c;
        cin >> arr[idx][1] >> arr[idx][2];
    }
    PreorderTraversal('A');
    cout << '\n';
    InorderTraversal('A');
    cout << '\n';
    PostorderTraversal('A');
    cout << '\n';
    return 0;
}
