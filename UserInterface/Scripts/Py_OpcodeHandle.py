#! /usr/bin/python3
import xlrd
#import the excel path
loc = "GUI_Matrix_DSX.xlsx"
#open file
StartRow        	 				= 2 #Start row from excel file
#Column
Output_OpcodeName	 					= 0
Output_OpcodeValue		 				= 1
Output_ConditionClearOrInitial_Default 	= 2
Output_ConditionClearOrInitial_CC 		= 3
Output_ConditionClearOrInitial_OC 		= 4
Output_ConditionClearOrInitial_SM 		= 5
Output_ConditionClearOrInitial_GAUGE	= 6
Output_ConditionClearOrInitial_GAUGSM 	= 7
Output_ConditionClearOrInitial_BO	 	= 8
Output_ClearOrInitial 					= 9 #Insert the Clear all screen/ Initial whole screen
Output_Update        					= 10 #Insert the function update or not
Output_FlashingOrKeepUpdate 			= 11 #Insert the function flashing or keep update
Output_HandlePreOpcode					= 12 #Consider handle the preOpcode value after changed or not
OutPut_OpcodeComment	 				= 13
OutPut_ManualMappingInterface			= 14

#Define subfunction

def subFunc_ConditionCheck_preOC(dat_condition):
	f1.write("	if(")
	array_ConditonClearOrInitial = dat_condition.split(" | ")
	len_array = len(array_ConditonClearOrInitial)
	for cur_element in range(0, len_array): #Count how many elements					
		if (cur_element != 0):
			f1.write("||") #write the OR when check condition
		f1.write("(" + array_ConditonClearOrInitial[cur_element] + "==pre_DSX_Opcode)") 	
	f1.write(")\n	{\n")
	f1.write("		retCond_uc = FALSE;\n")
def subFunc_ConditionCheck_OC(dat_condition):
	f1.write("	if(")
	array_ConditonClearOrInitial = dat_condition.split(" | ")
	len_array = len(array_ConditonClearOrInitial)
	for cur_element in range(0, len_array): #Count how many elements					
		if (cur_element != 0):
			f1.write("||") #write the OR when check condition
		f1.write("(" + array_ConditonClearOrInitial[cur_element] + "==DSX_Opcode)") 	
	f1.write(")\n	{\n")
	f1.write("		retCond_uc = TRUE;\n")
#open excel file
wb = xlrd.open_workbook(loc)
with open("../GUI/DsxOcConfig.c", "w") as f1:
	f1.write("/*CODE GENERATED PLEASE NOT MODIFY BY HAND!!!*/\n")
	f1.write("#include" + '"' + "L4X9_includes.h" + '"' + "\n")
	f1.write("/*Opcode static handle struct*/\n")
	#Open Opcode Handle worksheet
	#f1.write("typedef enum {\n")
	worksheetOpcode = wb.sheet_by_name("Opcode Handle")
	num_rows_Opcode = worksheetOpcode.nrows
	#Initial array to handle Init/Clear screen function
	f1.write("const p_VoidFunc_t IniFunc_Handle[OC_ValueMax + 1] = {\n")
	for cur_cel in range(StartRow, num_rows_Opcode):
		#Opcode name
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		f1.write("Call_InitFunc_" + dat_OcName + ",\n")
	f1.write("};\n")
	#---------------------------------------------------------
	#Update portion array to handle Init/Clear screen function
	f1.write("const p_VoidFunc_t UpdatePortionFunc_Handle[OC_ValueMax + 1] = {\n")
	for cur_cel in range(StartRow, num_rows_Opcode):
		#Opcode name
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		f1.write("Call_UpdPortionFunc_" + dat_OcName + ",\n")
	f1.write("};\n")
	#---------------------------------------------------------	
	#Condition to clear a portion
	f1.write("const pCondition_Func ConditionCheckFunc[OC_ValueMax + 1] = {\n")
	for cur_cel in range(StartRow, num_rows_Opcode):
		#Opcode name
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		f1.write("Call_CondiCheckFunc_" + dat_OcName + ",\n")
	f1.write("};\n")
	#---------------------------------------------------------	
	#Flashing / Update data function only
	f1.write("const p_VoidFunc_t UpdateOrFlashFunc[OC_ValueMax + 1] = {\n")
	for cur_cel in range(StartRow, num_rows_Opcode):
		#Opcode name
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		f1.write("Call_UpdOrFlashFunc_" + dat_OcName + ",\n")
	f1.write("};\n")
	#---------------------------------------------------------	
	#Process PreOpcode value after Opcode changed
	f1.write("const p_VoidFunc_t HandlePreOCFunc[OC_ValueMax + 1] = {\n")
	for cur_cel in range(StartRow, num_rows_Opcode):
		#Opcode name
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		f1.write("Call_HandlePreOCFunc_" + dat_OcName + ",\n")
	f1.write("};\n")
	#---------------------------------------------------------		
	#Condition to handle preOpcode value after changed
	f1.write("const pCondition_Func CondCheckPreOCFunc[OC_ValueMax + 1] = {\n")
	for cur_cel in range(StartRow, num_rows_Opcode):
		#Opcode name
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		f1.write("Call_CondiCheckPreOCFunc_" + dat_OcName + ",\n")
	f1.write("};\n")
	#---------------------------------------------------------
	print("Portion has " + str(num_rows_Opcode) + " data")	
