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
	//接受报文函数，channel里面存的是netdevice
	int bind(Ptr<Node>nodeptr);
	//将节点加载到当前的网络设备上	
	int bind(Ptr<Lorachannel> channel_m);
		//重载,这里应该是绑定channel。
	Ptr<Node> GetNode();
	//netdevice里面是有node的，这个函数支持返回node类型，先不实现这个函数
	//std::vector< Ptr< Node > > 	m_nodes <-nodecontainer里面的
	//返回本netdevice绑定的node
	int  Send (Ptr<Packet> packet_re);
private:	
		//自己是挂在那个node下面的	
	Ptr<Node> node_index;
		//自己的channel
	Ptr<LoraChannel> LoraChannel;


};