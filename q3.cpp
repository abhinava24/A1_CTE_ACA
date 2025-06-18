#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> twoSumStack(vector<int>& A, int B) {
    stack<pair<int, int>> s;
    vector<int> result;

    for (int i = 0; i < A.size(); i++) {
        while (!s.empty() && s.top().first + A[i] == B) {
            result.push_back(s.top().second + 1);  // Store 1-based index
            result.push_back(i + 1);
            return result;
        }
        s.push({A[i], i});
    }

    return result;  // No valid pair found
}