#include <iostream>
#include <cstdio>
using namespace std;

class block_of_clock
{
private:
    int amount;
    int clocks[9];
public:
    block_of_clock()
    {
        amount=0;
    }
    block_of_clock(int i)
    {
        amount=9;
        for (int i=0;i<amount;i++)
        {
            clocks[i]=0;
        }
    }
    block_of_clock(int aa,int bb,int cc)
    {
        amount=9;
        for (int i=0;i<amount;i++)
        {
            clocks[i]=0;
        }
        clocks[aa]=1;
        clocks[bb]=1;
        clocks[cc]=1;
    }
    block_of_clock(int aa,int bb,int cc,int dd)
    {
        amount=9;
        for (int i=0;i<amount;i++)
        {
            clocks[i]=0;
        }
        clocks[aa]=1;
        clocks[bb]=1;
        clocks[cc]=1;
        clocks[dd]=1;
    }
    block_of_clock(int aa,int bb,int cc,int dd,int ee)
    {
        amount=9;
        for (int i=0;i<amount;i++)
        {
            clocks[i]=0;
        }
        clocks[aa]=1;
        clocks[bb]=1;
        clocks[cc]=1;
        clocks[dd]=1;
        clocks[ee]=1;
    }
    void push(int i)
    {
        clocks[amount++]=i;
    }
    void operator=(block_of_clock const &a)
    {
        for (int i=0;i<9;i++)
        {
            clocks[i]=a.clocks[i];
        }
    }
    block_of_clock operator+(block_of_clock const &a)
    {
        block_of_clock tmp;
        for (int i=0;i<9;i++)
        {
            tmp.clocks[i]=(clocks[i]+a.clocks[i])%4;
        }
        return tmp;
    }
    block_of_clock operator*(int a)
    {
        block_of_clock tmp(1);
        for (int i=0;i<a;i++)
        {
            for (int j=0;j<9;j++)
            {
                tmp.clocks[j]=(clocks[j]+tmp.clocks[j])%4;
            }
        }
        return tmp;
    }
    int is_Mid_night()
    {
        int i=1;
        for (int j=0;j<9;j++)
        {
            if (clocks[j]!=0)
            {
                i=0;
                break;
            }
        }
        return i;
    }
    void print_block()
    {
        for (int i=0;i<3;i++)
        {
            for (int j=0;j<3;j++)
            {
                cout<<clocks[i*3+j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }

};
int main()
{
    int tmp;
    block_of_clock A,B[10];
    for (int i=0;i<9;i++)
    {
        cin>>tmp;
        A.push((tmp/3)%4);
    }
    B[0]=block_of_clock(0,1,3,4);
    B[1]=block_of_clock(0,1,2);
    B[2]=block_of_clock(1,2,4,5);
    B[3]=block_of_clock(0,3,6);
    B[4]=block_of_clock(1,3,4,5,7);
    B[5]=block_of_clock(2,5,8);
    B[6]=block_of_clock(3,4,6,7);
    B[7]=block_of_clock(6,7,8);
    B[8]=block_of_clock(4,5,7,8);
    B[9]=block_of_clock(1);
    int a,b,c,d,e,f,g,h,i;
    a=b=c=d=e=f=g=h=i=0;
    for (int j=0;j<262144;j++)
    {
        i=j%4;
        h=(j/4)%4;
        g=(j/16)%4;
        f=(j/64)%4;
        e=(j/256)%4;
        d=(j/1024)%4;
        c=(j/4096)%4;
        b=(j/16384)%4;
        a=(j/65536)%4;
        if ((A+B[0]*a+B[1]*b+B[2]*c+B[3]*d+B[4]*e+B[5]*f+B[6]*g+B[7]*h+B[8]*i).is_Mid_night())break;
    }
    for (int i=0;i<a;i++)
    {
        cout<<'1'<<' ';
    }
    for (int i=0;i<b;i++)
    {
        cout<<'2'<<' ';
    }
    for (int i=0;i<c;i++)
    {
        cout<<'3'<<' ';
    }
    for (int i=0;i<d;i++)
    {
        cout<<'4'<<' ';
    }
    for (int i=0;i<e;i++)
    {
        cout<<'5'<<' ';
    }
    for (int i=0;i<f;i++)
    {
        cout<<'6'<<' ';
    }
    for (int i=0;i<g;i++)
    {
        cout<<'7'<<' ';
    }
    for (int i=0;i<h;i++)
    {
        cout<<'8'<<' ';
    }
    for (int k=0;k<i;k++)
    {
        cout<<'9'<<' ';
    }
    return 0;
}

