//该类主要是LoRa的工厂函数

#include"LoraChannelHelper.h"
#include"LoraChannel.h"
LoraChannelHelper
{
	public:
		static LoraChannel* MakeLoraChannel();
		LoraChannelHelper();
		~LoraChannelHelper();
	
};