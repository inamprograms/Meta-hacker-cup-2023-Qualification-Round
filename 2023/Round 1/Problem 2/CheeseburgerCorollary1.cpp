#include<iostream>
#include <unordered_map>
#include<fstream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
ifstream fileRead("D:/Git Hub Repos/Meta Hacker Cup 2023 - Round 1/Problem 2/sum_41_chapter_1_validation_input.txt");
ofstream file("D:/Git Hub Repos/Meta Hacker Cup 2023 - Round 1/Problem 2/output.txt");
void calculate(int test_case){
    int P;
    fileRead >> P;

    if (P < 4) {
        cout << "Case #" << test_case << ": " << -1 << '\n';
        file << "Case #" << test_case << ": " << -1 << '\n';
        return;
    }
    
    vector<int> factors;
    int sumOfFactors = 0; 
    while (P > 1) {
        bool foundFactor = false;
        for (int i = 2; i <= P; ++i) {
            if (P % i == 0) {
                factors.push_back(i);
                sumOfFactors += i; 
                P /= i;
                foundFactor = true;
                break;
            }
        }
        if (!foundFactor) {
           
            factors.push_back(P);
            sumOfFactors += P;
            break;
        }
    }

    if (sumOfFactors != 41) {
        cout << "Case #" << test_case << ": " << -1 << '\n';
        file << "Case #" << test_case << ": " << -1 << '\n';
        return;
    }

    // if (factors.size() > 100) {
    //     cout << "Case #" << test_case << ": " << -1;
    //     file << "Case #" << test_case << ": " << -1;
    // }

    vector<int> array;
    for (int factor : factors) {
        array.push_back(factor);
    }
    cout << "Case #" << test_case << ": " << array.size();
    file << "Case #" << test_case << ": " << array.size();
    for (int f = 0; f < array.size(); f++) {
        // array.push_back(factor);
        cout << " " << array[f];
        file << " " << array[f];
    }
    cout << '\n';
    file << '\n';
}

int main(){ 
   
    int test_cases;
  
    fileRead >> test_cases;
    for(int tc = 1; tc <=test_cases; tc++){ 
        calculate(tc);
        cout << flush;
    }
    file.close();
    return 0;

}

