/*Missing Int: Given an input file with four billion non-negative integers, provide an
algorithm to generate an integer that is not contained in the file. 
Assume you have 1GB of memory available for this task

Soln - There are a total of 2^32, or 4 billion distinct integers posible and
2^31 non-negative integers. Therefore, we know the input file (assuming it is
ints and not longs) contains some duplicates. 

We have 1 GB memory available, or 8 billion bits. Thus with 8 billion bits, we
can map all possible integers to a distinct bit with the available memory. 

1. Create bit vector (BV) with 4 billion bits. Recall that a bit vector is an array
that compactly stores boolean values by using an array of ints. Each int
represents 32 boolean values. 

2. Initialize BV with all 0s.

3. Scan all numbers (num) from the file and call BV.set(num,1)

4. Now scan again BV from the 0th index.

5. Return the first index which has a value of 0.