#include <stdlib.h>
#include "BMPHelper.h"
#include <stdio.h>
#include <string.h>


#pragma warning(disable : 4996)


void allDone() {
	printf("Welcome to the BMPBox.\n");

	
	BMPResolver();

	HistogramStatic();

	SpatialDomainFilter("3-1.bmp", "3-2.bmp", TYPE_AVERAGE);
	SpatialDomainFilter("3-1.bmp", "3-3.bmp", TYPE_MEDIAN);

	//ͼ������

	transform("3-3.bmp", "scale.bmp", TRANSFORM_SCALE, 3, 4);

	//ͼ��ƽ��

	transform("3-3.bmp", "shift.bmp", TRANSFORM_SHIFT, -20, -200);

	//ͼ����
	//ˮƽ
	transform("3-3.bmp", "x-mirror.bmp", TRANSFORM_MIRROR, 1, 0);
	//��ֱ
	transform("3-3.bmp", "y-mirror.bmp", TRANSFORM_MIRROR, -1, 0);

	//ͼ����ת
	transform("3-3.bmp", "rotate.bmp", TRANSFORM_ROTATE, PI/8, 0);


	ThresholdSegment("2.bmp", "threshold-seed.bmp", THRESHOLD_SEED, 100);
	ThresholdSegment("2.bmp", "threshold-iteration.bmp", THRESHOLD_ITERATION, 10);
	ThresholdSegment("2.bmp", "threshold-ostu.bmp", THRESHOLD_OSTU, 0);

	/*
	���ߴ���ҵ����Ե���
	*/
		//prewitt
		EdgeDetection("3-3.bmp", "3-prewitt.bmp", Edge_Dectect_Type_PREWITT);
		//sobel
		EdgeDetection("3-3.bmp", "3-sobel.bmp", Edge_Dectect_Type_SOBEL);
		//log
		EdgeDetection("3-3.bmp", "3-log.bmp", Edge_Dectect_Type_LOG);
}

