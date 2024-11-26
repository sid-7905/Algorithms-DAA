#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string findLCS(vector<string> &X, vector<string> &Y) {
    int m = X.size(), n = Y.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = lcs + X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    reverse(lcs.begin(),lcs.end());
    return lcs;
}

vector<string> longestCommonSubsequence(vector<vector<string>> &grades)
{
    if (grades.empty())
        return {};
    vector<string> res;

    for (int i = 0; i < grades.size(); i++)
    {   
        for(int j = i + 1; j<grades.size(); j++){
            string lcs = findLCS(grades[i], grades[j]);
            res.push_back(lcs);
        }
    }
    return res;
}

int main()
{
    vector<string> arr_str = {
        "ABCDBCBBBCABDDBCBCCCDDBBBCBBFFBCDDCDABABCDBBABABBCBBBBCDABBCCCBCABABABABBBBCDDBC",
        "BCCCABCCCCCCBCCCFFBCCCABABAABBCCABBCBCBCABBBBBAAABAAAAABDDABBCBCABBCCCBBBBABBBCD",
        "ABBBCDFFBCCCBBAABBABBCDDABAABCABCCABABBBBCBBBBCDABBBCCBBDDABABABBCBCFFABBCBCBCDD",
        "DDABCCCCBCBBBCBCABBCAAABCDBCBCBCBBABBCBCCCABABBBBBBBABBBABBBCDABBBBBBBBCCCABBCFF",
        "BBBCCDBCDDAABBCCABABBCAABBCDABBCABCCDDAAABBCCCABABABBCBBBCCDBCCCCDABBCBCBBCDCDBB",
        "BCABABCCDDDDBBCCCCBBCCBBCCBBBBCDBBBCABBBBBABCCBBABBBBCABDDABCCCCABAAAABCBCCCBBBC",
        "ABABBCCDBCBBCCBCBCABDDBCCCBCBBBBABABABBBBCABCCBBCDCCBCBBBBAABBABABBBCCDDCDBCBCCC",
        "CDCDCDBBCDBBAACDBCBCABBCABBCDDBCCDBBBCCDDDCDCCCCBCABCCCDBBBCDDCCBBAABCBBBCCDCDDD",
        "CCBBABBBCCABABABCDBBBBCDBBBCCDFFBCCCBBAABCBBABABBCABBBCCABDDABBBBBABBCBBBBBCBBBC",
        "ABCCDDBBBBCCCCBBCCBCBCBBCCBBCCCDBBBCABABBBBCBBABCDAABBABAABCCCBBABCCDDBBBBCCBCCD",
        "ABABCDABBCBBBCBCCCABBCDDBCABABBBABCCABCDABABABCDABBBCCCDBCDDCCABABCCBBBBABABBBBC",
        "BCABBBBCABBCCCCDDDBBBCBBCCBBBCBCBCABBBBCABBCCDCDBCBBABCCABDDBCBCBBCDBBABCCCDCCAB",
        "DDDDBBBBAABCBCBBBCBBBCBCCCFFABABBBCCABBCCCCCAADDBBBBCCCCCCCCABBCABBBCCDDABBBCDBC",
        "CDABBBBCDDBCCDCCBBBBCDABABCCBCBCAABBBCFFBCCDBCBCAABBCDBBFFBCBBBCABBBDDCCBBABCDCC",
        "BBABBBDDBCBBCCBCABBBABBBDDBBABBCBCBBCCABBBABCCBCCCABBCBCABCCBCBCBCAABBBBCDCDDDAB",
        "BCBCCDCCCDCDDDABBBBCBBCDCCBCABDDBBBCCCABCCCCBCBCABCCBCCCBBABBBBBBBCCAABBCCABBCBC",
        "ABBBBBBBBBDDBCBCBCCCBBCDCCBCCCBBCCBBBCBCBBBCCDAACDBCABCCCCAACDABBCCCABCCBBABBBCC",
        "BCDDABCDCCDDABABBCBBBCCDBBBBCCBCABABCCBBCCBCBCABBCCCBBBCAAAAABABBCBBBBCCCCDDBCAB",
        "ABBBABFFCDBBCDBCFFDDBCCCBBDDBCCCCDBBABABAACCDDBBBBCDBCABAADDABDDABCDCDBCABBCBCAB",
        "BCBBCDABABBCCDBCBBABBCBBBCABBBABCCBCABBCCCABBCCDBBBCABCDBBBBBCFFBBAAABBCBCBCABBC"};

    vector<vector<string>> grades;

    for(int i = 0;i<arr_str.size(); i++){
        string s = arr_str[i];
        vector<string> v;
        for(int j = 0; j<s.size(); j+=2){
            v.push_back(s.substr(j,2));
        }
        grades.push_back(v);
    }


    vector<string> result = longestCommonSubsequence(grades);
    int index = 0;
    for (int i = 0; i < grades.size(); i++)
    {   
        for(int j = i + 1; j<grades.size(); j++){
           cout<<"LCS of the string "<<i+1<<" and "<<j+1<<" is: "<<result[index++]<<endl;
        }
    }

    return 0;
}
