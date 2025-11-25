
def no_divisor(n):

    c=0
    for i in range(1,n+1):
        if n % i ==0:
            c+=1
    return c

import math
def no_divisor_optimal(n):

    c=0
    for i in range(1,int(math.sqrt(n))):
        if n % i ==0:
            c+=1
        
        if i!=n//i:
            c+=1
    return c

def divisors_optimal(n):

    c=0
    divisors=[]
    for i in range(1,int(math.sqrt(n))):
        if n % i ==0:
            divisors.append(i)
        
        if i!=n//i:
            divisors.append(n//i)

    return sorted(divisors)



n=36

print("Number of Divisor : ",no_divisor(n))
print("Number of Divisor : ",no_divisor_optimal(n))
print("Number of Divisor : ",divisors_optimal(n))