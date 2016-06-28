#include"application.h"
class MyApp : public Application 
{
public:

  MyApp ();
  virtual ~MyApp();

  void Setup (Ptr<Socket> socket, Address address, uint32_t packetSize, uint32_t nPackets, DataRate dataRate);

private:
  virtual void StartApplication (void);
  virtual void StopApplication (void);

  void ScheduleTx (void);
  void SendPacket (void);

  //ԭ���󶨵���socket��ͨ��socketȥ����send,������send��netdevice���棬
  
  uint32_t        m_packetSize;//���ݰ��ĳ���
  uint32_t        m_nPackets;//���ݰ�������
  DataRate        m_dataRate;//���͵�����
  EventId         m_sendEvent;//�¼�ID��֪������û
  bool            m_running;//״̬
  uint32_t        m_packetsSent;//���Ͱ�����������
  LoraNetDevice*  m_netdevice;   //��Ӧ��������һ��netdevice��
  uint32_t        m_loranodeid;  //��Ӧ��������node��ID��
};

MyApp::MyApp ()
{
}

MyApp::~MyApp()
{
}

void MyApp::Setup ( uint32_t packetSize, uint32_t nPackets, DataRate dataRate\
									  uint32_t running,  uint32_t packetsSent,\
									   LoraNetDevice* netdevice, uint32_t loranodeid
									)
{
  //�������ã�Ҫ������Ͷ��ٴ��������������
  
	m_packetSize=packetSize;//���ݰ��ĳ���
  m_nPackets=nPackets;//���ݰ�������
  m_dataRate=dataRate;//���͵�����
  //m_sendEvent=??;//�¼�ID��֪������û
  m_running=running;//״̬
  m_packetsSent=packetsSent;//���Ͱ�����������
  m_netdevice=netdevice;   //��Ӧ��������һ��netdevice��
  m_loranodeid=loranodeid;  //��Ӧ��������node��ID��
}

void MyApp::StartApplication (void)
{
  m_running = true;
  m_packetsSent = 0;
  SendPacket ();
}

void 
MyApp::StopApplication (void)
{
  m_running = false;

  if (m_sendEvent.IsRunning ())
    {
      Simulator::Cancel (m_sendEvent);
    }

  if (m_socket)
    {
      m_socket->Close ();
    }
}

void 
MyApp::SendPacket (void)
{
  Ptr<Packet> packet = Create<Packet> (m_packetSize);
  m_netdevice->Send (packet);

  if (++m_packetsSent < m_nPackets)
    {
      ScheduleTx ();
    }
}

void 
MyApp::ScheduleTx (void)
{
  if (m_running)
    {
      Time tNext (Seconds (m_packetSize * 8 / static_cast<double> (m_dataRate.GetBitRate ())));
      m_sendEvent = Simulator::Schedule (tNext, &MyApp::SendPacket, this);
    }
}


void
MyApp::Listen()
{
	
	



}