#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;

    // Map from element in nums2 to its next greater
    int nextGreater[10001];
    for (int i = 0; i < 10001; i++) nextGreater[i] = -1;

    int stack[1000];
    int top = -1;

    for (int i = 0; i < nums2Size; i++) {
        while (top >= 0 && nums2[i] > stack[top]) {
            nextGreater[stack[top]] = nums2[i];
            top--;
        }
        stack[++top] = nums2[i];
    }

    for (int i = 0; i < nums1Size; i++) {
        ans[i] = nextGreater[nums1[i]];
    }

    return ans;
}