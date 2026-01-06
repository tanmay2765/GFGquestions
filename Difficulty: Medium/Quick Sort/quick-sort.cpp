class Solution {
  public:
    void quickSort(vector<int>& arr, int l, int h) {
        // code here
        if(l<h){
            int pi=partition(arr,l,h);
            quickSort(arr,l,pi-1);
            quickSort(arr,pi+1,h);
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

    
};