// ***Problem Desc***: given an arr of strings that can have any char in them. serialize to form a single message, make decoding logic too

/*
  **Solution path**:
    1. Cannot use a separator as it could be in string
    2. need to know the length somehow, split at so and so length
    3. lengths first? -> could be part of the string as well, won't work
    4. lengths after each word -> what if numbers part of the string too
    5. lengths (followed by a delimiter) before each word
*/

// ***Problem solution [encode: O(n) time, decode: O(n*l) time | O(1) space]***:
string encode(vector<string>& strs) {
     string encoded = "";
     for (auto s: strs) encoded += to_string(s.size()) + '*' + s;
     return encoded;
 }

 vector<string> decode(string s) {
     vector<string> ans;
     int last=0, i=0, nextLen=-1; 
     while (i<=s.size()) {
         if (nextLen==-1) {
             if (s[i]=='*') {nextLen = stoi(s.substr(last, i-last));}
             i++;
         } else {
             ans.push_back(s.substr(i, nextLen));
             i = last = i+nextLen;
             nextLen = -1;
         }
     } return ans;
 }
