#include <iostream>
#include <unordered_map>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
ifstream fileRead("D:/Git Hub Repos/Meta hacker cup/2023/Qualification Round/Problem 4/two_apples_a_day_input.txt");
ofstream file("D:/Git Hub Repos/Meta hacker cup/2023/Qualification Round/Problem 4/output.txt");
void calculate(int test_case)
{
    long long int N, no_of_apples;
    // cin >> N;
    fileRead >> N;
   
    no_of_apples = 2 * N - 1;

    vector<long long int> apples(no_of_apples);

    for (long long int i = 0; i < apples.size(); i++)
    {
        // cin >> apples[i];
        fileRead >> apples[i];
    }
    cout << "Case #" << test_case << ": ";
    file << "Case #" << test_case << ": ";

    sort(apples.begin(), apples.end());

    long long left = 0, right = apples.size() - 1, sum = 0, predict = -1, count = 0;
    if (apples.size() == 1)
    {
        cout << apples[left] << '\n';
        file << apples[left] << '\n';
        return;
    }
    sum = apples[left] + apples[right];
    while (left < right)
    {
        if (count > 1)
        {
            cout << -1 << '\n';
            file << -1 << '\n';
            return;
        }
        left++;
        right--;
        if (left >= right)
        {
            break;
        }
        
        if (sum != (apples[left] + apples[right]))
        {
            predict = apples[left - 1];
            right++;
            count++;
            sum = apples[left] + apples[right];
        }
    }
    int res = sum - (predict == -1 ? apples[left]: predict) ;
    cout << res << '\n';
    file << res << '\n';
}

int main()
{

    int test_cases;
    // cin >> test_cases;
    fileRead >> test_cases;

    for (int tc = 1; tc <= test_cases; tc++)
    {
        calculate(tc);
        cout << flush;
    }
    file.close();
    return 0;
}
