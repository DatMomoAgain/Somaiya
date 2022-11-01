#include<stdio.h>
int n = 12;
int arr[3] = {0},nums[12]={0},cnt[3]={0};

//returns index of minimum element
int mini(int arr[3])
{
    int m = arr[0];
    for(int i=0; i<2; i++)
    {
        if(m>arr[i+1])
        {
            m = arr[i+1];
        }
    }
    for(int i=0; i<3; i++)
    {
        if(m==arr[i])
        {
            m = i;
            break;
        }
    }
    return m;
}

int main(void)
{
printf("LRU IMPLEMENTATION\n");
printf("Enter The Numbers\n");

//taking input
for(int i=0;i<n;i++){
    scanf("%d",&nums[i]);
}

int c=1;
int t=0;
for(int i=0;i<n;i++){
  int flag =0;
    for(int j=0;j<t;j++){
        if(arr[j] == nums[i]){
            cnt[j] = c;
            c++;
            flag=1;
            break;
        }
    }
    if(flag!=1 && t>2)
    {
        //printf("minimum index: %d\n", mini(cnt));
        arr[mini(cnt)] = nums[i];
        cnt[mini(cnt)] = c;
        c++;
    }
    else if(flag!=1){
        arr[t] = nums[i];
        cnt[t] = c;
        c++;
        ++t;
    }
    for(int j=0; j<t; j++)
    {
        printf("%d ",arr[j]);
    }
    printf("\n");
}
return 0;
}
