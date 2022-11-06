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


    
    