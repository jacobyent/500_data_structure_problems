# Given an unsorted integer array, find a pair with the given sum in it.  
# 
# https://www.techiedelight.com/find-pair-with-given-sum-array/

# Initial guess: nlogn time O(1) spatial 

# solution: hashing, O(n) x 2, subtract the array value from target and check if new value exists in dict, if not store in dict with arr
# value as key and array position as value repeat until all elements have been checked or a pair is found
import random


def pair_sum(arr, target):
    left = 0
    right = len(arr) - 1
    while(left < right):
        value = arr[left] + arr[right]
        if value == target:
            print("Found pair ({0},{1})".format(arr[left], arr[right]))
        if value > target:
            right = right - 1
        else:
            left = left + 1
        



def main():
    N = 10
    tar = 5
    array = []
    for i in range(N): 
        array.append(random.randint(1,10))
    print(array) 
    array.sort()
    print(array) 
    pair_sum(array, tar)

main()





