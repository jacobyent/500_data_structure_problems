# https://www.techiedelight.com/count-triplets-which-form-inversion-array

# initial thoughts: linear time, constant space


import random 


def chompy(arr):
    count = 0 
    local_max = arr[0]
    
    print(count) 
     

def main():
    N = 10 
    array = []
    for i in range(N):
        array.append(random.randint(1,10))
        
    chompy(array)