
def armstrong(n):

    sum=0
    digits=len(str(n))
    while n>0:
        l=n%10

        sum += l**digits

        n=n//10
    return sum


n=9474
print(armstrong(n))
if armstrong(n) == n:
    print("Armstrong...")
else:
    print("Not Armstrong...")