class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>freq;
        unordered_map<int,int>freq_occ;
        for(int &ele : arr){
            freq[ele]++;
        }
        for(auto &itr : freq){
            freq_occ[itr.second]++;
        }
        for(auto &itr : freq_occ){
            if(itr.second > 1) return false;
        }
        return true;
    }
};