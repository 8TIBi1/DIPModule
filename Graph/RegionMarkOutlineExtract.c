#include "BMPHelper.h"

void RegionMark(const char * from, const char * to)
{
	BMFILEHEADER header;
	INFOHEADER info;


	unsigned char ** data = malloc(sizeof(unsigned char*));
	RGBQUAD ** palette = malloc(sizeof(RGBQUAD*));
	unsigned pixelCounts = BMPReader8(from, &header, &info, palette, data);

	unsigned char **outData = malloc(sizeof(unsigned char*));

	*outData = malloc(pixelCounts);
	unsigned  * markMatrix= malloc(pixelCounts*sizeof(unsigned));
	//��ʼ����Ǿ���
	for (unsigned i = 0; i < info.height; i++)
	{

		for (unsigned j = 0; j < info.width; j++)
		{
			if (*(*data + i * info.width + j)==0)
			{
				markMatrix[i * info.width + j] = 1;
			}
			else
			{
				markMatrix[i * info.width + j] = 0;
			}
		}
	}
	int tag = 2;
	//��һ��ɨ��
	for (unsigned i = 0; i < info.height; i++)
	{

		for (unsigned j = 0; j < info.width; j++)
		{
			//��������Ϊ0���򲻱�

			if (markMatrix[i * info.width + j]!=1)
			{
				continue;
			}
			markRegion(markMatrix, i, j, info.width, info.height, tag);
			tag++;
			
			//�����1�������8��������ɨ���Ԫ��

			//�����ж������Ƿ�Ϸ��������I�������J�ĸ�����
			
			//�����Ϊ0���򴴽��µı��
			//�������ͬ�Ҳ�Ϊ0����Ϊ�����0ֵ
			//����в�ͬ�ķ�0ֵ����ȡ��һ������¼�ȼ�

			//*(*outData + i * info.width + j) = 0;
		}
	}
	//��2��ɨ��
	for (unsigned i = 0; i < info.height; i++)
	{

		for (unsigned j = 0; j < info.width; j++)
		{
		
			if (markMatrix[i * info.width + j] > 0)
			{
				int newGray = 255 * 1.0* markMatrix[i * info.width + j] / 255;
				if (newGray>255)
				{
					newGray = 255;
				}
				*(*outData + i * info.width + j) = newGray;
				RGBQUAD b = { 255, 0, 0, 0 };
				RGBQUAD g = { 0, 255, 0, 0 };
				RGBQUAD r = { 0, 0, 255, 0 };
				if (markMatrix[i * info.width + j]%3==0)
				{
					*(*palette + newGray) = b;
				}
				else if (markMatrix[i * info.width + j] % 3 == 1)
				{
					*(*palette + newGray) = g;
				}
				else{
					*(*palette + newGray) = r;
				}
				
			}
			
		}
	}

	BMPWriter8(to, &header, &info, palette, outData);
}

void OutlineExtract(const char * from, const char * to)
{
	BMFILEHEADER header;
	INFOHEADER info;


	unsigned char ** data = malloc(sizeof(unsigned char*));
	RGBQUAD ** palette = malloc(sizeof(RGBQUAD*));
	unsigned pixelCounts = BMPReader8(from, &header, &info, palette, data);

	unsigned char **outData = malloc(sizeof(unsigned char*));

	*outData = malloc(pixelCounts);
	unsigned  * markMatrix = malloc(pixelCounts * sizeof(unsigned));
	unsigned  * markMatrixCache = malloc(pixelCounts * sizeof(unsigned));
	//��ʼ����Ǿ���
	for (unsigned i = 0; i < info.height; i++)
	{

		for (unsigned j = 0; j < info.width; j++)
		{
			if (*(*data + i * info.width + j) == 0)
			{
				//ǰ��Ϊ1
				markMatrix[i * info.width + j] = 1;
				markMatrixCache[i * info.width + j] = 1;
			}
			else
			{
				//����Ϊ0
				markMatrix[i * info.width + j] = 0;
				markMatrixCache[i * info.width + j] = 0;
			}
		}
	}
	int tag = 2;
	//��һ��ɨ��
	for (unsigned i = 0; i < info.height; i++)
	{

		for (unsigned j = 0; j < info.width; j++)
		{
			//��������Ϊ0���򲻱�

			if (markMatrix[i * info.width + j] != 1)
			{
				continue;
			}
			

			if (i==1||j==1||i==info.height-1||j==info.width-1)
			{
				markMatrixCache[i * info.width + j] = 2;
				continue;
			}

			if (markMatrix[i * info.width + j-1]==0|| markMatrix[(i-1) * info.width + j - 1] == 0
				|| markMatrix[(i - 1) * info.width + j ] == 0|| markMatrix[(i - 1) * info.width + j + 1]==0
				|| markMatrix[i * info.width + j + 1] == 0|| markMatrix[(i + 1) * info.width + j + 1] == 0
				|| markMatrix[(i + 1) * info.width + j] == 0|| markMatrix[(i + 1) * info.width + j - 1] == 0)
			{
				markMatrixCache[i * info.width + j] = 2;
			}
			
		}
	}
	//��2��ɨ��
	for (unsigned i = 0; i < info.height; i++)
	{

		for (unsigned j = 0; j < info.width; j++)
		{

			if (markMatrixCache[i * info.width + j] == 2)
			{
				int newGray = 155;
				*(*outData + i * info.width + j) = newGray;
				RGBQUAD b = { 255, 0, 0, 0 };
				*(*palette + newGray) = b;

			}

		}
	}

	BMPWriter8(to, &header, &info, palette, outData);
}


void markRegion(unsigned  *markMatrix,unsigned i, unsigned j,int width,int height,int tag) {

	
	if (markMatrix[i * width + j] == tag|| markMatrix[i * width + j]==0)
	{
		return;
	}
	markMatrix[i * width + j] = tag;
	if (i!=0)
	{
		markRegion(markMatrix, i - 1, j, width, height, tag);
	}
	if (j!=0)
	{
		markRegion(markMatrix, i, j - 1, width, height, tag);
	}
	if (i != height - 1)
	{
		markRegion(markMatrix, i + 1, j, width, height, tag);
	}
	if (j != width - 1)
	{
		markRegion(markMatrix, i, j + 1, width, height, tag);
	}

}