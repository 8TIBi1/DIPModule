#include "BMPHelper.h"
#include <stdio.h>



/*
����ָ��������ֵ����������
��������ֵ�Ͳ���T����ʼ��������
���������������������ص㶼�Ѿ�������
��ͬ������ɫʹ�á���������/��������Ŀ*255����Ϊ�Ҷ�ֵ

*/
void regionSegmentSeed(const char * src, const char * dest, Point * seeds, int length,int t)
{
	//BMFILEHEADER header;
	//INFOHEADER info;


	////ԭͼ��������
	//unsigned char ** data = malloc(sizeof(unsigned char*));
	////ԭͼ��ɫ������
	//RGBQUAD ** palette = malloc(sizeof(RGBQUAD*));
	////��ȡͼƬ������������
	//unsigned pixelCounts = BMPReader8(src, &header, &info, palette, data);

	////���������ͼƬ����������
	//unsigned char **outData = malloc(sizeof(unsigned char*));
	//*outData = malloc(pixelCounts);



	for (size_t i = 0; i < length; i++)
	{

	}


	//BMPWriter8(dest, &header, &info, palette, outData);
}

void regionSegmentWithoutSeed(const char * src, const char * dest)
{
}
