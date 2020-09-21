#ifndef KNU_OOP_K28_SORTS_H
#define KNU_OOP_K28_SORTS_H

template<class T>
void bubble_sort(T *arr, int size, int(*compare_func)(T &obj1, T &obj2)) {
    T temp;

    if (compare_func == nullptr) {
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < size - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    } else {
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < size - i; j++) {
                if (compare_func(arr[j], arr[j + 1]) == 1) {
                    temp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}

template<class T>
void insertion_sort(T *arr, int size, int(*compare_func)(T &obj1, T &obj2)) {
    T key;
    int j;

    if (compare_func == nullptr) {
        for (int i = 1; i < size; i++) {
            key = arr[i];
            j = i;
            while (j > 0 && arr[j - 1] > key) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = key;
        }
    } else {
        for (int i = 1; i < size; i++) {
            key = arr[i];
            j = i;
            while (j > 0 && compare_func(arr[j - 1], key) == 1) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = key;
        }
    }

}

template<class T>
void merge(T *arr, int l, int m, int r, int(*compare_func)(T &obj1, T &obj2)) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    T L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    if (compare_func == nullptr) {
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    } else {
        while (i < n1 && j < n2) {
            if (compare_func(L[i], R[j]) <= 0) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
    }


    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

template<class T>
void merge_sort_temp(T *arr, int l, int r, int(*compare_func)(T &obj1, T &obj2)) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort_temp(arr, l, m, compare_func);
        merge_sort_temp(arr, m + 1, r, compare_func);

        merge(arr, l, m, r, compare_func);
    }
}

template<class T>
void merge_sort(T *arr, int size, int(*compare_func)(T &obj1, T &obj2)) {
    merge_sort_temp(arr, 0, size - 1, compare_func);
}

template<class T>
int partition(T *arr, int low, int high, int(*compare_func)(T &obj1, T &obj2)) {
    T pivot = arr[high];
    int i = (low - 1);

    if (compare_func == nullptr) {
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
    } else {
        for (int j = low; j <= high - 1; j++) {
            if (compare_func(pivot, arr[j]) == 1) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template<class T>
void quick_sort_temp(T *arr, int low, int high, int(*compare_func)(T &obj1, T &obj2)) {
    if (low < high) {
        int pi = partition(arr, low, high, compare_func);

        quick_sort_temp(arr, low, pi - 1, compare_func);
        quick_sort_temp(arr, pi + 1, high, compare_func);
    }
}

template<class T>
void quick_sort(T *arr, int size, int(*compare_func)(T &obj1, T &obj2)) {
    quick_sort_temp(arr, 0, size - 1, compare_func);
}

//template <class T>
//T *getMax(T *arr, int size){
//    T *max = arr[0];
//
//    for (int i = 1; i < size; i++)
//        if (arr[i] > max)
//            max = arr[i];
//    return max;
//}
//
//template <class T>
//void countSort(T *arr, int n, int exp){
//    int output[n];
//    int i, count[10] = {0};
//    for (i = 0; i < n; i++)
//        count[ (arr[i]/exp)%10 ]++;
//
//    for (i = 1; i < 10; i++)
//        count[i] += count[i - 1];
//
//    for (i = n - 1; i >= 0; i--)
//    {
//        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
//        count[ (arr[i]/exp)%10 ]--;
//    }
//
//    for (i = 0; i < n; i++)
//        arr[i] = output[i];
//}
//
//template <class T>
//void radix_sort(T *arr, int size){
//     T &m = getMax(arr, size);
//
//    for (int exp = 1; m/exp > 0; exp *= 10)
//        countSort(arr, size, exp);
//}

#endif
