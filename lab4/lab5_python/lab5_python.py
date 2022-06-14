from classes import*
m=int(input("enter m:"))
n=int(input("enter n:"))
rnum=CreateArrRational(m)
cnum=CreateArrComp(n)
out_r(rnum)
out_compl(cnum)
for n in rnum:
    n.reducing(2)
for n in cnum:
    n.increase(3)
print("modified numbers:")
out_r(rnum)
out_compl(cnum)
sum=Sum(rnum,cnum)
print("sum=",sum)