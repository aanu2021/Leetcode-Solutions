class Solution {
public:
    
    bool static comp(const vector<int>&x,const vector<int>&y){
        if(x[0] == y[0]) return x[1] < y[1];
        return x[0] > y[0];
    }
    
    bool static comp2(const vector<int>&x,const vector<int>&y){
        if(x[0] == y[0]) return x[1] > y[1];
        return x[0] < y[0];
    }
    
    vector<vector<int>> reconstructQueue3(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp);
        vector<vector<int>>ans;
        for(int i=0;i<people.size();i++){
            ans.insert(ans.begin() + people[i][1],people[i]);
        }
        return ans;
    }
    
    vector<vector<int>> reconstructQueue2(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp2);
        int n = people.size();
        vector<vector<int>>ans(n);
        for(int i=0;i<n;i++){
            int j = 0 , cnt = 0;
            for(j=0;j<n;j++){
                if(ans[j].size() == 0){
                    if(cnt == people[i][1]){
                        break;
                    }
                    cnt++;
                }
            }
            ans[j] = people[i];
        }
        return ans;
    }
    
     
     vector<int>tree;
    
     void BuildSeg(int idx,int low,int high){
         if(low > high) return;
         if(low == high){
             tree[idx] = 0;
             return;
         }
         else{
             int mid = (low + high)/2;
             BuildSeg(2*idx+1,low,mid);
             BuildSeg(2*idx+2,mid+1,high);
             tree[idx] = tree[2*idx+1] + tree[2*idx+2];
         }
     }
    
    void Update(int idx,int low,int high,int pos){
        if(low > high) return;
        if(low == high){
            tree[idx]++;
            return;
        }
        else{
            int mid = (low + high)/2;
            if(pos <= mid){
                Update(2*idx+1,low,mid,pos);
            }
            else{
                Update(2*idx+2,mid+1,high,pos);
            }
            tree[idx] = tree[2*idx+1] + tree[2*idx+2];
        }
    }
    
    int query(int idx,int low,int high,int l,int r){
        if(low > high || low > r || high < l) return 0;
        if(low == high) return tree[idx];
        if(low >= l && high <= r) return tree[idx];
        else{
            int mid = (low + high)/2;
            int leftQ = query(2*idx+1,low,mid,l,r);
            int rightQ = query(2*idx+2,mid+1,high,l,r);
            return leftQ + rightQ;
        }
    }
    
     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
         sort(people.begin(),people.end(),comp2);
         int n = people.size();
         // for(int i=0;i<people.size();i++){
         //     cout<<people[i][0]<<" "<<people[i][1]<<" ,";
         // }cout<<"\n";
         vector<vector<int>>answer(n);
         tree.resize(4*n,0);
         BuildSeg(0,0,n-1);
         for(int i=0;i<n;i++){
             int reqd = people[i][1];
             int low = 0, high = n-1;
             int ans = -1;
             while(low <= high){
                 int mid = (low + high)/2;
                 int bigger = (mid);
                 bigger -= query(0,0,n-1,0,mid-1);
                 // cout<<mid<<" "<<bigger<<"\n";
                 if(bigger <= reqd){
                     ans = mid;
                     low = mid + 1;
                 }
                 else{
                     high = mid - 1;
                 }
             }
             // cout<<ans<<"\n";
             answer[ans] = people[i];
             Update(0,0,n-1,ans);
             // for(int j=0;j<n;j++){
             //     if(answer[j].size()){
             //         cout<<answer[j][0]<<" "<<answer[j][1]<<", ";
             //     }else{
             //         cout<<"    ,";
             //     }
             // }cout<<"\n";
         }
         return answer;
    }
    
};

// [7,0] [5,0] [7,1] [6,1] [5,2] [4,4]

// [5,0] [7,0] [6,1] [7,1] [5,2] [4,4]

// [7,0] [7,1] [6,1] [5,0] [5,2] [4,4]

// 5 7 5 6 4 7 

/*

[4,4] [5,0] [5,2] [6,1] [7,0] [7,1]

                         4
---   ---   ---   ---   ---   ---
 0     1     2     3     4     5   
 
 */