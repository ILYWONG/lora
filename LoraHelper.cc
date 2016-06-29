#include"LoraHelp.h"

NetDeviceContainer  LoraHelp::install(Ptr<Lorachannel>channel_m,Ptr<NodeContainer>nodecontainer_return)
{
		//返回值是一个NetDeviceContainer 对象
		//存在的问题是NetDeviceContainer里面的是什么，这是一个类，直接
		//访问成员是不能访问的，在改一改
	 
		NetDeviceContainer NetDeviceContainer_return;
		//channel 里面是由netdevice指针列表的
		//std::vector< Ptr< NetDevice > > 	m_devices
		assert(channel_m!=NULL);
		assert(nodecontainer_return!=NULL);
		for(int i=0;i<(*nodecontainer_return.GetN());i++)
		{
			NetDeviceContainer_return.Add(Ptr(new LoraNetDevice()));
			/*
			*	void 	Add (Ptr< NetDevice > device)
 			*	Append a single Ptr<NetDevice> to this container. More...
 			*/
 			/*
 			Ptr< NetDevice > 	Get (uint32_t i) const
 			*/
			if(!(NetDeviceContainer_return.Get(i).bind(nodecontainer_return[i])))
			{
				
				/*
				*Ptr<NetDevice> Get(uint32_t i)const
 				*Get the Ptr<NetDevice> stored in this container at a given index. More...
				*/
					std::cout<<"error创建网络设备失败,原因是绑定节点失败，当前是第"<<i<<"个网络设备"<<endle;
					return NULL;	
			}
			if(!(NetDeviceContainer_return.Get(i).bind(channel_m)))
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

/*
改造channel,现有的channel，在有的netdevice,最后用netdevice去更新channel,
仅仅需要该做，所以传入指针即可
*/

bool LoraHelp::install(Lorachannel* channel_m,NetDeviceContainer* NetDeviceContainer_re)
{
	//为这个参数赋值std::vector<Ptr<LoraNetDevice>> LoraNetDevicecontainer;
		assert((channel_m!=NULL)||(NetDeviceContainer_re!=NULL));
		for(int i=0;i<(*NetDeviceContainer_re).GetN();i++)
		{
				(*channel_m).LoraNetDevicecontainer.Add(NetDeviceContainer_re.Get(i));
													
		}
		return true;
	
}