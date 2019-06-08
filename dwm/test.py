from collections import Counter 
import csv
import math

filename = input("enter the file name")
n=int(input("enter the number of tuples"))

dataset=[]
pair_ds=[]

ds_count={}
Gain={}
HD=int(0)


def rd_csv():

	with open(filename) as f:
		read_csv = csv.reader(f,delimiter=',')
		col_names = next(read_csv)

		for i in read_csv:
			dataset.append(i)

			for j,k in zip(col_names,i):

				ds_count[j] = ds_count[j] if(j in ds_count) else []
				ds_count[j].append(k)
				pair_ds.append((k,i[-1]))

		for i in ds_count:
			ds_count[i] = dict(Counter(ds_count[i]))

	f.close()


def entropy(col):

	Hd={}
	Gain[col] = 0

	for i in ds_count[col]:
		Hd[i] = Hd[i] if(i in Hd) else 0
		

		for j in pair_ds:
			Pi = pair_ds[j]/ds_count[col][i]
			Hd[i] = Hd[i]+Pi*math.log10(1/Pi) if(j[0]==i) else Hd[i]

		#print(Hd)
	for i in Hd:
			#print(i)
			Gain[col] = Gain[col] + (Hd[i]*(ds_count[col][i]/n))
			#print(Gain[col])
	Gain[col] = HD- Gain[col]




rd_csv()

pair_ds = dict(Counter(pair_ds))

cls = list(ds_count.keys())[-1]
#print(ds_count)
for i in ds_count[cls]:
	HD = HD+(ds_count[cls][i]/n)*math.log10(n/ds_count[cls][i])

for i in ds_count:
	if(not(i==cls)):
		entropy(i)


print("hence the root is ",max(Gain,key=Gain.get))

		

