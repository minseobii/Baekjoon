#include <iostream>
using namespace std;
int N;
int Heap[100001];
int HeapCount = 0;

void swap(int a, int b) {
    int temp = Heap[a];
    Heap[a] = Heap[b];
    Heap[b] = temp;
}

void heap_push(int input) {
    Heap[++HeapCount] = input;
    int Parents = HeapCount/2;
    int Child = HeapCount;
    while (Parents > 0 && (abs(Heap[Parents]) > abs(Heap[Child])) || ((abs(Heap[Parents]) == abs(Heap[Child])) && Heap[Parents] > Heap[Child])) {
        swap(Parents, Child);
        Child = Parents;
        Parents = Parents/2;
    }
}

int heap_pop() {
    if (HeapCount == 0) {
        return 0;
    }
    else {
        int ReturnValue = Heap[1];
        Heap[1] = 0;
        swap(1, HeapCount--); 
        int Parents = 1;
        int Child = 2;
        
        while (Child <= HeapCount) {
            if (Child < HeapCount && abs(Heap[Child]) > abs(Heap[Child+1])) {
                Child++;
            }
            else if (Child < HeapCount && abs(Heap[Child]) == abs(Heap[Child+1]) && Heap[Child] > Heap[Child+1]) {
                Child++;
            }

            if ((abs(Heap[Parents]) > abs(Heap[Child])) || ((abs(Heap[Parents]) == abs(Heap[Child])) && Heap[Parents] > Heap[Child])) {
                swap(Parents, Child);
                Parents = Child;
                Child = Child * 2;
            }
            else {
                break;
            }
        }

        return ReturnValue;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    while (N--) {
        int input;
        cin >> input;
        if (input) {
            heap_push(input);
        }
        else {
            cout << heap_pop() << '\n';
        }
    }
    return 0;
}
