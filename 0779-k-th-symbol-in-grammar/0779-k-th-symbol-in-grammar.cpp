class Solution {
public:
    int kthGrammar(int n, int k) {
        vector<int>v;
        while(k != 1){
            v.push_back(k);
            k = (k+1)/2;
        }
        v.push_back(1);
        reverse(v.begin(),v.end());
        int sz = v.size();
        int ele = 0;
        for(int i=0;i<sz-1;i++){
            int x = v[i];
            int y = v[i+1];
            if((2*x) == y){
                ele = 1 - ele;
            }
        }
        return ele;
    }
};

/*

0
01
0110
01101001
0110100110010110 
01101001100101101001011001101001    

22 -> 11 -> 6 -> 3 -> 2 -> 1
                      
1 -> 2 -> 3 -> 6 -> 11 -> 22

0 -> 1 -> 1 -> 0 -> 0 -> 1

0 -> 01
1 -> 10

*/
 