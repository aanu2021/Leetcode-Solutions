class Solution {
public:
    string clearStars(string s) {
        int n = s.length();
        vector<int>removed(n, 0);
        vector<vector<int>>bucket(26);
        for(int i=0;i<n;i++){
            if(s[i] == '*'){
                for(int j=0;j<26;j++){
                    if(bucket[j].size() > 0){
                        removed[i] = 1;
                        removed[bucket[j].back()] = 1;
                        bucket[j].pop_back();
                        break;
                    }
                }
            }
            else{
                bucket[s[i]-'a'].push_back(i);
            }
        }
        string res = "";
        for(int i=0;i<n;i++){
            if(!removed[i]) res += s[i];
        }
        return res;
    }
};