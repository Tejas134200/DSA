class Solution {
public:
    string addBinary(string a, string b) {
        int sa = a.size();
        int sb = b.size();
        string ans;
        int carry = 0;
        int i = sa - 1, j = sb - 1;

        // Process both strings from the end to the beginning
        while (i >= 0 || j >= 0 || carry > 0) {
            int bitA = (i >= 0) ? (a[i--] - '0') : 0;
            int bitB = (j >= 0) ? (b[j--] - '0') : 0;

            int sum = bitA + bitB + carry;
            ans.push_back((sum % 2) + '0'); // Append the result of the current bit
            carry = sum / 2;               // Update the carry
        }

        // The result is in reverse order; reverse it to get the correct answer
        reverse(ans.begin(), ans.end());
        return ans;
    }
};