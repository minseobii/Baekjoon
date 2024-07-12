#include <iostream>
using namespace std;
int N;
int idx = 1;
int heap[100001] = {0,};

void swap(int i, int j) {
    int temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void heapremove() {
   if (idx == 1) {
   }
   else if (idx == 2) {
    heap[1] = 0;
    idx--;
   }
   else {
    int root = 1;
    int left = 2;
    int right = 3;
    heap[root] = heap[idx-1];
    heap[idx-1] = 0;
    idx--;

    while (1) {
        if ((left < idx && heap[left] < heap[root]) && (right < idx && heap[left] < heap[root])) {
            if (heap[left] < heap[right]) {
                swap(left, root);
                root = left;
            }
            else {
                swap(right, root);
                root = right;
            }
        }
        else if (left < idx && heap[left] < heap[root] ) {
            swap(left, root);
            root = left;
        }
        else if (right < idx && heap[right] < heap[root]) {
            swap(right, root);
            root = right;
        }
        else {
            break;
        }

        left = root*2;
        right = root*2 + 1;
    }
   }
}

void heapadd(int a) {
    heap[idx] = a;
    int child = idx;

    int parents = child/2;
    while (parents > 0 && heap[parents] > a) {
        swap(parents, child);
        child = parents;
        parents = parents / 2;
    }

    idx++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    
    
    

    for (int i=0;i<N;i++) {
        int input;
        cin >> input;

        if (input == 0) {
            cout << heap[1] << '\n';
            heapremove();
        }
        else {
            heapadd(input);
        }
    }
    return 0;
}
