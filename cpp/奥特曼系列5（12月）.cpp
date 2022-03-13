#include <iostream>
using namespace std;
class Ultraman
{
	 int damage,hp,money,exp,rank;
    public:
    Ultraman(int r):rank(r),hp(r*10),damage(r * 3), money(r * 10), exp(0){};
    int getDamage() { return damage; };
    int getHp(){return hp;};
    void attacked(int da){hp-=da/2;};
    void display(){cout <<"������״̬("<< "rank=" << (int)rank << " hp=" << (int)hp << " damage=" << (int)damage << " exp=" << (int)exp << " money=" << (int)money << ")"<<endl;};
    void restore();
    int getRank(){return rank;};
    void escape(){  money=0;};
    void win(int e,int m);
    void upgrade();
};
void Ultraman::win(int e,int m)
{
    exp += e ;
    money += m ;
    while(exp>=10*rank) upgrade();
}
void Ultraman::restore()
{
    if (hp > 10 && (hp <= rank * 10 * 0.5))
        while (hp < rank * 10)
        {
            if (money >= 10)
            {
                money -= 10;
                hp++;
            }
            else break;
        }
}
void Ultraman::upgrade()
{
    exp -= 10 * (rank);
    rank++;
    hp = rank * 10;
    damage = rank * 3;
}
class Monster{
    int damage,hp,money,exp,rank;
    public:
    Monster(int r,int d,int h,int m,int e):rank(r),damage(d),hp(h),money(m),exp(e){};
    int getRank(){return rank;};//֪���ȼ���֪���˹������ػ���Ĺ�����
    void attacked(int da){hp-=da;};
    int getDamage(){return damage;};
    int getHp(){return hp;};
    int getExp(){return exp;};
    int getMoney(){return money;};
    virtual void lose(){};
    virtual void display(){cout <<(int)rank << " hp=" << (int)hp << " damage=" << (int)damage << " exp=" << (int)exp << " money=" << (int)money <<")"<< endl;}
};
class NMonster:public Monster{
  
    public:
    NMonster(int rank):Monster(rank,rank*2,rank*20,rank*10,rank*10){};
    void lose(){cout<<"Boss!Help!"<<endl;};
    void display(){cout<< "����״̬(rank=" ;Monster::display();};
}; 
class BOSS:public Monster
{
    private: int count;
    public:
        int XP(){cout<<"XP*****"<<endl;return Monster::getDamage()*3;};
        BOSS():Monster(10,50,300,1001,1000){};
        void attacked1(int da);
        int getDamage(){if(count%5==0) return XP(); return Monster::getDamage();};
        void lose(){cout<<"I'll be back!"<<endl;};
         void display(){cout<<"Boss����״̬(rank=" ;Monster::display();};
 };
void BOSS::attacked1(int da)
{
    count++;
    Monster::attacked(da);
}
int main(){
    //����������ĵȼ�ֵ�����õȼ�ֵ������һ��������������ʾ�����������ʼ״̬��
    int ograd;   cin>>ograd;
    Ultraman uobj(ograd); 
    int t;   cin>>t;//����Ҫ��Ĺ��޸�����
    while(t--&&uobj.getHp()>10){//ֻҪ������û��Ҳû���ܣ��ͼ�������޵�ս��
         uobj.display();   
         Monster* p;  
         char c=0;
         while(1){
             cin>>c;
             if(c=='B') {p=new BOSS();break;}
             else if(c=='M') {int r;cin>>r;p=new NMonster(r);break;}   
             else cout<<"�����������������"<<endl;
         }
         p->display();         
         //����ս����־flagΪtrue������ս��ѭ�����������£�
         int flag=1;
         while(flag) //��ս��δ�����ͼ���
         {   p->attacked(uobj.getDamage());//����������1��             
             if (p->getHp()>0)  //����û��
             {   uobj.attacked(p->getDamage());//���޷���1��
                  if (uobj.getHp()>10)      //����������ֵ���ڵ㣬������
                      uobj.restore();//��������Ѫ���ڷ������ж��Ƿ���Ҫ��Ѫ
                  else {   //���������ܣ������"lose"���س�
                      uobj.escape();
                      cout<<"lose"<<endl;                    
                      uobj.display();//���������״̬        
                      flag=0;//ֹͣս��                  
                  }
             }
             else //��������
             {   uobj.win(p->getExp(),p->getMoney());     //������ʤ���������"win"���س�
                  cout<<"win"<<endl;
					p->lose();//�������ս����Ϣ
                  flag=0;//ֹͣս�� 
             }
         }
    }
    return 0;
}
