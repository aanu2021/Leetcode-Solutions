class Solution {
public:
    
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        else{
            return false;
        }
    }
    
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxCnt = 0;
        int currCnt = 0;
        for(int i=0;i<n;i++){
            currCnt += isVowel(s[i]);
            if(i >= k){
                currCnt -= isVowel(s[i-k]);
            }
            maxCnt = max(maxCnt,currCnt);
        }
        return maxCnt;
    }
};