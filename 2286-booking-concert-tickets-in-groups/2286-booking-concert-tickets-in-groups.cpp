class BookMyShow {
    int n;
    int m;
    vector<array<long long, 2>> stree; 
    
    // segment tree that tracks (max, sum) of each segment
    
    // stree[i][0] --> Maximum element out of the interval
    // stree[i][1] --> Total Sum of the interval 
    
public:
    void build(int i, int p, int q) {
        
        // For leaf nodes [ i.e range or single element ] , we have to assert the base case , stree[i] = {m , m};
        
        if (p == q) {
            stree[i] = {m, m};
            return;
        }
        
        // Find the mid point which boils down the interval into two halves and that is the major part , which helps us to reduce the time complexity from O(N) to O(log2(N)) for average cases.
        
        int r = (p + q) / 2;
        
        stree[i] = {m, (long long)(q-p+1)*m};
        
        // Recursively call the left half and right half of the current interval.
        
        build(2*i+1, p, r);
        build(2*i+2, r+1, q);
        
    }

    vector<int> query_max(int i, int p, int q, int k, int maxRow) {
        
        // If the current row number is not valid as per our requirement , we have to skip it.
        if (p > maxRow || p > q )
            return {};
        
        // Again , if the maxvalue of the current interval becomes < k , that means exploring these interval by breaking it into first and second half , will gonna be increase our time complexity unnecessarily.
        
        if (stree[i][0] < k)
            return {};
        
        // Here , the base case is the leaf nodes , that is single point interval , if stree[i][0]>=k , then return the row number and column number .
        
        if (p == q)
            return {p, (int)(m - stree[i][0])};
        
        // Now its the time to recursively check the left half and right half , does there any valid answer exist or not.
        
        int r = (p + q) / 2;
        
        vector<int> ret = query_max(2*i+1, p, r, k, maxRow);
        
        if (ret.size())
            return ret;
        
        return query_max(2*i+2, r+1, q, k, maxRow);
        
    }

    void update_max(int i, int p, int q, int row, int k) {
        
        // Base cases where the range is out of bound
        
        if (p > row || q < row)
            return;
        
        if (p == q) {
            stree[i][0] -= k;
            stree[i][1] -= k;
            // cout << p << " " << stree[i][0] << endl;
            return;
        }
        
        int r = (p + q) / 2;
        
        stree[i][1] -= k;
        
        update_max(2*i+1, p, r, row, k);
        update_max(2*i+2, r+1, q, row, k);
        
        stree[i][0] = max(stree[2*i+1][0], stree[2*i+2][0]);
        
    }

    long long query_sum(int i, int p, int q, int maxRow) {
        if (p > maxRow)
            return 0;
        if (q <= maxRow)
            return stree[i][1];
        int r = (p + q) / 2;
        return query_sum(2*i+1, p, r, maxRow) + query_sum(2*i+2, r+1, q, maxRow);
    }

    void update_sum(int i, int p, int q, int k, int maxRow) {
        if (p > maxRow)
            return;
        if (p == q) {
            stree[i][0] -= k;
            stree[i][1] -= k;
            // cout << p << " " << stree[i][0] << endl;
            return;
        }
        int r = (p + q) / 2;
        stree[i][1] -= k;
        if (r+1 > maxRow || stree[2*i+1][1] >= k) {
            update_sum(2*i+1, p, r, k, maxRow);
        } else {
            k -= stree[2*i+1][1];
            update_sum(2*i+1, p, r, stree[2*i+1][1], maxRow);
            // Be aware: stree[2*i+1][1] updates while updating the left tree
            update_sum(2*i+2, r+1, q, k, maxRow);
        }
        stree[i][0] = max(stree[2*i+1][0], stree[2*i+2][0]);
    }


    BookMyShow(int n_in, int m_in) {
        
        n = n_in;
        m = m_in;

        int sz = 1;
        while (sz < n*2)
            sz <<= 1;
        stree.resize(sz);

        // Build the Segment Tree for each and every intervals [ max , sum ]
        
        build(0, 0, n-1);
        
    }

    vector<int> gather(int k, int maxRow) {
        // cout << "gather " << k << " " << maxRow << endl;
        
        // query_max function returns the vector which helps us to find out the smallest possible row and smallest possible column [r + c] , where number of seats unoccupied >= k , and also r>=0 && r<=maxRow
        
        vector<int> ret = query_max(0, 0, n-1, k, maxRow);
        
        // If a valid answer exists , then we have to update the range sum from [0 to ret[0]] and more importantly the max-point updation [ at ret[0] ]
        
        if (ret.size()>0)
            
            update_max(0, 0, n-1, ret[0], k);
        
        return ret;
        
    }

    bool scatter(int k, int maxRow) {
        // cout << "scatter " << k << " " << maxRow << endl;
        long long cnt = query_sum(0, 0, n-1, maxRow);
        bool ret = cnt >= k;
        if (ret)
            update_sum(0, 0, n-1, k, maxRow);
        return ret;
    }
};