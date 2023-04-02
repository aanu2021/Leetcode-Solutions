class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int>pq;
        int minValue = INT_MAX;
        int minEle = INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]%2){
                nums[i] *= 2;
            }
        }
        for(int i=0;i<n;i++){
            minEle = min(minEle,nums[i]);
        }
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(!pq.empty() && pq.top()%2==0){
            int ele = pq.top(); pq.pop();
            minValue = min(minValue,ele-minEle);
            pq.push(ele/2);
            minEle = min(minEle,(ele/2));
        }
        minValue = min(minValue,pq.top()-minEle);
        return minValue;
    }
};

/*

1 3 4 5  20
2 4 6 10 20

2 4 6 10 10
2 4 5 6 10
2 4 5 5 6
2 4 3 5 5   

odd -> odd*2   (to increase a number)
even -> even/2 (to decrease a number)

a1 a2 a3 a4 a5 a6

now let say a is sorted in non-decreasing order.
to minimize the deviation we need to increase a1 and decrease a6.

But for that we need to figure out the current maximum and minimum element in the array. As after every performed operation maximum and minimum elements may get changed.

Still figuring out current maximum or current minimum element in the array is easy  (we can use maxheap / minheap).

But dealing with both maximum and minimum is indeed a difficult job.

is there any way to convert this problem into a one way traffic (where we need to find out the current maximum or current minimum only).

definitely we can do so. 

see once we are using our operation (1) [odd -> 2*odd] , odd element changes into an even number , and after that we can not use operation no 1 on an even element. 

So our first target would be change all the odd elements into an even number. Such that we have to deal with only one type of operation (2) [even -> even/2].

b : [b1 b2 b3 b4 b5 b6]

check the current maximum element in the array , i.e b6 , if it is even , divide it by 2 , and insert it into the maxheap.
    
*/