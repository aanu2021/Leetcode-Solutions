class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int n = flowers.size();
        int m = people.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>answer(m,0);
        vector<pair<int,int>>vec(m);
        for(int i=0;i<m;i++){
            vec[i] = {people[i],i};
        }
        sort(flowers.begin(),flowers.end());
        sort(vec.begin(),vec.end());
        int j = 0;
        for(int i=0;i<m;i++){
            while(j<n && flowers[j][0] <= vec[i].first){
                pq.push(flowers[j][1]);
                j++;
            }
            while(!pq.empty() && pq.top() < vec[i].first){
                pq.pop();
            }
            answer[vec[i].second] = pq.size();
        }
        return answer;
    }
};
