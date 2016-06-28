//该类主要是LoRa的工厂函数

#include"LoraChannelHelper.h"
LoraChannelHelper::LoraChannelHelper()
{
	//构造函数空
	
}


LoraChannelHelper::~LoraChannelHelper()
{
	//析构函数函数空，不写成虚函数，是因为没有必要
	
}


static LoraChannel* LoraChannelHelper::MakeLoraChannel()
{
	//这里可以使用单例模式
	LoraChannel*re=	new LoraChannel();
	return re;	
	
}