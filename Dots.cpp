#include<iostream>
#include<cmath>
#include<cfloat>
using namespace std;
int main()
{
    int n=0,i,j;
    while (n <1){//если N < 1 - вводим ещЄ раз
            cout<<"Enter N ";
            cin>>n; //ввод N
        }
    double a[n][4],distance; //объ€вление массива Nx4 элементов и переменной distance
    for(i=0;i<n;i++){
        cout<<"X"<<i+1<<"= ";
        cin>>a[i][0]; //X
        cout<<"Y"<<i+1<<"= ";
        cin>>a[i][1]; //Y
        if(n==1)a[i][2]=0; else a[i][2]=DBL_MAX; //радиус (если точка 1, то 0 иначе максимально допустмое значение)
        a[i][3]=0; //счетчик "соседей"
    }
    for (i=0;i<n-1;i++) //вычисление радиуса
        for(j=i+1;j<n;j++){
                distance=sqrt(pow(a[j][0]-a[i][0],2)+pow(a[j][1]-a[i][1],2)); //вычисление рассто€ни€ между точками
                if(a[i][2]>distance)a[i][2]=distance;
                if(a[j][2]>distance)a[j][2]=distance;
            }
    for (i=0;i<n-1;i++) //вычисление количества "соседей"
        for(j=i+1;j<n;j++){
                distance=sqrt(pow(a[j][0]-a[i][0],2)+pow(a[j][1]-a[i][1],2));
                if(a[i][2]*2>=distance)a[i][3]++;
                if(a[j][2]*2>=distance)a[j][3]++;
            }
    for (i=0;i<n;i++) //вывод результата
            cout<<"X("<<a[i][0]<<","<<a[i][1]<<") Rad: "<<a[i][2]<<" CON: "<<a[i][3]<<"\n";
    getchar();
    return 0;
}
