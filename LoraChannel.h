#include<iostream>

using namespace NS3;
LoraChannel::channel
{
	//channel�࣬Ҫ���ṩ�շ�������
	//ʵ��send
	//ʵ��recv
	//sendEnd���������������ȥ��recv
	//recv����netdevice��ʵ�ֵ�
	
	private:
  //std::vector< NetDeviceContainer > 	m_deviceList;//��ζ�������豸����channel�У�����csma�ķ�����
	//wifi�ķ������ǰ�����㶼�ŵ�channel��ȥ	
	//����Ҫ���������豸��Ŀ����Ϊ�˻��ѵ�ԭ�������������wifi�ķ���
	//wifi�ķ����Ǳ�������ָ�뵽�����У�����û�б�Ҫ��ô�鷳��ѡ��ʹ��vector���ָ�룬��ȥ��Ÿ�������ϣ����phy�ĸ���
	//����ֱ�ӵ����õ�channel�У�����Ҫ�������Ұָ�룬��Ϊ���������ȥ��ĳһ���豸��phy�����ܵ��������phyָ�뻹�ڣ���
	//�Ͳ�����Ұָ��
	std::vector<NetDeviceContainer*> LoraNetDevicecontainer;
	//channel  �����������豸��ָ�룬���������豸Ҫ����channel,����Ҫ����ָ��
	//��ʱ��vetor���ָ�룬���ǿɲ����л���֪�����������á�
	Time m_delay��
	Packet* m_currentPkt��
	
	
	public:
	void LoraChannel();
	bool TransmitStart (Ptr< Packet > p, uint32_t srcId);
	
	bool set_netdevice_lora(Ptr<LoraNetDevice>);
	pt<LoraNetDevice> get_netdevice_lora(uint32_t dev_id);
	
	
	
	bool  find_dev_equal(Ptr<LoraNetDevice> dev1,Ptr<LoraNetDevice> dev2);
	
}
;