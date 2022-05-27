class Solution {
public:
    
    set<string>st;
    
    vector<string>result;
    
    void func(string s,vector<string>vec){
        
        if(s.length()==0){
           
            string str="";
            
            for(int i=0;i<vec.size();i++){
                str+=vec[i];
                str+=" ";
            }
            
            str.pop_back();
            
            result.push_back(str);
            
            return;
            
        }
        
        
        for(int i=0;i<s.length();i++){
            
            string left=s.substr(0,i+1);
            string right=s.substr(i+1);
            
            if(st.find(left)!=st.end()){
                
                vec.push_back(left);
                
                func(right,vec);
                
                vec.pop_back();
                
            }
            
        }
        
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(string str:wordDict){
            st.insert(str);
        }
        
        vector<string>vec;
        
        func(s,vec);
        
        return result;
        
    }
};