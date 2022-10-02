#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int min(int a,int b){
    if(a>b){
        return b;
    }
    else return a;
}
void merge(vector<int> &arr,int i,int mid,int j){
    vector<int> temp1;
    int i1=i;
    int j2=mid+1;
    while(i1<=mid&&j2<=j){
          if(arr[i1]>arr[j2]){
            temp1.push_back(arr[j2]);
            j2++;
          }
          if(arr[i1]<arr[j2]){
            temp1.push_back(arr[i1]);
            i1++;
          }
          if(arr[i1]==arr[j2]){
              temp1.push_back(arr[i1]);
              i1++;
          }
    }
    if(i1<=mid){
        for(int k=i1;k<=mid;k++){
             temp1.push_back(arr[k]);
        }
    }
    if(j2<=j){
        for(int k=j2;k<=j;k++){
            temp1.push_back(arr[k]);
        }
    }
    int val=0;
    for(int k=i;k<=j;k++){
        arr[k]=temp1[val];
        val++;
    }
    return ;
}
void mergesort(vector<int> &arr,int i,int j){
    if(i==j){
      return;
    }
    int mid=(i+j)/2;
    mergesort(arr,i,mid);
    mergesort(arr,mid+1,j);
    merge(arr,i,mid,j);
    return ;

}
int main(){
    vector<int> arr={2,3,1,6,2,3};
    mergesort(arr,0,arr.size()-1);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}
