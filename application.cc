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

  //原来绑定的是socket，通过socket去调用send,这里是send在netdevice里面，
  
  uint32_t        m_packetSize;//数据包的长度
  uint32_t        m_nPackets;//数据包的数量
  DataRate        m_dataRate;//发送的速率
  EventId         m_sendEvent;//事件ID不知道有用没
  bool            m_running;//状态
  uint32_t        m_packetsSent;//发送包的数量上限
  LoraNetDevice*  m_netdevice;   //该应用属于哪一个netdevice的
  uint32_t        m_loranodeid;  //该应用所属的node的ID号
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
  //参数配置，要解决发送多少次这个参数的问题
  
	m_packetSize=packetSize;//数据包的长度
  m_nPackets=nPackets;//数据包的数量
  m_dataRate=dataRate;//发送的速率
  //m_sendEvent=??;//事件ID不知道有用没
  m_running=running;//状态
  m_packetsSent=packetsSent;//发送包的数量上限
  m_netdevice=netdevice;   //该应用属于哪一个netdevice的
  m_loranodeid=loranodeid;  //该应用所属的node的ID号
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