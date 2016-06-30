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
	const int packetSize=1000;//���ݰ��ĳ���
	const int nPackets=10000;//Ҫ���͵����ݰ�������
	const int dataRate=10000;//���ݰ����͵�����
	int loranodeid=0;
	const int node_num=10;
	const int not_running=0;
	const int m_nPackets=0;//����ǰ��ۼӳ�ʼֵ
	const int running=1;
	const uint32_t m_packetsSent=10000;//����ǰ�����ֵ
	
	
	Ptr<NodeContainer>nodes(new NodeContainer());
  (*nodes).Create (node_num);

  LoraHelper LoraHelper_m;
  NetDeviceContainer devices;
	Ptr<LoraChannel>lora_channel_m(LoraChannelHelper::MakeLoraChannel());
  devices = LoraHelper_m.install(lora_channel_m,nodes);
	//����ɣ�devices�������Ǻ������е���Ϣ
	
	lora_channel_m->init_set_netdevice_lora(nodes);

	//Ϊchannel�����еĽڵ�
	MyApp app_m_MME=MyApp();
	app_m_MME.Setup(packetSize,nPackets,dataRate\
										not_running,m_nPackets,m_packetsSent,\
										(*devices)[0],0	);
	//gatewayapp,�������
		
	Myapp app_m_node=MyApp();
	
	for(int j=1;j<node_num;j++)
	{
		app_m_node.Setup(packetSize,nPackets,dataRate\
										not_running,m_nPackets,m_packetsSent,\
										(*devices)[j],m_loranodeid);
	}
	
	//�ն˽ڵ��App��ɲ���
	
	app_m_MME.Start (Seconds (2.0));
  app_m_MME.Stop (Seconds (10.0));
			
	app_m_node.Start();
	app_m_node.Stop();
	//�ն˽ڵ��Ӧ�����ÿ�ʼʱ��ͽ���ʱ��
		
	
  Simulator::Run ();
  Simulator::Destroy ();
	 
	
}