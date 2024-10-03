#include<bits/stdc++.h>
using namespace std;

#define lli long long
const lli someMax = (1LL * INT_MAX) + 1;
class MinStack {
    stack<lli> st;
    lli currMinElement;
    // stack<int> monSt;
public:
    MinStack() {
        currMinElement = someMax;
    }
    
    void push(int val) {
        if(st.empty()) {
            currMinElement = val;
            st.push(val);
        } else if(val < currMinElement) {
            lli newVal = 2*(1LL*val) - currMinElement;
            st.push(newVal);
            currMinElement = val;
        } else {
            st.push(val);
        }
    }
    
    void pop() {
       lli val = st.top();
       st.pop();
       if(st.empty()) {
            currMinElement = someMax;
            return;
       }
       if(val >= currMinElement) {
            return;
       }

        lli prevMin = 2 * (currMinElement) - val;
        currMinElement = prevMin;
        return;
    }
    
    int top() {
        if(st.top() < currMinElement) {
            return currMinElement;
        }
        return st.top();
    }
    
    int getMin() {
        return currMinElement;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */