#include"LoraHelp.h"

NetDeviceContainer  LoraHelp::install(Lorachannel* channel_m,LoraNodeContainer* nodecontainer_return)
{
	 //����ֵ��һ��NetDeviceContainer ����
	 NetDeviceContainer NetDeviceContainer_return;
	 //channel ��������netdeviceָ���б��
	 //std::vector< Ptr< NetDevice > > 	m_devices
	 
	for(int i=0;i<(*nodecontainer_return).size();i++)
	{
		NetDeviceContainer_return.push_back(new LoraNetDevice);
		if(!(NetDeviceContainer_return[NetDeviceContainer_return.size()-1].bind(nodecontainer_return[i])))
		{
				std::cout<<"error���������豸ʧ��,ԭ���ǰ󶨽ڵ�ʧ�ܣ���ǰ�ǵ�"<<i<<"�������豸"<<endle;
				return NULL;	
		}
		if(!(NetDeviceContainer_return[NetDeviceContainer_return.size()-1].bind(channel_m)))
		{
				std::cout<<"error���������豸ʧ��,ԭ���ǰ��ŵ�ʧ�ܣ���ǰ�ǵ�"<<i<<"�������豸"<<endle;
				return NULL;	
		}
		
	}
	/*������Ҫ����Ϊchannel����netdevice*/
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
	//Ϊ���������ֵstd::vector<Ptr<LoraNetDevice>> LoraNetDevicecontainer;
		for(int i=0;i<NetDeviceContainer_re.size();i++)
		{
				(*channel_m).LoraNetDevicecontainer.push_back(NetDeviceContainer_re[i]);
													
		}
	
}