#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int largestRectangleArea(int* heights, int n) {
    stack<int> st;
    int maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currHeight = (i == n) ? 0 : heights[i];

        while (!st.empty() && currHeight < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();
            int width;

            if (st.empty()) {
                width = i;
            } else {
                width = i - st.top() - 1;
            }

            int area = height * width;
            if (area > maxArea) maxArea = area;
        }

        st.push(i);
    }

    return maxArea;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0) return 0;
    int cols = matrixColSize[0];
    int* heights = new int[cols];
    memset(heights, 0, cols * sizeof(int));

    int maxRect = 0;

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }

        int area = largestRectangleArea(heights, cols);
        if (area > maxRect) maxRect = area;
    }

    delete[] heights;
    return maxRect;
}

int main() {
    char* mat[] = {
        (char*)"1010",
        (char*)"1011",
        (char*)"1111"
    };
    int rows = 3;
    int cols[] = {4, 4, 4};

    int maxArea = maximalRectangle(mat, rows, cols);
    cout << "Max Rectangle Area: " << maxArea << endl;

    return 0;
}
