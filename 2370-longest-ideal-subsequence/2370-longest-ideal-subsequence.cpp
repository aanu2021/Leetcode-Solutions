class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int>freq(26, -1);
        for(int i=0;i<n;i++){
            char ch = s[i];
            int currValue = (int)(ch-'a');
            int prevMax = 0;
            for(int j=0;j<26;j++){
                if(freq[j] == -1) continue;
                if(abs(j - currValue) > k) continue;
                prevMax = max(prevMax, freq[j]);
            }
            freq[ch-'a'] = 1 + prevMax;
        }
        return *max_element(freq.begin(),freq.end());
    }
};

// a c f g b d
// 0 1 2 3 4 5
    
// 1 2 1 2 3 4
    