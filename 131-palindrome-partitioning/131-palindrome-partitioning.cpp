class Solution {
public:
    
    vector<vector<string>>result;
    
    bool isPalindrome(string s){
        
        int l=0,r=s.length()-1;
        
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        
        return true;
        
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
        
        result.clear();
        
        int n=s.length();
        
        vector<string>vec;
        
        func(s,0,n,vec);
        
        return result;
        
    }
};