f1.close()
#-------------------------------------------------------------------------------------------------------------
with open("../GUI/DsxOcConfig.h", "w") as f1:
	f1.write("/*CODE GENERATED PLEASE NOT MODIFY BY HAND*/\n")
	f1.write("#ifndef _DSXOCCFG_H\n")
	f1.write("#define _DSXOCCFG_H\n")
	f1.write("/*Declare the function using to handle Opcode value*/\n")
	#Open Opcode Handle worksheet
	#f1.write("typedef enum {\n")
	worksheetOpcode = wb.sheet_by_name("Opcode Handle")
	num_rows_Opcode = worksheetOpcode.nrows
	f1.write("extern const p_VoidFunc_t IniFunc_Handle[];\n")
	f1.write("extern const p_VoidFunc_t UpdatePortionFunc_Handle[];\n")
	f1.write("extern const pCondition_Func ConditionCheckFunc[];\n")
	f1.write("extern const pCondition_Func CondCheckPreOCFunc[];\n")
	f1.write("extern const p_VoidFunc_t UpdateOrFlashFunc[];\n")
	f1.write("extern const p_VoidFunc_t HandlePreOCFunc[];\n")
	f1.write("/*Declare the needed function support to display -> This shall be manual implement*/\n")
	f1.write("void FuncDoNothing(void);\n")	
	f1.write("unsigned char ReturnTrue(void);\n")	
	f1.write("unsigned char ReturnFalse(void);\n")	
	for cur_cel in range(StartRow, num_rows_Opcode):
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		#Check the declare function Initial/Clear or not
        #When it 'On'' then create one function that will be implement by manual
		dat_ClearOrInitial 	= worksheetOpcode.cell_value(cur_cel, Output_ClearOrInitial)
		dat_MappingInterface = worksheetOpcode.cell_value(cur_cel, OutPut_ManualMappingInterface) #map this function to other handle
		if dat_ClearOrInitial == "On" and dat_MappingInterface == "":
			f1.write("/*1. Clear or Initilal screen for  " + dat_OcName + " operation*/\n")        
			f1.write("void IniOrClrScrFunc_" + dat_OcName + "(void);\n")
        #When it 'On'' then create one function that will be implement by manual
		dat_UpdatePor = worksheetOpcode.cell_value(cur_cel, Output_Update)
		if dat_UpdatePor == "On" or dat_UpdatePor == "ENB" and dat_MappingInterface == "":
			f1.write("/*1.2 Update the porition screen when the opcode changed for " + dat_OcName + " operation*/\n")        
			f1.write("void UpdPorFunc_" + dat_OcName + "(void);\n")
			f1.write("/*Condition check return the result when need to clear all the the screen or one portion only of " + dat_OcName + "*/\n")        
			f1.write("unsigned char CondiCheck_" + dat_OcName + "(void);\n")
		#Flashing or keep update display item
		dat_FlashingItem 	= worksheetOpcode.cell_value(cur_cel, Output_FlashingOrKeepUpdate)
		if dat_FlashingItem == "On" and dat_MappingInterface == "":
			f1.write("/*1.3 Flashing or keep update content of items " + dat_OcName + " */\n")        
			f1.write("void UpdOrFlasFunc_" + dat_OcName + "(void);\n") 			
		#Handle the preOpcode value when Opcode value changed
		dat_HandlePreOpcode = worksheetOpcode.cell_value(cur_cel, Output_HandlePreOpcode)
		if dat_HandlePreOpcode == "On" or dat_HandlePreOpcode == "ENB" and dat_MappingInterface == "":
			f1.write("/*2. Process preOpcode after change to " + dat_OcName + " */\n")        
			f1.write("void HandlePreOCFunc_" + dat_OcName + "(void);\n") 
			f1.write("/*Condition check to progress preOC value" + dat_OcName + "*/\n")        
			f1.write("unsigned char CondiPreOcCheck_" + dat_OcName + "(void);\n")
	for cur_cel in range(StartRow, num_rows_Opcode):
		#List all the function and mapped to manual implement or default function -> void DoNothing(void)
		dat_OcName 				= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		dat_ClearOrInitial 		= worksheetOpcode.cell_value(cur_cel, Output_ClearOrInitial)
		dat_MappingInterface 	= worksheetOpcode.cell_value(cur_cel, OutPut_ManualMappingInterface) #map this function to other handle
		if dat_ClearOrInitial == "On":
			if(dat_MappingInterface == ""):
				f1.write("#define Call_InitFunc_" + dat_OcName + "	IniOrClrScrFunc_" + dat_OcName + "\n")
			else:
				f1.write("#define Call_InitFunc_" + dat_OcName + "	IniOrClrScrFunc_" + dat_MappingInterface + " /*Re-map*/\n")
		else:
			f1.write("#define Call_InitFunc_" + dat_OcName + "	FuncDoNothing\n")	#mean not use
		#Update portion data
		dat_UpdatePor 	= worksheetOpcode.cell_value(cur_cel, Output_Update)
		if dat_UpdatePor == "On" or dat_UpdatePor == "ENB":
			f1.write("#define Call_CondiCheckFunc_" + dat_OcName + "	CondiCheck_" + dat_OcName + "\n")
			f1.write("#define Call_UpdPortionFunc_" + dat_OcName + "	UpdPorFunc_" + dat_OcName + "\n")
		elif dat_ClearOrInitial == "": #when no Update and No clear/Initial -> Do nothing and keep flashing
			f1.write("#define Call_CondiCheckFunc_" + dat_OcName + " ReturnFalse\n")
			f1.write("#define Call_UpdPortionFunc_" + dat_OcName + "	FuncDoNothing\n")#mean not use
		else:
			f1.write("#define Call_CondiCheckFunc_" + dat_OcName + " ReturnTrue\n")
			f1.write("#define Call_UpdPortionFunc_" + dat_OcName + "	FuncDoNothing\n") #mean not use
		#Flashing item or data handle
		dat_FlashingItem 	= worksheetOpcode.cell_value(cur_cel, Output_FlashingOrKeepUpdate)
		if dat_FlashingItem == "On":
			if(dat_MappingInterface == ""):
				f1.write("#define Call_UpdOrFlashFunc_" + dat_OcName + "	UpdOrFlasFunc_" + dat_OcName + "\n")
			else:
				f1.write("#define Call_UpdOrFlashFunc_" + dat_OcName + "	UpdOrFlasFunc_" + dat_MappingInterface + " /*Re-map*/\n")
		else:
			f1.write("#define Call_UpdOrFlashFunc_" + dat_OcName + "	FuncDoNothing\n")#mean not use
		#Hanlde the preOpcode after changed
		dat_HandlePreOpcode = worksheetOpcode.cell_value(cur_cel, Output_HandlePreOpcode)
		if dat_HandlePreOpcode == "On" or dat_HandlePreOpcode == "ENB":
			f1.write("#define Call_CondiCheckPreOCFunc_" + dat_OcName + "	CondiPreOcCheck_" + dat_OcName + "\n")
			f1.write("#define Call_HandlePreOCFunc_" + dat_OcName + "	HandlePreOCFunc_" + dat_OcName + "\n")
		else:
			f1.write("#define Call_CondiCheckPreOCFunc_" + dat_OcName + "	ReturnFalse\n") #Default value
			f1.write("#define Call_HandlePreOCFunc_" + dat_OcName + "	FuncDoNothing\n")
	f1.write("#endif")
	print("Portion has " + str(num_rows_Opcode) + " data")
