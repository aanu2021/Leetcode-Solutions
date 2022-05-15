class Solution {
public:
    
    bool isVowel(char ch){
        
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }else{
            return false;
        }
        
    }
    
    int maxVowels(string s, int k) {
        
        int n=s.length();
        
        int maxi=0;
        
        int cnt=0;
        
        for(int i=0;i<k;i++){
            
            if(isVowel(s[i])==true)
                cnt++;
            
        }
        
        maxi=cnt;
        
        for(int i=k;i<n;i++){
            
            if(isVowel(s[i])==true)
                cnt++;
            
            if(isVowel(s[i-k])==true){
                cnt--;
            }
            
            maxi=max(maxi,cnt);
            
        }
        
        return maxi;
        
    }
};