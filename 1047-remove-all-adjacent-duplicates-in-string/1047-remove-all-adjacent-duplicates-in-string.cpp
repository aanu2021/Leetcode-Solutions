class Solution {
public:
    
    string removeDuplicates2(string s) {
        int n = s.length();
        string res="";
        for(int i=0;i<n;i++){
            if(res.length() && res.back()==s[i]){
                res.pop_back();
            }else{
                res+=s[i];
            }
        }
        return res;
    }
    
    string removeDuplicates(string s) {
        int n = s.length();
        int left = 0,right = 0;
        for(right=0;right<n;right++){
            if(left>0 && s[left-1]==s[right]){
                left--;
            }else{
                s[left] = s[right];
                left++;
            }
        }
        return s.substr(0,left);
    }
    
};

   