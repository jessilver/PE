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
    float somatorio=0,U=0;
    for(int i=0;i<N;i++){
        somatorio+=(Xi[i]);
    }
    U=somatorio/N;
    return U;
}

float media_agr(int N, float *Xi,float *Fi){
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

#endif