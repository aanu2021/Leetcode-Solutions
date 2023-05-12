class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int,int>mp;
        int n = logs.size();
        for(int i=0;i<n;i++){
            mp[logs[i][0]]++;
            mp[logs[i][1]]--;
        }
        int currFreq = 0;
        int maxFreq = 0;
        int year = -1;
        for(auto &itr : mp){
            currFreq += itr.second;
            if(currFreq > maxFreq){
                maxFreq = currFreq;
                year = itr.first;
            }
        }
        return year;
    }
};