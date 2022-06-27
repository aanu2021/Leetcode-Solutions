class Solution {
public:
    int minPartitions(string s) {
        
        int maxi=s[0]-'0';
        
        for(int i=1;i<s.length();++i){
            if(maxi<s[i]-'0'){
                maxi=(s[i]-'0');
            }
        }
        
        return maxi;
        
    }
};