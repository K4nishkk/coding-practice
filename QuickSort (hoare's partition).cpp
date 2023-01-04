// hoare partition
int hoarePartition(vector<int> &vec, int low, int high) {
    int pivot = vec[low];
    int i = low - 1, j = high + 1;

    while (true) {
        do
            i++;
        while (vec[i] < pivot);

        do 
            j--;
        while (vec[j] > pivot);

        if (i >= j)
            return j;

        swap(vec[i], vec[j]);
    }
}

void hoareQuickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int pi = hoarePartition(vec, low, high);

        hoareQuickSort(vec, low, pi);
        hoareQuickSort(vec, pi + 1, high);
    }
}
