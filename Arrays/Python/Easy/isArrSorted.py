

def isArrSorted(nums,n):

    isSorted=True
    for i in range(n-1):
        if nums[i] > nums[i+1]:
            isSorted=False
    return isSorted


nums=[2,3,5,1,6,2,6,7,7,0]
n=len(nums)

print(isArrSorted(nums,n))
