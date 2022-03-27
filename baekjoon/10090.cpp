#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int arr[1000001];
int tmp[1000001];
int T, N;
long long cnt;

void merge(int left, int mid, int right) {
	int low = left;
	int high = mid + 1;
	int k = left;

	while (low <= mid && high <= right) {
		if (arr[low] <= arr[high]) {
			tmp[k] = arr[low++];
		}
		else {
			cnt += (mid - low + 1);
			tmp[k] = arr[high++];
		}
		k++;
	}

	if (low > mid) {
		for (int i = high; i <= right; i++) {
			tmp[k] = arr[i];
			k++;
		}
	}
	else {
		for (int i = low; i <= mid; i++) {
			tmp[k] = arr[i];
			k++;
		}
	}

	for (int i = left; i <= right; i++) {
		arr[i] = tmp[i];
	}
}

void mergeSort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    mergeSort(0, N - 1);
    cout << cnt << "\n";
}