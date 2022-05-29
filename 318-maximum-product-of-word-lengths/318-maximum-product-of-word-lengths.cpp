class Solution {
public:
    
    bool isIntersect(vector<int>&freq1,vector<int>&freq2){
        
        for(int i=0;i<26;i++){
            if(freq1[i]!=0 && freq2[i]!=0){
                return true;
            }
        }
        
        return false;
        
    }
    
    int maxProduct(vector<string>& words) {
        
        int n=words.size();
        
        int maxLen=0;
        
        for(int i=0;i<words.size();i++){
            
            vector<int>freq1(26,0);
            
            for(char ch:words[i]){
                freq1[ch-'a']++;
            }
            
            for(int j=i+1;j<words.size();j++){
                
                vector<int>freq2(26,0);
                
                for(char ch:words[j]){
                    freq2[ch-'a']++;
                }
                
                int len1=words[i].length();
                int len2=words[j].length();
                
                if(isIntersect(freq1,freq2)==false){
                    maxLen=max(maxLen,(len1*len2));
                }
                
            }
            
        }
        
        return maxLen;
        
    }
};