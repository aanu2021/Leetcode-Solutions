class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        unordered_map<int,int>freq;
        unordered_map<int,vector<int>>freq_to_ele;
        vector<int>freqArr(n+1,0);
        
        for(int &ele : nums) freq[ele]++;
        for(auto &itr : freq) freqArr[itr.second]++;
        for(auto &itr : freq) freq_to_ele[itr.second].push_back(itr.first);
        
        vector<int>answer;
        
        for(int i=n;i>=0;i--){
            while(freqArr[i] > 0 && k > 0){
                freqArr[i]--;
                k--;
                answer.push_back(freq_to_ele[i].back());
                freq_to_ele[i].pop_back();
            }
        }
        
        return answer;
        
    }
};