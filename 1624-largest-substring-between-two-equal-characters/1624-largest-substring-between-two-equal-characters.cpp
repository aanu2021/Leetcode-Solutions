class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.length();
        int maxLen = -1;
        vector<int>lastIdx(26,-1);
        for(int i=0;i<n;i++){
            int c = (int)(s[i]-'a');
            if(lastIdx[c] != -1){
                maxLen = max(maxLen, i - lastIdx[c] - 1);
            }
            else{
                lastIdx[c] = i;
            }
        }
        return maxLen;
    }
};