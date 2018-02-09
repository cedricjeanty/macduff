# File: cmacduff.pxd
# Author: Cedric Jeanty
#
# Description:
#   This file contains the definition of the interface to the
# functions defined in macduff.cpp. This definition will allow us to
# wrap this object and make calls to it.
#
# @note - this file must be named differently from the *.pyx file
#    @see docs for cython

from libc.stdint cimport uint8_t, int8_t

cdef extern from "cv.h":
	ctypedef struct IplImage:
		pass
# 	ctypedef cvScalar:
# 		pass

cdef extern from "opencv2/core/core.hpp" namespace "cv":
	cdef cppclass Mat:
		Mat() except +
		void create(int, int, int)
		void* data
		int rows
		int cols
		int channels()

cdef extern from "macduff.h":
	ctypedef struct ColorChecker:
		pass
	# cdef struct ColorChecker:
	# 	float error
	# 	Mat * values
	# 	Mat * points
	# 	float size

	# cdef int _MACBETH_WIDTH "MACBETH_WIDTH"
	# cdef int _MACBETH_HEIGHT "MACBETH_HEIGHT"
	# cdef int _MACBETH_SQUARES "MACBETH_SQUARES"

	# cdef colorchecker_srgb:
	# 	pass

	cdef struct point_t:
		int x
		int y

	cdef struct value_t:
		uint8_t r,g,b

	cdef struct ColorChecker2:
		float error
		point_t points[24]	#TODO: make this number come from the .h
		value_t values[24]
		float size

	# Methods
	# ColorChecker2 find_macbeth( uint8_t *img , int width, int height )
	ColorChecker2 convert_colorChecker(ColorChecker checker)
	IplImage * mat2IplImage(uint8_t *img , int width, int height)
	ColorChecker find_macbeth(IplImage* macbeth_img)