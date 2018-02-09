# File: macduff.pyx
# Author: Cedric Jeanty
#
# Description:
#   This file contains a cython implementation for finding
# macbeth color calibration cards in images

import numpy as np
cimport numpy as np

cimport cmacduff

#TODO: find some way to grab this from the .h file?
macbeth_sRGB = [
	(67,81,115),
	(129,149,196),
	(157,123,93),
	(65,108,90),
	(176,129,130),
	(171,191,99),
	(45,123,220),
	(168,92,72),
	(98,84,195),
	(105,59,91),
	(62,189,160),
	(41,161,229),
	(147,62,43),
	(72,149,71),
	(56,48,176),
	(22,200,238),
	(150,84,188),
	(166,136,0),
	(240,245,245),
	(201,201,200),
	(161,161,160),
	(121,121,120),
	(85,84,83),
	(50,50,50)
]

DTYPE = np.uint8
ctypedef np.uint8_t DTYPE_t

def find_macbeth(np.ndarray[DTYPE_t, ndim=3, mode="c"] img):
	cdef DTYPE_t* pframe = &(img[0,0,0])
	cdef int r,c 
	# cdef struct ColorChecker color_data

	ipl_img = cmacduff.mat2IplImage(pframe, img.shape[1], img.shape[0])
	color_data = cmacduff.find_macbeth(ipl_img)
	color_data2 = cmacduff.convert_colorChecker(color_data)

	return color_data2



