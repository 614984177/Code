#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class MinStack 
{
public:
    /** initialize your data structure here. */
    stack<pair<int, int>> sta;
    MinStack() 
    {
        while (!sta.empty()) sta.pop();
    }
    
    void push(int x) 
    {
        if (sta.empty()) sta.emplace(x, x);
        else sta.emplace(x, min(x, sta.top().second));
    }
    
    void pop() 
    {
        sta.pop();
    }
    
    int top() 
    {
        return sta.top().first;
    }
    
    int getMin() 
    {
        return sta.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main()
{

    return 0;
}
/*

*/