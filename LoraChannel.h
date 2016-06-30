#include<iostream>
#include "ns3/core-module.h"
#include "ns3/simulator-module.h"
#include "ns3/node-module.h"
#include "ns3/helper-module.h"
#include "LoraNetDevice.h"
#include <vector>
using namespace NS3;

//��������������netdevice��������Ҫ����ѭ�����õ�����
class LoraNetDevice;//ǰ������
LoraChannel::channel
{
	private:
  Ptr<NetDeviceContainer> LoraNetDevicecontainer;
	Time m_delay;//ʱ����Ϣ
  Ptr<Packet>m_currentPkt;//�ŵ��еĵ�ǰ������ʱ����
 
	public:
	void LoraChannel();//���캯��
	bool TransmitStart (Ptr<Packet> p, uint32_t srcId); //���ĵķ�������
	bool init_set_netdevice_lora(Ptr<NodeContainer>devices_trans);//�����ŵ��е������豸
	pt<LoraNetDevice> get_netdevice_lora(uint32_t dev_id);//���һ���ŵ��е������豸�����Ŀǰ��ʵ��
	bool set_netdevice_lora(Ptr<LoraNetDevice>);//���������豸�Ľӿڣ���ʱ��ʵ��
	bool set_current_packet(Ptr<Packet> read); //���Ҫʵ�֣�����Ҫע��ͬ�����첽������
}
;