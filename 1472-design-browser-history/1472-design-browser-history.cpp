class BrowserHistory {
public:
    
    string current;
    stack<string>history;
    stack<string>future;
    
    BrowserHistory(string homepage) {
        current = homepage;
        while(!history.empty()) history.pop();
        while(!future.empty()) future.pop();
    }
    
    void visit(string url) {
        history.push(current);
        current = url;
        while(!future.empty()) future.pop();
    }
    
    string back(int steps) {
        while(steps > 0 && !history.empty()){
            future.push(current);
            current = history.top();
            history.pop();
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        while(steps > 0 && !future.empty()){
            history.push(current);
            current = future.top();
            future.pop();
            steps--;
        }
        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
  
 
 /*

 visit visit visit visit back forward   
   
 b      c     d     e     2    1 
 
 history = a b c 
 
 future = e 
 
 current = d
 
 */
 