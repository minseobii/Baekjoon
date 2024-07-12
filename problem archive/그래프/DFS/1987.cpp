#include <iostream>
#include <queue>
using namespace std;

int R,C;
char arr[21][21];
int ans=0;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int alphabet[27];

int DFS(int x, int y, int num) {
    int tempnum=0; 
    
    if (alphabet[arr[x+1][y]-'A'] == 0 && x+1 < R) {
        alphabet[arr[x+1][y]-'A']++;
        tempnum = max(DFS(x+1,y,num+1),tempnum);
        alphabet[arr[x+1][y]-'A']--;
    }
    if (alphabet[arr[x][y+1]-'A'] == 0 && y+1 < C) {
        alphabet[arr[x][y+1]-'A']++;
        tempnum = max(DFS(x,y+1,num+1),tempnum);
        alphabet[arr[x][y+1]-'A']--;
    }
    if (alphabet[arr[x-1][y]-'A'] == 0 && x > 0) {
        alphabet[arr[x-1][y]-'A']++;
        tempnum = max(DFS(x-1,y,num+1),tempnum);
        alphabet[arr[x-1][y]-'A']--;
    }
    if (alphabet[arr[x][y-1]-'A'] == 0 && y > 0) {
        alphabet[arr[x][y-1]-'A']++;
        tempnum = max(DFS(x,y-1,num+1),tempnum);
        alphabet[arr[x][y-1]-'A']--;
    }
    return max(num,tempnum);
}

int main() {
    cin >> R >> C;
    for (int i=0;i<R;i++) {
        for (int j=0;j<C;j++) {
            cin >> arr[i][j];
        }
    }
    alphabet[arr[0][0]-'A']++;
    cout << DFS(0,0,1);
    return 0;
}