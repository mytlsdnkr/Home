#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define cutpoint1 2
#define cutpoint2 6
#define K 10
#define numberOfCity 9
#define numberOfchild 2
#define tNUM 100

void createChild(int p1[],int p2[],int c1[],int c2[]){
    srand(time(NULL));
    int i=0;
    int ctemp1[cutpoint2-cutpoint1+1];
    int ctemp2[cutpoint2-cutpoint1+1];
    int flag=0;

    int randtemp1[cutpoint2-cutpoint1+1];
    int randtemp2[cutpoint2-cutpoint1+1];

    for(i=cutpoint1+1;i<cutpoint2+1;i++){
        c1[i]=p2[i];
        c2[i]=p1[i];
    }
    for(i=0;i<cutpoint1;i++){
       ctemp1[i]=p1[i];
       ctemp2[i]=p2[i];

        
    }

    for(i=cutpoint2+1;i<numberOfCity;i++){
        ctemp1[i]=p1[i];
        ctemp2[i]=p2[i];
    }

    for(i=0;i<(cutpoint2-cutpoint1+1);i++){


        while(1){

            randtemp1[i]= rand()%(cutpoint2-cutpoint1+1);
            flag=0;

        }
    }


    
    
}
void childmincost(int set[][numberOfCity]){
    int i,j;
    int sum[numberOfchild];
    
    for(i=0;i<numberOfchild;i++){
        for(j=0;j<numberOfCity-1;j++){
            if(set[i][j+1]<set[i][j]){
                sum[i]+=set[i][j]-set[i][j+1];
            }else{

                sum[i]+=set[i][j+1]-set[i][j];
            }
        }
    }

    for(i=0;i<numberOfchild;i++){
        printf("sum[%d]=%d\n",i,sum[i]);

    }

}
int main(){
    srand(time(NULL));
    int flag;
    int c1[numberOfCity];
    int c2[numberOfCity];
    int c1index,c2index;
    int p1[numberOfCity];
    int p2[numberOfCity];

    int set[K][numberOfCity];
    int sum[K];

    int i,j,k,s=0;

    for(i=0;i<numberOfCity;i++){
        c1[i]=0;
        c2[i]=0;
        p1[i]=0;
        p2[i]=0;
    }

    
    for(i=0;i<K;i++){
        sum[i]=0;
    }

    for(i=0;i<K;i++){
        for(j=0;j<numberOfCity;j++){
            while(1){
                set[i][j]=(rand()%numberOfCity)+1;
                flag=0;

                for(k=0;k<j;k++){
                    if(set[i][j]==set[i][k]){
                        flag=1;
                        break;
                    }
                }
                if(!flag){
                    break;
                }
            }
        }
    }

    for(i=0;i<K;i++){
        for(j=0;j<numberOfCity-1;j++){
            if(set[i][j+1]<set[i][j]){
                sum[i]+=set[i][j]-set[i][j+1];
            }else{

                sum[i]+=set[i][j+1]-set[i][j];
            }
        }
    }

    for(i=0;i<K;i++){
        printf("P[%d]={ ",i);
        for(j=0;j<numberOfCity;j++){
            printf(" %d ",set[i][j]);
           
        }
        printf("}\n");
    }

    int array[K];

    for(i=0;i<K;i++){
        array[i]=i;
    }
    int temp,temp1=0;;

    for(i=0;i<K;i++){
        for(j=i;j<K;j++){
            if(sum[i]>sum[j]){
                temp=sum[i];
                sum[i]=sum[j];
                sum[j]=temp;
                temp1=array[i];
                array[i]=array[j];
                array[j]=temp1;
            }
        }
    }


    printf("Choose %d and %d genetic\n",array[0],array[1]);


    for(i=0;i<numberOfCity;i++){
        p1[i]=set[array[0]][i];
        p2[i]=set[array[1]][i];
    }

    printf("\n");


    while(s<tNUM){




    }



    

   

return 0;
}