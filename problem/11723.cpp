#include <iostream>
#include <string>
using namespace std;
int M;
string strarr[6] = {"add", "remove", "check" , "toggle", "all" , "empty"};
bool arr[21] = {false,};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M;

    while (M--) {
        string str;
        int num;
        cin >> str;

        if (str.compare(strarr[0]) == 0) {
            cin >> num;
            arr[num] = true;
        }
        else if (str.compare(strarr[1]) == 0) {
            cin >> num;
            arr[num] = false;
        }
        else if (str.compare(strarr[2]) == 0) {
            cin >> num;
            if (arr[num]) {
                cout << 1 << '\n';
            }
            else {
                cout << 0 << '\n';
            }
        }
        else if (str.compare(strarr[3]) == 0) {
            cin >> num;
            if (arr[num]) {
                arr[num] = false;
            }
            else {
                arr[num] = true;
            }
        }
        else if (str.compare(strarr[4]) == 0) {
            for (int i=1;i<21;i++) {
                arr[i] = true;
            }
        }
        else if (str.compare(strarr[5]) == 0) {
            for (int i=1;i<21;i++) {
                arr[i] = false;
            }
        }
    }
    return 0;
}
