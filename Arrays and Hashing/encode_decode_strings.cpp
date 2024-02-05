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
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string encode(vector<string> strs) {
    string encoded = "";
    for (auto str : strs) encoded += (to_string(str.length()) + '*' + str);
    return encoded;
}

vector<string> decode (string encoded) {
    vector<string> strs;
    int i = 0, j = 0;
    while (i<encoded.length()) {
        while (encoded[j] != '*') j++;
        int len = stoi(encoded.substr(i, j-i));
        strs.push_back(encoded.substr(j+1, len));
        i = j+len+1;
        j = i;
    }
    return strs;
}


int main() {
    vector<string> strs = {"Hello", "world!26*"};
    for (auto s: strs) cout << s << " ";
    
    cout<<endl<<encode(strs)<<endl;
    
    strs = decode(encode(strs));
    for (auto s: strs) cout << s << " ";

    return 0;
}
