// ***Problem Desc***: given a string with digit chars, produce possible strings using the num pad on old phones
// ***Sol [O(n.4<sup>n</sup>) time | O(n) space]***:
unordered_map<char, string> numMap;
void backtrack(string &code, int di, string &digits, vector<string>& ans) {
    if (di == digits.size()) {ans.push_back(code); return;}
    char num = digits[di];
    for(auto c: numMap[num]) {code += c; backtrack(code, di+1, digits, ans); code.pop_back();}
}
vector<string> letterCombinations(string digits) {
    vector<string> ans; if (!digits.size()) return ans; string code="";
    numMap['2'] = "abc"; numMap['3'] = "def"; numMap['4'] = "ghi"; numMap['5'] = "jkl";
    numMap['6'] = "mno"; numMap['7'] = "pqrs"; numMap['8'] = "tuv"; numMap['9'] = "wxyz";
    backtrack(code, 0, digits, ans);
    return ans;
}
