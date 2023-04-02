class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>answer;
        sort(potions.begin(),potions.end());
        int n = spells.size();
        int m = potions.size();
        for(int i=0;i<n;i++){
            long long req = (success/spells[i]);
            if(success%spells[i]) req++;
            int idx = lower_bound(potions.begin(),potions.end(),req) - potions.begin();
            answer.push_back(m-idx);
        }
        return answer;
    }
};

// 5 * x >= 7
// x >= 7/5    