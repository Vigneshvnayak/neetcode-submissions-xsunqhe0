class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
       int n = arr.size();
       int great = arr[n-1];
       int temp = 0;
       for (int i=n-2; i >= 0; i--) {
        temp = arr[i];
        arr[i] = great;
        great = max(great, temp);
       }
       arr[n-1] = -1;
       return arr;
    }
};