#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> relation;
int colSize;

bool isUnique(int subset) {
    unordered_map<string, int> m;
    for (const vector<string>& row : relation) {
        string key = "";
        for (int col = 0; col < colSize; ++col) {
            if (subset & (1 << col)) {
                key += row[col] + ",";
            }
        }
        if (m.find(key) != m.end()) {
            return false;
        }
        m[key] = 1;
    }
    return true;
}

bool isMinimal(int subset, const vector<int>& candidateKeys) {
    for (int key : candidateKeys) {
        if ((subset & key) == key) {
            return false;
        }
    }
    return true;
}

int solution(vector<vector<string>> relationInput) {
    relation = relationInput;
    colSize = relation[0].size();
    vector<int> candidateKeys;

    int totalComb = 1 << colSize;
    for (int subset = 1; subset < totalComb; subset++) {
        if (isUnique(subset) && isMinimal(subset, candidateKeys)) {
            candidateKeys.push_back(subset);
        }
    }
    return candidateKeys.size();
}