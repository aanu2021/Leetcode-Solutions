class Solution {
public:
    
    bool Match(char ch1,char ch2){
        if(ch1==ch2+32 || ch1+32==ch2){
            return true;
        }else{
            return false;
        }
    }
    
    string makeGood(string s) {
        string res="";
        for(int i=0;i<s.length();i++){
            if(res.length() && Match(res.back(),s[i])){
                res.pop_back();
            }else{
                res+=s[i];
            }
        }
        return res;
    }
};