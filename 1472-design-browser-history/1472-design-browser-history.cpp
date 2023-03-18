class BrowserHistory {
public:
    
    stack<string>history, future;
    string current;
    
    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        history.push(current);
        current = url;
        while(!future.empty()){
            future.pop();
        }
    }
    
    string back(int steps) {
        while(steps > 0 && !history.empty()){
            future.push(current);
            current = history.top();
            history.pop();
            // future.push(current);
            steps--;
        }
        return current;
    }
    
    string forward(int steps) {
        while(steps > 0 && !future.empty()){
            history.push(current);
            current = future.top();
            future.pop();
            // history.push(current);
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
                   