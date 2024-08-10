#include<iostream>
#include <unordered_map>
#include<fstream>
#include <cmath>
#include<vector>
using namespace std;
ifstream fileRead("D:/Git Hub Repos/Meta hacker cup 2023 - Qualification Round/Problem 2/cheeseburger_corollary_2_validation_input.txt");
ofstream file("D:/Git Hub Repos/Meta hacker cup 2023 - Qualification Round/Problem 2/output.txt");
void calculate(int test_case){
    long long int A, B, C, cash;
    // cin >> A >> B >> C;
    fileRead >> A >> B >> C;
    long long k, r;
 
    cout << "Case #" << test_case << ": ";
    file << "Case #" << test_case << ": ";
    if (A <= B/2)
    {
        k = C/A;
        cout << k << '\n';
        file << k << '\n';
        return;
    }
    else if(B <= A/2 || B == A){
        k = (C/B) * 2 -1;
        // k = (C/B) * 2 ;
        cout << k << '\n';
        file << k << '\n';
        return;
    }

    else
    {
        k = 0;
        while (C > 0)
        {
            if (C < A && C < B)
            {
                cout << k << '\n';
                file << k << '\n';
                return;
            }
            r = (C % B);
            k += (C/B)*2 -1;
            // k += (C/B)*2;
            C = r;
            if (C > 0)
            {
                k += (C/A);
                C = C/A;
            }
        }
        cout << k << '\n';
        file << k << '\n';
        
    }
  
}

int main(){ 

    int test_cases;
    // cin >> test_cases;
    fileRead >> test_cases;


    for(int tc = 1; tc <=test_cases; tc++){ 
        calculate(tc);
        cout << flush;
    }
    file.close();
    return 0;

}



