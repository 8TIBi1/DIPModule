#include <stdlib.h>
#include "BMPHelper.h"
#include <stdio.h>
#include <string.h>


#pragma warning(disable : 4996)




int main(int argc,const char* argv){

	/*if (argc==1||(argc==2&&(0==strcmp("help",argv[1])|| 0 == strcmp("h", argv[1]))))
	{
		printf("Welcome to the BMPBox.\n");
		printf("You can execute the program with the following functions:\n");
		printf("DIPModule help/h\t\tlist available subcommands and some concept guides.\n");
	}*/

	/*
	��һ����ҵ��BMP�ļ�����
	*/
	//BMPResolver();

	/*
	�ڶ�����ҵ��ֱ��ͼ����
	*/
	//HistogramStatic();
	
	/*
	��������ҵ���ռ����˲�
	*/

	/*SpatialDomainFilter("3-1.bmp", "3-2.bmp", TYPE_AVERAGE);
	SpatialDomainFilter("3-1.bmp", "3-3.bmp", TYPE_MEDIAN);*/

	/*SpatialDomainFilter("3-1.bmp", "3-2.bmp", TYPE_AVERAGE);
	for (size_t i = 0; i < 2; i++)
	{
		SpatialDomainFilter("3-2.bmp", "3-2-3.bmp", TYPE_AVERAGE);
	}
	SpatialDomainFilter("3-1.bmp", "3-3.bmp", TYPE_MEDIAN);
	for (size_t i = 0; i < 2; i++)
	{
		SpatialDomainFilter("3-3.bmp", "3-3-3.bmp", TYPE_MEDIAN);
	}
*/

	/*
	���Ĵ���ҵ��ͼ��任
	*/


	//ͼ������

	//transform("3-3.bmp", "scale.bmp", TRANSFORM_SCALE, 3, 4);

	//ͼ��ƽ��

	//transform("3-3.bmp", "shift.bmp", TRANSFORM_SHIFT, -20, -200);

	//ͼ����
	////ˮƽ
	//transform("3-3.bmp", "x-mirror.bmp", TRANSFORM_MIRROR, 1, 0);
	////��ֱ
	//transform("3-3.bmp", "y-mirror.bmp", TRANSFORM_MIRROR, -1, 0);

	//ͼ����ת
	//transform("3-3.bmp", "rotate.bmp", TRANSFORM_ROTATE, PI/8, 0);

	/*
	�������ҵ����ֵ�ָ�
	*/

	//ThresholdSegment("2.bmp", "threshold-seed.bmp", THRESHOLD_SEED, 100);
	//ThresholdSegment("2.bmp", "threshold-iteration.bmp", THRESHOLD_ITERATION, 10);
	//ThresholdSegment("2.bmp", "threshold-ostu.bmp", THRESHOLD_OSTU, 0);


	/*
	��������ҵ����������ķָ�
	*/



	/*
	���ߴ���ҵ����Ե���
	*/
/*	//prewitt
	EdgeDetection("3-3.bmp", "3-prewitt.bmp", Edge_Dectect_Type_PREWITT);
	//sobel
	EdgeDetection("3-3.bmp", "3-sobel.bmp", Edge_Dectect_Type_SOBEL);
	//log
	EdgeDetection("3-3.bmp", "3-log.bmp", Edge_Dectect_Type_LOG);*/


	/*
	�ڰ˴���ҵ������任
	*/

	/*
	�ھŴ���ҵ����������������ȡ
	*/
	system("pause");
	return 0;
}