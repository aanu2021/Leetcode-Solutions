class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.length();
        
        stack<string>S;
        
        for(int i=0;i<n;++i){
            
            if(s[i]==' '){
                continue;
            }
            
            int j=i;
            
            while(j<n && s[j]!=' '){
                j++;
            }
            
            reverse(s.begin()+i,s.begin()+j);
            
            i=j;
            
            i--;
            
        }
        
        return s;
        
    }
};


//i=2 , j=5
    

    
    