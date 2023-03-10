#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        int a = arr[i];
        int target = K - a;
        int s = i + 1, e = n - 1;
        while (s < e)
        {
            if (arr[s] + arr[e] == target)
            {
                ans.push_back({arr[i], arr[s], arr[e]});
                while (s < e && arr[s] == arr[s + 1])
                    s++;
                while (s < e && arr[e] == arr[e - 1])
                    e--;
                s++;
                e--;
            }
            else if (arr[s] + arr[e] > target)
                e--;
            else
                s++;
        }
        while (i + 1 < n && arr[i] == arr[i + 1])
            i++;
    }
    return ans;
}