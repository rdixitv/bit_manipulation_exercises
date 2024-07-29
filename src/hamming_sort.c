#include <stdio.h>

#include "exercises.h"

// Sorts the given numbers in ascending order by their Hamming distance from the
// number k. The Hamming distance between two numbers is the number of bits that
// differ in the binary representation of the numbers. For example, the Hamming
// distance of 6 from 4 from 2 is 2.

void hammingSort(int k, int arr[], int size) {

    // Store the Hamming distances between each element of arr and k in the
    // array dists.
    int dists[size];
    for (int i = 0; i < size; i++) {
        int setBits = 0;

        for (int x = arr[i] ^ k; x > 0; x >>= 1) {
            setBits += x & 1;
        }

        dists[i] = setBits;
    }

    // Use selection sort to sort the numbers by distance.
    for (int i = 0; i < size - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < size; j++) {
            if (dists[j] < dists[pos]) {
                pos = j;
            }
        }

        int tmp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = tmp;

        tmp = dists[i];
        dists[i] = dists[pos];
        dists[pos] = tmp;
    }
}

void runHammingSort() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    hammingSort(k, arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
}
