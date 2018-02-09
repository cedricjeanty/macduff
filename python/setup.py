# File: setup.py
# Author: Cedric Jeanty
#
# Description:
#   Cython-based extension build
#
import os.path
from subprocess import check_output
from distutils.core import setup, Extension
import numpy as np
from Cython.Build import cythonize

C_DIR = ".."
CV_DIRS = [x.strip()[2:] for x in check_output(['pkg-config', '--cflags', 'opencv']).split(' ')]
CV_LINK_ARGS = [x.strip() for x in check_output(['pkg-config', '--libs', 'opencv']).split(' ')[1:]]

INC_DIRS = []
INC_DIRS.append(C_DIR)
INC_DIRS.extend(CV_DIRS)

ext_modules=[
	Extension(
		"macduff",
		sources=["macduff.pyx",  os.path.join(C_DIR,"macduff.cpp")],
		include_dirs=INC_DIRS,
		libraries=[], # Unix-like specific
		language="c++",
		extra_link_args=CV_LINK_ARGS
	)
]

setup(
		name = 'MACDUFF',
		version = '0.1',
		include_dirs = [np.get_include()], #Add Include path of numpy
		ext_modules = cythonize(ext_modules)
	)