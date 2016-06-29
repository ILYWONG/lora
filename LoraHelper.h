#include <assert.h>


#include "ns3/core-module.h"
#include "ns3/simulator-module.h"
#include "ns3/node-module.h"
#include "ns3/helper-module.h"
#include "LoraNetDevice.h"

LoraHelper
{
	public:
		SetDeviceAttribute();
		SetChannelAttribute();
		int install(LoraNetDevice* LoraNetDevice_m,LoraChannel* LoraChannel_m);//完成netdevice 和 channel ，
		//这个install 要完成device 的创建，支持从node集合生成包含了node集合的
		//netdevice集合，并支持赋值给空的netdevice集合，这个集合到
		//的拷贝
		bool install(Lorachannel* channel_m,NetDeviceContainer* NetDeviceContainer_re);
		
	private:
		
	
	
}