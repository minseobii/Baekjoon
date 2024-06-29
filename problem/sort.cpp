void swap(int arr[] ,int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp
}

void sort(int arr[],int N) {
    for (int i=0;i<N;i++) {
        int min = i;
        for (int j=i+1;j<N;j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr,i,min);
    }
}