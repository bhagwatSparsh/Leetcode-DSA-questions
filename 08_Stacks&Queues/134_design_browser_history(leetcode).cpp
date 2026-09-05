class BrowserHistory {
public:
    stack<string> past;
    stack<string> future;
    string curr; // it is imp as it is what we display

    BrowserHistory(string homepage) {
        // currently kaha pe hu mai(which homepage)
        curr=homepage;
        
        
    }
    
    void visit(string url) {
        // if we visit a new webpage so remove forward history
        past.push(curr);
        curr=url;

        future=stack<string>(); // assign stack to clear it

        
        
    }
    
    string back(int steps) {
        while (steps>0 && !past.empty()){
            future.push(curr); // store in future the currn calue for frd reference
            curr=past.top(); // currn now becomes st.top
            past.pop();
            steps--; // dec steps


            
        }
        return curr;

        
    }
    
    string forward(int steps) {
        while(steps>0 && !future.empty()){
            past.push(curr);
            curr=future.top();
            future.pop();
            steps--;
        }
        return curr;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */