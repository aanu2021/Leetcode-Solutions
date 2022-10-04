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
    
    void dfs(vector<string>&arr,int idx,int n,string str){
        
        if(isUnique(str)){
            
            maxLen = max(maxLen,(int)str.length());
            
        }
        
        else{
            
            return;
            
        }
        
        if(idx == n){
            
            return;
            
        }
        
        dfs(arr,idx+1,n,str);
        
        dfs(arr,idx+1,n,str+arr[idx]);
        
    }
    
    int maxLength(vector<string>& arr) {
        
        int n = arr.size();
        
        dfs(arr,0,n,"");
        
        return maxLen;
        
    }
};