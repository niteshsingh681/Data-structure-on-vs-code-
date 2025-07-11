# include <iostream>
# include <vector>  
# include <string>
using namespace std;
class Solution {
public:
    void helper(vector<int>& arr, vector<vector<int>>& ans, vector<int>& temp, int k, int n, int i) {
        // base cases
        if (k == 0 && n == 0) {
            ans.push_back(temp);
            return;
        }
        if (k == 0 || n < 0 || i == arr.size()) return;

        // include arr[i]
        temp.push_back(arr[i]);
        helper(arr, ans, temp, k - 1, n - arr[i], i + 1);
        temp.pop_back();

        // exclude arr[i]
        helper(arr, ans, temp, k, n, i + 1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        vector<int> temp;
        helper(arr, ans, temp, k, n, 0);
        return ans;
    }
};
 
int main() {
    Solution sol;
    int k, n;
    cout << "Enter the number of elements in combination (k): ";
    cin >> k;
    cout << "Enter the target sum (n): ";
    cin >> n;

    vector<vector<int>> result = sol.combinationSum3(k, n);

    cout << "Generated Combinations:\n";
    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}