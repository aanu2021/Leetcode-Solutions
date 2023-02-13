class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2){
            if(high%2==0){
                return 1 + ((high-low)/2);
            }
            else{
                return 1 + ((high-low)/2);
            }
        }
        else{
            if(high%2==0){
                return  ((high-low)/2);
            }
            else{
                return 1 + ((high-low)/2);
            }
        }
    }
};


    
    