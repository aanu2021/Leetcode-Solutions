class Solution {
public:
    
    bool isPalindrome(string &s){
        int l = 0;
        int r = s.length();
        r--;
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    
    vector<vector<string>>ans;
    
    void func(string &s,int i,int n,vector<string>&solution){
        if(i == n){
            ans.push_back(solution);
            return;
        }
        string str = "";
        for(int j=i;j<n;j++){
            str += s[j];
            if(isPalindrome(str)){
                solution.push_back(str);
                func(s,j+1,n,solution);
                solution.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string>solution;
        func(s,0,n,solution);
        return ans;
    }
};