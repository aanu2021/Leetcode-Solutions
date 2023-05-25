//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    typedef long long ll;
  
    vector<string>answer;
    
    void func(string &input,int pos,string currExp,ll currVal,ll lastVal,int target){
        
        if(pos == input.length()){
            if(currVal == target) answer.push_back(currExp);
            return ;
        }
        
        ll value = 0LL;
        string part = "";
        
        for(int index=pos;index<input.length();index++){
            
            if(index != pos && input[pos] == '0') break;
            
            value = (value*10LL) + (input[index]-'0');
            part += input[index];
            
            if(pos==0){
                func(input,index+1,currExp+part,value,value,target);
            }
            else{
                func(input,index+1,currExp+"+"+part,currVal + value,value,target);
                func(input,index+1,currExp+"-"+part,currVal - value,-value,target);
                func(input,index+1,currExp+"*"+part,currVal - lastVal + (lastVal*value),lastVal*value,target);
            }
            
        }
        
    }
  
    vector<string> addOperators(string S, int target) {
        
        answer.clear();
        
        func(S,0,"",0LL,0LL,target);
        
        return answer;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends