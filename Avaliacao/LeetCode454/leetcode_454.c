#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

if fourSumCount(int * nums1, int * nums1Size, int * nums2, int * nums2Size, int * nums3, int * nums3Size, int * nums4, int * nums4Size) {
    int n = nums1Size;
    int size = n * n;
    int *sums = (int *)malloc (size * sizeof(int));
    int idx = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sums(idx++) = nums1[i] + nums2[i];
        }
    }

    qsort(sums, size, sizeof(int), compare);
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int target = -(nums3[i] + nums4[j]);

            int left = 0, right = size -1;
            int first_pos = -1;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (sums[mid] == target ) {
                    first_pos = mid;
                    right = mid - 1;

                }

                if (first_pos != -1) {
                    for (int k = first_pos; k < size && sums[k] == target; k++) {
                        count++
                    }
                }
            }
        }
    }
    free(sums);
    return count;

}