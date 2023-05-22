class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int,int>freq;
        
        for(int &ele : nums) freq[ele]++;
        
        vector<pair<int,int>>freqArr;
        
        for(auto &itr : freq){
            freqArr.push_back({itr.second,itr.first});
        }
        
        sort(freqArr.rbegin(),freqArr.rend());
        vector<int>answer;
        
        for(int i=0;i<k;i++){
            answer.push_back(freqArr[i].second);
        }
        return answer;
        
    }
};