#include <iostream>
#include <vector>
#include <thread>

using namespace std;

void count(int *arr, int n, int *putarr, int index){
	int val = 0;
	for(int i = 0;i < n;i++){
		val = arr[i] + val;
	}
	putarr[index] = val;
}

int main() {
	int N = 0;
	int M = 0;
	int **arrs = new int*[M];
	int *arr = new int[N];
	cout << "N: ";
	cin >> N;
	cout << "M: ";
	cin >> M;
	if(M == 0){
		cout << "M can't equal 0";
		return 1;
	}else if(M > N){
		cout << "M cannot be bigger then N";
		return 2;
	}
	for(int i = 0;i < N;i++){
		arr[i] = rand() % 10;
		cout << arr[i] << " ";
	}	
	cout << "\n";
	int ind = 0;
	for(int i = 0;i < M;i++){
		if(i == M - 1){
			arrs[i] = new int[N / M + N % M];
			for(int j = 0;j < N / M + N % M;j++){
				arrs[i][j] = arr[ind];
				ind++;
				cout << arrs[i][j] << " "; 
			}
			cout << "\n";
			break;
		}
		arrs[i] = new int[N / M];
		for(int j = 0;j < N / M;j++){
			arrs[i][j] = arr[ind];
			ind++;
			cout << arrs[i][j] << " "; 
		}
		cout << "\n";
	}
	
	int* sumarr = new int[M];
	thread* thds = new thread[M];
	for(int i = 0;i < M;i++){
		if(i == M - 1){
			thds[i] = thread(count, arrs[i], N / M + N % M, sumarr, i);
			break;
		} 
		thds[i] = thread(count, arrs[i], N / M, sumarr, i);
	}
	
	int sum = 0;
	for(int i = 0;i < M;i++){
		if(thds[i].joinable()){
			thds[i].join();
			cout << sumarr[i] << " ";
			sum = sum + sumarr[i];
		}
	}
	
	cout << "\n" << sum;
	
	return 0;
}