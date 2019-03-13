#include "BMPHelper.h"
#include <stdio.h>

void HistogramStatic() {

	const int L = 256;

	

	// 24λ���ɫת8λ�Ҷ�

	BMP24To8Gray("1.bmp", "2.bmp");

	BMFILEHEADER header;
	INFOHEADER info;
	unsigned char ** data = malloc(sizeof(RGBITEM*));
	RGBQUAD ** palette = malloc(sizeof(RGBQUAD*));

	unsigned pixelCounts = BMPReader8("2.bmp", &header, &info, palette, data);

	int histogram[256] = { 0 };
	double grayscaleDistribution[256] = { 0 };
	double cumulativeDistribution[256] = { 0 };


	//24λ���ɫ��Ҷ�
	for (size_t i = 0; i < pixelCounts; i++)
	{
		
		histogram[*(*data+i)]++;
	}

	for (size_t i = 0; i < 256; i++)
	{
		grayscaleDistribution[i] = histogram[i] * 1.0 / pixelCounts;
		//��cdf
		if (i==0)
		{
			cumulativeDistribution[i] = grayscaleDistribution[i];
		}
		else
		{
			cumulativeDistribution[i] = cumulativeDistribution[i - 1] + grayscaleDistribution[i];
		}
	/*	if (grayscaleDistribution[i] * 100.0 <0.01)
		{
			continue;
		}
		printf("�Ҷȼ���%3d��ͳ�����ظ��ʣ�%4.2f%%\n", i, grayscaleDistribution[i]*100);*/
	}

	for (size_t i = 0; i < pixelCounts; i++)
	{
		
		int newGray = (int)(cumulativeDistribution[*(*data + i)] * (L-1) + 0.5);
		*(*data + i) = newGray;

	}

	int histogramLatest[256] = { 0 };
	double grayscaleDistributionLatest[256] = { 0 };
	for (size_t i = 0; i < pixelCounts; i++)
	{

		histogramLatest[*(*data + i)]++;
	}
	for (size_t i = 0; i < 256; i++)
	{
		grayscaleDistributionLatest[i] = histogramLatest[i] * 1.0 / pixelCounts;
	}
	BMPWriter8("3.bmp", &header, &info, palette, data);
	outputGrayscaleHistogram("4.bmp", grayscaleDistribution, &info);
	outputGrayscaleHistogram("5.bmp", grayscaleDistributionLatest, &info);
	printf("%f\n", cumulativeDistribution[L - 1]);
	//BMPWriter("histogramout.bmp", &header, &info, palette, data);


}