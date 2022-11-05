class Solution {
public:
    
    unordered_set<string>S;
    
    vector<string>ans;
    
    void func(string &s,int i,int n,vector<string>&solution){
        
        if(i==n){
            
            string str = "";
            
            for(int j=0;j<solution.size();j++){
                str+=solution[j];
                if(j+1!=solution.size()){
                    str+=" ";
                }
            }
            
            ans.push_back(str);
            
            return;
            
        }
        
        string str = "";
        
        for(int j=i;j<n;j++){
            
            str += s[j];
            
            if(S.find(str)!=S.end()){
                
                solution.push_back(str);
                
                func(s,j+1,n,solution);
                
                solution.pop_back();
                
            }
            
        }
        
    }
    
 vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(string &str:wordDict){
            S.insert(str);
        }
        
        int n = s.length();
        
        vector<string>solution;
        
        func(s,0,n,solution);
        
        return ans;
        
    }
};