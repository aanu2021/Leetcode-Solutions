class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(char ch:tasks){
            freq[ch-'A']++;
        }
        sort(freq.begin(),freq.end());
        int maxi = freq[25];
        int idle = (maxi-1)*n;
        for(int i=0;i<25;i++){
            idle -= min(maxi-1,freq[i]);
        }
        return tasks.size() + max(0,idle);
    }
};