f1.close()
	
#---------------------------------------------------------
#---------------------------------------------------------
#-----Condition to clear all screen
#---------------------------------------------------------
#---------------------------------------------------------
with open("../GUI/DsxConditionCheck.c", "w") as f1:
	f1.write("/*CODE GENERATED PLEASE NOT MODIFY BY HAND!!!*/\n")
	f1.write("#include" + '"' + "L4X9_includes.h" + '"' + "\n")
	f1.write("/*\n*Condition check when update portion screen is On\n")
	f1.write("* Return TRUE-> Clear/Initial all screen\n")
	f1.write("* Return FALSE-> Update portion only -> hanlde in Update portion function\n*/\n\n")
	#---------------------------------------------------------------------------------------------
	#----- Condition check to clear all the screen or update portion only
	#---------------------------------------------------------------------------------------------
	#---------------------------------------------------------------------------------------------
	for cur_cel in range(StartRow, num_rows_Opcode):
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
        #When it 'On' call this function to check 
		dat_UpdatePor = worksheetOpcode.cell_value(cur_cel, Output_Update)
		if dat_UpdatePor == "On":
			f1.write("/*Condition check return the result when need to clear all the the screen or one portion only of " + dat_OcName + "*/\n")        
			f1.write("unsigned char CondiCheck_" + dat_OcName + "(void)\n")		
			f1.write("{\n")
			f1.write("	unsigned char retCond_uc = TRUE;\n")
			#split condition
			# subFunc_GetAllTheConditionDat(cur_cel)
			dat_Condition_CC 		= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_CC)
			dat_Condition_OC 		= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_OC)
			dat_Condition_SM 		= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_SM)
			dat_Condition_GAUGE 	= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_GAUGE)
			dat_Condition_GAUGESM 	= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_GAUGSM)
			dat_Condition_BO	 	= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_BO)
			dat_Conditon_Default 	= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_Default)
			#When no setting specific to one mode
			if ((dat_Condition_CC=="") and (dat_Condition_OC=="") and (dat_Condition_SM=="") and (dat_Condition_GAUGE=="") and (dat_Condition_GAUGESM=="") and (dat_Condition_BO=="")):
				subFunc_ConditionCheck_preOC(dat_Conditon_Default)
			else:
				f1.write("	switch(GUI_DIVE_Mode)\n{\n")
				#CC Mode
				if (dat_Condition_CC != ""):
					f1.write("case NVD_MDCC:\n")
					subFunc_ConditionCheck_preOC(dat_Condition_CC)
					f1.write("		}\n break;\n")	
				#OC Mode
				if (dat_Condition_OC != ""):
					f1.write("case NVD_MDOC:\n")
					subFunc_ConditionCheck_preOC(dat_Condition_OC)
					f1.write("		}\n break;\n")	
				#SM Mode
				if (dat_Condition_SM != ""):
					f1.write("case NVD_MDSM:\n")
					subFunc_ConditionCheck_preOC(dat_Condition_SM)			
					f1.write("		}\n break;\n")	
				#GAUGE Mode
				if (dat_Condition_GAUGE != ""):
					f1.write("case NVD_MDGAUGE:\n")
					subFunc_ConditionCheck_preOC(dat_Condition_GAUGE)
					f1.write("		}\n break;\n")	
				#GAUGESM Mode
				if (dat_Condition_GAUGESM != ""):
					f1.write("case NVD_MDGSM:\n")
					subFunc_ConditionCheck_preOC(dat_Condition_GAUGESM)
					f1.write("		}\n break;\n")					
				#BO Mode
				if (dat_Condition_BO != ""):
					f1.write("case NVD_MDBO:\n")
					subFunc_ConditionCheck_preOC(dat_Condition_BO)
					f1.write("		}\n break;\n")	
				#default
				f1.write("	default:\n")
				subFunc_ConditionCheck_preOC(dat_Conditon_Default)
				f1.write("		}\n break;\n")	
			f1.write("}\n	return retCond_uc;\n};\n")
	#---------------------------------------------------------------------------------------------
	#----- Condition check to progress preOpcode value
	#---------------------------------------------------------------------------------------------
	#---------------------------------------------------------------------------------------------
	f1.write("/*\n*Condition check when redraw the portion or not\n")
	f1.write("* Return TRUE-> Redraw that item\n")
	f1.write("* Return FALSE-> Do nothing\n*/\n\n")
	for cur_cel in range(StartRow, num_rows_Opcode):
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
        #When it 'On'' then create one function that will be implement by manual
		dat_HandlePreOpcode = worksheetOpcode.cell_value(cur_cel, Output_HandlePreOpcode)
		if dat_HandlePreOpcode == "On":
			dat_Conditon_Default = worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_Default)
			f1.write("/*Condition check return the result when need to clear all the the screen or one portion only of " + dat_OcName + "*/\n")        
			f1.write("unsigned char CondiPreOcCheck_" + dat_OcName + "(void)\n")		
			f1.write("{\n")
			f1.write("	unsigned char retCond_uc = FALSE;\n")
			#split condition
			dat_Condition_CC 		= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_CC)
			dat_Condition_OC 		= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_OC)
			dat_Condition_SM 		= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_SM)
			dat_Condition_GAUGE 	= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_GAUGE)
			dat_Condition_GAUGESM 	= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_GAUGSM)
			dat_Condition_BO 	= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_BO)
			dat_Conditon_Default 	= worksheetOpcode.cell_value(cur_cel, Output_ConditionClearOrInitial_Default)				
			if ((dat_Condition_CC=="") and (dat_Condition_OC=="") and (dat_Condition_SM=="") and (dat_Condition_GAUGE=="") and (dat_Condition_GAUGESM=="") and (dat_Condition_BO=="")):
				subFunc_ConditionCheck_OC(dat_Conditon_Default)
			else:
				f1.write("	switch(GUI_DIVE_Mode)\n{\n")
				#CC Mode
				if (dat_Condition_CC != ""):
					f1.write("case NVD_MDCC:\n")
					subFunc_ConditionCheck_OC(dat_Condition_CC)
					f1.write("		}\n break;\n")	
				#OC Mode
				if (dat_Condition_OC != ""):
					f1.write("case NVD_MDOC:\n")
					subFunc_ConditionCheck_OC(dat_Condition_OC)
					f1.write("		}\n break;\n")	
				#SM Mode
				if (dat_Condition_SM != ""):
					f1.write("case NVD_MDSM:\n")
					subFunc_ConditionCheck_OC(dat_Condition_SM)			
					f1.write("		}\n break;\n")	
				#GAUGE Mode
				if (dat_Condition_GAUGE != ""):
					f1.write("case NVD_MDGAUGE:\n")
					subFunc_ConditionCheck_OC(dat_Condition_GAUGE)
					f1.write("		}\n break;\n")	
				#GAUGESM Mode
				if (dat_Condition_GAUGESM != ""):
					f1.write("case NVD_MDGSM:\n")
					subFunc_ConditionCheck_OC(dat_Condition_GAUGESM)
					f1.write("		}\n break;\n")					
				#BO Mode
				if (dat_Condition_BO != ""):
					f1.write("case NVD_MDBO:\n")
					subFunc_ConditionCheck_OC(dat_Condition_BO)
					f1.write("		}\n break;\n")	
				#default
				f1.write("	default:\n")
				subFunc_ConditionCheck_OC(dat_Conditon_Default)
				f1.write("		}\n break;\n")	
			f1.write("}\n	return retCond_uc;\n};\n")
