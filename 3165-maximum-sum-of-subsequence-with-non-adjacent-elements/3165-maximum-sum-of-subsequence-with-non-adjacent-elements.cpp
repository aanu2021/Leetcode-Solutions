// class Solution {
// public:
    
//     typedef long long ll;
//     const ll M = 1e9 + 7;
    
//     struct Node{
        
//         ll lr;
//         ll lplus1;
//         ll rminus1;
//         ll lplus1rminus1;
        
//         Node(){
//             lr = 0LL;
//             lplus1 = 0LL;
//             rminus1 = 0LL;
//             lplus1rminus1 = 0LL;
//         }
//     };
    
//     /*
    
//     [A, L] 
//     [B, R]
    
//     [A+1, B] =   [A+1, L-1] + [B+1, R] 
//                  [A+1, L-1] + [B, R]
//                  [A+1, L] + [B+1, R]
        
//     [A, B-1] =   [A, L-1] + [B+1, R-1]
//                  [A, L-1] + [B, R-1]
//                  [A, L] + [B+1, R-1]
        
//     [A+1, B-1] = [A+1, L-1] + [R+1, B-1]
//                  [A+1, L] + [R+1, B-1]
//                  [A+1, L-1] + [R, B-1]
                 
//     */             
        
    
//     Node merge(Node a, Node b){
//         Node node;
//         node.lr = max({a.rminus1 + b.lplus1, a.rminus1 + b.lr, a.lr + b.lplus1});
//         node.lplus1 = max({a.lplus1rminus1 + b.lplus1, a.lplus1rminus1 + b.lr, a.lplus1 + b.lplus1});
//         node.rminus1 = max({a.rminus1 + b.lplus1rminus1, a.rminus1 + b.rminus1 + a.lr + b.lplus1rminus1});
//         node.lplus1rminus1 = max({a.lplus1rminus1 + b.lplus1rminus1, a.lplus1 + b.lplus1rminus1, a.lplus1rminus1 + b.rminus1});
//         return node;
//     }
    
//     vector<Node>tree;
    
//     void Build(vector<int>&nums, int idx, int low, int high){
//         if(low > high) return;
//         if(low == high){
//             tree[idx].lr = max(0LL, (ll)nums[low]);
//             tree[idx].lplus1 = 0LL;
//             tree[idx].rminus1 = 0LL;
//             tree[idx].lplus1rminus1 = 0LL;
//             return;
//         }
//         else{
//             int mid = (low + high)/2;
//             Build(nums, 2*idx+1, low, mid);
//             Build(nums, 2*idx+2, mid+1, high);
//             tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
//         }
//     }
    
//     void update(int idx, int low, int high, int pos, int val){
//         if(low > high) return;
//         if(low == high){
//             tree[idx].lr = (ll)max(0, val);
//             tree[idx].lplus1 = 0LL;
//             tree[idx].rminus1 = 0LL;
//             tree[idx].lplus1rminus1 = 0LL;
//             return;
//         }
//         else{
//             int mid = (low + high)/2;
//             if(pos <= mid){
//                 update(2*idx+1, low, mid, pos, val);
//             }
//             else{
//                 update(2*idx+2, mid+1, high, pos, val);
//             }
//             tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
//         }
//     }
    
//     int query(){
//        ll answer = max({tree[0].lr, tree[0].lplus1, tree[0].rminus1, tree[0].lplus1rminus1});
//         return (int)(answer%M);
//     }
    
//     int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
//         int n = nums.size();
//         ll answer = 0LL;
//         tree.clear();
//         tree = vector<Node>(4*n+5);
//         Build(nums, 0, 0, n-1);
//         for(int i=0;i<queries.size();i++){
//             int idx = queries[i][0];
//             int val = queries[i][1];
//             update(0, 0, n-1, idx, val);
//             ll curr = query();
//             answer += curr;
//             cout<<curr<<"\n";
//             answer %= M;
//         }
//         for(int i=0;i<n;i++)
//         return answer;
//     }
// };

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define vpii vector<pair<int, int>>
#define vpii vector<pair<int, int>>
#define vvpii vector<vector<pair<int, int>>>
#define vpll vector<pair<long long, long long>>
#define vvpll vector<vector<pair<long long, long long>>>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long>>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

#define feach(el, v) for(auto &el: v)
#define rep(i, n) for(int i=0;i<n;i++)
#define reprv(i, n) for(int i=n-1;i>=0;i--)
#define reps(i, s, e) for(int i=s;i<e;i++)
#define reprve(i, e, s) for(int i=e;i>=s;i--)
#define repe(x, y) for (auto &x: y)
#define repe2(x, a, y) for (auto &[x,a]: y)

const ll MOD = 1e9 + 7;

struct nd {
    ll lr, lplus1r, lrminus1, lplus1rminus1;
};

nd combine (nd a, nd b) {
    ll lr = max(a.lrminus1 + b.lplus1r, a.lr + b.lplus1r);
    lr = max(lr, a.lrminus1 + b.lr);

    ll lplus1r = max(a.lplus1rminus1 + b.lplus1r, a.lplus1r + b.lplus1r);
    lplus1r = max(lplus1r, a.lplus1rminus1 + b.lr);

    ll lrminus1 = max(a.lrminus1 + b.lplus1rminus1, a.lr + b.lplus1rminus1);
    lrminus1 = max(lrminus1, a.lrminus1 + b.lrminus1);

    ll lplus1rminus1 = max(a.lplus1rminus1 + b.lplus1rminus1, a.lplus1r + b.lplus1rminus1);
    lplus1rminus1 = max(lplus1rminus1, a.lplus1rminus1 + b.lrminus1);

    return {
        lr % MOD, lplus1r % MOD, lrminus1 % MOD, lplus1rminus1 % MOD
    };
}

class Solution {
public:
    void build(vector<nd> &stree, vi &vec, int v, int tl, int tr) {
        if (tl == tr) {
            stree[v] = {
                    max(0, vec[tl]), 0, 0, 0
            };
            return;
        }
        int tm = (tl + tr) >> 1;
        build(stree, vec, 2*v + 1, tl, tm);
        build(stree, vec, 2*v + 2, tm + 1, tr);

        stree[v] = combine(stree[2*v + 1], stree[2*v + 2]);
    }

    void update(vector<nd> &stree, int pos, int val, int v, int tl, int tr) {
        if (tl == tr) {
            stree[v] = {
                    max(0, val), 0, 0, 0
            };
            return;
        }

        int tm = (tl + tr) >> 1;
        if (pos <= tm) update(stree, pos, val, 2*v + 1, tl, tm);
        else update(stree, pos, val, 2*v + 2, tm + 1, tr);

        stree[v] = combine(stree[2*v + 1], stree[2*v + 2]);
    }

    ll query(vector<nd> &stree) {
        ll ans = max(stree[0].lr, stree[0].lplus1r);
        ans = max(ans, stree[0].lrminus1);
        ans = max(ans, stree[0].lplus1rminus1);
        return ans;
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<nd> segtree(4 * n + 5);
        build(segtree, nums, 0, 0, n - 1);

        ll ans = 0;
        int q = queries.size();
        rep(i, q) {
            ll pos = queries[i][0], x = queries[i][1];
            update(segtree, pos, x, 0, 0, n - 1);
            ans += query(segtree);
            ans %= MOD;
        }
        return ans;
    }
};