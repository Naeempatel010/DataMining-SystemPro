from collections import Counter
import csv, math

filename = input("Enter the Filename: ")
n = int(input("Enter the number of Tuples: "))

dataset = []
pair_ds = []

ds_count = {}
Gain = {}

HD = int(0)


def rd_csv():
    with open(filename) as DT:
        readcsv = csv.reader(DT, delimiter = ',')
        col_names = list(next(readcsv))
        
        for i in readcsv:
            dataset.append(i) 
            
            for j,k in zip(col_names, i):
                ds_count[j] = ds_count[j] if(j in ds_count) else []                         #Creates list for each column                                         
                ds_count[j].append(k)                                                       #Appends the column value             
                pair_ds.append((k,i[-1]))                                                   #[List of tuples]Associates/Appends each value of each attribute with its corresponding Class value 
        
        for i in col_names:
            #print(ds_count[i]) 
            ds_count[i] = dict(Counter(ds_count[i]))
                                                  #[Dictionary of Dictionary]Counting the occurence of each value of each attribute
    #print(ds_count)
    DT.close()



def cal_HD(col):
    Hd = {} 
    Gain[col] = 0
    #print(pair_ds)
    for i in ds_count[col]:
        Hd[i] = Hd[i] if(i in Hd) else 0                                                    #Initializing H(D) of each value of each attribute with 0
        #print(Hd[i])  
        for j in pair_ds:
            #print(j)                                                           
            Pi = pair_ds[j]/ds_count[col][i]                                                #Calculating Probability of each Value of each attribute 
            Hd[i] = Hd[i]+(Pi)*math.log10(1/Pi) if(j[0] == i) else Hd[i]                    #Calculates H(D) of each value of each attribute
    print(Hd)
    for i in Hd:
        Gain[col] += (Hd[i]*(ds_count[col][i]/n))                                           #Summation of PiHi of the corresponding Attribute
    
    Gain[col] = HD - Gain[col]                                                              #Gain of the corresponding Attribute




rd_csv()

pair_ds = dict(Counter(pair_ds))                                                    #[Dictionary of tuples]Counting the occurence of each value of each attribute with its corresponding class value 
    
cls = list(ds_count.keys())[-1]                                                     #Identifying the column which is the class
print(cls)
for i in ds_count[cls]:
    HD += (ds_count[cls][i]/n)*math.log10(n/ds_count[cls][i])                       #Calculating the Initial State Entropy

for i in ds_count:
    if (not(i == cls)):                                                             #Loop runs through every attribute except for the class
        cal_HD(i)                                                                   

print("Hence root is :",max(Gain, key=Gain.get))