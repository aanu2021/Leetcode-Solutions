class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        
        return x[1] < y[1];
        
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
       sort(intervals.begin(),intervals.end(),comp);
        
       int ans=0;
        
       int curr=intervals[0][1];
        
       for(int i=1;i<intervals.size();++i){
           
           if(intervals[i][0]<curr){
               
               ans++;
               
           }
           
           else{
               
               curr=intervals[i][1];
               
           }
           
       }
        
       return ans; 
        
    }
};


//[1,2] [1,4] [3,4]
