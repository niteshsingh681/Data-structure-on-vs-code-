#include <iostream>
#include <vector>
# include <string>
using namespace std;
class Solution {
      private :
          void chacha(vector<string> &ans,string s,int i){
              if(i==s.length()){
                  ans.push_back(s);
                  return;
              }
              if(s[i]!='?') {
                  chacha(ans,s,i+1);
              }
              else{
                  s[i]='0';chacha(ans,s,i+1);
                  s[i]='1';chacha(ans,s,i+1);
                  
                  // s[i] = '?'; 
              }
          }
      public:
        vector<string> generate_binary_string(string s) {
          vector<string> ans;
          chacha(ans,s,0);
          return ans;
            
        }
    };
    int main() {
        Solution sol;
        string s;
        cout << "Enter the binary string with wildcards (use '?' for wildcards): ";
        cin >> s;
        
        vector<string> result = sol.generate_binary_string(s);
        
        cout << "Generated Binary Strings:\n";
        for (const auto& str : result) {
            cout << str << endl;
        }
        
        return 0;
    }