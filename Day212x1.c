#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int n, int k, int* returnSize) {
    int *res = malloc((n-k+1)*sizeof(int));
    int *dq = malloc(n*sizeof(int));
    int front=0,rear=0;
    *returnSize=0;

    for(int i=0;i<n;i++){
        if(front<rear && dq[front]<=i-k) front++;

        while(front<rear && nums[dq[rear-1]]<nums[i]) rear--;

        dq[rear++]=i;

        if(i>=k-1){
            res[(*returnSize)++]=nums[dq[front]];
        }
    }
    free(dq);
    return res;
}

int main(){
    int n,k;
    scanf("%d",&n);
    int *nums=malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&nums[i]);
    scanf("%d",&k);

    int size;
    int *ans=maxSlidingWindow(nums,n,k,&size);

    for(int i=0;i<size;i++) printf("%d ",ans[i]);

    free(nums);
    free(ans);
}