#! /usr/bin/python3
from posixpath import dirname
import xlrd
import os
import glob
import sys  
#import the excel path
locCwd = "/mnt/c/Users/ducth/Dropbox/DSX_L49/UserInterface/"
# locCwd = os.getcwd() #get present working directory
loc = "GUI_Matrix_DSX.xlsx"
StartRow        	 				= 2 #Start row from excel file
Output_OpcodeName	 				= 0
#open file
locInput = "/mnt/c/Users/ducth/Dropbox/DSX_L49/UserInterface/GUI/OpcodeHandle/Menu/Dive Planner/Menu_DiveSim_MainPage.c"
#open excel file
wb = xlrd.open_workbook(loc)
worksheetOpcode = wb.sheet_by_name("Opcode Handle")
num_rows_Opcode = worksheetOpcode.nrows
#for each opcode value -> check the file and replace
def replaceTheTextContent(fileDir):
	for cur_cel in range(StartRow, num_rows_Opcode):
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		#open file 'read string'
		fileInput = open(fileDir, "rt")
		dataIn = fileInput.read()
		#replace content
		dataIn = dataIn.replace("IniOrClrScrFunc_" + dat_OcName + "(void)", "IniOrClrScrFunc_" + dat_OcName + "(void* pData_st)")
		dataIn = dataIn.replace("UpdPorFunc_" + dat_OcName + "(void)", "UpdPorFunc_" + dat_OcName + "(void* pData_st)")
		dataIn = dataIn.replace("UpdOrFlasFunc_" + dat_OcName + "(void)", "UpdOrFlasFunc_" + dat_OcName + "(void* pData_st)")
		dataIn = dataIn.replace("HandlePreOCFunc_" + dat_OcName + "(void)", "HandlePreOCFunc_" + dat_OcName + "(void* pData_st)")
		#close file
		fileInput.close()
		#open file 'write string'
		fileInput = open(fileDir, "wt")
		#overwite
		fileInput.write(dataIn)
		#close
		fileInput.close()
#list the file
def getListOfFiles(dirName):
    # create a list of file and sub directories 
    # names in the given directory 
    listOfFile = os.listdir(dirName)
    allFiles = list()
    # Iterate over all the entries
    for entry in listOfFile:
        # Create full path
        fullPath = os.path.join(dirName, entry)
        # If entry is a directory then get the list of files in this directory 
        if os.path.isdir(fullPath):
            allFiles = allFiles + getListOfFiles(fullPath)
        else:
            allFiles.append(fullPath)
                
    return allFiles        
def main():
    reload(sys)  
    sys.setdefaultencoding('utf8')
    dirName = locCwd
    # print(locInput)
    # dirs=directories
    for (root, dirs, file) in os.walk(locCwd):
        for f in file:
            if '.c' in f:
                pathName = os.path.join(root, f)
                print(pathName)
                replaceTheTextContent(pathName)
    # print('\nNamed with wildcard ?:')
    # for files in glob.glob(locCwd + ".c"):
    #     print(files)
    # Get the list of all files in directory tree at given path
    # listOfFiles = getListOfFiles(dirName)
    
    # Print the files
    # for elem in listOfFiles:
    #     print(elem)
    # print ("****************")
    
    # Get the list of all files in directory tree at given path
    # listOfFiles = list()
    # for (dirpath, dirnames, filenames) in os.walk(dirName):
    #     listOfFiles += [os.path.join(dirpath, file) for file in filenames]
        
        
    # Print the files    
    # for elem in listOfFiles:
    #     print(elem)    
        
if __name__ == '__main__':
    main()