class Solution {
public:
    
    typedef long long ll;
    
    struct Pair{
        int cost;
        int index;
        int group;
    };
    
    struct comp{
       bool operator()(const Pair&x,const Pair&y){
           if(x.cost == y.cost){
               return x.index > y.index;
           }
           return x.cost > y.cost;
       }  
    };
    
    long long totalCost(vector<int>& costs, int c, int k) {
        
        priority_queue<Pair,vector<Pair>,comp>pq;
        
        int n = costs.size();
        
        ll answer = 0LL;
        
        for(int i=0;i<k;i++){
            pq.push({costs[i],i,1});
        }
        for(int i=n-1;i>=max(n-k,k);i--){
            pq.push({costs[i],i,2});
        }
        
        int L = k, R = n-k-1;
        
        while(!pq.empty() && c > 0){
            
            auto worker = pq.top(); pq.pop();
            
            int currCost = worker.cost;
            int currIndex = worker.index;
            int group = worker.group;
            
            answer += (ll)currCost;
            c--;
            
            if(group == 1){
                if(L <= R){
                    pq.push({costs[L],L,1});
                    L++;
                }
            }
            else{
                if(L <= R){
                    pq.push({costs[R],R,2});
                    R--;
                }
            }
            
        }
        
        return answer;
        
    }
};