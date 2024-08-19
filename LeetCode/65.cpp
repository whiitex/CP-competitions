class Solution {
public:
    bool isNumber(string s) {
        bool needadigit = false;
        bool first = true;
        bool second = false;
        bool third = false;
        for (int i=0; i<s.length(); ++i) {

            if (i == 0) {
                if (s[0] == '+' or s[0] == '-') {
                    needadigit = true;
                } else if (s[0] == '.') {
                    second = true; first = false;
                    needadigit = true;
                } else if (!isdigit(s[0]))
                    return false;
                continue;
            }

            if (isdigit(s[i])) {
                if (first or second) {
                    needadigit = false; continue;
                } else third = false; needadigit = false; continue;
            }

            if (s[i] == '.' and first) {
                first = false; second = true; continue;
            }

            if ((first or second) and (s[i] == 'e' or s[i] == 'E') and !needadigit) {
                first = false; second = false; third = true;
                needadigit = true; continue;
            }

            if (third and (s[i] == '+' or s[i] == '-')) {
                needadigit = true; third = false; continue;
            }

            return false;
        }

        return !needadigit;
    }
};