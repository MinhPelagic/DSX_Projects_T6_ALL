#! /usr/bin/python3
import xlrd
import ast
#import the excel path
loc = "GUI_Matrix_DSX.xlsx"
#open file
StartRow        	 			= 1 #Start row from excel file
#Column
Output_ContextName	 			= 0
Output_LeftContext        	 	= 1
Output_CenterContext        	= 2
Output_Middle_01_Context        = 3
Output_Middle_02_Context        = 4
Output_RightContext        		= 5
Output_DispDot_Context        	= 6 #Check the display Dot
Output_Pos_CC	        		= 7
Output_Pos_OC	        		= 8
Output_Pos_SM	        		= 9
Output_Pos_GAUGE        		= 10
Output_Pos_GAUGSM        		= 11
Output_Pos_BO	        		= 12
Output_Comment	        		= 13
#open excel file
wb = xlrd.open_workbook(loc)
context_File_list = \
[\
"../GUI/OpcodeHandle/Menu/Device Settings/", \
"../GUI/OpcodeHandle/Menu/Display Settings/", \
"../GUI/OpcodeHandle/Menu/Dive Settings/", \
"../GUI/OpcodeHandle/Menu/Set Alarms/", \
"../GUI/OpcodeHandle/Menu/Set SP/", \
"../GUI/OpcodeHandle/Menu/Set Date and Time/", \
"../GUI/OpcodeHandle/Menu/SP Switch/", \
"../GUI/OpcodeHandle/Menu/Set Menu/", \
"../GUI/OpcodeHandle/Menu/Main Menu/", \
"../GUI/OpcodeHandle/Menu/Dive Main Menu/", \
"../GUI/OpcodeHandle/Menu/Dive Menu/", \
"../GUI/OpcodeHandle/Menu/Set Gases/", \
"../GUI/OpcodeHandle/Menu/Dive Planner/", \
"../GUI/OpcodeHandle/Menu/GPS Menu/", \
"../GUI/OpcodeHandle/Compass Mode/", \
]
#The tab name in excel file
tabMenuInExcel = \
[\
"DeviceSettings",
"DisplaySettings",
"DiveSettings",
"SetAlarms",
"SetSP",
"SetDateAndTime",
"SPSwitch",
"SetMenu",
"MainMenu",
"DiveMainMenu",
"DiveMenu",
"SetGases",
"DivePlanner",
"GPSMenu",
"CompassMenu",
]
#count the items
i_count	= 0
for currentFile in context_File_list:
	with open(currentFile + "Context" + tabMenuInExcel[i_count] + "Cfg" + ".c", "w") as f1:
		f1.write("/*CODE GENERATED PLEASE NOT MODIFY BY HAND!!!*/\n")
		f1.write("#include " + '"' + "L4X9_includes.h" + '"' + "\n")
		f1.write("#include " + '"' + "Context" + tabMenuInExcel[i_count] + "Cfg.h" + '"' + "\n")
		#Open worksheet
		worksheetOpcode = wb.sheet_by_name(tabMenuInExcel[i_count])
		f1.write("/*\nContext content progress to " + tabMenuInExcel[i_count] + "\nNOTE: These config are generated !!!\n*/\n")
		num_rows_Opcode = worksheetOpcode.nrows
		#Write the content set variables
		for cur_cel in range(StartRow, num_rows_Opcode):
			#Comment
			dat_Comment = worksheetOpcode.cell_value(cur_cel, Output_Comment)
			f1.write("/*\n----------------------------------\n" + str(dat_Comment) + \
			"\n----------------------------------\n*/\n")
			#Context name
			dat_ContextName = worksheetOpcode.cell_value(cur_cel, Output_ContextName)
			f1.write("const menuItemContext_ts Context_" + dat_ContextName + "=\n{\n")
			#Left context
			dat_LeftContext = worksheetOpcode.cell_value(cur_cel, Output_LeftContext)
			if 'On' == dat_LeftContext or 'OnlyLeft' == dat_LeftContext:
				if 'On' == dat_LeftContext:
					f1.write("ENABLE_DISPLAY,\n")
				else:
					f1.write("ONLYLEFT_DISPLAY,\n")
				f1.write(dat_ContextName + "_Context_Left,\n")
			else:
				f1.write("DISABLE_DISPLAY,\n")
				f1.write("ContextEmpty,\n")
			#Center context
			dat_CenterContext = worksheetOpcode.cell_value(cur_cel, Output_CenterContext)
			if 'On' == dat_CenterContext:
				f1.write("ENABLE_DISPLAY,\n")
				f1.write(dat_ContextName + "_Context_Center,\n")
			else:
				f1.write("DISABLE_DISPLAY,\n")
				f1.write("ContextEmpty,\n")
			#Middle-01 context
			dat_Middle_01_Contextt = worksheetOpcode.cell_value(cur_cel, Output_Middle_01_Context)
			if 'On' == dat_Middle_01_Contextt:
				f1.write("ENABLE_DISPLAY,\n")
				f1.write(dat_ContextName + "_Context_Middle_01,\n")
			else:
				f1.write("DISABLE_DISPLAY,\n")
				f1.write("ContextEmpty,\n")
			#Middle-02 context
			dat_Middle_02_Contextt = worksheetOpcode.cell_value(cur_cel, Output_Middle_02_Context)
			if 'On' == dat_Middle_02_Contextt:
				f1.write("ENABLE_DISPLAY,\n")
				f1.write(dat_ContextName + "_Context_Middle_02,\n")
			else:
				f1.write("DISABLE_DISPLAY,\n")
				f1.write("ContextEmpty,\n")				
			#Right context
			dat_RightContext = worksheetOpcode.cell_value(cur_cel, Output_RightContext)
			if 'On' == dat_RightContext or 'ColorOn' == dat_RightContext:
				f1.write("ENABLE_DISPLAY,\n")
				f1.write(dat_ContextName + "_Context_Right,\n")
			else:
				f1.write("DISABLE_DISPLAY,\n")
				f1.write("ContextEmpty,\n")						
			#Right Color handle or not
			dat_RightContext = worksheetOpcode.cell_value(cur_cel, Output_RightContext)
			if 'ColorOn' == dat_RightContext:
				f1.write("ENABLE_COLOR_HANDLE,\n")
			else:
				f1.write("DISABLE_COLOR_HANDLE,\n")
			#Check the condition display the dot
			dat_DispTheDot_Context = worksheetOpcode.cell_value(cur_cel, Output_DispDot_Context)
			if 'On' == dat_DispTheDot_Context:
				f1.write("&" + dat_ContextName + "_CheckDispTheDot,\n") #point to function condition check
			else:
				f1.write("&ReturnFalse,\n")			
			#Set position in each mode CC/OC/SM/GAUGE/GAUGSM
			dat_posCC = worksheetOpcode.cell_value(cur_cel, Output_Pos_CC)
			dat_posOC = worksheetOpcode.cell_value(cur_cel, Output_Pos_OC)
			dat_posSM = worksheetOpcode.cell_value(cur_cel, Output_Pos_SM)
			dat_posGAUGE = worksheetOpcode.cell_value(cur_cel, Output_Pos_GAUGE)
			dat_posGAUGESM = worksheetOpcode.cell_value(cur_cel, Output_Pos_GAUGSM)
			dat_posBO = worksheetOpcode.cell_value(cur_cel, Output_Pos_BO)
			f1.write("{" + str(dat_posCC) + "," + str(dat_posOC) + "," + str(dat_posSM) + "," + str(dat_posGAUGE) + "," + str(dat_posGAUGESM) + "," + str(dat_posBO) + "},\n")
			f1.write("};\n")
	i_count = i_count + 1
	f1.close()
