#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
using namespace std;
ifstream file("D:/Git Hub Repos/Meta hacker cup/2023/Qualification Round/Problem 1/cheeseburger_corollary_1_input.txt");
int main() {
    
    // file.open("", ios::in); 
    // if (file.is_open()) { 
        string line;
    
        while (getline(file, line)) { 
            istringstream ss(line);
            string digit;
            while (ss >> digit)
            {
                int myint1 = stoi(digit);
                cout << myint1 << endl;
            }
        }
        file.close(); 
    // }
}
