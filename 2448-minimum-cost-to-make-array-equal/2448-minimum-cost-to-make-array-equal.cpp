/*

 Point to be remembered : 
 
 (1) For these type of problems "Make all the array elements equal" --> we will convert all 
 the elements of the array into any one of the array element (that is currently present in the array) , 
 and then we will calculate the associated cost for it.
 
 (2) We need to sort the array in non-decreasing order , in such a way after which all the elements less than or 
 equal to the pivot element (here we will inc/dec all the array elements into the 'pivot' element) lie in its left 
 side and all the elements greater than or equal to the pivot will lie in exact right side.
 
 Approach : 
 
 Let's say we have an array in non-decreasing order [a , b , c , d , e , f , g]
 
 Definitely a <= b <= c <= d <= e <= f <= g <= ......
 
 Assume for now , our target pivot element is 'd' , then we need to decrease 'e' , 'f' , 'g' to 'd'.
 
 Say the cost associated to 'e' , 'f' , 'g' is  'x' , 'y' , 'z'
 
 Required number of operations = (e-d)*x + (f-d)*y + (g-d)*z  ....... (i)
 
 Simplify eqn (i) == e*x + f*y + g*z - d*x - d*y - d*z 
 
                  == (e*x + f*y + g*z) - d*(x+y+z)
                  
 What we can observe over here is the pivot value (i.e 'd') is already known to us , then we are left with two 
 variable quantities (x+y+z) and (ex + fy + gz)
 
 Cool , (x+y+z) is the suffix sum of all the costs after the pivot element.
 
 Again , we can maintain another suffix sum array which will store the (ex + fy + gz) quantity
 
 Where Suffix2[i] = (ex+fy+gz , fy+gz , gz)
 
 And   Suffix1[i] = (x+y+z , y+z , z)
 
 
 Now the expression(i) can be further simplified as (Suffix2[i+1] - (pivot[i]*Suffix1[i+1])) [considering i-th 
 index element as the pivot element]
 
 After that do the same thing for the elements , which are currently at the left side of the pivot element using 
 Prefix1[i] and Prefix2[i] array with precomputations.
 
 And after calculating in a same way we will get the similar kind of expression ((pivot[i]*Prefix1[i-1]) - 
 Prefix2[i-1])
 
 Overall Cost Associated with it = 
 
 (Suffix2[i+1] - (pivot[i]*Suffix1[i+1])) + ((pivot[i]*Prefix1[i-1]) - Prefix2[i-1])
 

*/

/*

T.C : O(N*logN)
S.C : O(N)

*/

class Solution {
public:
    
    typedef long long ll;
    
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        int n = nums.size();
        
        vector<pair<int,int>>vec(n);
        
        for(int i=0;i<n;i++){
            vec[i] = {nums[i],cost[i]};
        }
        
        sort(vec.begin(),vec.end());
        
        for(int i=0;i<n;i++){
            nums[i] = vec[i].first;
            cost[i] = vec[i].second;
        }
        
        vector<ll>prefix1(n+1,0LL);
        vector<ll>prefix2(n+1,0LL);
        vector<ll>suffix1(n+1,0LL);
        vector<ll>suffix2(n+1,0LL);
        
        prefix1[0] = (ll)cost[0];
        prefix2[0] = (ll)cost[0]*(ll)nums[0];
        
        suffix1[n-1] = (ll)cost[n-1];
        suffix2[n-1] = (ll)cost[n-1]*(ll)nums[n-1];
        
        for(int i=1;i<n;i++){
            
            prefix1[i] = prefix1[i-1];
            prefix1[i] += (ll)cost[i];
            
            prefix2[i] = prefix2[i-1];
            prefix2[i] += (ll)((ll)cost[i]*(ll)nums[i]);
            
        }
        
        for(int i=n-2;i>=0;i--){
            
            suffix1[i] = suffix1[i+1];
            suffix1[i] += (ll)cost[i];
            
            suffix2[i] = suffix2[i+1];
            suffix2[i] += (ll)((ll)cost[i]*(ll)nums[i]);
            
        }
        
        ll ans = 1e18;
        
        for(int i=0;i<n;i++){
            
            ll ps1 = (i-1 >= 0 ? prefix1[i-1] : 0LL);
            ll ps2 = (i-1 >= 0 ? prefix2[i-1] : 0LL);
            
            ll ss1 = suffix1[i+1];
            ll ss2 = suffix2[i+1];
            
            ll cost1 = (ll)nums[i]*(ps1-ss1);
            ll cost2 = (ss2 - ps2);
            
            ans = min(ans,cost1 + cost2);
            
        }
        
        return ans;
    }
    
};

/*

arr : 1 2 3 5
cost : 2 14 3 1
    
a b c d e
A B C D E

convert all the array elements into 'c'
    
(c-a)*A + (c-b)*B + (d-c)*D + (e-c)*E

= c * (A + B - D - E) + d*D + e*E - a*A - b*B



convert all the array elements into 'd'
    
(d-a)*A + (d-b)*B + (d-c)*C + (e-d)*E 

= d * (A + B + C - E) + e*E - c*C - b*B - a*A

 prefix1 = A, A+B, A+B+C, A+B+C+D
 prefix2 = A*a, A*a+B*b, A*a+B*b+C*c, 
 suffix1 = A+B+C+D, B+C+D, C+D, D
 suffix2 = A*a+B*b+C*c, B*b+C*c, C*c
 
 */
   