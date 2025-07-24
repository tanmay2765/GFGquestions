class Solution {
  public:
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l<r){
            int m=(l+r)/2;
            mergeSort(arr,l,m);
            mergeSort(arr,m+1,r);
            merge(arr,l,m,r);
        }
    }
    void merge(vector<int>& arr,int l,int m,int r){
        vector<int> temp(r-l+1);
        int i=l,j=m+1,k=0;
        while(i<=m && j<=r){
            if(arr[i]<=arr[j]) temp[k++]=arr[i++];
            else temp[k++]=arr[j++];
        }
        while(i<=m) temp[k++]=arr[i++];
        while(j<=r) temp[k++]=arr[j++];
        for(int i=l;i<=r;i++) arr[i]=temp[i-l];
    }
};