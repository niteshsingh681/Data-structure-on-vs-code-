# include <iostream>
# include <vector>
# include <string>
using namespace std;
class Solution {
  private :
     void generateCombinations(vector<string> &ans, string temp, int index, const string &digits, const vector<string> &mapping) {
         if (index == digits.size()) {
             ans.push_back(temp);
             return;
         }
         int digit = digits[index] - '0';
         for (char ch : mapping[digit]) {
             temp.push_back(ch);
             generateCombinations(ans, temp, index + 1, digits, mapping);
             temp.pop_back();
         }
     }
  public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;
        
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        generateCombinations(ans, "", 0, digits, mapping);
        return ans;
    }
};
int main() {
    Solution sol;
    string digits;
    cout << "Enter the phone number digits: ";
    cin >> digits;

    vector<string> result = sol.letterCombinations(digits);

    cout << "Generated Combinations:\n";
    for (const auto& str : result) {
        cout << str << endl;
    }

    return 0;
}
