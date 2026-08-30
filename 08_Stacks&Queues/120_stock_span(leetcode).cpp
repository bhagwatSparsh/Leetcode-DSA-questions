class StockSpanner {
public:
    stack<pair<int, int>> st; // pair in stack of {price, span}
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1; // span of every price is 1 by default;
        while( !st.empty() && st.top().first <=price){
            span=span+st.top().second;
            st.pop();

        }
        st.push({price, span});
        return span;

        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */