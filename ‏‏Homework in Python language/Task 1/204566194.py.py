def xnor (x,y):
    '''This function get two boolean parameters and returns the result of the 'xnor' between them  
    for example: the parameters are True and True and the result is true''' 
    if x==True and y==True:
        return True
    elif x==False and y==False:
        return True
    else:
        return False      
print(xnor(True,False))
 
def Learn(x):
    '''
    This function get age of person and returns his status  
    for example: the age is 15 and the output is grade_school
    '''
    if x>=4 and x<=5:
        return "kindergarden"
    elif x>=6 and x<=14:
        return "grade_school"
    elif x>=15 and x<=18:
        return "grade_school"
    elif x>=19 and x<=21:
        return "army"
    elif x>=22 and x<=25:
        return "sce"
    else:
        return "None" 
print(Learn(15))    

def IsDivBy (numerator,denominator):
    '''This function get two  parameters and returns true if 'numerator is divisible without remainder 
    for example: the parameters are 15 and 3 and the result is true''' 
    if denominator==0:
        return False
    else:
        if numerator%denominator==0:
            return True
        else:
            return False      
print(IsDivBy (15,3))       
     

def Calc_pi(n):
    '''This function calculate the value of pie with the Leibniz formula for π
    for example: the parameter is 5 and the result is => 3.3396825396825403'''
    sum1=1
    i=0
    y=3
    while i<n-1:
        if i==0 or i%2==0:
            sum1=sum1-(1/y)
        else:
            sum1=sum1+(1/y)
        y+=2
        i+=1
    return sum1*4 
print(Calc_pi(5))

def Lucky_tickets():
    '''This function get number ,   
    for example: the number is 5 and the output is 22''' 
    loto=0
    for i in range (100000,1000000):
        temp=i
        sum1,sum2=0,0
        for j in range(3):
            sum1+=temp%10
            temp//=10
        for j in range(3):
            sum2+=temp%10
            temp//=10
        if sum1==sum2:
            loto+=1
    return loto  
print(Lucky_tickets())

def FRec(n):
    '''This function get number , if the number is <= 3 its return his value, if its > its do a 'formula' on him  
    for example: the number is 5 and the output is 22''' 
    if n<=3:
        return n
    elif n>3:
        return (FRec(n-1)+2*FRec(n-2)+3*FRec(n-3))
print(FRec(10))

def FIer(n):
    '''This function get number , if the number is <= 3 its return his value, if its > its do a 'formula' on him  
    for example: the number is 5 and the output is 22'''
    sum1,sum2=0,0
    temp=n
    if n<=3:
        return n
    if n>3: 
            for j in range (4,n):
                sum2+=(j-1+(2*(j-2))+(3*(j-3)))
            sum1+=(sum2+(2*(n-2))+(3*(n-3)))
    return sum2
print(FIer(10))
 #      
def RecPrint(begin, end, skip):
    '''This function print all the numbers between 'begin' and 'end' with jumps of 'skip' numbers 
    for example: the numbers are 53,91,5 and the output is 53, 63 ,73 ,83 ,91'''
    if begin>end:
        return 0
    else:
        print(begin,end=" ")
        RecPrint (begin+skip,end,skip)
RecPrint(53, 91, 10)
 
def Creator(x):
    '''This function get number and return new number that include just his even digits 
        for example: the number is -414178 and the output is -448'''
    if x==0:
        return 0
    flag=0
    if(x<0):
        x=-x
        flag=1
    y=x%10
    if y%2==0:
        if flag==1:
            return -(y+10*Creator((x//10)))
        else:
            return y+10*Creator(x//10)
    else:
        if flag==1:
            return Creator(-(x//10))
        else:
            return Creator(x//10)
     
print(Creator(-414178))
 

def PrintReverse(x):
    '''This function get number and print him in reverse 
     for example: the number is 1234567 and the output is 7 6 5 4 3 2 1'''
    if x%10==0:
        return 0
    else:
        print(x%10,end=" ")
        PrintReverse(x//10)    
PrintReverse(1234567)    
     
