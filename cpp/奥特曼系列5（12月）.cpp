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
    void display(){cout <<"奥特曼状态("<< "rank=" << (int)rank << " hp=" << (int)hp << " damage=" << (int)damage << " exp=" << (int)exp << " money=" << (int)money << ")"<<endl;};
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
    int getRank(){return rank;};//知道等级就知道了攻击型守护神的攻击力
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
    void display(){cout<< "怪兽状态(rank=" ;Monster::display();};
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
         void display(){cout<<"Boss怪兽状态(rank=" ;Monster::display();};
 };
void BOSS::attacked1(int da)
{
    count++;
    Monster::attacked(da);
}
int main(){
    //输入奥特曼的等级值，利用等级值，声明一个奥特曼对象并显示奥特曼对象初始状态。
    int ograd;   cin>>ograd;
    Ultraman uobj(ograd); 
    int t;   cin>>t;//输入要打的怪兽个数数
    while(t--&&uobj.getHp()>10){//只要奥特曼没死也没逃跑，就继续与怪兽的战斗
         uobj.display();   
         Monster* p;  
         char c=0;
         while(1){
             cin>>c;
             if(c=='B') {p=new BOSS();break;}
             else if(c=='M') {int r;cin>>r;p=new NMonster(r);break;}   
             else cout<<"请重新输入怪兽类型"<<endl;
         }
         p->display();         
         //设置战斗标志flag为true，启动战斗循环，具体如下：
         int flag=1;
         while(flag) //当战斗未结束就继续
         {   p->attacked(uobj.getDamage());//奥特曼攻击1次             
             if (p->getHp()>0)  //怪兽没死
             {   uobj.attacked(p->getDamage());//怪兽反击1次
                  if (uobj.getHp()>10)      //奥特曼生命值大于点，不逃跑
                      uobj.restore();//奥特曼回血，在方法中判断是否需要加血
                  else {   //奥特曼逃跑，并输出"lose"并回车
                      uobj.escape();
                      cout<<"lose"<<endl;                    
                      uobj.display();//输出奥特曼状态        
                      flag=0;//停止战斗                  
                  }
             }
             else //怪兽死了
             {   uobj.win(p->getExp(),p->getMoney());     //奥特曼胜利，并输出"win"并回车
                  cout<<"win"<<endl;
					p->lose();//输出怪兽战败信息
                  flag=0;//停止战斗 
             }
         }
    }
    return 0;
}
