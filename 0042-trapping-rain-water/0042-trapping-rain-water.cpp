class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0, leftHeight = 0, rightHeight = 0;
        int left = 0, right = n-1;
        while(left <= right){
            if(height[left] <= height[right]){
                leftHeight = max(leftHeight, height[left]);
                total += (leftHeight - height[left]);
                left++;
            }
            else{
                rightHeight = max(rightHeight, height[right]);
                total += (rightHeight - height[right]);
                right--;
            }
        }
        return total;
    }
};