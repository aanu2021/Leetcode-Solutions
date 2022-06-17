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
        
        if(maxheap.size()==minheap.size()){
            
            if(minheap.top()>=num){
                maxheap.push(num);
            }
            
            else{
                maxheap.push(minheap.top());
                minheap.pop();
                minheap.push(num);
            }
            
        }
        
        else{
            
            if(maxheap.top()<=num){
                minheap.push(num);
            }
            
            else{
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(num);
            }
            
        }
        
    }
    
    double findMedian() {
        
        int m=maxheap.size();
        int n=minheap.size();
        
        if((m+n)%2!=0){
            return maxheap.top()*1.0;
        }
        
        else{
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