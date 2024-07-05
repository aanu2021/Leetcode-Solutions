class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        int minDistance = INT_MAX;
        int maxDistance = INT_MIN;
        
        int index = 1, previousNodeValue = head->val;
        int prevCritical = -1, firstCritical = -1, lastCritical = -1;
        
        ListNode * ptr = head->next;
        while(ptr && ptr->next){
            if((ptr->val > previousNodeValue && ptr->val > ptr->next->val) || (ptr->val < previousNodeValue && ptr->val < ptr->next->val)){
                if(firstCritical == -1) firstCritical = index;
                if(prevCritical != -1) minDistance = min(minDistance, index - prevCritical);
                prevCritical = index;
                lastCritical = index;
            }
            previousNodeValue = ptr->val;
            ptr = ptr->next;
            index++;
        }
        maxDistance = lastCritical - firstCritical;
        if(minDistance == 0 || minDistance == INT_MAX) return {-1,-1};
        else return {minDistance, maxDistance};
    }
};