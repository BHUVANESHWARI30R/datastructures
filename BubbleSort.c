// Bubble Sort

#include<stdio.h>
int main(){
    int a[20],n,temp,i,j;
    printf("enter the no.of elements : ");
    scanf("%d",&n);
    for( i=0;i<n;i++){
        printf("\n enter the data : ");
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\nsorted array \n");
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}

/*

		OUTPUT
		
enter the no.of elements : 7

 enter the data : 4

 enter the data : 6

 enter the data : 1

 enter the data : 9

 enter the data : 2

 enter the data : 5

 enter the data : 9
4       6       1       9       2       5       9
sorted array
1       2       4       5       6       9       9

*/