#---------------------------------------------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------------------------------------------
#-----------Header files---------------------------------
#---------------------------------------------------------------------------------------------------------------------------------
#---------------------------------------------------------------------------------------------------------------------------------
i_count	= 0
for currentFile in context_File_list:
	with open(currentFile + "Context" + tabMenuInExcel[i_count] + "Cfg" + ".h", "w") as f1:
		f1.write("#ifndef " + "__CONTEXT_" + tabMenuInExcel[i_count].upper() + "_H__\n")
		f1.write("#define " + "__CONTEXT_" + tabMenuInExcel[i_count].upper() + "_H__\n")
		f1.write("#include " + "<stdint.h>\n")
		#Open worksheet
		worksheetOpcode = wb.sheet_by_name(tabMenuInExcel[i_count])
		f1.write("/*\nContext handle to " + tabMenuInExcel[i_count] + "\nNOTE: These config are generated !!!\n*/\n")
		num_rows_Opcode = worksheetOpcode.nrows
		#Write the content set variables
		for cur_cel in range(StartRow, num_rows_Opcode):
			#Context name
			dat_ContextName = worksheetOpcode.cell_value(cur_cel, Output_ContextName)
			#extern variables
			f1.write("extern const menuItemContext_ts Context_" + dat_ContextName + ";\n")
			#Left context
			dat_LeftContext = worksheetOpcode.cell_value(cur_cel, Output_LeftContext)
			if 'On' == dat_LeftContext or 'OnlyLeft' == dat_LeftContext:
				f1.write("void " + dat_ContextName + "_Context_Left(char*);\n")
			#Center context
			dat_CenterContext = worksheetOpcode.cell_value(cur_cel, Output_CenterContext)
			if 'On' == dat_CenterContext:
				f1.write("void " + dat_ContextName + "_Context_Center(char*);\n")
			#Middle-01 context
			dat_Middle_01_Context = worksheetOpcode.cell_value(cur_cel, Output_Middle_01_Context)
			if 'On' == dat_Middle_01_Context:
				f1.write("void " + dat_ContextName + "_Context_Middle_01(char*);\n")
			#Middle-02 context
			dat_Middle_02_Context = worksheetOpcode.cell_value(cur_cel, Output_Middle_02_Context)
			if 'On' == dat_Middle_02_Context:
				f1.write("void " + dat_ContextName + "_Context_Middle_02(char*);\n")	
			#Condition check display the dot
			dat_DispTheDot_Context = worksheetOpcode.cell_value(cur_cel, Output_Middle_02_Context)
			if 'On' == dat_DispTheDot_Context:
				f1.write("unsigned char " + dat_ContextName + "_CheckDispTheDot(void);\n")		
			#Right context
			dat_RightContext = worksheetOpcode.cell_value(cur_cel, Output_RightContext)
			if 'On' == dat_RightContext or 'ColorOn' == dat_RightContext:
				f1.write("void " + dat_ContextName + "_Context_Right(char*);\n")
		f1.write("\n#endif\n")
	i_count = i_count + 1
	f1.close() 	
print("END!!!!!")
