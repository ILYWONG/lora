#include "LoraNetDevice.h"
void LoraNetDevice::Receive(Ptr<Packet>p,uint32_t nodeID)
{
	  //�������ݰ��Ŀ�������������µ����ݰ���������豸��ID�š�
	  //�����ͽ�����
	  //�����������channel�е��õģ�channel
	  std::cout<<"���ܵ����ݰ�ռλ"<<"�յ�����id="<<nodeid<<"�����ݰ�"<<endle;	
}
Ptr<Node> LoraNetDevice::GetNode()
{
	if(node_index.size()==0)
		return NULL;
	else
		return node_index;
}
int LoraNetDevice::bind(Ptr<Lorachannel> channel_m)
{
	//��channel
	//std::vector<LoraChannel*> LoraChannel;
	if(LoraChannel.size()!=0)
	{
		std::<<"error"<<"�����ٰ��ˣ��Ѿ�����˸�netdevice�豸�İ�"<<endl;
		return 0;
	}
	else
	{
		LoraChannel=channel_m;
		std::<<"info"<<"��netdevice��channel"<<endl;
		return 1;
	}

}

int LoraNetDevice::bind(Ptr<Node>nodeptr)
{
	if(node_index.size()!=0)
	{
		std::cout<<"error"<<"netdevice�Ѿ���ɰ�node"<<endl;
		return 0;
	}
	else
	{
		node_index=nodeptr;
		std::cout<<"info"<<"netdevice�󶨵�channel"<<end;
		return 1;
	}

}

int  LoraNetDevice::Send (Ptr<Packet> packet_re)
{
	//��Ϊnetdevice����channel��ָ��ģ������ǿ����������װchannel��send
	
		//std::vector<LoraChannel*> LoraChannel;
		//bool LoraChannel::TransmitStart (Ptr< Packet > p, uint32_t srcId)
		LoraChannel->TransmitStart(packet_re,(node_index->GetId()));
		
}