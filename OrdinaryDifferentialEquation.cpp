/*
 Ordinary differential equation in C++
 C++による常微分方程式の計算アルゴリズム
 https://github.com/neguseatama
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

//常微分方程式dy/dx=f(x)の関数
//f(x)=x+yとする。
double f(double x,double y){
    return x+y;
}

//ニュートン法による常微分方程式の解の計算
double newton(double x0,double y0,double h,ll n){
    double x=x0;
    double y=y0;
    for(ll i=0;i<n;i++){
        //ルンゲ=クッタ法による数値積分も利用
        double k1=f(x,y);
        double k2=f(x+h/2.0,y+h*k1/2.0);
        double k3=f(x+h/2.0,y+h*k2/2.0);
        double k4=f(x+h,y+h*k3);
        y+=h*(k1+2.0*k2+2.0*k3+k4)/6.0;
        x+=h;
    }
    return y;
}

int main(void){
    //初期値
    double x0,y0;
    cin>>x0>>y0;
    
    //ステップサイズ,ステップ数
    double h;
    ll n;
    cin>>h>>n;

    // 計算結果の表示
    cout<<"y("<<x0+n*h<<") = ";
    cout<<fixed<<setprecision(30)<<newton(x0,y0,h,n)<<endl;

    return 0;
}