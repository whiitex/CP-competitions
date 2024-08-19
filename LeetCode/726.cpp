class Solution {
public:
    string countOfAtoms(string s) {
        queue<string> que;
        for (int i=s.size()-1; i>=0; --i) {

            // number / '('
            int num = 0, dec = 1;
            if (isdigit(s[i])) {
                while (isdigit(s[i])) {
                    num += dec * int(s[i] - '0');
                    dec *= 10;
                    --i;
                }
                que.push(to_string(num));
            } else if (!isdigit(s[i]) and s[i] != '(')
                que.push("1");
            else if (s[i] == '(') {
                que.push("(");
                continue;
            }

            // element or ')'
            if (s[i] == ')') {
                que.push(")");
                continue;
            } else {
                string element;
                while (i>=0 and !isdigit(s[i]) and s[i] != ')' and s[i] != '(') {
                    element.push_back(s[i]);
                    if (isupper(s[i--])) break;
                } ++i;
                reverse(element.begin(), element.end());
                que.push(element);
            }
        }
/*
        while (!que.empty()) {
            cout << que.front() << ' ';
            que.pop();
        }
*/
        map<string, int> mp;
        int mul = 1;
        stack<int> mults;

        while (!que.empty()) {
            string num_str = que.front(); que.pop();
            if (num_str == "(") {
                mul /= mults.top();
                mults.pop();
                continue;
            }

            string el = que.front(); que.pop();
            int num = 0;
            int dec = 1;
            for (int i=num_str.size()-1; i>=0; --i) {
                num += int(num_str[i] - '0') * dec;
                dec *= 10;
            }

            if (el == ")") {
                mults.push(num);
                mul *= num;
            } else mp[el] += num * mul;
        }

        string ans;
        for (auto p: mp) {
            // cout << p.first << ' ';
            for (char c: p.first) ans.push_back(c);
            // cout << p.second << ' ';
            if (p.second == 1) continue;
            for (char c: to_string(p.second)) ans.push_back(c);
        }

        return ans;
    }
};