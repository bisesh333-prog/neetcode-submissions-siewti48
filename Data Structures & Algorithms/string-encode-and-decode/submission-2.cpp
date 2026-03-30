class Solution {
public:
    string encode(vector<string>& strs) {
        string s = "";
        for (auto &it : strs) {
            s += to_string(it.size()) + "#" + it;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            // 1️⃣ Find the delimiter #
            int j = i;
            while (s[j] != '#') j++;

            // 2️⃣ Extract the length
            int len = stoi(s.substr(i, j - i));

            // 3️⃣ Extract the actual string
            string temp = s.substr(j + 1, len);

            ans.push_back(temp);

            // 4️⃣ Move to next encoded string
            i = j + 1 + len;
        }
        return ans;
    }
};
