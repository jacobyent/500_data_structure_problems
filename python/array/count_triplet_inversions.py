# https://www.techiedelight.com/count-triplets-which-form-inversion-array

# initial thoughts: linear time, constant space

# I missunderstood the problem, we are suppoed to count every possible inversion. Which can be done in quadratic time and linear space

import random 


def chompy(arr):
    count = 0 
    local_max = -1000
    mid = -999
    for i in range(len(arr)):
        if local_max < arr[i]:
            local_max = arr[i]
        elif mid < arr[i]:
            mid = arr[i]
        else: 
            count += 1
    print(count) 
     

def main():
    N = 10 
    array = []
    for i in range(N):
        array.append(random.randint(1,10))
    print(array) 
    chompy(array)
    
main()