from module import *
file1_name="input1.txt"
file2_name="output1.txt"
text=input_text()#введення тексту
action(file1_name,text)#додавання тексту до першого файла
add_to_file(file1_name,file2_name)#створення другого файла
output(file1_name)#виведення вмісту файлів
output(file2_name)