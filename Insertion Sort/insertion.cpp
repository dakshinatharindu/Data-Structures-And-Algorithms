#include <bits/stdc++.h>
using namespace std;

void insertion(int *A, int n){
    int key, i;
    for (int j = 1; j < n; j++)
    {
        key = A[j];
        i = j - 1;
        while (i > -1 && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i+1] = key;
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

    insertion(A, n);
    
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    
    return 0;
}