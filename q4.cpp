#include <iostream>
#include <cstring>
#include <cstdlib>
#include <queue>
using namespace std;

#define MAX_GROUPS 10000

// Manual sort function (simple bubble sort)
void sortString(char* str, char* sorted) {
    int len = strlen(str);
    strcpy(sorted, str);

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (sorted[i] > sorted[j]) {
                char temp = sorted[i];
                sorted[i] = sorted[j];
                sorted[j] = temp;
            }
        }
    }
}

// Compare two strings
bool isSame(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

// Function to group anagrams
int** anagrams(const char** A, int n1, int* len1, int** len2) {
    char sortedKeys[MAX_GROUPS][105];  // stores sorted versions
    queue<int> indexGroups[MAX_GROUPS]; // stores 1-based indices
    int groupCount = 0;

    for (int i = 0; i < n1; i++) {
        char sorted[105];
        sortString((char*)A[i], sorted);

        bool found = false;
        for (int j = 0; j < groupCount; j++) {
            if (isSame(sortedKeys[j], sorted)) {
                indexGroups[j].push(i + 1);  // 1-based index
                found = true;
                break;
            }
        }

        if (!found) {
            strcpy(sortedKeys[groupCount], sorted);
            indexGroups[groupCount].push(i + 1);
            groupCount++;
        }
    }

    // Allocate result
    *len1 = groupCount;
    int** result = (int**)malloc(groupCount * sizeof(int*));
    *len2 = (int*)malloc(groupCount * sizeof(int));

    for (int i = 0; i < groupCount; i++) {
        int size = indexGroups[i].size();
        result[i] = (int*)malloc(size * sizeof(int));
        (*len2)[i] = size;

        for (int j = 0; j < size; j++) {
            result[i][j] = indexGroups[i].front();
            indexGroups[i].pop();
        }
    }

    return result;
}
int main() {
    const char* A[] = {"cat", "dog", "god", "tca"};
    int n1 = 4;

    int len1;
    int* len2;

    int** groups = anagrams(A, n1, &len1, &len2);

    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2[i]; j++) {
            cout << groups[i][j] << " ";
        }
        cout << endl;
    }

    // Free memory
    for (int i = 0; i < len1; i++) {
        free(groups[i]);
    }
    free(groups);
    free(len2);

    return 0;
}

