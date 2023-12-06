class Solution {
public:
    
    int fun(int num){
        return ((num*(num+1))/2);
    }
    
    int totalMoney(int n) {
        int num_of_weeks = (n/7);
        int rem_of_days = (n%7);
        int sum = (num_of_weeks*28);
        sum += (7*fun(num_of_weeks-1));
        int first_date_value = num_of_weeks + 1;
        for(int i=1;i<=rem_of_days;i++){
            sum += first_date_value++;
        }
        return sum;
    }
};
