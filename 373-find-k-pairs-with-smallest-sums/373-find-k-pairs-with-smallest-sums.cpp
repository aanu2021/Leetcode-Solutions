class Solution {
public:
    
    struct comp{
      
        bool operator()(const vector<int>&x,const vector<int>&y){
            return x[0] > y[0];
        }
        
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int m=nums1.size();
        int n=nums2.size();
        
        vector<vector<int>>ans;
        
        priority_queue<vector<int>,vector<vector<int>>,comp>pq;
        
        pq.push({nums1[0]+nums2[0],0,0});
        
        set<pair<int,int>>visited;
        
        visited.insert({0,0});
        
        for(int i=0;i<k && !pq.empty();++i){
            
            ans.push_back({nums1[pq.top()[1]],nums2[pq.top()[2]]});
            
            auto curr=pq.top();
            pq.pop();
            
            int x=curr[1];
            int y=curr[2];
            
            if(x+1<m && y<n && visited.find({x+1,y})==visited.end()){
                
                visited.insert({x+1,y});
                pq.push({nums1[x+1]+nums2[y],x+1,y});
                
            }
            
            if(x<m && y+1<n && visited.find({x,y+1})==visited.end()){
                
                visited.insert({x,y+1});
                pq.push({nums1[x]+nums2[y+1],x,y+1});
                
            }

        }
        
        return ans;
        
    }
};