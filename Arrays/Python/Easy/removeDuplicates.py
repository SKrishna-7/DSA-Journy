

def removeDup_brute(nums,n):

    unique=set()          #O(n logn)

    for num in nums:      #O(n)
        unique.add(num)

    
    index=0
    for unum in unique:         #~~ O(n-x)
        nums[index] = unum
        index+=1
    
  

    for i in range(index,n):     # ~O(x)
        nums[i]='_'

    return nums


def removeDup_Optimal(nums,n):

    pointer=0

    for i in range(1,n):

        if nums[i] != nums[pointer]:
            nums[pointer+1]=nums[i]
            pointer+=1

    return nums[:pointer+1]


nums=[1,1,2,2,3,4,5,6,7,7]
n=len(nums)

# print(removeDup_brute(nums,n))   # O(nlog) + O(n)
print(removeDup_Optimal(nums,n))   #O(n)