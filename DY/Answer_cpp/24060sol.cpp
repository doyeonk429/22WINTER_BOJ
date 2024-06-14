#include <iostream>
using namespace std;

int* A;
int* tmp;
int n, cnt = 0, k = 0, result = -1;

void merge(int A[], int p, int q, int r)
{
    int i = p, j = q + 1, t = 1;

    while (i <= q && j <= r)
    {
        if (A[i] <= A[j])
            tmp[t++] = A[i++];
        else
            tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];

    while (j <= r)
        tmp[t++] = A[j++];

    i = p, t = 1;
    while (i <= r)
    {
        A[i++] = tmp[t++];
        cnt++;
        if (cnt == k)
        {
            result = A[i - 1];
            break;
        }
    }
}

void merge_sort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

int main() {
    cin >> n >> k;
    A = new int[n + 1];
    tmp = new int[n + 1];
    for (int i = 0; i < n; i++)
        cin >> A[i];

    merge_sort(A, 0, n - 1);
    cout << result;

    return 0;
}
