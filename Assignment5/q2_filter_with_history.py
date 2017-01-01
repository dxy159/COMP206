import sys
import pickle
import ctypes
import os.path 
from shutil import copyfile

clib = ctypes.cdll.LoadLibrary("./libfast_filter.so")

history = []
if not os.path.isfile("dump.txt"):
	dump = open("dump.txt", 'w+')
else: 
	history = pickle.load(open("dump.txt", 'rb'))

command = sys.argv[1]

if command == "load":
	copyfile(sys.argv[2], "result.bmp")
	os.remove("dump.txt")
	history = []
	history.append(open(sys.argv[2], 'rb').read())

elif command == "filter":
	img = open("result.bmp", 'rb')
	img_data = img.read()

	img.close()

	out_img_data = " " * len(img_data)
	weights = []
	for weight in sys.argv[3:]:
		weights.append(float(weight))
	CFloatArrayType = ctypes.c_float * len(weights)
	filter_weights = CFloatArrayType( *weights )
	filter_width = int(sys.argv[2])
	
	clib.doFiltering(img_data, filter_weights, filter_width, out_img_data)

	out_img = open("result.bmp", 'wb')
	out_img.write(out_img_data)
	out_img.close()
	history.append(out_img_data)
	pickle.dump(history, open("dump.txt", 'wb'))

elif command == "undo":
	active_data = open("result.bmp", 'rb').read()
	if len(history) > 0:
		for i in range(len(history)):
			if history[i] == active_data:
				new_data = history[i - 1]
				open("result.bmp", 'wb').write(new_data)
	else:
		print "Cannot undo image."

elif command == "redo":
	active_data = open("result.bmp", 'rb').read()
	index = 0

	for i in range(len(history)):
		if history[i] == active_data:
			index = i

	if (len(history) > index + 1):
		open("result.bmp", 'wb').write(history[index + 1])
	else:
		print "Cannot redo image"
else:
	print "Please enter in proper command"






