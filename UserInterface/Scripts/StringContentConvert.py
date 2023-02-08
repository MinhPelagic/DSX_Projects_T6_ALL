#! /usr/bin/python3
import xlrd

#import the excel path
TxtStr_Order = 1
English_Column = 2
Italiano_Column = 3
French_Column = 4
German_Column = 5
Czech_Column = 6
Polish_Column = 7
Korean_Column = 8
ChineseSimp_Column = 9
ChineseTrad_Column = 10
Russian_Column = 11
Espanol_Column = 12
Portugese_Column = 13

loc = "DSX_Translation Document.xlsx"
#open file
wb = xlrd.open_workbook(loc)
worksheet = wb.sheet_by_name("TxTStr Name")
num_rows = worksheet.nrows
print("Number of Rows in sheet" + " = " + str(num_rows))
num_col = worksheet.ncols
print("Number of Column in sheet" + " = " + str(num_col))
def putHeaderTxtStr():
	f1.write("/*CODE GENERATED PLEASE NOT MODIFY BY HAND!!!*/\n")
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
def castAllTheStringToUTF8(languageColumnNumber):
	for cur_cel in range(1, num_rows):
		data = worksheet.cell_value(cur_cel, languageColumnNumber)
		str_out_temp = str(data.encode('utf8'))
		#add special character between 2 ""
		# for ele in str_out_temp:
		lenVal = len(str_out_temp) #length of string
		for lenCount in range(0, lenVal):
			if str_out_temp[lenCount] == "\\" and str_out_temp[lenCount+1] == 'x' and str_out_temp[lenCount+4] != '\\' and str_out_temp[lenCount+4] != " ":
				str_out_temp = str_out_temp[:(lenCount+4)] + '"' + '"' +  str_out_temp[(lenCount+4):]
		str_out_temp = str_out_temp[2:-1]
		f1.write('"' + str_out_temp + '"' + "CRLF\n")
	f1.write("};")
#Text string order----------------------------------------------------------------
with open("../GUI/LangTextString/TxtStr_Order_DSX.h", "w") as f1:
	f1.write("#ifndef _TxtStrOrder_\n#define _TxtStrOrder_\n#define CRLF " + '"' + "\\r\\n"  +'"' + "\ntypedef enum {\n")
	for cur_cel in range(1, num_rows):
		data = worksheet.cell_value(cur_cel, TxtStr_Order)
		f1.write(data + "\n")
	f1.write("}TxtStr_Name_e;\n#endif")
f1.close()
#ENGLISH-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_English.c", "w") as f1:
	putHeaderTxtStr()
	f1.write("const char LangStr_EngLish["  +  "] = {\n")
	castAllTheStringToUTF8(English_Column)
f1.close()
#ITALIANO-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_Italiano.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_Italian["  +  "] = {\n")
	castAllTheStringToUTF8(Italiano_Column)
f1.close()
#FRENCH-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_French.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_French["  +  "] = {\n")
	castAllTheStringToUTF8(French_Column)
f1.close()
#GERMAN-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_German.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_German["  +  "] = {\n")
	castAllTheStringToUTF8(German_Column)
f1.close()
#CZECH-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_Czech.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_Czech["  +  "] = {\n")
	castAllTheStringToUTF8(Czech_Column)
f1.close()
#POLISH-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_Polish.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_Polish["  +  "] = {\n")
	castAllTheStringToUTF8(Polish_Column)
f1.close()
#ESPANOL-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_Espanol.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_Espanol["  +  "] = {\n")
	castAllTheStringToUTF8(Espanol_Column)
f1.close()
#PORTUGESE-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_Portugese.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_Portugese["  +  "] = {\n")
	castAllTheStringToUTF8(Portugese_Column)
f1.close()
#KOREAN-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_Korean.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_Korean[] = {\n")
	castAllTheStringToUTF8(Korean_Column)
f1.close()
#RUSSIAN-------------------------------------------------------------------------
with open("../GUI/LangTextString/StringText_Russian.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_Russian[] = {\n")
	castAllTheStringToUTF8(Russian_Column)
f1.close()
#CHINESE Simplified----------------------------------------------------------------
with open("../GUI/LangTextString/StringText_ChineseSimp.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_ChineseSimplified[] = {\n")
	castAllTheStringToUTF8(ChineseSimp_Column)
f1.close()
#CHINESE Traditional----------------------------------------------------------------
with open("../GUI/LangTextString/StringText_ChineseTrad.c", "w") as f1:
	f1.write("#include" + '"' + "TxtStr_Order_DSX.h" + '"\n')
	f1.write("const char LangStr_ChineseTraditional[] = {\n")
	castAllTheStringToUTF8(ChineseTrad_Column)
f1.close()
print("END!!!!!")
