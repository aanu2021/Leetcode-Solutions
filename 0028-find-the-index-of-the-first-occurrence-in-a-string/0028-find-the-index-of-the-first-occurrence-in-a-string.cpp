class Solution {
public:
    int strStr(string s, string p) {
        int n = s.length();
        int m = p.length();
        if(n < m) return -1;
        vector<int>lps(m,0);
        for(int i=1;i<m;i++){
            int len = lps[i-1];
            while(len > 0 && p[i] != p[len]){
                len = lps[len-1];
            }
            if(p[len] == p[i]){
                len++;
            }
            lps[i] = len;
        }
        vector<int>indices;
        int j = 0;
        for(int i=0;i<n;i++){
            if(s[i]==p[j]){
                j++;
                if(j == m){
                    indices.push_back(i-m+1);
                    j = lps[j-1];
                }
            }
            else{
                while(j > 0 && s[i] != p[j]){
                    j = lps[j-1];
                }
                if(s[i] == p[j]){
                    j++;
                }
            }
        }
        // for(int i=0;i<indices.size();i++){
        //     cout<<indices[i]<<" ";
        // }cout<<"\n";
        if(indices.size()) return indices[0];
        else return -1;
    }
};