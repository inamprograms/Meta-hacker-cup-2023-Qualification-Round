// #include <iostream>
// #include<fstream>
// using namespace std;
// ofstream file("D:/Git Hub Repos/Meta hacker cup/2023/Qualification Round/Problem 2/output.txt");
// // Function to find the largest K-decker cheeseburger possible
// void findLargestKDecker(int i) {

//     unsigned long long A, B, C;
//     cin >> A >> B >> C;
//     // long long int A, B, C;
//     // cin >> A >> B >> C;
//     // cin.ignore(); // Clear the input buffer


//     // Calculate the maximum number of single and double cheeseburgers we can buy within the budget C
//     unsigned long long maxSingleBurgers = C / A;
//     unsigned long long maxDoubleBurgers = C / B;

//     unsigned long long maxK = 0; // Initialize the maximum K
    
//     unsigned long long singleK = 0;
//     unsigned long long doubleK = 0;
//     cout << "Case #" << i << ": ";
//     file << "Case #" << i << ": ";
//     if(A == 1 && B == 1){
//         doubleK = 2*(B * C);
//         cout << doubleK-1 << '\n';
//         file << doubleK-1 << '\n';
//         return;
//     }
//     else if(A == 1){
//         singleK = A * C;
//         cout << singleK << '\n';
//         file << singleK << '\n';
//         return;
//     }
//     else if(B == 1){
//         doubleK = 2*(B * C);
//         cout << doubleK-1 << '\n';
//         file << doubleK-1 << '\n';
//         return;

//     }
//     // Loop through possible numbers of single and double cheeseburgers
//     for (unsigned long long numSingle = 0; numSingle <= maxSingleBurgers; numSingle++) {
//         for (unsigned long long numDouble = 0; numDouble <= maxDoubleBurgers; numDouble++) {
//             unsigned long long totalBuns = 2 * (numSingle + numDouble); // Total number of buns
//             unsigned long long totalPatties = numSingle + 2 * numDouble; // Total number of patties
//             unsigned long long totalCheese = numSingle + 2 * numDouble; // Total number of cheese slices

//             // Calculate the maximum K for the current combination of burgers
//             unsigned long long maxPossibleK = totalBuns / 2;
//             if (totalPatties < maxPossibleK) {
//                 maxPossibleK = totalPatties;
//             }
//             if (totalCheese < maxPossibleK) {
//                 maxPossibleK = totalCheese;
//             }

//             // Update maxK if the current combination allows for a larger K
//             maxK = max(maxK, maxPossibleK);
//         }
//     }

//     // for (unsigned long long numSingle = 0; numSingle <= maxSingleBurgers; numSingle++) {
//     //     // Calculate the remaining budget after buying single cheeseburgers
//     //     unsigned long long remainingBudget = C - (numSingle * A);

//     //     // Calculate the maximum number of double cheeseburgers that can be bought with the remaining budget
//     //     unsigned long long numDouble = remainingBudget / B;

//     //     // Calculate the total number of cheeseburgers (single and double)
//     //     unsigned long long totalCheeseburgers = numSingle + numDouble;

//     //     // Calculate the maximum K for the current combination of cheeseburgers
//     //     unsigned long long maxPossibleK = numSingle + 2 * numDouble;

//     //     // Update maxK if the current combination allows for a larger K
//     //     maxK = max(maxK, maxPossibleK);
//     // }
//     cout << maxK<< '\n';
//     file << maxK<< '\n';
// }

// int main() {
//     int T;
//     cin >> T; // Number of test cases

//     // cin.ignore(); // Clear the newline character

//     for (int i = 1; i <= T; i++) {
//         findLargestKDecker(i);
//     }

//     return 0;
// }



#include <iostream>
using namespace std;

bool isPossible(long long A, long long B, long long C, long long K) {
    long long cost = (K / 2) * A + (K / 2) * 2 * B; // Calculate the cost for K-decker cheeseburgers
    if (K % 2 == 1) {
        cost += A; // Add the cost of a single cheeseburger if K is odd
    }
    return cost <= C;
}

long long largestPossibleK(long long A, long long B, long long C) {
    long long low = 1, high = 2e16; // Initialize the search range
    long long result = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (isPossible(A, B, C, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int T;
    cin >> T; // Number of test cases

    for (int i = 1; i <= T; i++) {
        long long A, B, C;
        cin >> A >> B >> C;
        
        long long result = largestPossibleK(A, B, C);

        cout << "Case #" << i << ": " << result << endl;
    }

    return 0;
}

