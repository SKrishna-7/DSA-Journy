


def largestElement_bruteforce(nums,n):
    
    for i in range(n):
        islarge=True
        for j in range(n):
            if nums[j] > nums[i]:
               islarge=False
               break
        
        if islarge:
            return nums[i]             #O(n*n)
    return -1



def largestElement_better(nums):
    nums=sorted(nums)  #O(n log n)
    return nums[-1]



def largestElement_optimal(nums):
    
    largest=nums[0]
    
    for num in nums:
        if num > largest:
            largest=num
    return largest



nums=[2,1,5,8,1,3,4,6]
n=len(nums)

print("Largest Element : ",largestElement_bruteforce(nums,n))  # O(n*n)
print("Largest Element : ",largestElement_better(nums))        # O(n log n)
print("Largest Element : ",largestElement_optimal(nums))       # O(n)
print(nums)





