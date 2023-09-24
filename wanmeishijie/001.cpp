/*
输入两个字符串a,b。字符串内容为二进制数字，求两个字符串相加的结果，
加法计算方法以二进制方法计算，返回对应的字符串结果。字符串长度不超过100。
示例：
输入：“1101”， “1100”
输出：“11001”
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string addBinaryStrings(string s1, string s2) {
    string result;
    int carry = 0;
    int i = s1.length() - 1;
    int j = s2.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;

        if (i >= 0) {
            sum += s1[i] - '0';
            i--;
        }

        if (j >= 0) {
            sum += s2[j] - '0';
            j--;
        }

        carry = sum / 2;
        int digit = sum % 2;
        result.push_back(digit + '0'); // 转化为字符串
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string s1, s2;
    cout << "请输入两个二进制字符串：" << endl;
    cin >> s1 >> s2;

    string result = addBinaryStrings(s1, s2);

    cout << "相加结果为：" << result << endl;

    return 0;
}