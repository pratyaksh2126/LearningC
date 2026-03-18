#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,k;
    scanf("%d",&n);
    int *nums=malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&nums[i]);
    scanf("%d",&k);

    for(int i=0;i<=n-k;i++){
        int max=nums[i];
        for(int j=i;j<i+k;j++){
            if(nums[j]>max) max=nums[j];
        }
        printf("%d ",max);
    }

    free(nums);
}
