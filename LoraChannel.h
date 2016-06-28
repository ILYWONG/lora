#include<iostream>

using namespace NS3;
LoraChannel::channel
{
	//channel类，要求提供收发操作。
	//实现send
	//实现recv
	//sendEnd函数，这个函数会去掉recv
	//recv是在netdevice中实现的
	
	private:
  //std::vector< NetDeviceContainer > 	m_deviceList;//意味着网络设备存在channel中，这是csma的方案。
	//wifi的方案，是把物理层都放到channel中去	
	//这里要存下网络设备的目的是为了唤醒的原因，我们这里采用wifi的方案
	//wifi的方案是保存下来指针到链表中，这里没有必要这么麻烦，选择使用vector存放指针，不去存放副本，是希望，phy的更新
	//可以直接的作用到channel中，但是要避免产生野指针，因为在其他层次去掉某一个设备的phy，可能导致这里的phy指针还在，这
	//就产生了野指针
	std::vector<NetDeviceContainer*> LoraNetDevicecontainer;
	//channel  包含到所有设备的指针，并且所有设备要包含channel,所以要借助指针
	//暂时用vetor存放指针，但是可不可行还不知道，先这样用。
	Time m_delay；
	Packet* m_currentPkt；
	
	
	public:
	void LoraChannel();
	bool TransmitStart (Ptr< Packet > p, uint32_t srcId);
	
	bool set_netdevice_lora(Ptr<LoraNetDevice>);
	pt<LoraNetDevice> get_netdevice_lora(uint32_t dev_id);
	
	
	
	bool  find_dev_equal(Ptr<LoraNetDevice> dev1,Ptr<LoraNetDevice> dev2);
	
}
;