def MajorityElement_Brute(nums,n):

    cnt=0
    for i in range(n):
        for j in range(i,n):
            if nums[i] == nums[j]:
                cnt+=1
            
        if cnt>= n/2:
            return nums[i]
    return -1
            
def MajorityElement_Better(nums,n):

    map={}

    for num in nums:
        if num in map:
            map[num] +=1
        else : map[num]=1

    for k,v in map.items():
        if v > n//2:
            return k
        
    return -1
            
def MajorityElement_optimal(nums,n):
    cnt=0
    el=0
    
    for num in nums:
        if cnt==0:
            el=num
            cnt=1
        elif el == num: cnt+=1
        else : cnt -=1
    
    cnt1= 0
    for num in nums:
        if num == el: cnt1+=1
    if cnt1 >= n//2:
        return el
    return -1


nums = [1, 1, 1, 2, 1, 2]  
n= len(nums)
# 6/2 =3 appears >= 3

# print(MajorityElement_Brute(nums,n))
# print(MajorityElement_Better(nums,n))
print(MajorityElement_optimal(nums,n))