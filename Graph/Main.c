#include <stdlib.h>
#include "BMPHelper.h"
#include <stdio.h>

#pragma warning(disable : 4996)

int main(){
	
	/*int a, b, c, d, e, f;

	const char * buffer = "1 2 3 4 5 6";

	int result = sscanf(buffer, "%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

	printf("������%d�������ֱ�Ϊ%d %d %d %d %d %d",result, a, b, c, d, e, f);*/
	
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

	//transform("3-3.bmp", "scale.bmp", TRANSFORM_SCALE, 1.5, 1.5);

	//ͼ��ƽ��

	//transform("3-3.bmp", "shift.bmp", TRANSFORM_SHIFT, -20, -200);

	//ͼ����
	////ˮƽ
	//transform("3-3.bmp", "x-mirror.bmp", TRANSFORM_MIRROR, 1, 0);
	////��ֱ
	//transform("3-3.bmp", "y-mirror.bmp", TRANSFORM_MIRROR, -1, 0);

	//ͼ����ת

	transform("3-3.bmp", "rotate.bmp", TRANSFORM_ROTATE, PI/8, 0);

	system("pause");
	return 0;
}