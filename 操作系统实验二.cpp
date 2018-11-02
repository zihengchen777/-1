#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fstream>
#include<string.h>
using namespace std;
#define RUN "运行"
#define WAIT "等待"
#define DELETE "销毁"
#define READY "就绪"
#define WAITCREATE "待创建"
typedef struct pcb
{
    int name;
    char state[20];
    struct pcb*next;

}pcb;
pcb *head=NULL;  //正常队列
pcb *head1=NULL; //未到达队列
pcb pcbs[5];

class mainPcb{

public:
    void runProcess();     //运行进程，以实现操作
    void createProcess();
    void deleteProcess();
    void hangProcess();
    void activeProcess();
    void timeTo();
    void initialize();     //初始化 所有进程均为待创建
    //void processStste();
};
//运行进程
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
    cout<<"进程序号"<<"\t"<<"进程初始状态"<<"\n";
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
void mainPcb::createProcess() //创建进程
{
    cout<<"创建进程\n";
    cout<<"=============\n";

    for(int i=0;i<5;i++){

        pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,WAITCREATE)==0){
        strcpy(pcbs[i].state,READY);
         break;
        }
        cout<<"进程序号\t"<<"进程状态\n";
        for(int j=0;j<5;j++)
        cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";
    }
     cout<<"\n";


}
void mainPcb::deleteProcess() //销毁进程
{
    cout<<"销毁进程";
    cout<<"==============\n";
    for(int i=0;i<5;i++){
            pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,RUN)==0){
            strcpy(pcbs[i].state,DELETE);
            break;
        }
        cout<<"进程序号\t"<<"进程状态\n";
        for(int j=0;j<5;j++)
            cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";
    }
    cout<<"\n";
}
void mainPcb::hangProcess()  //挂起进程
{
     cout<<"挂起进程\n";
    cout<<"=============\n";

    for(int i=0;i<5;i++){

        pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,RUN)==0){
        strcpy(pcbs[i].state,WAIT);
         break;
        }

        }
        cout<<"进程序号\t"<<"进程状态\n";
        for(int j=0;j<5;j++){
        cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";


    }
     cout<<"\n";
}
void mainPcb::activeProcess()  //激活进程
{
    cout<<"激活进程";
    cout<<"===============\n";
     for(int i=0;i<5;i++){

        pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,WAIT)==0){
        strcpy(pcbs[i].state,READY);
         break;
        }

    }
    cout<<"进程序号\t"<<"进程状态\n";
        for(int j=0;j<5;j++)
        cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";
     cout<<"\n";
}
void mainPcb::timeTo()  //时间片到
{
    cout<<"时间片到";
    cout<<"===============\n";
     for(int i=0;i<5;i++){

        pcbs[i].name=i+1;
        if(strcmp(pcbs[i].state,RUN)==0){
        strcpy(pcbs[i].state,READY);
         break;
        }
    }
    cout<<"进程序号\t"<<"进程状态\n";
        for(int j=0;j<5;j++)
        cout<<pcbs[j].name<<"\t\t"<<pcbs[j].state<<"\n";
     cout<<"\n";
}


int main()
{


    mainPcb textpcb;
    textpcb.initialize();

    cout<<"=========================操作系统第二次实验======================\n";
    cout<<"陈子恒 2016210889\n";
    cout<<"0退出实验\n";
    cout<<"1创建进程\n";
    cout<<"2销毁进程\n";
    cout<<"3挂起进程\n";
    cout<<"4激活进程\n";
    cout<<"5时间片到\n";

    int choice;
    cout<<"请输入你的选择（数字)\n";
    cin>>choice;

while(choice!=0){
    switch(choice)
    {

    case 1:
        textpcb.createProcess();    //创建进程
        //textpcb.processStste();
        break;
    case 2:
        textpcb.deleteProcess();   //销毁进程
        break;
    case 3:
        textpcb.hangProcess();      //挂起进程
        break;
    case 4:
        textpcb.activeProcess();    //激活进程
        break;
    case 5:
        textpcb.timeTo();           //时间片到
        break;
    }

    cin>>choice;
    cout<<"\n";
    textpcb.runProcess();  //无论做出什么选择，都要有一个运行进程才行
  }

  cout<<"您以退出本次实验"<<"\n";

}
