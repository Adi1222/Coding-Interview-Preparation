#include <iostream>
#include <map>
using namespace std;

// Optimal way: use only one map

int main()
{
    string s1 = "geeks";
    string s2 = "eggkf";

    int k = 1;

    map<char, int> mp;

    for (char c : s1)
    {
        mp[c]++;
    }

    for (char c : s2)
    {
        if (--mp[c] <= 0)
        {
            mp.erase(c);
        }
    }

    if (mp.size() <= k)
    {
        cout << "YES"
             << " " << endl;
    }
    else
    {
        cout << "NO"
             << " " << endl;
    }

    return 0;
}