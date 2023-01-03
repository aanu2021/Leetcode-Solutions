class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].length();
        int ans = 0;
        for(int i=0;i<m;i++){
            char ch='a';
            bool flag = true;
            for(int j=0;j<n;j++){
                if(strs[j][i]>=ch){
                    ch = strs[j][i];
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(!flag) ans++;
        }
        return ans;
    }
};