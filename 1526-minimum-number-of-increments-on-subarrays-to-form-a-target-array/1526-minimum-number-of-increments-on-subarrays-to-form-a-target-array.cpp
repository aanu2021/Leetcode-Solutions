class Solution {
public:
    int minNumberOperations(vector<int>& A) {
        int n = A.size();
        int pre = 0,ans = 0;
        for(int a:A){
            ans+=max(a-pre,0);
            pre = a;
        }
        return ans;
    }
};