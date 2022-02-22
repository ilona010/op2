def input_text():#введення тексту
    print("Введіть текст:")
    flag=True
    text=""
    lines=[]
    while flag:
        line=input()
        for i in range(len(line)):
            if line[i]==chr(20):
                pos=line.find(chr(20))
                line=line[:pos:]
                flag=False
        lines.append(line)
    text='\n'.join(lines)
    return text
def action(file_name,text):#додавання тексту до першого файла
    s=input("Введіть 'c' для створення нового файла або 'a' для додавання тексту до існуючого файла:")
    if s=='с':
        with open(file_name,'w') as file:
            file.write(text)
    elif s=='а':
        with open(file_name,'a') as file:
            file.write('\n'+text)
def count_words(line):#знаходження кількості слів в рядку
    words=line.split()
    count=len(words)
    return count
def len_longest(line):#знаходження довжини найдовшого слова в рядку
    words=line.split()
    max_length=0
    for word in words:
        if len(word)>max_length:
            max_length=len(word)
    return max_length
def add_to_file(file_name1,file_name2):#створення другого файла
    file1=open(file_name1,'r')
    file2=open(file_name2,'w')
    text=file1.read().split('\n')
    for line in text:
        count=count_words(line)
        length=len_longest(line)
        new_line=str(count)+' '+line+' '+str(length)+'\n'
        file2.write(new_line)
    file1.close()
    file2.close()
def output(file_name):#виведення вмісту файлів
    print(file_name,":")
    file=open(file_name,'r')
    flag=True
    while flag:
        line=file.readline()
        if not line:
            flag=False
        print(line.strip())
    file.close()