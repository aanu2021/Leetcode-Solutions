class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        int currIdx = 0;
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            if(s[i]==' ') continue;
            if(currIdx){
                s[currIdx++] = ' ';
            }
            int j = i;
            while(j<n && s[j]!=' '){
                s[currIdx++] = s[j++];
            }
            reverse(s.begin()+currIdx-j+i,s.begin()+currIdx);
            i = j;
            i--;
        }
        
        s.erase(s.begin()+currIdx,s.end());
        
        return s;
        
    }
};

       