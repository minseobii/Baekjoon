#include <iostream>
using namespace std;
int N;
int arr[128][128] = {0,};

int answhite=0;
int ansblue=0;

struct PAIR {
    int white,blue;
};

struct PAIR solve(int i, int j, int n) {
    PAIR pair;
    if (n == 2) {
        int blue=0;
        if (arr[i][j] == 1) {
            blue++;
        }
        if (arr[i+1][j] == 1) {
            blue++;
        }
        if (arr[i][j+1] == 1) {
            blue++;
        }
        if (arr[i+1][j+1] == 1) {
            blue++;
        } 

        if (blue == 4) {
            pair = {0, -1};
        }
        else if (blue == 0) {
            pair = {-1, 0};
        }
        else {
            pair = {4-blue, blue};
        }
    }

    else {
        PAIR first_pair = solve(i,j,n/2);
        PAIR second_pair = solve(i+n/2,j,n/2);
        PAIR third_pair = solve(i,j+n/2,n/2);
        PAIR fourth_pair = solve(i+n/2,j+n/2,n/2);

        if (first_pair.blue == -1 && second_pair.blue == -1 && third_pair.blue == -1 && fourth_pair.blue == -1) {
            pair = {0,-1};
        }
        else if (first_pair.white == -1 && second_pair.white == -1 && third_pair.white == -1 && fourth_pair.white == -1) {
            pair = {-1 ,0};
        }

        else {
            if (first_pair.blue == -1) {
                first_pair.blue = 1;
            }
            else if (first_pair.white == -1) {
                first_pair.white = 1;
            }

            if (second_pair.blue == -1) {
                second_pair.blue = 1;
            }
            else if (second_pair.white == -1) {
                second_pair.white = 1;
            }

            if (third_pair.blue == -1) {
                third_pair.blue = 1;
            }
            else if (third_pair.white == -1) {
                third_pair.white = 1;
            }

            if (fourth_pair.blue == -1) {
                fourth_pair.blue = 1;
            }
            else if (fourth_pair.white == -1) {
                fourth_pair.white = 1;
            }

            pair = {first_pair.white + second_pair.white + third_pair.white + fourth_pair.white ,
                    first_pair.blue + second_pair.blue + third_pair.blue + fourth_pair.blue};
        }
    }

    return pair;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i=0;i<N;i++) {
        for (int j=0;j<N;j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }

    PAIR ans_pair = solve(0,0,N);

    if (ans_pair.blue == -1) {
        ansblue = 1;
    }
    else if (ans_pair.white == -1) {
        answhite = 1;
    }
    else {
        ansblue = ans_pair.blue;
        answhite = ans_pair.white;
    }

    cout << answhite << endl;
    cout << ansblue << endl;

    return 0;
}
