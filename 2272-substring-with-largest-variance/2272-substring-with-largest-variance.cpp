class Solution {
public:
    
    int find_variance(string &s,char ch1,char ch2){
        
        int cnt=0,currsum=0;
        
        int maxsum=0;
        
        int n=s.length();
        
        for(int i=0;i<n;++i){
            
            if(s[i]==ch1){
                currsum++;
            }
            
            else if(s[i]==ch2){
                currsum--;
                cnt++;
            }
            
            
            if(cnt!=0){
                
                maxsum=max(maxsum,currsum);
                
            }
            
            if(currsum<0){
                
                currsum=0;
                cnt=0;
                
            }
            
        }
        
        return maxsum;
        
    }
    
    int largestVariance(string s) {
        
        int n=s.length();
        
        int max_variance=0;
        
        vector<int>freq(26,0);
        
        for(int i=0;i<n;++i){
            
            freq[s[i]-'a']++;
            
        }
        
        for(char ch1='a';ch1<='z';ch1++){
            
            for(char ch2='a';ch2<='z';ch2++){
                
                if(ch1==ch2 || freq[ch1-'a']==0 || freq[ch2-'a']==0){

                        continue;

                }
                
                int curr_variance=find_variance(s,ch1,ch2);
                
                max_variance=max(max_variance,curr_variance);
                
            }
            
        }
        
        
        reverse(s.begin(),s.end());
        
        for(char ch1='a';ch1<='z';ch1++){
            
            for(char ch2='a';ch2<='z';ch2++){
                
                if(ch1==ch2 || freq[ch1-'a']==0 || freq[ch2-'a']==0){

                        continue;

                }
                
                int curr_variance=find_variance(s,ch1,ch2);
                
                max_variance=max(max_variance,curr_variance);
                
            }
            
        }
        
        return max_variance;
        
    }
};