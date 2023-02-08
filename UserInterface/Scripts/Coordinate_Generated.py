#! /usr/bin/python3
import xlrd
#import the excel path
loc = "DSX_CoordinationClear.xlsx"
#open file
#data = "abc"
OutPutNAME	 	= 0
OutPutNORMAL 	= 10
OutPutFLIPPED 	= 19
OutPutPointer 	= 20
OutputCompass_X	= 0
OutputCompass_Y	= 1
#Worksheet POINTs	
OutPutNORMAL_POINTs		= 3
OutPutFLIPPED_POINTs 	= 6
OutPutPointer_POINTs	= 7
#open excel file
wb = xlrd.open_workbook(loc)
with open("../GUI/DSX_Coordinate.c", "w") as f1:
	f1.write("/*CODE GENERATED PLEASE NOT MODIFY BY HAND!!!*/\n")
	f1.write("#include" + ' "' + "L4X9_includes.h" + '"\n')
	f1.write("#include" + ' "' + "DSX_Coordinate.h" + '"\n')
	#Insert compass coordinate
	worksheet_compass = wb.sheet_by_name("CompassPoint")
	num_rows_Compass = worksheet_compass.nrows
	print("Copied: [" + str(num_rows_Compass) + "] data from CompassPoint")
	f1.write("/*Compass points to display in main compass*/\n")
	f1.write("/*There are 2 parts of Y coordinate and X shall be increase from 0 to 360*/\n")
	f1.write("const GUI_POINT Pos_CompassMainArrayRotate[" + str(num_rows_Compass) +"]= {")
	for cur_cel in range(0, num_rows_Compass):
		#Process the X value
		data = worksheet_compass.cell_value(cur_cel, OutputCompass_X)
		convertedStrX = str(data)
		convertedStrX = convertedStrX.replace(".0","")
		#Process the Y value
		data = worksheet_compass.cell_value(cur_cel, OutputCompass_Y)
		convertedStrY = str(data)
		convertedStrY = convertedStrY.replace(".0","")
		f1.write("{" + convertedStrX + "," + convertedStrY + "},")
	f1.write("};\n")
	print("Process portion data")
	#Worksheet_Main	
	worksheet_MAIN = wb.sheet_by_name("Main")
	num_rows_MAIN = worksheet_MAIN.nrows
	for cur_cel in range(2, num_rows_MAIN):
		#Output the NAME
		data = worksheet_MAIN.cell_value(cur_cel, OutPutNAME)
		f1.write("/*" + data + " portion*/\n")
		#Output the Normal screen
		data = worksheet_MAIN.cell_value(cur_cel, OutPutNORMAL)
		f1.write(data + "\n")
		#Output the Flipped screen
		data = worksheet_MAIN.cell_value(cur_cel, OutPutFLIPPED)
		f1.write(data + "\n")
		#Output the pointer to these data
		data = worksheet_MAIN.cell_value(cur_cel, OutPutPointer)
		f1.write(data + "\n")
		#f1.write("/*-----------------------------------------------------------------------------------------*/\n")
	print("Portion has " + str(num_rows_MAIN) + " data")	
	#-------------------------------------------------------------------------------------------------------------
	worksheet_POINTs = wb.sheet_by_name("POINTs")		
	print("Process POINTs data")
	num_rows_POINTs = worksheet_POINTs.nrows
	for cur_cel in range(1, num_rows_POINTs):
		#Output the NAME
		data = worksheet_POINTs.cell_value(cur_cel, OutPutNAME)
		f1.write("/*" + data + " coordination*/\n")
		#Output the Normal screen
		data = worksheet_POINTs.cell_value(cur_cel, OutPutNORMAL_POINTs)
		f1.write(data + "\n")
		#Output the Flipped screen
		data = worksheet_POINTs.cell_value(cur_cel, OutPutFLIPPED_POINTs)
		f1.write(data + "\n")
		#Output the pointer to these data
		data = worksheet_POINTs.cell_value(cur_cel, OutPutPointer_POINTs)
		f1.write(data + "\n")
		#f1.write("/*-----------------------------------------------------------------------------------------*/\n")
	print("POINTs has " + str(num_rows_POINTs) + " data")	
	#Assign the value base on the screen rotation
	f1.write("void AsssignedCoordinated(uint8_t FlippingStauts) \n{\n")
	f1.write("\tif(FlippingStauts)\n{\n")
	f1.write("\t/*If screen is flipped then changed the coorditnate*/\n")
	#Assigned pointer value when flipped screen
	for cur_cel in range(2, num_rows_MAIN):
		#Flipped portion
		data = worksheet_MAIN.cell_value(cur_cel, OutPutNAME)
		f1.write("\t" + data + " = &" + data + "_Flipped;\n")
	for cur_cel in range(1, num_rows_POINTs):
		#Flipped coordination
		data = worksheet_POINTs.cell_value(cur_cel, OutPutNAME)
		f1.write("\t" + data + " = &" + data + "_Flipped;\n")
	f1.write("\t}\n\telse{\n")
	#Assigned pointer value when normal screen
	f1.write("\t/*Assign the normal value when screen is no flipped*/\n")
	for cur_cel in range(2, num_rows_MAIN):
		#Normal portion
		data = worksheet_MAIN.cell_value(cur_cel, OutPutNAME)
		f1.write("\t" + data + " = &" + data + "_Normal;\n")
	for cur_cel in range(1, num_rows_POINTs):
		#Normal coordination
		data = worksheet_POINTs.cell_value(cur_cel, OutPutNAME)
		f1.write("\t" + data + " = &" + data + "_Normal;\n")
	f1.write("\t}\n};")
f1.close()
with open("../GUI/DSX_Coordinate.h", "w") as f1:
	f1.write("#ifndef _DSX_Coordinate_H_\n#define _DSX_Coordinate_H_\n")
	f1.write("extern const GUI_POINT Pos_CompassMainArrayRotate[];\n")
	f1.write("/*Coordinate GUI struct*/\n")
	f1.write("typedef struct \n{\n")
	f1.write("int X;\n")
	f1.write("int Y;\n")
	f1.write("int X0;\n")
	f1.write("int Y0;\n")
	f1.write("int Width;\n")
	f1.write("int Height;\n")
	f1.write("int X1;\n")
	f1.write("int Y1;\n")
	f1.write("} CooGUI_tds;\n")
	f1.write("void AsssignedCoordinated(uint8_t);\n")
	for cur_cel in range(2, num_rows_MAIN):
		#Normal portion
		data = worksheet_MAIN.cell_value(cur_cel, OutPutPointer)
		f1.write("extern " + data + "\n")
	num_rows_POINTs = worksheet_POINTs.nrows
	for cur_cel in range(1, num_rows_POINTs):
		data = worksheet_POINTs.cell_value(cur_cel, OutPutPointer_POINTs)
		f1.write("extern " + data + "\n")	
	f1.write("#endif")
f1.close()	
print("END!!!!!")
