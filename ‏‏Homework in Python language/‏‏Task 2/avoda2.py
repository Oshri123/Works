"""Higher-order function operates other functions and sequence of data """
def myPrime(x): ##this function check if number is prime
    i=2 
    while i<x:
        if x%i == 0:
            return False
        i+=1
    else:
        return True
def isFib(x): ##this function check if the number include in Fibonacci series
    num1,num2=1,1
    if(x==1):
        return True
    else:
        while (num1+num2<=x):
            if num1+num2==x:
                return True
            num2+=num1
            num1=num2-num1
    return False
def myFilter(L,func):   ## this function filter list
    L2=[]
    for i in L:
        if func(i)==True:
            L2.append(i)
    return L2
def myFilterMulti(L,funcL): ## this function filter list of lists of function
    correct=0
    L2=[]
    for i in L:
        for j in funcL:
            if (j(i)==False):
                correct=1
        if(correct==0):
            L2.append(i)
        correct=0
    return L2
print(myFilter([2,4,5,6],myPrime))
print(myFilterMulti([2,4,5,6,7,13],[myPrime,isFib]))
L=[2,4,5,13,41,55,89,107,144]
L2=[myPrime,isFib,lambda x: x>9 and x<100]
print(myFilterMulti(L,L2))

"""Function to calculate the surface of a function using the trapeze's formula"""
def Trapez_rule(f,a,b,n):
    def next1(a,b,n):
        return ((b-a)/n)
    sum=(f(a)+f(b))/2
    i=1
    while i<n:
        sum+=f(i*next1(a,b,n))
        i+=1
    sum=sum*next1(a,b,n)
    return (sum)
print(Trapez_rule(lambda x:x**9,0.0,10.0,100000))

'''"""The function returns n times action of the variable """'''
def square(x):
    return x**2
def compose(f,g):
    return lambda x: f(g(x))
def incr(x):
    return x+1
def repeated(f,n):
    x=f
    for i in range (0,n-1):
        x= compose(x,f)
    return x

print(repeated(square,2)(5))
print(repeated (incr,4)(2))