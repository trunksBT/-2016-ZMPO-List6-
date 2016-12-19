import os
for file in os.listdir("Handlers"):
	with open("test.txt", "a") as myfile:
    	myfile.write(file)
