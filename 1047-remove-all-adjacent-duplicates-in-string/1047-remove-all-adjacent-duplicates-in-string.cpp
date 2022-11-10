class Solution {
public:
    string removeDuplicates(string s) {
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
};