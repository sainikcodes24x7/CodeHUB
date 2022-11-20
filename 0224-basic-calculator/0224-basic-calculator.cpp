class Solution {
private:
    // Operator precedence.
    static int prec(char ch) {
        switch (ch) {
            case '(':
                // Use the lowest because we handled this differently.
                return -1;

            case '+':
            case '-':
                return 0;

            case '*':
            case '/':
                return 1;

            case '_':
                // Use '_' for unary minus.
                return 2;
        }
        assert(false);
        return -1;
    }
    
    // Apply operators.
    static void apply(stack<int>& out, char op) {
        // Unary minus.
        if (op == '_') {
            out.top() *= -1;
            return;
        }

        const int right = out.top(); out.pop();
        const int left = out.top(); out.pop();
        switch (op) {
            case '+':
                out.push(left + right);
                break;
            case '-':
                out.push(left - right);
                break;
            case '*':
                out.push(left * right);
                break;
            case '/':
                out.push(left / right);
                break;
            default:
                assert(false);
        }
    }

public:
    static int calculate(string s) {
        // Handling unary '-' from wcipeg.com:
        // A minus sign is always binary if it immediately follows an operand
        // or a right parenthesis, and it is always unary if it immediately
        // follows another operator or a left parenthesis, or if it occurs at
        // the very beginning of the input. The algorithm must be modified in
        // order to distinguish between the two.

        // ... so we always push the last number
        s.push_back(' ');
        
        stack<int> out;
        stack<char> st;
        
        char prev = ' ';
        string num;
        for (char ch : s) {
            if (isdigit(ch)) {
                num.push_back(ch);
                prev = '1';
            } else {
                if (!empty(num)) {
                    out.push(stoi(num));
                    num.clear();
                }
                
                if (ch == ' ') continue;
                
                if (ch == '(') {
                    st.push('(');
                } else if (ch == ')') {
                    while (st.top() != '(') {
                        apply(out, st.top());
                        st.pop();
                    }
                    st.pop();
                } else {
                    // Unary minus.
                    if (ch == '-' && prev != '1' && prev != ')') {
                        ch = '_';
                    }
                    while (!empty(st) && prec(ch) <= prec(st.top())) {
                        apply(out, st.top());
                        st.pop();
                    }
                    st.push(ch);
                }

                prev = ch;
            }
        }
        
        while (!empty(st)) {
            apply(out, st.top());
            st.pop();
        }

        assert(size(out) == 1);
        return out.top();
    }
};