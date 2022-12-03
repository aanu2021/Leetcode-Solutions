class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char ch:s){
            freq[ch]++;
        }
        vector<pair<int,char>>vec;
        for(auto &itr:freq){
            vec.push_back({itr.second,itr.first});
        }
        sort(vec.rbegin(),vec.rend());
        s.clear();
        for(int i=0;i<vec.size();i++){
            int occurence = vec[i].first;
            char curr = vec[i].second;
            while(occurence>0){
                s+=curr;
                occurence--;
            }
        }
        return s;
    }
};