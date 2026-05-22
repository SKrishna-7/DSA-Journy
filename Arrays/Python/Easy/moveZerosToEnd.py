
def moveZerosToEnd_Brute(nums,n):

    temp=[0]*n        #SC -> O(n)
    index=0
    for num in nums:                #timeCom -> O(n)
        if num != 0:
            temp[index]= num
            index+=1
    nums = temp
    print(nums)

def moveZerosToEnd_Better(nums,n):

    index=0
    for num in nums:                #O(n)
        if num != 0:
            nums[index] = num
            index+=1

    for i in range(index,n):    # O(x) .. index-n
        nums[i] = 0
    print(nums)



def moveZerosToEnd_optimal(nums,n):

    index=-1
    for i in range(n):
        if nums[i] == 0:
            index=i
            break
    
    for j in range(index+1,n):
        if nums[j] != 0:
            nums[index],nums[j] = nums[j] , nums[index]
            index+=1
    
    print("Optimal Solution : " ,nums)
   


nums=[0, 1, 0, 3, 12]
n=len(nums)
# moveZerosToEnd_Brute(nums,n)
moveZerosToEnd_optimal(nums,n)