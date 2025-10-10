Binary Search

Overview
Binary Search is an efficient algorithm to find an element in a sorted array by repeatedly dividing the search space in half. It has a time complexity of O(log n) and space complexity O(1) (iterative version).

How I Approached It

-> I initially struggled with choosing the correct middle index and handling edge cases when the array has even or odd length.
-> At first, I wrote a recursive solution, but I realized that for large arrays, it could lead to stack overflow, so I switched to the iterative version.
-> I also learned the importance of updating start and end correctly, otherwise it can lead to infinite loops.

Common Mistakes I Made

-> Using mid = (start + end) / 2 without considering integer overflow. Fixed by using mid = start + (end - start) / 2.
-> Forgetting to handle the case when the element is not present, which caused my code to return wrong values.
-> Misunderstanding whether to use < or <= in the while loop, which affected correctness.
