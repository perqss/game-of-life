#include <iostream>

using namespace std;

const int N=6;
const int K=10;
char array1[N][N];
char array2[N][N];
 

int main()
{
    string s;
    int sum=0;

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++) cin>>array1[i][j];
    }
    cout<<"Enter 'START'."<<endl;
    cin>>s;
    if(s=="START")
    {
        for(int p=0;p<K;p++)
        {
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    for(int w=-1;w<=1;w++)
                    {
                        for(int k=-1;k<=1;k++)
                        {
                            sum+=array1[(i+w+N)%N][(j+k+N)%N]-'0';
                        } 
                    }
                    if(array1[i][j]=='1')
                    {
                        sum-=1;
                        if(sum==2 || sum==3) array2[i][j]='1';
                        else array2[i][j]='0';
                    }
                    else if(array1[i][j]=='0')
                    {
                        if(sum==3) array2[i][j]='1';
                        else array2[i][j]='0';
                    }
                    sum=0;
                }   
            }
            if(p==0)
            {
                cout<<"Starting turn."<<endl;
                for(int i=0;i<N;i++)
                {
                    for(int j=0;j<N;j++) cout<<array1[i][j];
                    cout<<endl;   
                }
                cout<<endl;
            }
            cout<<"Number of generation: "<<p+1<<endl;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    array1[i][j]=array2[i][j];
                    cout<<array2[i][j];
                    array2[i][j]=0;
                }
                cout<<endl;
            }
            cout<<endl;
        }
    }
    return 0;

}