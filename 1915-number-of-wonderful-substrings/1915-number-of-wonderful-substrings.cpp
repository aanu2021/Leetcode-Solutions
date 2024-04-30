class Solution {
public:
    
    typedef long long ll;
    
    long long wonderfulSubstrings(string word) {
        int n = word.length();
        unordered_map<int,int>freqMap;
        freqMap[0] = 1;
        ll answer = 0LL;
        int mask = 0;
        for(int i=0;i<n;i++){
            mask ^= (1<<(word[i]-'a'));
            answer += (ll)freqMap[mask];
            for(int j=0;j<10;j++){
                int nMask = mask^(1<<j);
                answer += (ll)freqMap[nMask];
            }
            freqMap[mask]++;
        }
        return answer;
    }
};