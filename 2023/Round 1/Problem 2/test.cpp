#include <iostream>
#include <vector>

using namespace std;

vector<int> result;
int targetSum;

// Function to find an array with the given sum and product
bool findArray(long long P, int currentSum, long long currentValue) {
    if (currentSum == targetSum) {
        if (P == 1) {
            return true;
        }
        return false;
    }

    for (long long factor = 2; factor <= P; ++factor) {
        if (P % factor == 0) {
            result.push_back(factor);
            if (findArray(P / factor, currentSum + factor, currentValue + 1)) {
                return true;
            }
            result.pop_back();
        }
    }

    return false;
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; ++i) {
        long long P;
        cin >> P;

        targetSum = 41; // Set the target sum
        result.clear(); // Clear any previous results

        cout << "Case #" << i << ": ";
        if (findArray(P, 0, 0)) {
            cout << result.size() << " ";
            for (int j = 0; j < result.size(); ++j) {
                cout << result[j] << " ";
            }
            cout << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}
