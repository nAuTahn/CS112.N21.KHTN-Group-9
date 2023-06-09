# -*- coding: utf-8 -*-
"""parallel_merge_sort.ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/1y3-qg1vUjc_zT_9tkhgoc5A8i7Lzr_gt
"""

from multiprocessing import Pool
import time, random

def split(a, n):
    # split array into n subarrays
    k, m = divmod(len(a), n)
    return (a[i*k+min(i, m):(i+1)*k+min(i+1, m)] for i in range(n))

def merge(arr_1, arr_2):
    # merge 2 sorted arrays
    merged = []
    p1 = 0; p2 = 0
    while (len(merged) != len(arr_1) + len(arr_2)):
        # if all elements in arr_2 is merged or arr_1[p1] < arr_2[p2] then add arr_1[p1] to the merged arr and increase p1
        if (p2 == len(arr_2)) or ((p1 < len(arr_1) and arr_1[p1] <= arr_2[p2])):
            merged.append(arr_1[p1])
            p1+= 1
        # else add arr_2[p2] to the merged array and increase p2
        else:
            merged.append(arr_2[p2])
            p2+= 1
 
    return merged

def merge_wrap(arr):
    left, right = arr
    return merge(left, right)

def merge_sort(arr):
    if len(arr) <= 1:
        return arr
    # split the array into 2 parts, sort each part, then merge them together
    left, right = split(arr, 2)
    return merge(merge_sort(left), merge_sort(right))

def parallel_merge_sort(arr):
    # number of processes
    n_processes = 8
    # create a pool
    pool = Pool(processes=n_processes)
    # split arr into parts
    unsorted_parts = split(arr, n_processes)
    # sort each part in parallel
    sorted_parts = pool.map(merge_sort, unsorted_parts)
 
    while (len(sorted_parts) > 1):
        # split the array into contiguous pairs
        pairs = [[sorted_parts[i], sorted_parts[i+1]]
                 for i in range(0, len(sorted_parts)-1, 2)]
        remain = []
        # if the size of sorted_parts is odd, the last part is unmerged
        if len(sorted_parts) % 2 == 1:
            remain = sorted_parts[-1]
        # merge each pair 
        sorted_parts = pool.map(merge_wrap, pairs)
        # if the last part is unmerged, append it to the final array
        if (len(remain)):
            sorted_parts.append(remain)
 
 
    return sorted_parts[0]

if __name__ == "__main__":
    random.seed(222)
 
    # get the size of array user input
    n = int(input("Enter the size of array: "))
 
    # generate a 32-bit interger unsorted array
    arr_unsorted = [random.randint(0, 1 << 31) for _ in range(n)]
 
    # sort with sequential merge sort
    start = time.time()
    arr_sorted = merge_sort(arr_unsorted)
    elapsed = time.time()
    print(f"Sequential merge sort: {elapsed - start} seconds")
 
    arr_sorted = []
    time.sleep(1);
 
    # sort with parallel merge sort
    start = time.time()
    arr_sorted = parallel_merge_sort(arr_unsorted)
    elapsed = time.time()
    print(f"Parallel merge sort: {elapsed - start} seconds")