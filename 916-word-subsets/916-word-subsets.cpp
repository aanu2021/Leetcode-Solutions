class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string>result;
        
        vector<int>freq(26,0);
        
        for(int i=0;i<words2.size();++i){
            
            vector<int>currfreq(26,0);
            
            for(char ch:words2[i]){
                
                currfreq[ch-'a']++;
                
            }
            
            for(int j=0;j<26;j++){
                
                freq[j]=max(freq[j],currfreq[j]);
                
            }
            
        }
        
        for(int i=0;i<words1.size();++i){
            
            vector<int>currfreq(26,0);
            
            for(char ch:words1[i]){
                
                currfreq[ch-'a']++;
                
            }
            
            bool flag=true;
            
            for(int j=0;j<26;j++){
                
                if(currfreq[j]<freq[j]){
                    flag=false;
                    break;
                }
                
            }
            
            if(flag){
                result.push_back(words1[i]);
            }
            
        }
        
        return result;
        
    }
};