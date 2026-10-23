#include <stdio.h>

/*A city monitors signal strength along an underground emergency cable.
The signal normally increases or stays stable, but after one damaged segment, it drops.
Find the first index i such that:
signal[i] > signal[i + 1]
This index represents the position just before the failure begins.
Example
Input:
10 13 15 18 22 21 19 16
Output:
Failure after index: 4
Signal drops from 22 to 21
Assumptions
For this assignment:
• the array has at least two elements
• there is exactly one failure point
• before the failure, values increase or stay equal
• after the failure, values are lower
Required Strategy
Use a binary-search-style Divide and Conquer algorithm.
Then decide whether to continue in the left half or the right half.
Expected complexity: O(log n).
*/

int find_failure(int left, int right, int *signal)
{
    if (left == right)
        return left;
    else {
        int m = (left + right) / 2;

        if (signal[m] > signal[m + 1])
            return find_failure(left, m, signal);
        else
            return find_failure(m + 1, right, signal);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int signal[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &signal[i]);

    int idx = find_failure(0, n - 1, signal);

    printf("Failure after index: %d\n", idx);
    printf("Signal drops from %d to %d\n", signal[idx], signal[idx + 1]);

    return 0;
}