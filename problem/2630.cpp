#include <iostream>
using namespace std;
int N;

int answhite=0;
int ansblue=0;

struct PAIR {
    int white,blue;
};

struct PAIR solve(int arr[], int i, int j, int n) {
    PAIR pair;
    if (N == 2) {
        int blue=0;
        if (arr[i][j] == 1) {
            blue++;
        }s
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
        PAIR first_pair = solve(arr,i,j,N/2);
        PAIR second_pair = solve(arr,i+N/2,j,N/2);
        PAIR third_pair = solve(arr,i,j+N/2,N/2);
        PAIR fourth_pair = solve(arr,i+N/2,j+N/2,N/2);

        if (first_pair.bule == -1 && second_pair.bule == -1 && third_pair.bule == -1 && fourth_pair.bule == -1 &&) {
            pair = {0,-1};
        }
        else if (first_pair.white == -1 && second_pair.white == -1 && third_pair.white == -1 && fourth_pair.white == -1 &&) {
            pair = {-1 ,0};
        }

        else {
            if (first_pair.bule == -1) {
                first_pair.bule = 1;
            }
            else if (first_pair.white == -1) {
                first_pair.white = 1;
            }

            if (secondpair.bule == -1) {
                secondpair.bule = 1;
            }
            else if (secondpair.white == -1) {
                secondpair.white = 1;
            }

            if (third_pair.bule == -1) {
                third_pair.bule = 1;
            }
            else if (third_pair.white == -1) {
                third_pair.white = 1;
            }

            if (fourth_pair.bule == -1) {
                fourth_pair.bule = 1;
            }
            else if (fourth_pair.white == -1) {
                fourth_pair.white = 1;
            }

            pair = {first_pair.white + second_pair.white + third_pair.white + fourth_pair.white ,
                    first_pair.bule + second_pair.bule + third_pair.bule + fourth_pair.bule};
        }
    }

    return pair;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    int arr[N][N] = {0,};

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

    PAIR ans_pair = solve(arr,0,0,N);

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
