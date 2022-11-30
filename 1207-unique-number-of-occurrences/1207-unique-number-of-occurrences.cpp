class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        vector<int>freq_arr(n+1,0);
        for(auto &itr:freq){
            freq_arr[itr.second]++;
        }
        for(int i=0;i<=n;i++){
            if(freq_arr[i]>1) return false;
        }
        return true;
    }
};