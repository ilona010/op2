import pickle
class Good:
    def __init__(self,name,data1,data2,price):
        self.name=name
        self.data1=data1
        self.data2=data2
        self.price=price
def output(filename):
    print(filename,":")
    with open(filename,'rb') as file:
        try:
            print("назва","\t","дата виготовлення","\t","кінцевий термін придатності","\t","ціна")
            while True:
                goods=pickle.load(file)
                for good in goods:
                    print(good.name,"\t",good.data1,"\t\t",good.data2,"\t\t\t",good.price)
        except EOFError:
            pass
def action(filename):
    s=input("введіть 0 для перезапису файла або + для його доповнення:")
    if s=='0':
        with open(filename, 'wb') as file:
            goods=CreateStore()
            pickle.dump(goods,file)
    if s=='+':
        with open(filename,'ab') as file:
            goods=CreateStore()
            pickle.dump(goods,file)
def CreateStore():
    goods=list()
    flag=True
    while flag:
        name=input("назва:")
        data1=input("дата виготовлення:")
        data2=input("кінцевий термін придатності:")
        price=float(input("ціна:"))
        a=Good(name,data1,data2,price)
        print("введіть + для продовження, а 0 для закінчення вводу:")
        c=input()
        if c=='0':
            flag=False
        goods.append(a)
    return goods
def CountDays(data):
    MonthDays=[31,28,31,30,31,30,31,31,30,31,30,31]
    d=int(data[0])*10+int(data[1])
    m=int(data[3])*10+int(data[4])
    y=int(data[6])*1000+int(data[7])*100+int(data[8])*10+int(data[9])
    k=y*365+d
    for i in range(m-1):
        k+=MonthDays[i]
    return k
def ChangePrice(filename1,filename2):
    goods2=list()
    with open(filename1,'rb') as file_1:
        try:
            while True:
                goods=pickle.load(file_1)
                for good in goods:
                    d1=CountDays(good.data1)
                    d2=CountDays(good.data2)
                    term=d2-d1
                    if term<=14:
                        good.price-=(good.price*0.05)
                    if term>365:
                        good.price+=(good.price*0.03)
                    goods2.append(good)
        except EOFError:
            pass
    with open(filename2,'wb') as file_2:
        pickle.dump(goods2,file_2)
def CreateFile3(name2,name3):
    goods3=list()
    data=input("введіть поточну дату:")
    m=int(data[3])*10+int(data[4])
    y=int(data[6])*1000+int(data[7])*100+int(data[8])*10+int(data[9])
    with open(name2,'rb') as file2:
        try:
            while True:
                goods=pickle.load(file2)
                for good in goods:
                    m1=int(good.data1[3])*10+int(good.data1[4])
                    y1=int(good.data1[6])*1000+int(good.data1[7])*100+int(good.data1[8])*10+int(good.data1[9])
                    if y==y1:
                        if m1<m:
                            goods3.append(good)
                    else:
                        goods3.append(good)
        except EOFError:
            pass
    with open(name3,'wb') as file3:
        pickle.dump(goods3,file3)
