#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s1 = "anagram";
    string s2 = "grammar";

    int k = 3;

    map<char, int> mp1;
    map<char, int> mp2;

    for (char c : s1)
    {
        mp1[c]++;
    }

    for (char c : s2)
    {
        mp2[c]++;
    }

    int cnt = 0;

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (mp1[ch] > mp2[ch])
        {
            cnt += (mp1[ch] - mp2[ch]);
        }
    }

    if (cnt <= k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}