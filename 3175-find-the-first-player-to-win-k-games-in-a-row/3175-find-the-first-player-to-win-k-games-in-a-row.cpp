class Solution {
public:
    int findWinningPlayer(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>indexMap;
        for(int i=0;i<n;i++){
            indexMap[nums[i]] = i;
        }
        int M = *max_element(nums.begin(),nums.end());
        if(k >= n) return indexMap[M];
        unordered_map<int,int>score;
        deque<int>q;
        for(int i=0;i<n;i++){
            q.push_back(nums[i]);
        }
        while(q.size() > 1){
            int x = q.front(); q.pop_front();
            int y = q.front(); q.pop_front();
            if(x == M) break;
            if(x > y){
                score[x]++;
                if(score[x] == k) return indexMap[x];
                else{
                    q.push_front(x);
                    q.push_back(y);
                }
            }
            else{
                score[y]++;
                if(score[y] == k) return indexMap[y];
                else{
                    q.push_front(y);
                    q.push_back(x);
                }
            }
        }
        return indexMap[M];
    }
};