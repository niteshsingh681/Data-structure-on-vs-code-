# include <iostream>
# include <string>
# include <vector>
using namespace std ;
class Solution {
private: 
       void generate(int open,int close,vector<string> &ans,string &s){
        if(open==0&&close ==0) {
            ans.push_back(s);
            return;
        }
        //pushing open bracket
        if(open>0){
            s.push_back('(');
            generate(open-1,close,ans,s);
            s.pop_back();
        }
        if(close>0  && close >open){
            s.push_back(')');
            generate(open,close-1,ans,s);
            s.pop_back();
        }
    }
public:
   
    vector<string> generateParenthesis(int n) {
        vector<string> ans;string s="";
        generate(n,n,ans,s);
        return ans;
    }
};
 int  main() {
    Solution sol;
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;
    vector<string> result = sol.generateParenthesis(n);
    cout << "Generated Parentheses Combinations:" << endl;
    for ( auto str:result){
        cout << str << endl;
    }
    return 0;
}