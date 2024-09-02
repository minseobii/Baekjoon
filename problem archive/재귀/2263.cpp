#include <iostream>
using namespace std;
int N,ans;
int inorder[100000];
int postorder[100000];
int memoization[100001];

void preorder(int l1, int r1, int l2, int r2) {
    if (l1 == r1) return;

    int root = postorder[r2-1];
    int i = memoization[root] - l1;

    cout << root << ' ';
    preorder(l1,l1+i,l2,l2+i);
    preorder(l1+i+1,r1,l2+i,r2-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> inorder[i];
        memoization[inorder[i]] = i;
    }
    for (int i=0;i<N;i++) {
        cin >> postorder[i];
    }

    preorder(0,N,0,N);
    return 0;
}
