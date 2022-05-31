class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n=s.length();
        
        if(n<k){
            return false;
        }
        
        set<string>st;
        
        string str="";
        
        for(int i=0;i<k;i++){
            str+=s[i];
        }
        
        st.insert(str);
        
        for(int i=k;i<n;i++){
            str.erase(0,1);
            str+=s[i];
            st.insert(str);
        }
        
       
        return st.size()==(1<<k);
        
    }
};