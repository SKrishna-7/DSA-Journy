

def largestElement_optimal(nums):
    
    largest=nums[0]
    
    for num in nums:
        if num > largest:
            largest=num
    return largest


def secondLargestElement_bruteforce(nums,n):
    
    nums=sorted(nums)
    largest=nums[-1]
    slargest=0

    for i in range(n-1,0,-1):
        if nums[i] != largest:
            slargest=nums[i]
            break
    
    return slargest



def secondLargestElement_better(nums):
    
    largest=largestElement_optimal(nums)
    slargest=float("-inf")

    for num in nums:

        if num > slargest and num!=largest:
            slargest=num

    return slargest




def secondLargestElement_optimal(nums):
    
    largest=nums[0]
    slargest=float("-inf")

    for num in nums:

        if num > largest:
            
            slargest=largest
            largest=num

        elif num > slargest and slargest != num:
            slargest=num

    return slargest



nums=[2,1,5,8,1,3,4,6]
n=len(nums)

print("Second Largest Element : ",secondLargestElement_bruteforce(nums,n))  
print("Second Largest Element : ",secondLargestElement_better(nums))  
print("Second Largest Element : ",secondLargestElement_optimal(nums))  
