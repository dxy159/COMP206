import ctypes
import sys
import struct

clib = ctypes.cdll.LoadLibrary("./libfast_filter.so")


img = open(sys.argv[1], 'rb')
img_data = img.read()
img.close()


out_img_data = " " * len(img_data)

filter_width = int(sys.argv[3])
weights = []
for weight in sys.argv[4:]:
	weights.append(float(weight))
CFloatArrayType = ctypes.c_float * len(weights)
filter_weights = CFloatArrayType( *weights )

clib.doFiltering(img_data, filter_weights, filter_width, out_img_data)

out_img = open(sys.argv[2], 'wb')
out_img.write(out_img_data)
out_img.close()
