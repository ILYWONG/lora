#include "ns3/core-module.h"
#include "ns3/simulator-module.h"
#include "ns3/node-module.h"
#include "ns3/helper-module.h"


#include"LoraPhyelper.h"
#include"LoraPhy.h"
#include"LoraNetDevice.h"
#include"LoraHelper.h"
#include"LoraChannel.h"


void main()
{
	const int packetSize=1000;//数据包的长度
	const int nPackets=10000;//要发送的数据包的数量
	const int dataRate=10000;//数据包发送的速率
	int loranodeid=0;
	const int node_num=10;
	const int not_running=0;
	const int m_nPackets=0;//这个是包累加初始值
	const int running=1;
	const uint32_t m_packetsSent=10000;//这个是包上限值
	
	
	Ptr<NodeContainer>nodes(new NodeContainer());
  (*nodes).Create (node_num);

  LoraHelper LoraHelper_m;
  NetDeviceContainer devices;
	Ptr<LoraChannel>lora_channel_m(LoraChannelHelper::MakeLoraChannel());
  devices = LoraHelper_m.install(lora_channel_m,nodes);
	//绑定完成，devices里面有是含有所有的信息
	
	lora_channel_m->init_set_netdevice_lora(nodes);

	//为channel绑定所有的节点
	MyApp app_m_MME=MyApp();
	app_m_MME.Setup(packetSize,nPackets,dataRate\
										not_running,m_nPackets,m_packetsSent,\
										(*devices)[0],0	);
	//gatewayapp,完成配置
		
	Myapp app_m_node=MyApp();
	
	for(int j=1;j<node_num;j++)
	{
		app_m_node.Setup(packetSize,nPackets,dataRate\
										not_running,m_nPackets,m_packetsSent,\
										(*devices)[j],m_loranodeid);
	}
	
	//终端节点的App完成布局
	
	app_m_MME.Start (Seconds (2.0));
  app_m_MME.Stop (Seconds (10.0));
			
	app_m_node.Start();
	app_m_node.Stop();
	//终端节点的应用设置开始时间和结束时间
		
	
  Simulator::Run ();
  Simulator::Destroy ();
	 
	
}