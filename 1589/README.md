# Solution
## Question

We have an array of integers, nums, and an array of requests where requests[i] = [starti, endi]. The ith request asks for the sum of nums[starti] + nums[starti + 1] + ... + nums[endi - 1] + nums[endi]. Both starti and endi are 0-indexed.

**Return the maximum total sum of all requests among all permutations of nums**.

Since the answer may be too large, return it modulo 109 + 7.

## Constrains
- n == nums.length
- 1 <= n <= 10^5
- 0 <= nums[i] <= 10^5
- 1 <= requests.length <= 10^5
- requests[i].length == 2
- 0 <= starti <= endi < n

## Example
```
Input: nums = [1,2,3,4,5], requests = [[1,3],[0,1]]
Output: 19
Explanation: One permutation of nums is [2,1,3,4,5] with the following result: 
requests[0] -> nums[1] + nums[2] + nums[3] = 1 + 3 + 4 = 8
requests[1] -> nums[0] + nums[1] = 2 + 1 = 3
Total sum: 8 + 3 = 11.
A permutation with a higher total sum is [3,5,4,2,1] with the following result:
requests[0] -> nums[1] + nums[2] + nums[3] = 5 + 4 + 2 = 11
requests[1] -> nums[0] + nums[1] = 3 + 5  = 8
Total sum: 11 + 8 = 19, which is the best that you can do.
```

## Analysis
- 題目分析
    - 求出所有permutation中最大的request total sum
    - n <= 10^5 ==> sol 要在 O(NlogN), 列舉所有permutation來找會TLE

- **among all permutations of nums**
    - 可以任意擺放nums中的數字

- 如何找到最大的request total request sum
    - reuqest sum: [starti, endi] index區間 對應的nums和
    - 使total request sum最大
        - frequency map among all requests
        - 最大frequency 乘上nums中最大值
        - 2nd大frequency 乘上nums中2nd大值
        - ...
- 計算frequency map
    - Brute force: 每個區間都掃一次並記錄==> O(N^2)會TLE
    - prefix sum + sorting ==> O(NlogN)
        - request 區間[start, end] 可以記錄在一個vector v[start]+= 1, v[end+1]+=-1
        - prefix sum 就是該index 需要被加的次數
    <img src="https://github.com/n3k0fi5t/LeetCode/blob/master/1589/1589.png" width="47%" height="47%">

- time complexity: O(NlogN)
- space complexity: O(N)
