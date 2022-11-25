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
        
        vector<pair<ll,ll>>vec(n);
        
        for(int i=0;i<n;i++){
            vec[i]={nums[i],cost[i]};
        }
        
        sort(vec.begin(),vec.end());
        
        vector<ll>prefix1(n,0LL);
        vector<ll>prefix2(n,0LL);
        vector<ll>suffix1(n,0LL);
        vector<ll>suffix2(n,0LL);
        
        prefix1[0]=vec[0].second;
        prefix2[0]=vec[0].second*vec[0].first;
        suffix1[n-1]=vec[n-1].second;
        suffix2[n-1]=vec[n-1].second*vec[n-1].first;
        
        for(int i=1;i<n;i++){
            
            prefix1[i] = prefix1[i-1];
            prefix2[i] = prefix2[i-1];
            
            prefix1[i] += vec[i].second;
            prefix2[i] += (vec[i].second*vec[i].first);
            
        }
        
        for(int i=n-2;i>=0;i--){
            
            suffix1[i] = suffix1[i+1];
            suffix2[i] = suffix2[i+1];
            
            suffix1[i] += vec[i].second;
            suffix2[i] += (vec[i].second*vec[i].first);
            
        }
        
        ll ans = LONG_MAX;
        
        for(int i=0;i<n;i++){
            
            ll curr_cost = 0LL;
            
            if(i>0){
                
                curr_cost += ((vec[i].first*prefix1[i-1]) - prefix2[i-1]);
                
            }
            
            if(i<n-1){
                
                curr_cost += (suffix2[i+1] - (vec[i].first*suffix1[i+1]));
                
            }
            
            ans = min(ans,curr_cost);
            
        }
        
        return ans;
        
    }
};
   