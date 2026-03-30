class Solution {
public:
    vector<string> split(string s, char delimit) {
        vector<string> res;
        stringstream ss(s);
        string token;
        while (getline(ss, token, '%')) {
            res.push_back(token);
        }
        return res;
    }
    string resolve(string key, unordered_map<string, string> &map, unordered_map<string, string>& resolved) {
        if (resolved.count(key)) return resolved[key];
        string val = map[key];
        if (val.find('%') == string::npos) {
            resolved[key] = val;
            return val;
        }
        vector<string> parts = split(val, '%');
        string res;
        for (int i = 0; i < parts.size(); i++) {
            if (i % 2 == 0) {
                res += parts[i];
            } else {
                res += resolve(parts[i], map, resolved);
            }
        }
        resolved[key] = res;
        return res;
    }

    string applySubstitutions(vector<vector<string>>& replacements, string text) {
       unordered_map<string, string> map; 
       for (vector<string> r : replacements) {
            map[r[0]] = r[1];
       }
       unordered_map<string, string> resolved;
       for (auto [key, value] : map) {
            resolve(key, map, resolved);
       }
       string res = "";
       vector<string> parts = split(text, '%');
       for (int i = 0; i < parts.size(); i++) {
            if (i % 2 == 0) {
                res += parts[i];
            } else {
                res += resolved[parts[i]];
            }
       }
       return res;
    }
};
