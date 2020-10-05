# Contains Duplicate III
### Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

T.C: O(Nlog(K))  as set is used which uses BST.
1. sorting, adding, deletion takes log(N) time in set/ordered map
2. as we have at most k elements present in the set at any time, T.C will be N*log(k), where N is size of array.
