class Solution {
public:
    int rearrangeCharacters(string s1, string s2) {
        
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        
        for(int i=0;i<s1.length();i++){
            freq1[s1[i]-'a']++;
        }
        
        for(int i=0;i<s2.length();i++){
            freq2[s2[i]-'a']++;
        }
        
        int cnt=INT_MAX;
        
        for(int i=0;i<26;i++){
            
            if(freq2[i]==0){
                continue;
            }
            
            int currval=(freq1[i]/freq2[i]);
            
            cnt=min(cnt,currval);
            
        }
        
        return cnt;
        
    }
};