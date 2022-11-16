/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    
    typedef long long ll;
    
    int guessNumber(int n) {
        
        ll low = 1, high = n;
        
        while(low<=high){
            
            ll mid = (low + high)/2;
            
            int curr = guess(mid);
            
            if(curr==0){
                return mid;
            }
            
            else if(curr==1){
                low = mid+1;
            }
            
            else{
                high = mid-1;
            }
            
        }
        
        return -1;
        
    }
};