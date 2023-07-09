class Solution {
public:
    
    int findVariance(string &s,int n,char ch1,char ch2){
        int maxSum = 0;
        int currSum = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]==ch1){
                currSum++;
            }
            if(s[i]==ch2){
                cnt++;
                currSum--;
            }
            if(cnt > 0){
                maxSum = max(maxSum, currSum);
            }
            if(currSum < 0){
                cnt = 0;
                currSum = 0;
            }
        }
        return maxSum;
    }
    
    int largestVariance(string s) {
        
        int n = s.length();
        
        vector<int>freq(26,0);
        for(char ch:s){
            freq[ch-'a']++;
        }
        
        int maxVariance = 0;
        
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2 || freq[ch1-'a']==0 || freq[ch2-'a']==0) continue;
                maxVariance = max(maxVariance, findVariance(s,n,ch1,ch2));
            }
        }
        
        reverse(s.begin(),s.end());
        
        for(char ch1='a';ch1<='z';ch1++){
            for(char ch2='a';ch2<='z';ch2++){
                if(ch1==ch2 || freq[ch1-'a']==0 || freq[ch2-'a']==0) continue;
                maxVariance = max(maxVariance, findVariance(s,n,ch1,ch2));
            }
        }
        
        return maxVariance;
        
    }
};