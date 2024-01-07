class Solution {
public:
    string addBinary(string a, string b) 
    {
        string result;
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        while(i >= 0 || j >= 0 || carry)
        {
            int numA = (i >= 0) ? a[i--] - '0' : 0,
                numB = (j >= 0) ? b[j--] - '0' : 0;
            
            int sum = numA + numB + carry;
            carry = sum / 2;
            result += (sum % 2) + '0';
        }
        
        reverse(begin(result), end(result));
        return result;
    }
};