#include"LoraNetDevice.h"

class LoraNetDevice
{
	
public:
	Receive(Ptr<Packet>p,Ptr<LoraNetDevice>sender );
	//void ns3::CsmaNetDevice::Receive(Ptr<Packet>p,Ptr<CsmaNetDevice>sender )
	int bind(LoraNode *nodeptr,int LoraNodeID);//将设备加载到当前的网络设备上	
	LoraNode * LoraNetDevice::GetNode ();
	int LoraNetDevice::bind(LoraNode *nodeptr);
	int 
private:	
		//自己是挂在那个node下面的	
		std::vector<LoraNode*> node_index;
		//自己的channel
		std::vector<LoraChannel*> LoraChannel;


}