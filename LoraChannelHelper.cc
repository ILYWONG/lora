//������Ҫ��LoRa�Ĺ�������

#include"LoraChannelHelper.h"
LoraChannelHelper::LoraChannelHelper()
{
	//���캯����
	
}


LoraChannelHelper::~LoraChannelHelper()
{
	//�������������գ���д���麯��������Ϊû�б�Ҫ
	
}


static LoraChannel* LoraChannelHelper::MakeLoraChannel()
{
	//�������ʹ�õ���ģʽ
	LoraChannel*re=	new LoraChannel();
	return re;	
	
}