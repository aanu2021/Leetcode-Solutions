class Solution {
public:
    
    bool isUnique(string &str){
        
        vector<int>freq(26,0);
        
        for(char ch:str){
            freq[ch-'a']++;
        }
        
        for(int i=0;i<26;i++){
            if(freq[i]>1){
                return false;
            }
        }
        
        return true;
        
    }
    
    int maxLen = 0;
    
    void dfs(vector<string>&arr,int i,int n,string str){
        
        if(isUnique(str)==false){
            
            return;
            
        }
        
        maxLen = max(maxLen,(int)str.length());
        
        if(i>=n){
            
            return;
            
        }
        
        dfs(arr,i+1,n,str);
        
        dfs(arr,i+1,n,str+arr[i]);
        
    }
    
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        
        dfs(arr,0,n,"");
        
        return maxLen;
        
    }
};