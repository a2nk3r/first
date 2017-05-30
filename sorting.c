#include<stdio.h>
void merging(int *A,int p,int q,int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[n1],R[n2];
    int i,j,k;
    for(i=0;i<n1;i++)
        L[i]=A[p+i];
    for(j=0;j<n2;j++)
        R[j]=A[q+1+j];
    i=j=0,k=p;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        A[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        A[k]=R[j];
        j++;
        k++;
    }
}
void mergesort(int *A,int p,int r){
    int q;
    if(p<r){
        q=(p+r)/2;
        mergesort(A,p,q);
        mergesort(A,q+1,r);
        merging(A,p,q,r);
    }
}
int main(){
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int A[n],i;
    for(i=0;i<n;i++)
        scanf("%d",A+i);
    mergesort(A,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",*(A+i));
    printf("\n");
    return 0;
}
