#include <stdio.h>
#include <limits.h>

int cutRod(int price[], int idx, int n) {
  
    // Base case: if index is 0, then the only option
    // is to take multiple pieces of length 1
    if (idx == 0) return n * price[0];
  
    // Base case: if the rod length is 0, no
    // more cuts can be made
    if (n == 0) return 0;

    // Option 1: Do not cut the rod at this index
    int notCut = cutRod(price, idx - 1, n);
    int cut = INT_MIN;
    int rodLen = idx + 1;

    // Option 2: Cut the rod if the current 
    // length is within bounds
    if (rodLen <= n)
        cut = price[idx] + cutRod(price, idx, n - rodLen);

    // Return the maximum value between
    // cutting and not cutting
    return (notCut > cut) ? notCut : cut;
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(price) / sizeof(price[0]);
    printf("%d\n", cutRod(price, size - 1, size));
    return 0;
}
