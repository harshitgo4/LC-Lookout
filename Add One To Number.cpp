#include <bits/stdc++.h> 
vector<int> addOneToNumber(vector<int> arr)
{
    // Write your code here
   int n = arr.size();
    int num = arr[n - 1];
    vector<int> ans;
    int i = 0;

    while (i < n && arr[i] == 0) {
        i++;
    }

    if (i == n) {
        ans.push_back(1);
        return ans;
    }

    if (num != 9) {
        arr[n - 1] = ++num;
        while (i < n) {
            ans.push_back(arr[i]);
            i++;  // Increment i inside the loop
        }
    } else {
        int index = n - 1;
        while (index >= i && arr[index] == 9)
            index--;

        if (index < i) {
            ans.push_back(1);
            while (i < n)
            {
                ans.push_back(0);
                i++;
            }
        } else {
            arr[index]++;
            while (i <= index)
                ans.push_back(arr[i++]);
                index++;
            while (index < n) {
                ans.push_back(0);
                index++;
            }
        }
    }
    return ans;
}

