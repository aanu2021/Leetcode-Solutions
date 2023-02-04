class Solution {
public:
    
    bool Match(vector<int>&freq1,vector<int>&freq2){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        vector<int>freq_demand(26,0);
        vector<int>freq_curr(26,0);
        for(int i=0;i<m;i++){
            freq_demand[s1[i]-'a']++;
        }
        for(int i=0;i<n;i++){
            freq_curr[s2[i]-'a']++;
            if(i >= m){
                freq_curr[s2[i-m]-'a']--;
            }
            if(Match(freq_demand,freq_curr)){
                return true;
            }
        }
        return false;
    }
};