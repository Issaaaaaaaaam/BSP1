import matplotlib.pyplot as plt
s = str(input("Enter the name of the data file : "))
f = open(s, "r")
all_lines = f.readlines()
list1 =[]
list2 =[]
list3 =[]
list4 =[]
list5 =[]
list6 =[]
list7 =[]
list8 =[]
list9 =[]
list10 =[]
list_of_modules = []
l = [1,2,3,4,5,6,7,8,9,10]
liste_of_t = [14,15,16,17,18,19,20,21,22,23]
f = [0,11,22,33,44,55,66,77,88,99]
for i in l :
    list1.append(float(all_lines[i]))
    list2.append(float(all_lines[i+11]))
    list3.append(float(all_lines[i+22]))
    list4.append(float(all_lines[i+33]))
    list5.append(float(all_lines[i+44]))
    list6.append(float(all_lines[i+55]))
    list7.append(float(all_lines[i+66]))
    list8.append(float(all_lines[i+77]))
    list9.append(float(all_lines[i+88]))
    list10.append(float(all_lines[i+99]))

for i in f :
    list_of_modules.append(int(all_lines[i]))

plt.plot(liste_of_t, list1 , label = "module is "+ str(list_of_modules[0]),color='green' )
plt.plot(liste_of_t, list2 , label = "module is "+ str(list_of_modules[1]),color='blue' )
plt.plot(liste_of_t, list3 , label = "module is "+ str(list_of_modules[2]),color='red' )
plt.plot(liste_of_t, list4 , label = "module is "+ str(list_of_modules[3]),color='black' )
plt.plot(liste_of_t, list5 , label = "module is "+ str(list_of_modules[4]),color='yellow' )
plt.plot(liste_of_t, list6 , label = "module is "+ str(list_of_modules[5]),color='pink' )
plt.plot(liste_of_t, list7 , label = "module is "+ str(list_of_modules[6]),color='violet' )
plt.plot(liste_of_t, list8 , label = "module is "+ str(list_of_modules[7]),color='orange' )
plt.plot(liste_of_t, list9 , label = "module is "+ str(list_of_modules[8]),color='brown' )
plt.plot(liste_of_t, list10 , label = "module is "+ str(list_of_modules[9]),color='grey' )

plt.xlabel("the argument t ")
plt.ylabel("the average time the computation took")
plt.title("graph of the time the computation took by the argument t for ten different modulus")


plt.legend()
plt.show()


