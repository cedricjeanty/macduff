#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

// ColorChecker XYZ vendor information from 2005,
// taken from http://www.babelcolor.com/main_level/ColorChecker.htm
float colorchecker_xyz[24][3] = {
	{10.7846492458451,9.81077849310112,7.70815627733434},
	{36.6852533323943,34.0026228274656,28.7808430583573},
	{15.8548147702032,17.6262277403054,35.6451162787379},
	{10.1128870138148,13.0229995780292,8.00651438080897},
	{22.877874100483,22.0251459896225,46.4889291382332 },
	{28.315347793307,40.7854321257436,48.8343537306251 },
	{38.08855026808,30.4515999685149,9.86964876829322  },
	{11.8273224924775,10.4789901634399,40.7526434703343},
	{27.9304847386873,18.6767748895944,15.7877503722228},
	{8.08839666594609,6.0155088618919,14.9984736208684 },
	{32.6431067060316,43.8995088995326,15.0731798688446},
	{45.4597574924436,42.7562725233556,12.0596519910001},
	{6.65597048768225,5.21320891079771,28.9877731066139},
	{13.7600185368047,22.9070673624638,11.9403205301331},
	{20.3624066906357,12.1131506597928,6.74719666886478},
	{55.1018843173195,58.8866752609815,14.5735569637824},
	{29.4169723142285,19.0876602614381,33.7239597694646},
	{12.8387045600875,18.5459610077425,42.4160176728439},
	{82.2406517798089,88.6827944210071,105.851085257239},
	{52.9906523247944,57.2174950869026,69.8804626631961},
	{32.6063504411145,35.2616841034241,43.2483741898732},
	{17.2741131602921,18.5936401635115,22.7358630679439},
	{7.93386184429607,8.56775332784279,10.818847695165 },
	{2.80207274806336,3.01238408341872,3.82277704246866}
};