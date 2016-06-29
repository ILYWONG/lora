#include<iostream>
#include "ns3/core-module.h"
#include "ns3/simulator-module.h"
#include "ns3/node-module.h"
#include "ns3/helper-module.h"
#include "LoraNetDevice.h"
#include <vector>
using namespace NS3;

//依赖基础包，和netdevice包，现在要处理循环引用的问题
class LoraNetDevice;//前向声明
LoraChannel::channel
{
	private:
  std::vector<NetDeviceContainer*> LoraNetDevicecontainer;
	Time m_delay;//时延信息
  Packet* m_currentPkt;//信道中的当前包，暂时不用
 
	public:
	void LoraChannel();//构造函数
	bool TransmitStart (Ptr<Packet> p, uint32_t srcId); //核心的发包函数
	bool init_set_netdevice_lora(NetDeviceContainer *devices_trans);//设置信道中的网络设备
	pt<LoraNetDevice> get_netdevice_lora(uint32_t dev_id);//获得一个信道中的网络设备，这个目前不实现
	bool set_netdevice_lora(Ptr<LoraNetDevice>);//设置网络设备的接口，暂时不实现
	bool set_current_packet(Packet* read); //这个要实现，但是要注意同步与异步的问题
}
;