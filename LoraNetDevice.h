#include"LoraChannle.h"

#include "ns3/core-module.h"
#include "ns3/simulator-module.h"
#include "ns3/node-module.h"
#include "ns3/helper-module.h"


class LoraChannel;
class LoraNetDevice
{
	
public:
	void Receive(Ptr<Packet>p,uint32_t nodeID );
	//���ܱ��ĺ�����channel��������netdevice
	int bind(Ptr<Node>nodeptr);
	//���ڵ���ص���ǰ�������豸��	
	int bind(Ptr<Lorachannel> channel_m);
		//����,����Ӧ���ǰ�channel��
	Ptr<Node> GetNode();
	//netdevice��������node�ģ��������֧�ַ���node���ͣ��Ȳ�ʵ���������
	//std::vector< Ptr< Node > > 	m_nodes <-nodecontainer�����
	//���ر�netdevice�󶨵�node
	int  Send (Ptr<Packet> packet_re);
private:	
		//�Լ��ǹ����Ǹ�node�����	
	Ptr<Node> node_index;
		//�Լ���channel
	Ptr<LoraChannel> LoraChannel;


};