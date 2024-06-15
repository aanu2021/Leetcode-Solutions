class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>>vec(n);
        for(int i=0;i<n;i++){
            vec[i] = {capital[i], profits[i]};
        }
        sort(vec.begin(),vec.end());
        priority_queue<int>pq;
        int ptr = 0;
        for(int i=0;i<k;i++){
            while(ptr < n && vec[ptr].first <= w){
                pq.push(vec[ptr++].second);
            }
            if(!pq.empty()){
                w += pq.top(); pq.pop();
            }
        }
        return w;
    }
};

// w = 0
// k = 2

// [0, 1, 1]
// [1, 2, 3]

// Sort based on capitals (in increasing order)
// push all the profits in a heap, which are having their req cap <= w
// pick the maximum profit present in the heap, add it into total w
// try to do the same thing for k iterations.
