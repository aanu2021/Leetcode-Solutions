class Solution {
public:
    
    bool isUnique(string &str){
        
        int n=str.length();
        
        vector<int>freq(26,0);
        
        for(int i=0;i<n;++i){
            freq[str[i]-'a']++;
        }
        
        for(int i=0;i<26;++i){
            if(freq[i]>1){
                return false;
            }
        }
        
        return true;
        
    }
    
    int maxLen=0;
    
    void dfs(string curr,int idx,vector<string>&arr){
        
        if(isUnique(curr)==false){
            return;
        }
        
        maxLen=max(maxLen,(int)curr.length());
        
        if(idx==arr.size()){
            
            return;
            
        }
        
        dfs(curr,idx+1,arr);
        
        dfs(curr+arr[idx],idx+1,arr);
        
    }
    
    int maxLength(vector<string>& arr) {
        
        dfs("",0,arr);
        
        return maxLen;
        
    }
};