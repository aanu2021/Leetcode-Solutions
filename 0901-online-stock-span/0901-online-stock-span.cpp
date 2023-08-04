class StockSpanner {
public:
    
    stack<pair<int,int>>S;
    int index;
    
    StockSpanner() {
       S.push({10000000,-1}); 
       index = 0;    
    }
    
    int next(int price) {
        while(!S.empty() && S.top().first <= price){
            S.pop();
        }
        int total = index - S.top().second;
        S.push({price, index});
        index++;
        return total;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */