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
		int install(LoraNetDevice* LoraNetDevice_m,LoraChannel* LoraChannel_m);//���netdevice �� channel ��
		//���install Ҫ���device �Ĵ�����֧�ִ�node�������ɰ�����node���ϵ�
		//netdevice���ϣ���֧�ָ�ֵ���յ�netdevice���ϣ�������ϵ�
		//�Ŀ���
		bool install(Lorachannel* channel_m,NetDeviceContainer* NetDeviceContainer_re);
		
	private:
		
	
	
}