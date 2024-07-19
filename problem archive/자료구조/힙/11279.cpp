#include <iostream>
using namespace std;
int N;
int MaxHeap[100001];
int HeapCount = 0;

void swap(int a, int b) {
    int temp = MaxHeap[a];
    MaxHeap[a] = MaxHeap[b];
    MaxHeap[b] = temp;
}

void heap_push(int input) {
    MaxHeap[++HeapCount] = input;
    int Parents = HeapCount/2;
    int Child = HeapCount;
    while (Parents > 0 && MaxHeap[Parents] < MaxHeap[Child]) {
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
        int ReturnValue = MaxHeap[1];
        MaxHeap[1] = 0;
        swap(1, HeapCount--); 
        int Parents = 1;
        int Child = 2;
        
        while (Child <= HeapCount) {
            if (Child < HeapCount && MaxHeap[Child] < MaxHeap[Child+1]) {
                Child++;
            }
            if (MaxHeap[Child] > MaxHeap[Parents]) {
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
