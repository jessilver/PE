#ifndef OPERACOES_H
#define OPERACOES_H
#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int PriNum(char* s){
    int num;

    printf("%s",s);
    scanf("%d",&num);

    return num;
}

int PriNumf(char* s){
    float num;

    printf("%s",s);
    scanf("%f",&num);

    return num;
}

float media(int N, float *Xi){
    system("pause");
    float somatorio=0,U=0;
    for(int i=0;i<N;i++){
        somatorio+=(Xi[i]);
    }
    U=somatorio/N;
    return U;
}

float media_agr(int N, float *Xi,float *Fi){
    system("pause");
    float somatorio=0,U=0,F=0;
    for(int i=0;i<N;i++){
        somatorio+=(Xi[i]*Fi[i]);
    }
    for(int i=0;i<N;i++){
        F+=Fi[i];
    }
    U=somatorio/F;
    return U;
}

float mediana(int N, float *En){
    system("pause");
    float Md;
    int i,i2;
    if(N%2==0){
        i=N/2;
        i2=N/2+1;
        Md=(En[i-1]+En[i2-1])/2;
    }else{
        i=((N+1)/2);
        Md=En[i-1];
    }
    return Md;
}

float mediana_agr(int N,float *h,float *Fi,float *Li,int op){
    system("pause");
    int Frec_tot,Fa=0,position_li=0;
    float Md,*tot_elem;
    int i1,i2;
    for(int i=0;i<N;i++){
        Frec_tot+=(Fi[i]);
    }
    tot_elem = (float *)malloc(Frec_tot*sizeof(float));

    for(int i=0,k=0;i<Frec_tot;k++)
    {
        for(int j=0;j<Fi[i];j++)
        {
            tot_elem[i]=h[k];
            i++;
            
        }
    }
    
    for(int i=0;i<Frec_tot;i++){
    printf("%.0f\n",tot_elem[i]);
    }

    if(op==2){
        if((int)Frec_tot%2==0){
            i1=Frec_tot/2;
            i2=Frec_tot/2+1;
            Md=(h[i1-1]+h[i2-1])/2;
        }else{
            i1=((Frec_tot+1)/2);
            Md=h[i1-1];
        }
        return Md;
    }else{
        for(int i=0;i<N;i++){
            if(Fa<(Frec_tot/2)){
                Fa+=(Fi[i]);
            }else if(Fa>(Frec_tot/2)){
                Fa-=(Fi[i-1]);
                position_li=i;
                break;
            }
        }
        Md=Li[position_li]+(((Frec_tot/2)+Fa)/Fi[position_li])*h[position_li];
    } 
    return Md;
}

#endif