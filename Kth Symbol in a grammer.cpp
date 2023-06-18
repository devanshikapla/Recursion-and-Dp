#include <bits/stdc++.h> 
int kthValue(int n, int k) 
{
    // Write your code here.
    if(n == 1 && k == 1) return 1;
    int mid = pow(2 , n - 1)/2;
    if(k <= mid) return kthValue(n - 1 , k);
    else return !kthValue(n - 1 , k - mid);
}
