#include<iostream>
#include <unordered_map>
#include<fstream>
#include<vector>
using namespace std;
ifstream fileRead("D:/Git Hub Repos/Meta hacker cup/2023/Qualification Round/Problem 2/cheeseburger_corollary_2_validation_input.txt");
ofstream file("D:/Git Hub Repos/Meta hacker cup/2023/Qualification Round/Problem 2/output.txt");
void calculate(int test_case){
    long long int A, B, C, cash;
    // cin >> A >> B >> C;
    fileRead >> A >> B >> C;
    cash = C;
    long long int singleK = 0;
    long long int doubleK = 0;
    cout << "Case #" << test_case << ": ";
    file << "Case #" << test_case << ": ";
    if(A == 1 && B == 1){
        doubleK = 2*(B * C);
        cout << doubleK-1 << '\n';
        file << doubleK-1 << '\n';
        return;
    }
    else if(A == 1){
        singleK = A * C;
        cout << singleK << '\n';
        file << singleK << '\n';
        return;
    }
    else if(B == 1){
        doubleK = 2*(B * C);
        cout << doubleK-1 << '\n';
        file << doubleK-1 << '\n';
        return;

    }
    while (1)
    {
        if(A < B && (cash >= A && cash > B)){
           
            singleK += 1;
            doubleK += 2;
            cash -= A;
            cash -= B;
            if (cash <= A && cash <= B)
            {
                cout << singleK+doubleK << '\n';
                file << singleK+doubleK << '\n';
                break;
            }
            
            
        }
        else if(cash >= C && A < B && (cash >= A && cash < B)){
            singleK = 1;
            cash -= A;
            if (cash <= A && cash <= B)
            {
                cout << singleK << '\n';
                file << singleK << '\n';
                break;
            }

        }
        else if( A < B && (cash <= A && cash <= B)){
            cout << 0 << '\n';
            file << 0 << '\n';
            break;
        }
    }
    
    // cout << max_decker <<'\n';
    // file << max_decker <<'\n';
    // int bunsWeHave, pAndc;
    // bunsWeHave = 2 * (S + D);
    // pAndc = (S * 1) + (D * 2);

    
    // if(bunsWeHave >= K+1){
    //     if(pAndc >= K){
    //         cout << "YES" << '\n';
    //         file << "YES" << '\n';
    //         return;
    //     }
    // }
    // cout << "NO" << '\n';
    // file << "NO" << '\n';  
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

