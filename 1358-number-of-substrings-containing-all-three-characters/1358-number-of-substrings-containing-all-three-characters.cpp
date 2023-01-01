class Solution {
public:
    
    typedef long long ll;
    
    int numberOfSubstrings(string s) {
        
        ll n = s.length();
        
        ll total_num_sub = (ll)(n*(n+1)/2);
        
        ll total_bad_sub = 0;
        
        int l = 0 ,r = 0 ,cnt = 0;
        vector<int>freq(26,0);
        
        while(r<n){
            
            if(freq[s[r]-'a']==0) cnt++;
            freq[s[r]-'a']++;
            
            while(l<=r && cnt>2){
                freq[s[l]-'a']--;
                if(freq[s[l]-'a']==0) cnt--;
                l++;
            }
            
            total_bad_sub += (ll)(r-l+1);
            r++;
            
        }
        
        return total_num_sub - total_bad_sub;
        
    }
};

/*

 a b c a b c

 0 1 2 3 4 5
 
 total = 21
 
 number of subarrays containing only one type of characters
 
 either (aaaa / bb / cccccc)
 
 a,b,c,a,b,c,ab,bc,ca,ab,bc

*/