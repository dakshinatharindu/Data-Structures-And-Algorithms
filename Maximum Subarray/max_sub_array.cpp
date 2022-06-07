#include <bits/stdc++.h>
using namespace std;

vector<int> find_max_crossing_subarray(int *A, int low, int mid, int high){
    int max_left, max_right;
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--)
    {
        sum += A[i];
        if (sum > left_sum){
            left_sum = sum;
            max_left = i;
        }
    }
    
    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid+1; i <= high; i++)
    {
        sum += A[i];
        if (sum > right_sum){
            right_sum = sum;
            max_right = i;
        }
    }
    return {max_left, max_right, left_sum+right_sum};
}

vector<int> find_maximum_subarray(int *A, int low, int high){
    if (high == low) return {low, high, A[low]};
    else{
        int mid = (low + high)/2;
        vector<int> left = find_maximum_subarray(A, low, mid);
        vector<int> right = find_maximum_subarray(A, mid+1, high);
        vector<int> cross = find_max_crossing_subarray(A, low, mid, high);

        if (left[2] > right[2] && left[2] > cross[2]) return left;
        else if (right[2] > left[2] && right[2] > cross[2]) return right;
        else return cross;
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<int> max_subarray = find_maximum_subarray(A, 0, n-1);
    cout << "Maximum Subarray :";
    for (int i = max_subarray[0]; i <= max_subarray[1]; i++)
    {
        cout << " " << A[i] ;
    }
    cout << endl << "Subarray Sum = " << max_subarray[2] << endl;
    return 0;
}