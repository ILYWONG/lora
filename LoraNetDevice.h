#include"LoraChannle.h"

#include "ns3/core-module.h"
#include "ns3/simulator-module.h"
#include "ns3/node-module.h"
#include "ns3/helper-module.h"


class LoraChannel;
class LoraNetDevice
{
	
public:
	void Receive(Ptr<Packet>p,uint32_t sender );
	//���ܱ��ĺ�����channel��������netdevice
	int bind(Node *nodeptr);
	//���ڵ���ص���ǰ�������豸��	
	int bind(LoraChannel* channel);
	//����,����Ӧ���ǰ�channel��
	Node* GetNode();
	//netdevice��������node�ģ��������֧�ַ���node���ͣ��Ȳ�ʵ���������
	//std::vector< Ptr< Node > > 	m_nodes <-nodecontainer�����
	//���ر�netdevice�󶨵�node
private:	
		//�Լ��ǹ����Ǹ�node�����	
	std::vector<Ptr<Node>> node_index;
		//�Լ���channel
	std::vector<Ptr<LoraChannel>> LoraChannel;


};