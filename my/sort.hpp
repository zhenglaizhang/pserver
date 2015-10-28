//
// Created by darinzh on 10/27/2015.
//

#ifndef CXX_SORT_HPP
#define CXX_SORT_HPP

#include <vector>
#include <stdexcept>
#include "util.hpp"

/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray is picked and moved to the sorted subarray.
Following example explains the above steps:
arr[] = 64 25 12 22 11

// Find the minimum element in arr[0...4] and place it at beginning
11 25 12 22 64

// Find the minimum element in arr[1...4] and
// place it at beginning of arr[1...4]
11 12 25 22 64

// Find the minimum element in arr[2...4] and
// place it at beginning of arr[2...4]
11 12 22 25 64

// Find the minimum element in arr[3...4] and
// place it at beginning of arr[3...4]
11 12 22 25 64
 * */

template<typename T>
void SelectionSort(std::vector<T> &V) {
    int min_index = 0;
    int sz = V.size();
    for (int i = 0; i < sz - 1; ++i) {  // not i < sz, i is the first elem of unsorted sub-array.
        print(V);
        min_index = i;
        for (int j = i + 1; j < sz; ++j) {
            if (V[j] < V[i]) { min_index = j; }
        }
        if (i != min_index) {           // We may ignore the check and just directly swap, perf diff?
            std::swap(V[min_index], V[i]);
        }
    }
}


/*
Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
Example:
First Pass:
( 5 1 4 2 8 ) –> ( 1 5 4 2 8 ), Here, algorithm compares the first two elements, and swaps since 5 > 1.
( 1 5 4 2 8 ) –>  ( 1 4 5 2 8 ), Swap since 5 > 4
( 1 4 5 2 8 ) –>  ( 1 4 2 5 8 ), Swap since 5 > 2
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 ), Now, since these elements are already in order (8 > 5), algorithm does not swap them.
Second Pass:
( 1 4 2 5 8 ) –> ( 1 4 2 5 8 )
( 1 4 2 5 8 ) –> ( 1 2 4 5 8 ), Swap since 4 > 2
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –>  ( 1 2 4 5 8 )
Now, the array is already sorted, but our algorithm does not know if it is completed. The algorithm needs one whole pass without any swap to know it is sorted.
Third Pass:
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
( 1 2 4 5 8 ) –> ( 1 2 4 5 8 )
 * */
template<typename T>
void BubbleSort(std::vector<T> V) {
    int i, j;
    bool swapped = true;
    auto sz = V.size();
    for (i = 1; (i < sz) && swapped; ++i) // Needs swap max sz-1 times for sz size
    {
        print(V);
        int end = sz - i;
        swapped = false;
        for (int j = 0; j < sz - i; ++j) {
            if (V[j] > V[j + 1]) {
                std::swap(V[j], V[j + 1]);
                swapped = true;
            }
        }
    }
}


/*
Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands.
// Sort an arr[] of size n
insertionSort(arr, n)
Loop from i = 1 to n-1.
……a) Pick element arr[i] and insert it into sorted sequence arr[0…i-1]
Example:
12, 11, 13, 5, 6
Let us loop for i = 1 (second element of the array) to 5 (Size of input array)
i = 1. Since 11 is smaller than 12, move 12 and insert 11 before 12
11, 12, 13, 5, 6
i = 2. 13 will remain at its position as all elements in A[0..I-1] are smaller than 13
11, 12, 13, 5, 6
i = 3. 5 will move to the beginning and all other elements from 11 to 13 will move one position ahead of their current position.
5, 11, 12, 13, 6
i = 4. 6 will move to position after 5, and elements from 11 to 13 will move one position ahead of their current position.
5, 6, 11, 12, 13
 * */
template<typename T>
void InsertionSort(std::vector<T> &V) {
    int sz = V.size();
    for (int i = 1; i < sz; ++i) {
        print(V);
        int key = V[i];                 // key points to current element
        int j = i - 1;
        while (j >= 0 && V[j] > key) {
            V[j + 1] = V[j];
            --j;
        }
        V[j + 1] = key;                 // Or we may check the j+1 == i equality
    }
}



