#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fstream>
#include<string.h>
using namespace std;
#define RUN "����"
#define WAIT "�ȴ�"
#define DELETE "����"
#define READY "����"
#define WAITCREATE "������"
typedef struct pcb
{
    int name;
    char state[20];
    struct pcb*next;

}pcb;
pcb *head=NULL;  //��������
pcb *head1=NULL; //δ�������
pcb pcbs[5];

class mainPcb{

public:
    void runProcess();     //���н��̣���ʵ�ֲ���
    void createProcess();
    void deleteProcess();
    void hangProcess();
    void activeProcess();
    void timeTo();
    void initialize();     //��ʼ�� ���н��̾�Ϊ������
    //void processStste();
};
//���н���
void mainPcb::runProcess(){
    bool flag=false;
    for(int i=0; i<5;i++){
        if(strcmp(pcbs[i].state,RUN)==0){
            flag =true;
            break;
            }

    }
    if(flag==false){
        for(int i=0;i<5;i++){
            if(strcmp(pcbs[i].state,READY)==0){
                strcpy(pcbs[i].state,RUN);
                break;
            }
        }
    }
}
void mainPcb::initialize()
{
    cout<<"�������"<<"\t"<<"���̳�ʼ״̬"<<"\n";
    for(int i=0;i<5;i++)
    {
        pcbs[i].name=i+1;
        strcpy(pcbs[i].state,WAITCREATE);
        cout<<pcbs[i].name<<"\t\t"<<pcbs[i].state<<"\n";
    }

}
/*void mainPcb::processStste()
{
   for(int i=0;i<5;i++)
   {
       cout<<pcbs[i].name<<"\t"<<pcbs[i].state<<"\n";
   }

}
*/
void mainPcb::createProcess() //��������
{
    cout<<"��������\n";
    cout<<"=============\n";

    for(int i=0;i<5;i++){

        pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,WAITCREATE)==0){
        strcpy(pcbs[i].state,READY);
         break;
        }
        cout<<"�������\t"<<"����״̬\n";
        for(int j=0;j<5;j++)
        cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";
    }
     cout<<"\n";


}
void mainPcb::deleteProcess() //���ٽ���
{
    cout<<"���ٽ���";
    cout<<"==============\n";
    for(int i=0;i<5;i++){
            pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,RUN)==0){
            strcpy(pcbs[i].state,DELETE);
            break;
        }
        cout<<"�������\t"<<"����״̬\n";
        for(int j=0;j<5;j++)
            cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";
    }
    cout<<"\n";
}
void mainPcb::hangProcess()  //�������
{
     cout<<"�������\n";
    cout<<"=============\n";

    for(int i=0;i<5;i++){

        pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,RUN)==0){
        strcpy(pcbs[i].state,WAIT);
         break;
        }

        }
        cout<<"�������\t"<<"����״̬\n";
        for(int j=0;j<5;j++){
        cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";


    }
     cout<<"\n";
}
void mainPcb::activeProcess()  //�������
{
    cout<<"�������";
    cout<<"===============\n";
     for(int i=0;i<5;i++){

        pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,WAIT)==0){
        strcpy(pcbs[i].state,READY);
         break;
        }

    }
    cout<<"�������\t"<<"����״̬\n";
        for(int j=0;j<5;j++)
        cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";
     cout<<"\n";
}
void mainPcb::timeTo()  //ʱ��Ƭ��
{
    cout<<"ʱ��Ƭ��";
    cout<<"===============\n";
     for(int i=0;i<5;i++){

        pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,RUN)==0){
        strcpy(pcbs[i].state,READY);
         break;
        }
    }
    cout<<"�������\t"<<"����״̬\n";
        for(int j=0;j<5;j++)
        cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";
     cout<<"\n";
}


int main()
{


    mainPcb textpcb;
    textpcb.initialize();

    cout<<"=========================����ϵͳ�ڶ���ʵ��======================\n";
    cout<<"���Ӻ� 2016210889\n";
    cout<<"0�˳�ʵ��\n";
    cout<<"1��������\n";
    cout<<"2���ٽ���\n";
    cout<<"3�������\n";
    cout<<"4�������\n";
    cout<<"5ʱ��Ƭ��\n";

    int choice;
    cout<<"���������ѡ������)\n";
    cin>>choice;

while(choice!=0){
    switch(choice)
    {

    case 1:
        textpcb.createProcess();    //��������
        //textpcb.processStste();
        break;
    case 2:
        textpcb.deleteProcess();   //���ٽ���
        break;
    case 3:
        textpcb.hangProcess();      //�������
        break;
    case 4:
        textpcb.activeProcess();    //�������
        break;
    case 5:
        textpcb.timeTo();           //ʱ��Ƭ��
        break;
    }

    cin>>choice;
    cout<<"\n";
    textpcb.runProcess();  //��������ʲôѡ�񣬶�Ҫ��һ�����н��̲���
  }

  cout<<"�����˳�����ʵ��"<<"\n";

}
