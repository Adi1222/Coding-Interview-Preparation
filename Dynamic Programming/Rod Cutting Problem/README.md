### Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces

#### Approach:  Recursive Relation:  cutRod(n) = max(price[i] + cutRod(n-i-1)) for all i in {0, 1 .. n-1}  
####           T.C: O(n^n)  

#### Optimal Approach: Considering the overlapping problems, let dp[i] be the max profit obtained for a rod of length i for each 1 <= i <= n , 
#### It uses value of smaller values of i already computed.
#### T.C : 0(N^2)
