class Solution {
public:
    int calculate(string s) {
        s.push_back(')');
        stack<int> st; st.push(1e9);

        bool minus = false;
        for (int i=0; i<s.size(); ++i) {
            char c = s[i];

            if (c == ' ' or c == '+') continue;
            if (c == '-') { minus = !minus; continue; }
            if (c == '(') {
                if (minus) st.push(-1e9);
                minus = 0; st.push(1e9);
                continue;
            }
            
            if (c == ')') {
                int num = st.top(); st.pop();
                while (st.top() != 1e9) {
                    num += st.top(); st.pop();
                } st.pop();
                
                if (!st.empty() and st.top() == -1e9) {
                    num = -num;
                    st.pop();
                }
                st.push(num);
            }

            else {
                int num = 0, j = i;
                while (j < s.size() and isdigit(s[j])) {
                    num *= 10;
                    num += s[j] - '0';
                    ++j;
                }
                
                if (!minus) st.push(num);
                else st.push(-num), minus = false;

                i = j-1;
            }
        }

        return st.top();
    }
};