# include <iostream>
#include <string> 
using namespace std;
// This code calculates the sum of all subsequences of a given string of digits.



class Solution {
public:
    void chacha(string &s, int i, int sum, int &cnt) {
        if (i == s.size()) {
            cnt += sum;
            return;
        }

        // Include s[i]
        chacha(s, i + 1, sum + (s[i] - '0'), cnt);

        // Exclude s[i]
        chacha(s, i + 1, sum, cnt);
    }

    int subsequenceSum(string s) {
        int cnt = 0;
        chacha(s, 0, 0, cnt);
        return cnt;
    }
};



 int main() {
    Solution sol;
    string s;
    cout << "Enter a string of digits: ";
    cin >> s;
    int result = sol.subsequenceSum(s);
    cout << "The sum of all subsequences is: " << result << endl;
    return 0;
 }
