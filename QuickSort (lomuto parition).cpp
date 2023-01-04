// lomuto parititon
int lomutoPartiton(vector<int> &vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;

    for (int j{low}; j < high; j++) 
        if (vec[j] < pivot) {
            i++;
            swap(vec[j], vec[i]);
        }

    swap(vec[i + 1], vec[high]);
    return i + 1;
}

// lomutoQuickSort algorithm
void lomutoQuickSort(vector<int> &vec, int low, int high) {
    if (low < high) {
        int pi = lomutoPartiton(vec, low, high);

        lomutoQuickSort(vec, low, pi - 1);
        lomutoQuickSort(vec, pi + 1, high);
    }
}
