class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char ch:s){
            freq[ch]++;
        }
        int n = s.length();
        vector<vector<char>>vec(n+1);
        for(auto &itr:freq){
            vec[itr.second].push_back(itr.first);
        }
        s.clear();
        for(int i=n;i>=0;i--){
            if(vec[i].size()==0) continue;
            int occurence = i;
            for(char ch:vec[i]){
                int currocc = occurence;
                while(currocc>0){
                    s+=ch;
                    currocc--;
                }
            }
        }
        return s;
    }
};