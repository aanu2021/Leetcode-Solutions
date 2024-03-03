class Solution {
public:
    
    vector<int>tree1, tree2;
    
    void Update(vector<int>&tree,int idx,int low,int high,int pos){
        if(low > high) return;
        if(low == high){
            tree[idx]++;
            return;
        }
        else{
            int mid = (low + high)/2;
            if(pos <= mid){
                Update(tree,2*idx+1,low,mid,pos);
            }
            else{
                Update(tree,2*idx+2,mid+1,high,pos);
            }
            tree[idx] = tree[2*idx+1] + tree[2*idx+2];
        }
    }
    
    int query(vector<int>&tree,int idx,int low,int high,int l,int r){
        if(low > high || low > r || high < l) return 0;
        if(low == high) return tree[idx];
        if(low >= l && high <= r) return tree[idx];
        else{
            int mid = (low + high)/2;
            int lSum = query(tree,2*idx+1,low,mid,l,r);
            int rSum = query(tree,2*idx+2,mid+1,high,l,r);
            return lSum + rSum;
        }
    }
    
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp = nums;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>indexMap;
        int ptr = 0;
        for(int i=0;i<n;i++){
            int j = i;
            while(j < n && temp[j] == temp[i]){
                j++;
            }
            indexMap[temp[i]] = ptr++;
            i = j;
            i--;
        }
        int m = ptr;
        tree1.clear();
        tree2.clear();
        tree1 = vector<int>(4*m + 2, 0);
        tree2 = vector<int>(4*m + 2, 0);
        int fCnt = 0, sCnt = 0;
        Update(tree1,0,0,m-1,indexMap[nums[0]]);
        Update(tree2,0,0,m-1,indexMap[nums[1]]);
        fCnt = 1, sCnt = 1;
        vector<int>v1, v2;
        v1.push_back(nums[0]);
        v2.push_back(nums[1]);
        for(int i=2;i<n;i++){
            int c1 = query(tree1,0,0,m-1,indexMap[nums[i]]+1,m-1);
            int c2 = query(tree2,0,0,m-1,indexMap[nums[i]]+1,m-1);
            if((c1 > c2) || (c1 == c2 && fCnt <= sCnt)){
                fCnt++;
                v1.push_back(nums[i]);
                Update(tree1,0,0,m-1,indexMap[nums[i]]);
            }
            else{
                sCnt++;
                v2.push_back(nums[i]);
                Update(tree2,0,0,m-1,indexMap[nums[i]]);
            }
            // else{
            //     if(fCnt > sCnt){
            //         sCnt++;
            //         v2.push_back(nums[i]);
            //         Update(tree2,0,0,m-1,indexMap[nums[i]]);
            //     }
            //     else{
            //         fCnt++;
            //         v1.push_back(nums[i]);
            //         Update(tree1,0,0,m-1,indexMap[nums[i]]);
            //     }
            // }
        }
        vector<int>answer;
        for(int &ele : v1){
            answer.push_back(ele);
        }
        for(int &ele : v2){
            answer.push_back(ele);
        }
        return answer;
    }
};