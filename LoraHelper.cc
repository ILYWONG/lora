#include"LoraHelp.h"

NetDeviceContainer  LoraHelp::install(Ptr<Lorachannel>channel_m,Ptr<NodeContainer>nodecontainer_return)
{
		//����ֵ��һ��NetDeviceContainer ����
		//���ڵ�������NetDeviceContainer�������ʲô������һ���ֱ࣬��
		//���ʳ�Ա�ǲ��ܷ��ʵģ��ڸ�һ��
	 
		NetDeviceContainer NetDeviceContainer_return;
		//channel ��������netdeviceָ���б��
		//std::vector< Ptr< NetDevice > > 	m_devices
		assert(channel_m!=NULL);
		assert(nodecontainer_return!=NULL);
		for(int i=0;i<(nodecontainer_return->GetN());i++)
		{
			NetDeviceContainer_return.Add(Ptr<LoraNetDevice>(new LoraNetDevice()));
			/*
			*	void 	Add (Ptr< NetDevice > device)
 			*	Append a single Ptr<NetDevice> to this container. More...
 			*/
 			/*
 			Ptr< NetDevice > 	Get (uint32_t i) const
 			*/
			if(!((NetDeviceContainer_return.Get(i))->bind(nodecontainer_return->Get(i))))
			{
				
				/*
				*Ptr<NetDevice> Get(uint32_t i)const
 				*Get the Ptr<NetDevice> stored in this container at a given index. More...
				*/
					std::cout<<"error���������豸ʧ��,ԭ���ǰ󶨽ڵ�ʧ�ܣ���ǰ�ǵ�"<<i<<"�������豸"<<endle;
					return NULL;	
			}
			if(!((NetDeviceContainer_return.Get(i))->bind(channel_m)))
			{
					std::cout<<"error���������豸ʧ��,ԭ���ǰ��ŵ�ʧ�ܣ���ǰ�ǵ�"<<i<<"�������豸"<<endle;
					return NULL;	
			}
		
		}
		return NetDeviceContainer_return;//���涼��ָ�룬����ָ��û�£����ǲ��ܶ�ָ�����Դ
	
};

/*
����channel,���е�channel�����е�netdevice,�����netdeviceȥ����channel,
������Ҫ���������Դ���ָ�뼴��
*/

bool LoraHelp::install(Ptr<Lorachannel>channel_m,Ptr<NetDeviceContainer> NetDeviceContainer_re)
{
		//Ϊ���������ֵstd::vector<Ptr<LoraNetDevice>> LoraNetDevicecontainer;
		assert((channel_m!=NULL)||(NetDeviceContainer_re!=NULL));
		/*for(int i=0;i<NetDeviceContainer_re->GetN();i++)
		{
				(channel_m->LoraNetDevicecontainer)->Add(NetDeviceContainer_re->Get(i));
				//����д�������⣬��ֱ�ӻ��netdevice��									
		}*/
		channel_m->init_set_netdevice_lora(NetDeviceContainer_re);
		 
		return true;
	
}