class row:
	
	def __init__(self):
		self.chills=""
		self.runny_nose=""
		self.headache=""
		self.flue=""



def calculate(clas,row_array,unknown,n):

	c_chills=0
	c_runny_nose=0
	c_headache=0
	c_class=0

	for i in range(n):


		if row_array[i].flue==clas:

			c_class = c_class + 1
			if row_array[i].chills == unknown.chills:
				c_chills=c_chills+1
			if row_array[i].runny_nose == unknown.runny_nose:
				c_runny_nose=c_runny_nose+1
			if row_array[i].headache == unknown.headache:
				c_headache=c_headache+1


	ans = (float(c_chills*c_runny_nose*c_headache)/(c_class**3))*(float(c_class)/n)
	return ans



n = int(input("enter the number of tuples"))

row_array=[]
print("enter the tuples")

for i in range(n):
	print("enter the input value for tuple",i)
	
	r = row()
	r.chills = input()
	r.runny_nose = input()
	r.headache = input()
	r.flue = input() 
	row_array.append(r)
r=1
while r==1:

	print("enter the unknown values")
	unknown=row()
	unknown.chills = input()
	unknown.runny_nose = input()
	unknown.headache = input()
	
	y=calculate('1',row_array,unknown,n)
	n=calculate('0',row_array,unknown,n)
	print("The probability of yes is ",y)
	print("The probability of no is ",n)

	print("do you wanna continue")
	r=int(input())


