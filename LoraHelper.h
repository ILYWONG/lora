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
		NetDeviceContainer install(Ptr<Lorachannel>channel_m,Ptr<NodeContainer>nodecontainer_return);//���netdevice �� channel ��
		//���install Ҫ���device �Ĵ�����֧�ִ�node�������ɰ�����node���ϵ�
		//netdevice���ϣ���֧�ָ�ֵ���յ�netdevice���ϣ�������ϵ�
		//�Ŀ���
		bool install(Ptr<Lorachannel>channel_m,Ptr<NetDeviceContainer> NetDeviceContainer_re);
		
	private:
		
	
	
}