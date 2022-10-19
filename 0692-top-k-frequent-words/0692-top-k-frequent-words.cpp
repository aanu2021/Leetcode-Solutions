class Solution {
public:
    
    struct comp{
        
      bool operator()(const pair<int,string>&x,const pair<int,string>&y){
          
          if(x.first==y.first){
              
              return x.second < y.second;
              
          }
          
          return x.first > y.first;
          
      }  
        
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        
        unordered_map<string,int>mp;
        
        for(int i=0;i<n;i++){
            mp[words[i]]++;
        }
        
        vector<string>ans;
        
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        
        for(auto itr:mp){
            
            pq.push({itr.second,itr.first});
            
            if(pq.size() > k){
                
                pq.pop();
                
            }
            
        }
        
        while(!pq.empty()){
            
            ans.push_back(pq.top().second);
            pq.pop();
            
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};