class Solution {
public:
    
    bool static comp(const pair<char,int>&x,const pair<char,int>&y){
        return x.second > y.second;
    }
    
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char,int>freq;
        for(char &ch : s){
            freq[ch]++;
        }
        vector<pair<char,int>>vec;
        for(auto &itr : freq){
            vec.push_back({itr.first,itr.second});
        }
        sort(vec.begin(),vec.end(),comp);
        string res(n,'_');
        int maxFreq = vec[0].second;
        if(maxFreq > ((n+1)/2)){
            return "";
        }
        int idx = 0;
        for(int i=0;i<vec.size();i++){
            char ch = vec[i].first;
            int occ = vec[i].second;
            while(occ--){
                if(idx>=n) idx = 1;
                res[idx] = ch;
                idx += 2;
            }
        }
        return res;
    }
};