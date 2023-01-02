class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.length();
        int lower = 0,upper = 0;
        for(int i=1;i<n;i++){
            if(word[i]>='a' && word[i]<='z') lower++;
            else upper++;
        }
        if(word[0]>='a' && word[0]<='z'){
            if(lower==n-1) return true;
            else return false;
        }
        else{
            if(lower==n-1 || upper==n-1) return true;
            else return false;
        }
    }
};