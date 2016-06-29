
#include"LoraChannel.h"
LoraChannel::LoraChannel()
{
//构造函数是空的
}
bool LoraChannel::TransmitStart (Ptr< Packet > p, uint32_t srcId)
{
	//唤醒recv
	/*std::vector<Ptr<LoraNetDevice>>::iterator it;
	for(it = LoraNetDevicecontainer.begin (); it!=LoraNetDevicecontainer.end (); it++)
	{
		Simulator::ScheduleWithContext(it->devicePtr->GetNode()->GetId(),m_delay,\
			&LoraNetDevice::Receive, it->devicePtr,m_currentPkt->Copy ());
	}
	devId++;*/
	//这里要向gateway发数据
	Simulator::ScheduleWithContext(LoraNetDevicecontainer[0]->GetNode()->GetId(),m_delay,\
			&LoraNetDevice::Receive, LoraNetDevicecontainer[0],m_currentPkt->Copy ());
	
	//参数说明，第一个参数是用来打日志的，第二个是时延，第三个是目标函数，第四个是要获得
	//netdevice实体，第五个是报文实体
	//注意这里是用的m_currentpkt
	
	 
	
	
}
bool LoraChannel::init_set_netdevice_lora(NetDeviceContainer *devices_trans)
{
	//现在只需要提取出来里面的指针，不需要修改
	LoraNetDevicecontainer.push_back(devices_trans);
}

bool LoraChannel::set_current_packet(Packet* read)
{
	m_currentPkt=read;
	
}




/*bool LoraChannel::set_netdevice_lora(Ptr<LoraNetDevice>)
{
	LoraNetDevicecontainer.push_back(Ptr<LoraNetDevice>);
}
*/
/*
pt<LoraNetDevice> LoraChannel::get_netdevice_lora(uint32_t dev_id)
{
	  std::vector<LoraNetDevice>::iterator it=find(LoraNetDevicecontainer.begin(),LoraNetDevicecontainer.end(),dev_id,find_dev_equal)
		if(it==LoraNetDevicecontainer.end())
			  return NULL;
		else
				return it;
	
}
bool  LoraChannel::find_dev_equal(Ptr<LoraNetDevice> dev1,Ptr<LoraNetDevice> dev2)
{
		return (dev1->id==dev1->id);	
}
*/