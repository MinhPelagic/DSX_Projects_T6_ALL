#! /usr/bin/python3
import xlrd
FontSizeOrderIncludeToC = 12
FontSizeOrderIncludeToH = 13
ContentRow				= 2
loc = "DSX_FontStruct.xlsx"
#open file
wb = xlrd.open_workbook(loc)
worksheet = wb.sheet_by_name("FontSize")
num_rows = worksheet.nrows
print("Assign the font of when initialize" + " = " + str(num_rows))
num_col = worksheet.ncols
with open("../GUI/DSX_FontStruct.h", "w") as f1:
	f1.write("#ifndef _DSX_FONT_ASSIGN_H\n")
	f1.write("#define _DSX_FONT_ASSIGN_H\n")
	#Decalare the struct of fonts to be used in each Opcode
	f1.write("/*Decalare the struct of fonts to be used in each Opcode*/\n")
	f1.write("typedef struct FontSize {\n")
	f1.write("	int Size_1;\n")
	f1.write("	int Size_2;\n")
	f1.write("	int Size_3;\n")
	f1.write("	int Size_4;\n")
	f1.write("	int Size_5;\n")
	f1.write("	int Size_6;\n")
	f1.write("	int Size_7;\n")
	f1.write("	int Size_8;\n")
	f1.write("	int Size_9;\n")
	f1.write("	int Size_10;\n")
	f1.write("	int Size_11;\n")
	f1.write("} FontSize_ts;\n")
	f1.write("/*Extern the variables in each Opcode*/\n")
	for cur_cel in range(ContentRow, num_rows):
		data = worksheet.cell_value(cur_cel, FontSizeOrderIncludeToH)
		f1.write(data + "\n")
	f1.write("#endif")
f1.close()
#Get the read cell then copy to the DSX_FontStruct.c
with open("../GUI/DSX_FontStruct.c", "w") as f2:
	f2.write("/*Declare the font size of each Opcode to be used*/\n")
	f2.write("#include " + '"' + "L4X9_includes.h" + '"' +"\n")
	for cur_cel in range(ContentRow, num_rows):
		data = worksheet.cell_value(cur_cel, FontSizeOrderIncludeToC)
		f2.write(data + "\n")
#	f1.write("}TxtStr_Name_e;\n#endif")
f2.close()

print("END!!!!!")
