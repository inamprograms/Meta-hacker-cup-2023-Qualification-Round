#include<iostream>
#include <unordered_map>
#include<fstream>
#include<vector>
using namespace std;
ifstream fileRead("D:/Git Hub Repos/Meta hacker cup 2023 - Qualification Round/Problem 3/dim_sum_delivery_input.txt");
ofstream file("D:/Git Hub Repos/Meta hacker cup 2023 - Qualification Round/Problem 3/output.txt");
void calculate(int test_case){
    long long int R, C, A, B;
    // cin >> R >> C >> A >> B;
    fileRead >> R >> C >> A >> B;
    long long int AstateR = 1;
    long long int BstateC = 1;

    long long int AstateC = 1;
    long long int BstateR = 1;
    cout << "Case #" << test_case << ": ";
    file << "Case #" << test_case << ": ";
    while (AstateR <= R && BstateC <= C)
    {   
        if (AstateR <= R && BstateC <= C)
        {
            int moveRequiredToCompleteA = R- AstateR;
            if(moveRequiredToCompleteA < A)
            {
                AstateR += moveRequiredToCompleteA;   
            }
            else
            {
                AstateR += A; 
            }
            BstateR = AstateR;
            if(AstateR == R && AstateC == C){
                cout << "YES" << '\n';
                file << "YES" << '\n';
                return; 
            }
            // BstateC = AstateR;

            long long int moveRequiredToCompleteB = C- BstateC;
            if (moveRequiredToCompleteB < B)
            {
                BstateC += moveRequiredToCompleteB;   
            }
            else
            {
                BstateC += B;
            }
            AstateC = BstateC;
        
            if(BstateC == C && BstateR == R){
                cout << "NO" << '\n';
                file << "NO" << '\n'; 
                return;
            } 
            // AstateR = BstateC;
        }
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

