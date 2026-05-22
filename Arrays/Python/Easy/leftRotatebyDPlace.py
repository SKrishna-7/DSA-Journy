

def leftRotateByD_bruteForce(nums,n,d):

    d=d%n

    temp=[]
    temp = nums[:d]

    # print(temp,n)

    for i in range(d,n):
        nums[i-d] = nums[i]

    nums[n-d:] = temp
    print(nums)



def rotate(nums,l,r):

    while l<=r:
        nums[l],nums[r] = nums[r] , nums[l]
        l+=1
        r-=1
    return nums

def leftRotateByD_optimal(nums,n,d):

    d=d%n

    nums=rotate(nums,0,d-1)
    nums=rotate(nums,d,n-1)
    nums=rotate(nums,0,n-1)

    print(nums)
    
   

nums=[1,2,3,4,5,6,7] # [4,5,6,7,1,2,3]
d=3
n=len(nums)
# leftRotateByD_bruteForce(nums,n,d)

leftRotateByD_optimal(nums,n,d)