f1.close()
#-------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------
#---------OPCODE LIST-----------
#-------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------
#-------------------------------------------------------------------------------------------------------------
with open("../DsxOCDefine.h", "w") as f1:
	f1.write("/*CODE GENERATED PLEASE NOT MODIFY BY HAND!!!*/\n")
	f1.write("#ifndef _DSXOC_H\n")
	f1.write("#define _DSXOC_H\n")
	f1.write("/*Definitions of 32-bit Opcode*/\n")
	f1.write("/*----------------------------------------*/\n\n")
	#Open Opcode_DSX worksheet
	f1.write("typedef enum \n{\n")
	worksheetOpcode = wb.sheet_by_name("Opcode Handle")
	num_rows_Opcode = worksheetOpcode.nrows
	cntRow = 0
	for cur_cel in range(StartRow, num_rows_Opcode):
		#Opcode name
		dat_OcName 	= worksheetOpcode.cell_value(cur_cel, Output_OpcodeName)
		#Opcode value defined
		dat_OcValue = worksheetOpcode.cell_value(cur_cel, Output_OpcodeValue)
		dat_Comment = worksheetOpcode.cell_value(cur_cel, OutPut_OpcodeComment)
		if dat_Comment!="":
			dat_Comment =  "/*" + dat_Comment + "*/"
		f1.write(dat_OcName + " = " + str(cntRow) + "u" + dat_Comment + ",\n")
		#count in creare
		cntRow=cntRow+1
	f1.write("} DSX_OPCODE_t;\n")
	f1.write("#define OC_ValueMax	(" + str(cntRow) + "U)\n")
	f1.write("#endif")
	print("Portion has " + str(num_rows_Opcode) + " data")	
f1.close()
print("END!!!!!")
	