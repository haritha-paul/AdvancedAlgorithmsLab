# Five-ary Search / Quinary Search

## Approach:
1. Divide the array into 5 partitions by generating 4 points of splitting.
2. Check if the search key equals to one of the 4 split points. If matched, return the index.
3. Recursively, check for the search element in the first, second, third, fourth and fifth partition respectively by repeating steps 1 and 2. If a match is found, return the corresponding index.
4. In case of unsuccessful search, return -1.

## Output:
I/P: 

10

7 1 4 2 8 5 9 10 14 12

5

O/P: 

3

# Dual Pivot QuickSort

## Approach:
1. Partition the input array with left and rightmost element as pivot.
2. In partitioning, move the leftmost and rightmost pivot to its original position.
3. Apply quicksort recursively in three resultant subarrays - (0 -p1),(p1-p2),(p2-(n-1))

## Output:
I/P: 

7

7 1 4 2 8 5 9 

O/P: 

1 2 4 5 7 8 9

# Random Merge Sort

## Approach:
1. Select two random numbers (instead of middle element for splitting)-n1,n2
3. Run merge sort on two subarrays (0-n1),(n1-n2).
2. Recursively divide till each individual element is sorted.
4. Mege the sorted subarrays
5. Run merge sort on resultant array and third subarray (0-n2),(n2-(size-1)).
6. Merge the sorted subarrays

## Output:
I/P: 

7

7 1 4 2 8 5 9 

O/P: 

1 2 4 5 7 8 9


