

def leftRotateByOne_BruteForce(nums,n):
    """
        TC -> O(n)
        SC -> O(n)
    """
    temp=[0]*n
    for i in range(1,n):
        temp[i-1] = nums[i]

    temp[n-1] = nums[0]
    nums = temp
    print(nums)


def leftRotateByOne_Optimal(nums,n):  
    """
        TC -> O(n)
        SC -> O(1)
    """
    temp=nums[0]

    for i in range(0,n-1):
        nums[i] = nums[i+1]
    nums[-1] = temp
    print(nums)


nums=[1,2,3,4,5,6,7]
n=len(nums)

# leftRotateByOne_BruteForce(nums,n)
leftRotateByOne_Optimal(nums,n)


