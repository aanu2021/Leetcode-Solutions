class Solution {
public:
    
    vector<vector<string>>result;
    
    bool isPalindrome(string s){
        
        string rev=s;
        
        reverse(rev.begin(),rev.end());
        
        return s==rev;
        
    }
    
    void func(string s,int i,int n,vector<string>&vec){
        
        if(i>=n){
            result.push_back(vec);
            return;
        }
        
        for(int j=i;j<n;j++){
            
            string sub=s.substr(i,j-i+1);
            
            if(isPalindrome(sub)==true){
                
                vec.push_back(sub);
                
                func(s,j+1,n,vec);
                
                vec.pop_back();
                
            }
            
        }
        
    }
    
    vector<vector<string>> partition(string s) {
        
        int n=s.length();
        
        vector<string>vec;
        
        func(s,0,n,vec);
        
        return result;
        
    }
};