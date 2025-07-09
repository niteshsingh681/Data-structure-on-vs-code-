# include <iostream>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
   set<vector<int>>st;
   void helper(vector<int>& arr,vector<vector<int>>&ans,vector<int>&combin,int tar,int ind){
    //base case 
    if(ind==arr.size() || tar<0) return ;
    if(tar==0) {
        if(st.find(combin)==st.end()){
        ans.push_back(combin); st.insert(combin);}
        return ;
        }

     combin.push_back(arr[ind]);
    //include singly
    helper(arr,ans,combin,tar-arr[ind],ind);
    //exclude
    combin.pop_back();
    helper(arr,ans,combin,tar,ind+1);
     // multiple inclusion
    
   }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>>ans;vector<int>combin;
        helper(arr,ans,combin,target,0);
         return ans;
    }
};
 int main() {
    Solution sol;
    vector<int> arr;
    int n, target;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> result = sol.combinationSum(arr, target);
    
    cout << "Combinations that sum to " << target << ":\n";
    for (const auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}