#include <stdlib.h>
#include "BMPHelper.h"
#include <stdio.h>


#pragma warning(disable : 4996)




int main(){

	

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

	ThresholdSegment("2.bmp", "threshold-seed.bmp", THRESHOLD_SEED, 100);
	ThresholdSegment("2.bmp", "threshold-iteration.bmp", THRESHOLD_ITERATION, 1);
	ThresholdSegment("2.bmp", "threshold-ostu.bmp", THRESHOLD_OSTU, 0);

	/*
	���ߴ���ҵ����Ե���
	*/

	/*EdgeDetection("3-3.bmp", "3-prewitt.bmp", Edge_Dectect_Type_PREWITT);
	EdgeDetection("3-3.bmp", "3-sobel.bmp", Edge_Dectect_Type_SOBEL);*/

	system("pause");
	return 0;
}