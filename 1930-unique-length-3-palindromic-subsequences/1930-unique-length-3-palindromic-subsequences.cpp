class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        int answer = 0;
        unordered_map<char,vector<int>>indexMap;
        for(int i=0;i<n;i++){
            indexMap[s[i]].push_back(i);
        }
        for(char c1='a';c1<='z';c1++){
            for(char c2='a';c2<='z';c2++){
                if(c1 == c2){
                    if(indexMap[c1].size() >= 3){
                        answer++;
                    }
                }
                else{
                    if(indexMap[c1].size() < 2 || indexMap[c2].size() == 0) continue;
                    int sz = indexMap[c1].size();
                    int firstIndex = indexMap[c1][0];
                    int lastIndex  = indexMap[c1][sz-1];
                    int idx = lower_bound(indexMap[c2].begin(),indexMap[c2].end(),firstIndex) - indexMap[c2].begin();
                    if(idx < indexMap[c2].size()){
                        int indexHave = indexMap[c2][idx];
                        if(indexHave > firstIndex && indexHave < lastIndex){
                            answer++;
                        }
                    }
                }
            }
        }
        return answer;
    }
};

// b b c b a b a


// a a -> 
// a b -> 1
// a c -> 
// b a -> 1
// b b -> 1
// b c ->
// c a -> 
// c b -> 1
// c c -> 


