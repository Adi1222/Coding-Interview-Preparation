/*
High school student Vasya got a string of length n as a birthday present. This string consists of letters 'a' and 'b' only. Vasya denotes beauty of the string as the maximum length of a substring (consecutive subsequence) consisting of equal letters.

Vasya can change no more than k characters of the original string. What is the maximum beauty of the string he can achieve?

Input
The first line of the input contains two integers n and k (1 ≤ n ≤ 100 000, 0 ≤ k ≤ n) — the length of the string and the maximum number of characters to change.

The second line contains the string, consisting of letters 'a' and 'b' only.

Output
Print the only integer — the maximum beauty of the string Vasya can achieve by changing no more than k characters.
*/



#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

char arr[100005];

void solve(int n, int k)
{
    unordered_map<char, int> mp; // char and its count

    int left = 0;
    int max_length = 0;
    int max_count_of_repeating_char = 0;

    for (int right = 0; right < n; right++)
    {
        mp[arr[right]]++;

        max_count_of_repeating_char = max(max_count_of_repeating_char, mp[arr[right]]);

        while (right - left + 1 - max_count_of_repeating_char > k)
        {
            mp[arr[left]]--;
            left += 1;

            if (max_count_of_repeating_char == mp[arr[left - 1]])
            {
                max_count_of_repeating_char = -1;
            }
        }

        max_length = max(max_length, right - left + 1);
    }

    cout << max_length << endl;

    return;
}

int main()
{
    // your code goes here
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; //
    //cin>>t;

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    solve(n, k);

    return 0;
}
