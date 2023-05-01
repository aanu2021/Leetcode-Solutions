class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        int maxi = *max_element(salary.begin(),salary.end());
        int mini = *min_element(salary.begin(),salary.end());
        int sum = accumulate(salary.begin(),salary.end(),0);
        sum -= maxi;
        sum -= mini;
        return (sum*1.0)/(n-2);
    }
};