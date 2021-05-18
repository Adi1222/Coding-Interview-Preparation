#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{

    string str = "cbaebabacd";
    string pat = "abc";

    map<char, int> mpat;
    map<char, int> mstr;

    for (char c : pat)
    {
        mpat[c]++;
    }

    int cnt = 0;

    int patlen = mpat.size();

    for (int i = 0; i < patlen; i++)
    {
        mstr[str[i]]++;
    }

    int l = 0, r;

    vector<int> ans;

    for (r = patlen; r < str.length(); r++)
    {
        if (mstr == mpat)
        {
            cnt += 1;
            ans.push_back(l);
        }

        mstr[str[r]]++;

        mstr[str[r - patlen]]--; // or mstr[str[l]]--;

        if (mstr[str[r - patlen]] == 0)
        {
            mstr.erase(str[r - patlen]);
        }

        l++;
    }

    if (mstr == mpat)
    {
        ans.push_back(l);
        cnt += 1;
    }

    cout << cnt << " " << endl;

    return 0;
}