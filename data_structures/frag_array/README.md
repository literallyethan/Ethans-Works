This data structure, one I hope I invented, is called a 
"Fragmented Array," or "FragArray."

The idea is to have an array-esque data structure that is viable
in memory environments that may be fragmented, or in a space where
a giant contiguous block of memory is not feasible.

In terms of implementation, the frag array is an array[n] of pointers,
and this array can grow or shrink in size. Each pointer element in this
array points to a "fragment," a "subarray" that contains real number
elements, or any data type one prefers. 

The effect is an array that is accessed by accessing a fragment, and
then accessing the element in that fragment. 

FragArray ints[32] =
	- each fragment is 10 long, for example
	- 10 fits in 32 3 times, with 2 leftover
	- math comes out to fragment 3, index 2

The accessing is faster than that of a linked list with a high n,
while still having the advantage of not needing to be contiguous.
