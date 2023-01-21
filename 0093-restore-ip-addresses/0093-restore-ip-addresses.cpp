class Solution {
public:
    
    bool isValid(string &s){
        if(s.length()==0 || s.length() > 3) return false;
        int len = s.length();
        int numValue = stoi(s);
        if(numValue > 0 && s[0]=='0') return false;
        if(numValue == 0 && len >= 2) return false;
        if(numValue >= 0 && numValue <= 255) return true;
        return false;
    }
    
    vector<string> restoreIpAddresses(string s) {
        int n = s.length();
        vector<string>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    string first = s.substr(0,i);
                    string second = s.substr(i,j-i);
                    string third = s.substr(j,k-j);
                    string fourth = s.substr(k);
                    if(isValid(first) && isValid(second) && isValid(third) && isValid(fourth)){
                        string curr = "";
                        curr += first;
                        curr += ".";
                        curr += second;
                        curr += ".";
                        curr += third;
                        curr += ".";
                        curr += fourth;
                        ans.push_back(curr);
                    }
                }
            }
        }
        return ans;
    }
};

/*

s0 s1 s2 s3 s4 s5 s6 s7
  i     j 

*/