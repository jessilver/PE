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
    int i;
    if(N%2==0){
        i=N/2;
        Md=(En[i-1]+En[i])/2;
    }else{
        i=((N+1)/2);
        Md=En[i-1];
    }
    return Md;
}
/**************************************** O PROBLEMA É AQUI* *****************************************/
float mediana_agr(int Num_ele,float *H,float *Fi,float *Li,int op){
    system("pause");
    float Md=0;
    if(op==1){
        float Fa=0,li=0,fmd=0,h=0,n=0;
        for (int i = 0; i < Num_ele; i++)
        {
            n+=Fi[i];
        }
        n=(int)n/2;
        for (int i = 0; i < Num_ele; i++)
        {
            if(Fa<n){
                Fa+=Fi[i];
                continue;
            }
            if(Fa>n){
                Fa-=Fi[i-1];
                li=Li[i-1];
                fmd=Fi[i-1];
                h=H[i];
                break;
            }
        }
        Md=li+((n-Fa)/fmd*h);
    }else{
        float n=0,*elementos;
        for (int i = 0; i < Num_ele; i++){
            n+=Fi[i];
        }
        elementos = (float *)malloc(n*sizeof(float));
        for (int i = 0;i< n; ){
            for(int j = 0;j<Num_ele;j++){
                for(int k = 0;k<Fi[j];k++){
                    elementos[i]=H[j];
                    i++;
                }
            }
        }
        if((int)n%2!=0){
            int i1;
            i1=((int)n+1)/2;
            Md=elementos[i1];
        }else{
            int i;
            i=(int)n/2;
            Md=(elementos[i-1]+elementos[i])/2; 
        } 
    }
    printf("Mediana = %.2f",Md);
    return 0;
}
#endif