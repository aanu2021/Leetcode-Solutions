class Solution {
public:
    
    typedef long long ll;
    
    struct comp{
      
        bool operator()(const pair<int,int>&x,const pair<int,int>&y){
            if(x.first == y.first) return x.second > y.second;
            return x.first > y.first;
        }
        
    };
    
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        
        // Sort the given tasks according to the ascending order of their starting times
        
        sort(tasks.begin(),tasks.end());
        
        // Now just after CPU observe that it has some already available resources , and it is done with the execution of previous processes , then two cases occur :
        
        // Case 1: Take the process with shortest processing time.
        // Case 2: Take the process with minimum shortest index , if all of them have same processing time.
        
        // For that matter we need to use minheap which will store all the processes available on the basis of their ascending processing time and if there is a tie , then on the basis of their ascending index.
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        
        long long currTime = 0LL;
        int idx = 0;
        
        vector<int>ans;
        
        while(!pq.empty() || idx<n){
            
            while(idx<n && (ll)tasks[idx][0]<=currTime){
                pq.push({tasks[idx][1],tasks[idx][2]});
                idx++;
            }
            
            if(!pq.empty()){
                ans.push_back(pq.top().second);
                currTime += (ll)pq.top().first;
                pq.pop();
            }
            else{
                currTime = (ll)tasks[idx][0];
            }
            
        }
        
        return ans;
        
    }
};

/*

i-th task --> [ start , duration ]

CPU is single threaded , that is why it can process at most one task at a time.
    
*/    
    
    
    