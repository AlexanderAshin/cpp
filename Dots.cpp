#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std;
int main()
{
    int n=0,i,j;
    while (n <1){//���� N < 1 - ������ ��� ���
            cout<<"Enter N ";
            cin>>n; //���� N
        }
    double a[n][4],distance; //���������� ������� Nx4 ��������� � ���������� distance
    for(i=0;i<n;i++){
        cout<<"X"<<i+1<<"= ";
        cin>>a[i][0]; //X
        cout<<"Y"<<i+1<<"= ";
        cin>>a[i][1]; //Y
        if(n==1)a[i][2]=0; else a[i][2]=DBL_MAX; //������ (���� ����� 1, �� 0 ����� ����������� ��������� ��������)
        a[i][3]=0; //������� "�������"
    }
    for (i=0;i<n-1;i++) //���������� �������
        for(j=i+1;j<n;j++){
                distance=sqrt(pow(a[j][0]-a[i][0],2)+pow(a[j][1]-a[i][1],2)); //���������� ���������� ����� �������
                if(a[i][2]>distance)a[i][2]=distance;
                if(a[j][2]>distance)a[j][2]=distance;
            }
    for (i=0;i<n-1;i++) //���������� ���������� "�������"
        for(j=i+1;j<n;j++){
                distance=sqrt(pow(a[j][0]-a[i][0],2)+pow(a[j][1]-a[i][1],2));
                if(a[i][2]*2>=distance)a[i][3]++;
                if(a[j][2]*2>=distance)a[j][3]++;
            }
    for (i=0;i<n;i++) //����� ����������
            cout<<"X("<<a[i][0]<<","<<a[i][1]<<") Rad: "<<a[i][2]<<" CON: "<<a[i][3]<<"\n";
    getchar();
    return 0;
}
