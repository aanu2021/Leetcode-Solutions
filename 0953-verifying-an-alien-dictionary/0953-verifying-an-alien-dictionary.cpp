class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = words.size();
        vector<int>Index(26,-1);
        for(int i=0;i<order.length();i++){
            Index[order[i]-'a'] = i;
        }
        for(int i=0;i<n-1;i++){
            int len1 = words[i].length();
            int len2 = words[i+1].length();
            int len = min(len1,len2);
            int idx = -1;
            for(int j=0;j<len;j++){
                if(words[i][j] != words[i+1][j]){
                    idx = j;
                    if(Index[words[i][j]-'a'] > Index[words[i+1][j]-'a']){
                        return false;
                    }
                    else{
                        break;
                    }
                }
            }
            if(idx == -1){
                if(len1 > len2) return false;
            }
        }
        return true;
    }
};