/*
http://geeksquiz.com/merge-sort/
MergeSort is a Divide and Conquer algorithm. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. The merg() function is used for merging two halves. The merge(arr, l, m, r) is key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one. See following C implementation for details.
MergeSort(arr[], l,  r)
If r > l
     1. Find the middle point to divide the array into two halves:
             middle m = (l+r)/2
     2. Call mergeSort for first half:
             Call mergeSort(arr, l, m)
     3. Call mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge the two halves sorted in step 2 and 3:
             Call merge(arr, l, m, r)
 * */


// Merge V[l..m] and V[m+1..r]
template<typename T>
void Merge(std::vector<T> &V, int l, int m, int r) {

}

template<typename T>
void MergeSort(std::vector<T> &V, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;    // //Same as (l+r)/2, but avoids overflow for large l and h
        MergeSort(V, l, m);
        MergeSort(V, m + 1, r);
        Merge(V, l, m, r);
    }
}

template<typename T>
void MergeSort(std::vector<T> &V) {

}



/*
Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (kind of hashing). Then doing some arithmetic to calculate the position of each object in the output sequence.

Let us understand it with the help of an example.

For simplicity, consider the data in the range 0 to 9.
Input data: 1, 4, 1, 2, 7, 5, 2
  1) Take a count array to store the count of each unique object.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  2  0   1  1  0  1  0  0

  2) Modify the count array such that each element at each index
  stores the sum of previous counts.
  Index:     0  1  2  3  4  5  6  7  8  9
  Count:     0  2  4  4  5  6  6  7  7  7

The modified count array indicates the position of each object in
the output sequence.

  3) Output each object from the input sequence followed by
  decreasing its count by 1.
  Process the input data: 1, 4, 1, 2, 7, 5, 2. Position of 1 is 2.
  Put data 1 at index 2 in output. Decrease count by 1 to place
  next data 1 at an index 1 smaller than this index.

Points to be noted:
1. Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K.
2. It is not a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data.
3. It is often used as a sub-routine to another sorting algorithm like radix sort.
4. Counting sort uses a partial hashing to count the occurrence of the data object in O(1).
5. Counting sort can be extended to work for negative inputs also.
 * */




/*
Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and partitions the given array around the picked pivot. There are many different versions of quickSort that pick pivot in different ways.
1) Always pick first element as pivot.
2) Always pick last element as pivot (implemented below)
3) Pick a random element as pivot.
4) Pick median as pivot.
The key process in quickSort is partition(). Target of partitions is, given an array and an element x of array as pivot, put x at its correct position in sorted array and put all smaller elements (smaller than x) before x, and put all greater elements (greater than x) after x. All this should be done in linear time.
Partition Algorithm
There can be many ways to do partition, following code adopts the method given in CLRS book. The logic is simple, we start from the leftmost element and keep track of index of smaller (or equal to) elements as i. While traversing, if we find a smaller element, we swap current element with arr[i]. Otherwise we ignore current element.

Quicksort is slightly sensitive to input that happens to be in the right order, in which case it can skip some swaps. Mergesort doesn't have any such optimizations, which also makes Quicksort a bit faster compared to Mergesort.
    http://newtechnobuzzz.blogspot.in/2014/07/why-quicksort-is-better-than-mergesort.html#.VjCIePkrKUk
 * */
template<typename T>
int partition(std::vector<T> &V, int l, int r) {
    T pivot = V[r];
    int i = l - 1;  // right most index of the smaller element
    for (int j = l; j <= r - 1; ++j) {          // <= r - 1, since we have r processed.
        // If the current element is <= pivot,
        if (V[j] <= pivot) {
            ++i;               // increase the index of smaller element
            std::swap(V[j], V[i]);  // swap the current element with index
        }
    }

    // i+1 is the final index of the pivot
    std::swap(V[i + 1], V[r]);
    return (i + 1);
}


