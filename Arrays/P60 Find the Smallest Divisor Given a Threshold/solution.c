#include <stdio.h>
#include <stdlib.h>

int smallestDivisor(int* nums, int numsSize, int threshold) {
    int left = 1, right = 1000000; 
    int result = right;
    while (left <= right) { // Binary search for the smallest divisor
        int mid = left + (right - left) / 2;
        int sum = 0;
        for (int i = 0; i < numsSize; i++) {
            sum += (nums[i] + mid - 1) / mid;
        }
        if (sum <= threshold) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    // Example usage:
    int nums[] = {1, 2, 5, 9};
    int threshold = 6;
    int result = smallestDivisor(nums, 4, threshold);
    printf("Smallest Divisor: %d\n", result);
    return 0;
}