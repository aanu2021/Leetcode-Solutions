class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int m = word1.size();
        int n = word2.size();
        int i = 0, j = 0;
        int idx_i = 0, idx_j = 0;
        while(i<m && j<n){
            if(word1[i][idx_i] != word2[j][idx_j]) return false;
            idx_i++;
            idx_j++;
            if(idx_i == word1[i].length()){
                idx_i = 0;
                i++;
            }
            if(idx_j == word2[j].length()){
                idx_j = 0;
                j++;
            }
        }
        return i==m && j==n;
    }
};