template<typename T>
void QuickSort(std::vector<T> &V, int l, int r) {
    if (l < r) {
        int p = partition(V, l, r);
        QuickSort(V, l, p - 1);             // Note it's p-1 here, not p!!
        QuickSort(V, p + 1, r);
    }
}

template<typename T>
void QuickSort(std::vector<T> &V) {
    QuickSort(V, 0, V.size() - 1);
}


/*
The lower bound for Comparison based sorting algorithm (Merge Sort, Heap Sort, Quick-Sort .. etc) is Ω(nLogn), i.e., they cannot do better than nLogn.

Counting sort is a linear time sorting algorithm that sort in O(n+k) time when elements are in range from 1 to k.

What if the elements are in range from 1 to n2?
We can’t use counting sort because counting sort will take O(n2) which is worse than comparison based sorting algorithms. Can we sort such an array in linear time?
Radix Sort is the answer. The idea of Radix Sort is to do digit by digit sort starting from least significant digit to most significant digit. Radix sort uses counting sort as a subroutine to sort.
The Radix Sort Algorithm
1) Do following for each digit i where i varies from least significant digit to the most significant digit.
………….a) Sort input array using counting sort (or any stable sort) according to the i’th digit.

Example:
Original, unsorted list:

170, 45, 75, 90, 802, 24, 2, 66
Sorting by least significant digit (1s place) gives: [*Notice that we keep 802 before 2, because 802 occurred before 2 in the original list, and similarly for pairs 170 & 90 and 45 & 75.]

170, 90, 802, 2, 24, 45, 75, 66
Sorting by next digit (10s place) gives: [*Notice that 802 again comes before 2 as 802 comes before 2 in the previous list.]

802, 2, 24, 45, 66, 170, 75, 90
Sorting by most significant digit (100s place) gives:

2, 24, 45, 66, 75, 90, 170, 802
What is the running time of Radix Sort?
Let there be d digits in input integers. Radix Sort takes O(d*(n+b)) time where b is the base for representing numbers, for example, for decimal system, b is 10. What is the value of d? If k is the maximum possible value, then d would be O(logb(k)). So overall time complexity is O((n+b) * logb(k)). Which looks more than the time complexity of comparison based sorting algorithms for a large k. Let us first limit k. Let k <= nc where c is a constant. In that case, the complexity becomes O(nLogb(n)). But it still doesn’t beat comparison based sorting algorithms.
What if we make value of b larger?. What should be the value of b to make the time complexity linear? If we set b as n, we get the time complexity as O(n). In other words, we can sort an array of integers with range from 1 to nc if the numbers are represented in base n (or every digit takes log2(n) bits).

Is Radix Sort preferable to Comparison based sorting algorithms like Quick-Sort?
If we have log2n bits for every digit, the running time of Radix appears to be better than Quick Sort for a wide range of input numbers. The constant factors hidden in asymptotic notation are higher for Radix Sort and Quick-Sort uses hardware caches more effectively. Also, Radix sort uses counting sort as a subroutine and counting sort takes extra space to sort numbers.

Implementation of Radix Sort
Following is a simple C++ implementation of Radix Sort. For simplicity, the value of d is assumed to be 10. We recommend you to see Counting Sort for details of countSort() function in below code.

 * */

int Max(const IntVector &V) {
    if (V.empty()) { throw std::out_of_range("V.empty()"); }
    int max = V[0];
    for (int i = 1; i < V.size(); ++i) {
        if (V[i] > max)
            max = V[i];
    }

    return max;
}

// http://www.geeksforgeeks.org/radix-sort/
// TODO: count sort and heap sort!!
void CountSort(const IntVector &V, int exp) {

}

void RadixSort(IntVector &V) {
    // find the max number to know the number of digits
    int max = Max(V);

    // Do counting sort for every digit
    // We pass exp here, exp is 10^i, where i is the current digit number
    for (int exp = 1; max / exp > 0; exp *= 10) {
        CountSort(V, exp);
    }
}

#endif //CXX_SORT_H
