class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>vec;
        int n = profits.size();
        for(int i=0;i<n;i++){
            vec.push_back({capital[i],profits[i]});
        }
        sort(vec.begin(),vec.end());
        priority_queue<int>pq;
        int ptr = 0;
        for(int i=0;i<k;i++){
            while(ptr < n && vec[ptr].first <= w){
                pq.push(vec[ptr++].second);
            }
            if(!pq.empty()){
                w += pq.top();
                pq.pop();
            }
        }
        return w;
    }
};
   