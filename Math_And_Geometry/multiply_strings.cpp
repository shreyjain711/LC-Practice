// ***Problem Desc***: given two large nums in string form, multiply them

// ***Multiply digitwise, i from n1-1..0, j n2-1..0, in the ans string, we make it n1+n2 of 0s init and then ans[i+j+1] gets mul result unit, carry in ans[i+j] [O(n1.n2) time | O(n1+n2) space]***:
string multiply(string num1, string num2) {
    int n1=num1.size(), n2=num2.size(); string ans(n1+n2, '0'); 
    for (int i=n2-1; ~i; --i) {
        for (int j=n1-1; ~j; --j) {
            int sum = (num2[i]-'0') * (num1[j]-'0') + (ans[i+j+1] - '0');
            ans[i+j+1] = sum%10 + '0'; ans[i+j] += sum/10;
        }
    } int i=0; while (i<n1+n2 && ans[i++] == '0'); i--; return ans.substr(i);
}
