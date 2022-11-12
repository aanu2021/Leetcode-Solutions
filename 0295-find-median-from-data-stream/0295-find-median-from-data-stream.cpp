class MedianFinder {
public:
    
    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        if(maxheap.size()==0){
            maxheap.push(num);
            return;
        }
        
        else if(maxheap.size()==minheap.size()){
            maxheap.push(num);
        }
        
        else{
            minheap.push(num);
        }
        
        if(maxheap.top() > minheap.top()){
                int ele1 = maxheap.top();
                maxheap.pop();
                int ele2 = minheap.top();
                minheap.pop();
                maxheap.push(ele2);
                minheap.push(ele1);
        }
        
    }
    
    double findMedian() {
        int m = maxheap.size();
        int n = minheap.size();
        if((m+n)%2){
            return (maxheap.top()*1.0);
        }else{
            return (maxheap.top()+minheap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */