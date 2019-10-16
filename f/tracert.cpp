//
// Created by Administrator on 2019/10/16.
//

/*
 C++ʵ��·��׷��(Tracert)���� ���� https://blog.csdn.net/qq_34490018/article/details/85093197#comments

 Tracertʵ��ԭ��
 Tracert����ؼ��Ƕ�IPͷ������ʱ��(time to live)TTL�ֶε�ʹ��,����ʵ��ʱ����Ŀ����������һ��ICMP����������Ϣ����ʼʱTTL����1��
 �����������ݱ��ִ�;�еĵ�һ��·����ʱ��TTL��ֵ�ͱ���Ϊ0�����·�����ʱ������˸�·������һ��ICMP��ʱ������ķ��ظ�Դ���������
 ���������ݱ���TTLֵ����1���Ա�IP���ܴ��͵���һ��·������������һ��·��������ICMP��ʱ������ķ��ظ�Դ�����������ظ�������̣�
 ֱ�����ݱ��ﵽ���յ�Ŀ����������ʱĿ������������ICMP����Ӧ����Ϣ��������Դ����ֻ��Է��ص�ÿһ��ICMP���Ľ��н���������
 �Ϳ����������ݱ���Դ��������Ŀ������;����������·����Ϣ��
 
 ������ Request timed out.����Ҫ����Ƿ���˷���ǽ�����˷���ǽ�ᵼ�·������
 */

#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <iomanip>

#pragma comment(lib, "ws2_32.lib")
using namespace std;

//IP��ͷ
typedef struct {
    unsigned char hdr_len:4;         //4λͷ������
    unsigned char version:4;         //4λ�汾��
    unsigned char tos;               //8λ��������
    unsigned short total_len;        //16λ�ܳ���
    unsigned short identifier;       //16λ��ʶ��
    unsigned short frag_and_flags;   //3λ��־��13λƬƫ��
    unsigned char ttl;               //8λ����ʱ��
    unsigned char protocol;          //8λ�ϲ�Э���
    unsigned short checksum;         //16λЧ���
    unsigned long sourceIP;          //32λԴIP��ַ
    unsigned long destIP;            //32λĿ��IP��ַ
} IP_HEADER;

//ICMP��ͷ
typedef struct {
    BYTE type;     //8λ�����ֶ�
    BYTE code;     //8λ�����ֶ�
    USHORT cksum;  //16λЧ���
    USHORT id;     //16λ��ʶ��
    USHORT seq;    //16λ���к�
} ICMP_HEADER;


//���Ľ���ṹ
typedef struct {
    USHORT usSeqNo;          //���к�
    DWORD dwRoundTripTime;   //����ʱ��
    in_addr dwIPaddr;        //���ر��ĵ�IP��ַ
} DECODE_RESULT;

//��������Ч��ͺ���
USHORT checksum(USHORT *pBuf, int iSize) {
    unsigned long cksum = 0;
    while (iSize > 1) {
        cksum += *pBuf++;
        iSize -= sizeof(USHORT);
    }
    if (iSize) {
        cksum += *(USHORT *) pBuf;
    }
    cksum = (cksum >> 16) + (cksum & 0xffff);
    cksum += (cksum >> 16);
    return (USHORT) (~cksum);
}

//�����ݰ����н���
BOOL
DecodeIcmpResponse(char *pBuf, int iPacketSize, DECODE_RESULT &DecodeResult, BYTE ICMP_ECHO_REPLY, BYTE ICMP_TIMEOUT) {
    //������ݱ���С�ĺϷ���
    IP_HEADER *pIpHdr = (IP_HEADER *) pBuf;
    int iIpHdrLen = pIpHdr->hdr_len * 4;
    if (iPacketSize < (int) (iIpHdrLen + sizeof(ICMP_HEADER)))
        return FALSE;
    //����ICMP����������ȡID�ֶκ����к��ֶ�
    ICMP_HEADER *pIcmpHdr = (ICMP_HEADER *) (pBuf + iIpHdrLen);
    USHORT usID, usSquNo;
    if (pIcmpHdr->type == ICMP_ECHO_REPLY)    //ICMP����Ӧ����
    {
        usID = pIcmpHdr->id;   //����ID
        usSquNo = pIcmpHdr->seq;  //�������к�
    } else if (pIcmpHdr->type == ICMP_TIMEOUT)   //ICMP��ʱ�������
    {
        char *pInnerIpHdr = pBuf + iIpHdrLen + sizeof(ICMP_HEADER);  //�غ��е�IPͷ
        int iInnerIPHdrLen = ((IP_HEADER *) pInnerIpHdr)->hdr_len * 4; //�غ��е�IPͷ��
        ICMP_HEADER *pInnerIcmpHdr = (ICMP_HEADER *) (pInnerIpHdr + iInnerIPHdrLen);//�غ��е�ICMPͷ
        usID = pInnerIcmpHdr->id;  //����ID
        usSquNo = pInnerIcmpHdr->seq;  //���к�
    } else {
        return false;
    }
    //���ID�����к���ȷ���յ��ڴ����ݱ�
    if (usID != (USHORT) GetCurrentProcessId() || usSquNo != DecodeResult.usSeqNo) {
        return false;
    }
    //��¼IP��ַ����������ʱ��
    DecodeResult.dwIPaddr.s_addr = pIpHdr->sourceIP;
    DecodeResult.dwRoundTripTime = GetTickCount() - DecodeResult.dwRoundTripTime;

    //������ȷ�յ���ICMP���ݱ�
    if (pIcmpHdr->type == ICMP_ECHO_REPLY || pIcmpHdr->type == ICMP_TIMEOUT) {
        //�������ʱ����Ϣ
        if (DecodeResult.dwRoundTripTime)
            cout << "    " << DecodeResult.dwRoundTripTime << "ms" << flush;
        else
            cout << "    " << "<1ms" << flush;
    }
    return true;
}


int main() {
    //��ʼ��Windows sockets���绷��
    WSADATA wsa;
    WSAStartup(MAKEWORD(2, 2), &wsa);
    char IpAddress[255];
    cout << "������һ��IP��ַ��������";
    cin >> IpAddress;
    //�õ�IP��ַ
    u_long ulDestIP = inet_addr(IpAddress);
    //ת�����ɹ�ʱ����������
    if (ulDestIP == INADDR_NONE) {
        hostent *pHostent = gethostbyname(IpAddress);
        if (pHostent) {
            ulDestIP = (*(in_addr *) pHostent->h_addr).s_addr;
        } else {
            cout << "�����IP��ַ��������Ч" << endl;
            WSACleanup();
            return 0;
        }
    }
    cout << "Tracing route to " << IpAddress << " with a maximum of 30 hops.\n" << endl;
    //���Ŀ�Ķ�socket��ַ
    sockaddr_in destSockAddr;
    ZeroMemory(&destSockAddr, sizeof(sockaddr_in));
    destSockAddr.sin_family = AF_INET;
    destSockAddr.sin_addr.s_addr = ulDestIP;
    //����ԭʼ�׽���
    SOCKET sockRaw = WSASocket(AF_INET, SOCK_RAW, IPPROTO_ICMP, NULL, 0, WSA_FLAG_OVERLAPPED);
    //��ʱʱ��
    int iTimeout = 3000;
    //���ճ�ʱ
    setsockopt(sockRaw, SOL_SOCKET, SO_RCVTIMEO, (char *) &iTimeout, sizeof(iTimeout));
    //���ͳ�ʱ
    setsockopt(sockRaw, SOL_SOCKET, SO_SNDTIMEO, (char *) &iTimeout, sizeof(iTimeout));


    //����ICMP����������Ϣ������TTL������˳���ͱ���
    //ICMP�����ֶ�
    const BYTE ICMP_ECHO_REQUEST = 8;   //�������
    const BYTE ICMP_ECHO_REPLY = 0;     //����Ӧ��
    const BYTE ICMP_TIMEOUT = 11;       //���䳬ʱ

    //������������
    const int DEF_ICMP_DATA_SIZE = 32;    //ICMP����Ĭ�������ֶγ���
    const int MAX_ICMP_PACKET_SIZE = 1024; //ICMP������󳤶ȣ�������ͷ��
    const DWORD DEF_ICMP_TIMEOUT = 3000;   //����Ӧ��ʱʱ��
    const int DEF_MAX_HOP = 30;            //�����վ��

    //���ICMP������ÿ�η���ʱ������ֶ�
    char IcmpSendBuf[sizeof(ICMP_HEADER) + DEF_ICMP_DATA_SIZE]; //���ͻ�����
    memset(IcmpSendBuf, 0, sizeof(IcmpSendBuf));     //��ʼ�����ͻ�����
    char IcmpRecvBuf[MAX_ICMP_PACKET_SIZE];        //���ջ�����
    memset(IcmpRecvBuf, 0, sizeof(IcmpRecvBuf));     //��ʼ�����ջ�����

    ICMP_HEADER *pIcmpHeader = (ICMP_HEADER *) IcmpSendBuf;
    pIcmpHeader->type = ICMP_ECHO_REQUEST;             //����Ϊ�������
    pIcmpHeader->code = 0;                             //�����ֶ�Ϊ0
    pIcmpHeader->id = (USHORT) GetCurrentProcessId();   //ID�ֶ�Ϊ��ǰ���̺�
    memset(IcmpSendBuf + sizeof(ICMP_HEADER), 'E', DEF_ICMP_DATA_SIZE);   //�����ֶ�

    USHORT usSeqNo = 0;                //ICMP�������к�
    int iTTL = 1;                      //TTL��ʼֵΪ1
    BOOL bReachDestHost = FALSE;       //ѭ���˳���־
    int iMaxHot = DEF_MAX_HOP;         //ѭ����������
    DECODE_RESULT DecodeResult;      //���ݸ����Ľ��뺯���Ľṹ������
    while (!bReachDestHost && iMaxHot--) {
        //����IP��ͷ��TTL�ֶ�
        setsockopt(sockRaw, IPPROTO_IP, IP_TTL, (char *) &iTTL, sizeof(iTTL));
        // << setw(2) << left ����룬����Ϊ2
        cout << setw(2) << left << iTTL << flush;       //�����ǰ���
        //���ICMP������ÿ�η��ͱ仯���ֶ�
        ((ICMP_HEADER *) IcmpSendBuf)->cksum = 0;                 //Ч�������Ϊ0
        ((ICMP_HEADER *) IcmpSendBuf)->seq = htons(usSeqNo++);    //������к�
        ((ICMP_HEADER *) IcmpSendBuf)->cksum = checksum((USHORT *) IcmpSendBuf,
                                                        sizeof(ICMP_HEADER) + DEF_ICMP_DATA_SIZE);  //����Ч���

        //��¼���кź͵�ǰʱ��
        DecodeResult.usSeqNo = ((ICMP_HEADER *) IcmpSendBuf)->seq;    //��ǰ���
        DecodeResult.dwRoundTripTime = GetTickCount();              //��ǰʱ��
        //����TCP����������Ϣ
        sendto(sockRaw, IcmpSendBuf, sizeof(IcmpSendBuf), 0, (sockaddr *) &destSockAddr, sizeof(destSockAddr));
        //����ICMP������Ĳ����н�������
        sockaddr_in from;              //�Զ�socket��ַ
        int iFromLen = sizeof(from);     //��ַ�ṹ��С
        int iReadDataLen;              //�������ݳ���
        while (1) {
            //��������
            iReadDataLen = recvfrom(sockRaw, IcmpRecvBuf, MAX_ICMP_PACKET_SIZE, 0, (sockaddr *) &from, &iFromLen);
            if (iReadDataLen != SOCKET_ERROR)//�����ݴﵽ
            {
                //�����ݰ����н���
                if (DecodeIcmpResponse(IcmpRecvBuf, iReadDataLen, DecodeResult, ICMP_ECHO_REPLY, ICMP_TIMEOUT)) {
                    //����Ŀ�ĵأ��˳�ѭ��
                    if (DecodeResult.dwIPaddr.s_addr == destSockAddr.sin_addr.s_addr)
                        bReachDestHost = true;
                    //���IP��ַ
                    cout << '\t' << inet_ntoa(DecodeResult.dwIPaddr) << endl;
                    break;
                }
            } else if (WSAGetLastError() == WSAETIMEDOUT) //���ճ�ʱ������Ǻ�
            {
                cout << "          *" << '\t' << "Request timed out" << endl;
                break;
            } else {
                break;
            }
        }
        iTTL++;   //����TTLֵ
    }
}