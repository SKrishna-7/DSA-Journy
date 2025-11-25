
def rev_number(n):

    rev=0
    while n>0:
        l=n%10

        rev=(rev * 10) + l

        n=n//10
    return rev


n=1231

if n == rev_number(n):
    print("Palindrome...!")
else: 
    print("Not Palindrome...!")