#include <stack>

using namespace std;

class MinStack {
private:
    stack<long long> st;
    long long min_val;
public:
    MinStack() {}
    void push(int val) {
        long long value = val;
        if (st.empty()) {
            st.push(value);
            min_val = value;
        } else if (value < min_val) {
            st.push(2 * value - min_val);
            min_val = value;
        } else {
            st.push(value);
        }
    }
    void pop() {
        if (st.empty()) return;
        if (st.top() < min_val) {
            min_val = 2 * min_val - st.top();
        }
        st.pop();
    }
    int top() {
        if (st.top() < min_val) return (int)min_val;
        return (int)st.top();
    }
    int getMin() {
        return (int)min_val;
    }
};