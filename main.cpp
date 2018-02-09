//main.cpp
#include "macduff.h"

int main( int argc, char *argv[] )
{
	if( argc < 2 )
	{
		fprintf( stderr, "Usage: %s image_file [output_image]\n", argv[0] );
		return 1;
	}

	const char *img_file = argv[1];

	IplImage * macbeth_img = cvLoadImage( img_file,
		CV_LOAD_IMAGE_ANYCOLOR|CV_LOAD_IMAGE_ANYDEPTH );

	ColorChecker found_colorchecker = find_macbeth( macbeth_img );

	// print out the colorchecker info
	for(int y = 0; y < MACBETH_HEIGHT; y++) {
		for(int x = 0; x < MACBETH_WIDTH; x++) {
			CvScalar this_value = cvGet2D(found_colorchecker.values,y,x);
			CvScalar this_point = cvGet2D(found_colorchecker.points,y,x);
			
			printf("%.0f,%.0f,%.0f,%.0f,%.0f\n",
				this_point.val[0],this_point.val[1],
				this_value.val[2],this_value.val[1],this_value.val[0]);
		}
	}
	printf("%0.f\n%f\n",found_colorchecker.size,found_colorchecker.error);
	
	// render the found colorchecker
	draw_colorchecker(found_colorchecker.values,found_colorchecker.points,macbeth_img,found_colorchecker.size);
			
	if( argc == 3) {
		cvSaveImage( argv[2], macbeth_img );
	}
	cvReleaseImage( &macbeth_img );

	return 0;
}