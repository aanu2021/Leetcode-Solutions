class MedianFinder {
public:
    
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    
    MedianFinder() {
        while(!maxHeap.empty()){
            maxHeap.pop();
        }
        while(!minHeap.empty()){
            minHeap.pop();
        }
    }
    
    void addNum(int num) {
        if(maxHeap.size() == 0){
            maxHeap.push(num);
            return;
        }
        if(maxHeap.size() == minHeap.size()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }
        if(maxHeap.top() > minHeap.top()){
            int ele1 = maxHeap.top(); maxHeap.pop();
            int ele2 = minHeap.top(); minHeap.pop();
            maxHeap.push(ele2);
            minHeap.push(ele1);
        }
    }
    
    double findMedian() {
        int sz = maxHeap.size();
        sz += minHeap.size();
        if(sz%2){
            return 1.0*maxHeap.top();
        }
        else{
            return (maxHeap.top() + minHeap.top())/2.0;
        }
    }
};
