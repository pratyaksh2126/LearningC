#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,k;
    scanf("%d",&n);
    int *nums=malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&nums[i]);
    scanf("%d",&k);

    int *left=malloc(n*sizeof(int));
    int *right=malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        if(i%k==0) left[i]=nums[i];
        else left[i]=left[i-1]>nums[i]?left[i-1]:nums[i];
    }

    for(int i=n-1;i>=0;i--){
        if(i==n-1 || (i+1)%k==0) right[i]=nums[i];
        else right[i]=right[i+1]>nums[i]?right[i+1]:nums[i];
    }

    for(int i=0;i<=n-k;i++){
        int max=right[i]>left[i+k-1]?right[i]:left[i+k-1];
        printf("%d ",max);
    }

    free(nums);
    free(left);
    free(right);
}