#program_list = ["Py_OpcodeHandle.py", "StringContentConvert.py", "Coordinate_Generated.py", "MenuContext.py"]
program_list = ["MenuContext.py"]

for program in program_list:
    exec(open(program).read())
    print("\nFinished: " + program)