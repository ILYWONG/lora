#include"LoraHelp.h"

NetDeviceContainer  LoraHelp::install(Lorachannel* channel_m,LoraNodeContainer* nodecontainer_return)
{
	 //返回值是一个NetDeviceContainer 对象
	 NetDeviceContainer NetDeviceContainer_return;
	 //channel 里面是由netdevice指针列表的
	 //std::vector< Ptr< NetDevice > > 	m_devices
	 
	for(int i=0;i<(*nodecontainer_return).size();i++)
	{
		NetDeviceContainer_return.push_back(new LoraNetDevice);
		if(!(NetDeviceContainer_return[NetDeviceContainer_return.size()-1].bind(nodecontainer_return[i])))
		{
				std::cout<<"error创建网络设备失败,原因是绑定节点失败，当前是第"<<i<<"个网络设备"<<endle;
				return NULL;	
		}
		if(!(NetDeviceContainer_return[NetDeviceContainer_return.size()-1].bind(channel_m)))
		{
				std::cout<<"error创建网络设备失败,原因是绑定信道失败，当前是第"<<i<<"个网络设备"<<endle;
				return NULL;	
		}
		
	}
	/*这里是要考虑为channel设置netdevice*/
	//**
	//**for()
	//**{
	//**	(*channel_m).push_back();
	//**	
	//**}
	//**
	
};

NetDeviceContainer  LoraHelp::install(Lorachannel* channel_m,NetDeviceContainer* NetDeviceContainer_re)
{
	//为这个参数赋值std::vector<Ptr<LoraNetDevice>> LoraNetDevicecontainer;
		for(int i=0;i<NetDeviceContainer_re.size();i++)
		{
				(*channel_m).LoraNetDevicecontainer.push_back(NetDeviceContainer_re[i]);
													
		}
	
}