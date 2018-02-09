//macduff.h

#ifndef MACDUFF_H
#define MACDUFF_H

#include <opencv/cv.h>
#include <opencv/highgui.h>

#define MACBETH_WIDTH   6
#define MACBETH_HEIGHT  4
#define MACBETH_SQUARES MACBETH_WIDTH * MACBETH_HEIGHT

// BabelColor averages in sRGB:
//   http://www.babelcolor.com/main_level/ColorChecker.htm
// (converted to BGR order for comparison)
static CvScalar colorchecker_srgb[MACBETH_HEIGHT][MACBETH_WIDTH] =
	{
		{
			cvScalar(67,81,115),
			cvScalar(129,149,196),
			cvScalar(157,123,93),
			cvScalar(65,108,90),
			cvScalar(176,129,130),
			cvScalar(171,191,99)
		},
		{
			cvScalar(45,123,220),
			cvScalar(168,92,72),
			cvScalar(98,84,195),
			cvScalar(105,59,91),
			cvScalar(62,189,160),
			cvScalar(41,161,229)
		},
		{
			cvScalar(147,62,43),
			cvScalar(72,149,71),
			cvScalar(56,48,176),
			cvScalar(22,200,238),
			cvScalar(150,84,188),
			cvScalar(166,136,0)
		},
		{
			cvScalar(240,245,245),
			cvScalar(201,201,200),
			cvScalar(161,161,160),
			cvScalar(121,121,120),
			cvScalar(85,84,83),
			cvScalar(50,50,50)
		}
	};


struct ColorChecker {
	double error;
	CvMat * values;
	CvMat * points;
	double size;
};

struct point_t {
	int x;
	int y;
};

struct value_t {
	uint8_t r,g,b;
};

struct ColorChecker2 {
	double error;
	point_t points[MACBETH_SQUARES];
	value_t values[MACBETH_SQUARES];
	double size;
};

void draw_colorchecker(CvMat * colorchecker_values, CvMat * colorchecker_points, IplImage * image, int size);

ColorChecker2 convert_colorChecker(ColorChecker checker);

IplImage * mat2IplImage(uint8_t *img , int width, int height );

// IplImage * find_macbeth(uint8_t *img , int width, int height);
// ColorChecker2 find_macbeth(uint8_t *img , int width, int height);
ColorChecker find_macbeth(IplImage* macbeth_img);
// ColorChecker2 convert_colorChecker(ColorChecker * checker);


#endif