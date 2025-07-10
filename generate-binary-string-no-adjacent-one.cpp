#include <iostream> 
#include <vector>
using namespace std;    
class Solution {
  private :
     void chacha(vector<string> &ans,int i,string temp){
         if(i==1) {
             ans.push_back(temp);
             return ;
         }
         if(temp.back()=='0'){
             temp.push_back('0');chacha(ans,i-1,temp);
             temp.pop_back();
             temp.push_back('1');chacha(ans,i-1,temp);
             temp.pop_back();
         }
         else {
             temp.push_back('0');chacha(ans,i-1,temp);temp.pop_back();
         }
     }
  public:
    vector<string> generateBinaryStrings(int num) {
       vector<string> ans;string zero="0";
       chacha(ans,num,zero);
       string one="1";
       chacha(ans,num,one);
       return ans;
       
    }
};
int main(){
    Solution sol;
    int n;
    cout << "Enter the length of binary strings: ";
    cin >> n;
    
    vector<string> result = sol.generateBinaryStrings(n);
    
    cout << "Generated Binary Strings:\n";
    for (const auto& str : result) {
        cout << str << endl;
    }
    
    return 0;
}