int main(int argc,const char* argv){

	/*if (argc==1||(argc==2&&(0==strcmp("help",argv[1])|| 0 == strcmp("h", argv[1]))))
	{
		printf("Welcome to the BMPBox.\n");
		printf("You can execute the program with the following functions:\n");
		printf("DIPModule help/h\t\tlist available subcommands and some concept guides.\n");
	}*/

	/*if (argc==1)
	{
		allDone();
	}*/
	printf("Welcome to the BMPBox.\n");
	printf("\n");
	printf("Processing...\n");
	printf("\n");
	/*
	��һ����ҵ��BMP�ļ�����
	*/

	printf("1.BMP�ļ����� Processing...\n");
	BMPResolver();
	printf("\n");


	/*
	�ڶ�����ҵ��ֱ��ͼ����
	*/
	printf("2.ֱ��ͼ���� Processing...\n");
	HistogramStatic();
	printf("\n");
	
	/*
	��������ҵ���ռ����˲�
	*/
	printf("3.�ռ����˲� Processing...\n");
	const char * spatialFrom = "3-1.bmp";
	const char * spatialAverageTo = "3-2.bmp";
	const char * spatialMedianTo = "3-3.bmp";
	printf("Read from %s\n", spatialFrom);
	SpatialDomainFilter(spatialFrom, spatialAverageTo, TYPE_AVERAGE);
	printf("Write Average to %s\n", spatialAverageTo);
	SpatialDomainFilter(spatialFrom, spatialMedianTo, TYPE_MEDIAN);
	printf("Write Median to %s\n", spatialMedianTo);

	//SpatialDomainFilter("3-1.bmp", "3-2.bmp", TYPE_AVERAGE);
	/*for (size_t i = 0; i < 2; i++)
	{
		SpatialDomainFilter("3-2.bmp", "3-2-3.bmp", TYPE_AVERAGE);
	}
	SpatialDomainFilter("3-1.bmp", "3-3.bmp", TYPE_MEDIAN);
	for (size_t i = 0; i < 2; i++)
	{
		SpatialDomainFilter("3-3.bmp", "3-3-3.bmp", TYPE_MEDIAN);
	}*/


	printf("\n");
	/*
	���Ĵ���ҵ��ͼ��任
	*/


	const char * transformFrom = "3-3.bmp";
	const char * scaleTo = "4-scale.bmp";
	const char * shiftTo = "4-shift.bmp";
	const char * mirrorXTo = "4-x-mirror.bmp";
	const char * mirrorYTo = "4-y-mirror.bmp";
	const char * rotateTo = "4-rotate.bmp";


	printf("4.ͼ��任 Processing...\n");
	//ͼ������
	printf("Read from %s\n", transformFrom);

	transform(transformFrom, scaleTo, TRANSFORM_SCALE, 3, 4);

	printf("Write scale to %s\n", scaleTo);
	//ͼ��ƽ��

	transform(transformFrom, shiftTo, TRANSFORM_SHIFT, -20, -200);
	printf("Write shift to %s\n", shiftTo);

	//ͼ����
	//ˮƽ
	transform(transformFrom, mirrorXTo, TRANSFORM_MIRROR, 1, 0);
	printf("Write mirror X to %s\n", mirrorXTo);
	//��ֱ
	transform(transformFrom, mirrorYTo, TRANSFORM_MIRROR, -1, 0);
	printf("Write mirror Y to %s\n", mirrorYTo);

	//ͼ����ת
	transform(transformFrom, rotateTo, TRANSFORM_ROTATE, PI/8, 0);
	printf("Write rotate to %s\n", rotateTo);

	printf("\n");
	/*
	�������ҵ����ֵ�ָ�
	*/
	printf("5.��ֵ�ָ� Processing...\n");
	const char * thresholdFrom = "2.bmp";
	const char * seedTo = "5-threshold-seed.bmp";
	const char * iterationTo = "5-threshold-iteration.bmp";
	const char * ostuTo = "5-threshold-ostu.bmp";

	printf("Read from %s\n", thresholdFrom);


	ThresholdSegment(thresholdFrom, seedTo, THRESHOLD_SEED, 100);
	printf("Write seed to %s\n", seedTo);
	ThresholdSegment(thresholdFrom, iterationTo, THRESHOLD_ITERATION, 10);
	printf("Write iteration to %s\n", iterationTo);
	ThresholdSegment(thresholdFrom, ostuTo, THRESHOLD_OSTU, 0);
	printf("Write ostu to %s\n", ostuTo);

	printf("\n");

	/*
	��������ҵ����������ķָ�
	*/
	printf("6.��������ķָ� Processing...\n");
	const char * regionFrom = "6.bmp";
	const char * regionSeedTo = "6-seed.bmp";
	const char * regionNoSeedTo = "6-no-seed.bmp";
	printf("Read from %s\n", regionFrom);
	regionSegmentSeed(regionFrom,regionSeedTo,NULL,0,1);
	printf("Write Seed to %s\n", regionSeedTo);
	regionSegmentWithoutSeed(regionFrom, regionNoSeedTo);
	printf("Write No Seed to %s\n", regionNoSeedTo);
	printf("\n");

	/*
	���ߴ���ҵ����Ե���
	*/
	printf("7.��Ե��� Processing...\n");

	const char * edgeFrom = "3-3.bmp";
	const char * prewittTo = "7-prewitt.bmp";
	const char * sobelTo = "7-sobel.bmp";
	const char * logTo = "7-log.bmp";
	printf("Read from %s\n", edgeFrom);
	//prewitt
	EdgeDetection(edgeFrom, prewittTo, Edge_Dectect_Type_PREWITT);
	printf("Write prewitt to %s\n", prewittTo);
	//sobel
	EdgeDetection(edgeFrom, sobelTo, Edge_Dectect_Type_SOBEL);
	printf("Write sobel to %s\n", sobelTo);
	//log
	EdgeDetection(edgeFrom, logTo, Edge_Dectect_Type_LOG);
	printf("Write log to %s\n", logTo);


	printf("\n");
	/*
	�ڰ˴���ҵ������任
	*/

	printf("8.����任 Processing...\n");
	const char *houghTo = "8-hough.bmp";


	//BMP24To8Gray("8-24.bmp", "8-8.bmp");

	const char *logAndThreshold = "8.bmp";

	EdgeDetection("8-8.bmp", "8-8-log.bmp", Edge_Dectect_Type_LOG);

	ThresholdSegment("8-8-log.bmp", logAndThreshold, THRESHOLD_OSTU, 0);
	printf("Read from %s\n", logAndThreshold);
	Hough(logAndThreshold, houghTo);
	printf("Write hough to %s\n", houghTo);

	printf("\n");

	/*
	�ھŴ���ҵ����������������ȡ
	*/
	printf("9.��������������ȡ Processing...\n");

	

	printf("Read from %s\n", "x");
	printf("Write hough to %s\n", "x");

	printf("All done.\n");
	printf("\n");
	printf("\n");
	system("pause");
	return 0;
}

