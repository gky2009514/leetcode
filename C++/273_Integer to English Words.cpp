class Solution {
public:
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        string res = "";
        if (num >= 1000000000) {
            res += getRep(num / 1000000000);
            res += "Billion ";
            num %= 1000000000;
        }
        if (num >= 1000000) {
            res += getRep(num / 1000000);
            res += "Million ";
            num %= 1000000;
        }
        if (num >= 1000) {
            res += getRep(num / 1000);
            res += "Thousand ";
            num %= 1000;
        }
        if (num > 0)
            res += getRep(num);
        return res.substr(0, res.length() - 1);
    }

private:
    vector<string> ones = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> ten_to_twe = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen",
        "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string getRep(int num) {
        string res = "";
        if (num == 0)
            return res;
        if (num >= 100) {
            res += ones[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num >= 20) {
            res += tens[num / 10] + " ";
            num %= 10;
        } else if (num >= 10) {
            res += ten_to_twe[num - 10] + " ";
            return res;
        }
        if (num > 0)
            res += ones[num] + " ";
        return res;
    }
};