
import math

def count_digits(n):
   
    n=abs(n)
    count=0

    if n==0:
        return 0
    while n!=0:
        last=n%10

        count+=1
        n=n//10

    return count

n=-12343

# Approach 1
print(f"counts of {n} : {count_digits(n)}")

# Approach 2

count=int(math.log10(abs(n)) + 1)
print(f"counts of {n} : {count}")

