class Solution {
public:
    int precedence (char x) {
        if (x == '+' || x == '-') {
            return 1;
        } else if (x == '/' || x == '*') {
            return 2;
        }
        return 0;
    }
    void solve (stack<int> &stk, stack<char> &op) {
        int x = stk.top();
        stk.pop();
        int y = stk.top();
        stk.pop();
        char o = op.top();
        op.pop();
        if (o == '+') stk.push(y + x);
        if (o == '-') stk.push(y - x);
        if (o == '*') stk.push(y * x);
        if (o == '/') stk.push(y / x);
        return;
    }
    int calculate(string s) {
        stack<int> stk;
        stack<char> op;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            if (c == ' ') {
                continue;
            }
            if (isdigit(c)) {
                int n = 0;
                while (i < s.length() && isdigit(s[i])) {
                    n = n * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                stk.push(n);
            } else if (c == '('){
                op.push(c);
            } else if (c == ')') {
                while (!op.empty() && op.top() != '(') {
                    solve(stk, op);
                }
                op.pop();
            } else {
                while (!op.empty() && precedence(op.top()) >= precedence(c)) {
                    solve(stk, op);
                }
                op.push(c);
            }
        }
        while (!op.empty()) {
            solve(stk, op);
        }
        return stk.top();
    }

};