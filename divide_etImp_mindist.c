/*A delivery company has drone centers placed along a straight highway.
Each center is represented by its position in kilometers. The positions are already sorted increasingly.
Find the smallest distance between two neighboring centers using Divide and Conquer.
Example
Input:
2 11 17 21 24 40
Output:
Minimum distance: 3
Between positions: 21 and 24
because:
24 - 21 = 3
Required Strategy
Split the sorted array into two halves.
For each recursive call, compute:
best distance in the left half
best distance in the right half
distance across the middle boundary
Return the smallest of the three.
Expected complexity: O(n).
*/

#include <stdio.h>

// Returns the minimum of two integers
int min(int a, int b)
{
    return a < b ? a : b;
}

// Returns the index of the left element of the closest pair
int find_min_distance(int left, int right, int *pos, int *out_left, int *out_right)
{
    // Base case: only one pair to compare
    if (right - left == 1)
    {
        *out_left  = pos[left];
        *out_right = pos[right];
        return pos[right] - pos[left];
    }

    int m = (left + right) / 2;

    // Best pair holders for left and right halves
    int ll, lr, rl, rr;

    int dist_left  = find_min_distance(left,  m, pos, &ll, &lr);
    int dist_right = find_min_distance(m, right, pos, &rl, &rr);

    // Distance across the middle boundary
    int dist_mid = pos[m] - pos[m - 1];

    // Pick the best of the three
    if (dist_left <= dist_right && dist_left <= dist_mid)
    {
        *out_left  = ll;
        *out_right = lr;
        return dist_left;
    }
    else if (dist_right <= dist_left && dist_right <= dist_mid)
    {
        *out_left  = rl;
        *out_right = rr;
        return dist_right;
    }
    else
    {
        *out_left  = pos[m - 1];
        *out_right = pos[m];
        return dist_mid;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int pos[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &pos[i]);

    int a, b;
    int dist = find_min_distance(0, n - 1, pos, &a, &b);

    printf("Minimum distance: %d\n", dist);
    printf("Between positions: %d and %d\n", a, b);

    return 0;
}