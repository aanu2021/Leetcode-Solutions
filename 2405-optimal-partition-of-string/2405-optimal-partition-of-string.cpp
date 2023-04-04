class Solution {
public:
    int partitionString(string s) {
        int n = s.length();
        unordered_map<int,int>freq;
        int ans = 1;
        for(int i=0;i<n;i++){
            if(freq[s[i]]==0){
                freq[s[i]]++;
                continue;
            }
            freq.clear();
            ans++;
            freq[s[i]]++;
        }
        return ans;
    }
};