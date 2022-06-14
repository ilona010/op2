from random import randint
class Num:
    def __init__(self,num):
        self.num=num
    def increase(self,x):
        self.num*=x
    def reducing(self,x):
        self.num/=x
    def mod(self):
        self.num=abs(num)
class RationalNum(Num):
    def __init__(self,num,denominator):
        super().__init__(num)
        self.denominator=denominator
    def reducing(self,x):
        self.denominator*=x
    def mod(self):
        return abs(self.num/self.denominator)
class CompNum(Num):
    def __init__(self,num,im):
        super().__init__(num)
        self.im=im
    def increase(self,x):
        self.num*=x
        self.im*=x
    def mod(self):
        return (self.num**2+self.im**2)**(0.5)
    
def CreateArrRational(x):
    numbers=[]
    for i in range(x):
        n1=randint(-10,10)
        n2=randint(0,10)
        num=RationalNum(n1,n2)
        numbers.append(num)
    return numbers
def CreateArrComp(x):
    numbers=[]
    for i in range(x):
        n1=randint(-10,10)
        n2=randint(0,10)
        num=CompNum(n1,n2)
        numbers.append(num)
    return numbers
def Sum(rnum,cnum):
    s=0
    for i in range(len(rnum)):
        s+=rnum[i].mod()
    for i in range(len(cnum)):
        s+=cnum[i].mod()
    return s
def out_r(rnum):
    for i in range(len(rnum)):
        print(rnum[i].num,'/',rnum[i].denominator)
def out_compl(cnum):
    for i in range(len(cnum)):
        print(cnum[i].num,"+i*",cnum[i].im)