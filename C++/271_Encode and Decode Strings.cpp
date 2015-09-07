class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (int i = 0; i < strs.size(); i++) {
            int l = (int)strs[i].length();
            res += to_string(l) + "@" + strs[i];
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int p = 0;
        while (p < s.length()) {
            int nt = (int)s.find_first_of("@", p);
            int l = stoi(s.substr(p, nt - p));
            res.push_back(s.substr(nt + 1, l));
            p = nt + l + 1;
        }
        return res;
    }
};