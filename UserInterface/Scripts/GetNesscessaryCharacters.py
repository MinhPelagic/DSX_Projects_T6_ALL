#! /usr/bin/python3
import os
fileInpuChinese_S = 'Chinese_Simplified.txt'
fileInpuChinese_T = 'Chinese_Traditional.txt'
fileInpuRussian = 'Russian.txt'
fileInpuKorean = 'Korean.txt'
#-----------------------------
print("Read the data of string DSX")
def SubFuncHandle(file, strname):
	StartUnicode = 0x0000
	EndUnicode = 0xFFFF
	StepRange = 0 
	NumOfRange = 8.05#devide to multiple range modified
	Array_1 = []
	f1_line = "abc"
	f2_line = ""
	i = 0
	j = 0
	k = 0
	#Hanlde function
	with open("%s_out.txt" % strname, "w") as f1:
		for line in file:
			#remove all trailing white space, enter, "
			f1_line = line.replace('\n',"")
			f1_line = f1_line.replace('"', "")
			f2_line = f1_line + f2_line
		#Get all the characters to list
		Array_1 = list(f2_line)
		#Minimize the list 
		Array_1 = list(dict.fromkeys(Array_1))
		#Display the nescessary char
		for i in range(0,len(Array_1)):
			f1.write(str(Array_1[i])+"\n")
		#-----------------------------
		StepRange = round((EndUnicode-StartUnicode)/NumOfRange)
		for k in range(StartUnicode, EndUnicode, StepRange):		
			f1.write("\n---------------------------------------------------------------------\n")
			print(k)
			print(k+StepRange)
			print(j)
			print("*****************")
			for j in range(k, k+StepRange):
				#if(Array_1.index(j)>-1):
				#	print(Array_1.index(j))
				if chr(j) in Array_1:{}
					#f1.write(str(chr(j))+"\n")
					#print(j)		
				else:
					f1.write(" U+"+str(hex(j).lstrip('0x')))
		f1.write("\n---------------------------------------------------------------------\n")
	file.close() # Close file

#Execute functions
#get the file name : print(os.path.splitext(fileInpuChinese_S)[0])
SubFuncHandle(open(fileInpuChinese_S, "r"), (os.path.splitext(fileInpuChinese_S)[0]))
SubFuncHandle(open(fileInpuChinese_T, "r"), (os.path.splitext(fileInpuChinese_T)[0]))
SubFuncHandle(open(fileInpuRussian, "r"), (os.path.splitext(fileInpuRussian)[0]))
SubFuncHandle(open(fileInpuKorean, "r"), (os.path.splitext(fileInpuKorean)[0]))

print("DONE!!!!!!!!!!!!!")