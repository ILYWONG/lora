
#include"LoraChannel.h"
LoraChannel::LoraChannel()
{
//���캯���ǿյ�
}



bool LoraChannel::TransmitStart (Ptr< Packet > p, uint32_t srcId)
{
	//����recv
	  std::vector<Ptr<LoraNetDevice>>::iterator it;
    for(it = LoraNetDevicecontainer.begin (); it!=LoraNetDevicecontainer.end (); it++)
    {
         // schedule reception events
         //������ʹ��phy����н������ݵ�
         //������һ���豸�������ݣ�����Ҫ�����Ǹ��豸���н��գ�����Ҫ���ǵ��ǻ���
         //phy���ǻ���netdevice������ǻ���netdevice,��Ϊ���������phy��channel��netdevice����һ��
    		 //
         Simulator::ScheduleWithContext(it->devicePtr->GetNode ()->GetId (),
                                       m_delay,&LoraNetDevice::Receive, it->devicePtr,
                                       m_currentPkt->Copy ());
    }
        devId++;
       
}

bool LoraChannel::set_netdevice_lora(Ptr<LoraNetDevice>)
{
		
	LoraNetDevicecontainer.push_back(Ptr<LoraNetDevice>);
	
}

bool LoraChannel::init_set_netdevice_lora(NetDeviceContainer *devices_trans)
{
	//����ֻ��Ҫ��ȡ���������ָ�룬����Ҫ�޸�
	
			LoraNetDevicecontainer.push_back(devices_trans);
			
}


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
