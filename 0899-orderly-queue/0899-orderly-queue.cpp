class Solution {
public:
    string orderlyQueue(string s, int k) {
        
        int n = s.length();
        
        if(k==1){
            
            string res = s;
            
            for(int i=1;i<=n;i++){
                string left = s.substr(0,i);
                string right = s.substr(i);
                string curr = "";
                curr+=right;
                curr+=left;
                res=min(res,curr);
            }
            
            return res;
            
        }
        
        else{
            
            sort(s.begin(),s.end());
            
            return s;
            
        }
        
    }
};

// aecdceb --> ecdceba --> edcebac --> ecebacd --> eebacdc --> ebacdce --> eacdceb --> acdcebe --> cdcebea --> dcebeac --> debeacc --> ebeaccd --> eeaccdb --> accdbee --> cdbeeac --> dbeeacc --> deeaccb --> accbdee --> cbdeeac --> 
    
    
// acdcb --> cdcba --> dcbac --> dbacc --> daccb --> accbd     
    
// accbd --> cbdac --> cdacb --> acbcd

// acbcd --> cbcda --> ccdab --> cdabc --> dabcc --> abccd