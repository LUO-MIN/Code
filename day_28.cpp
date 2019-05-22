//奇数位上都是奇数 或 者偶数位上都是偶数
void oddInoddEvenInEven(std::vector<int>& arr, int len){
	int i = 0; 
	int j = 1;
	while (i < len &&j < len){
		//判断偶数位
		while (i < len && arr[i] % 2 == 0){
			i += 2;
		}
		while (j < len && arr[j] % 2 != 0){
			j += 2;
		}
		if (i < len && j < len){
			swap(arr[i], arr[j]);
		}
	}
	return;
}

//猴子分桃子
int main()
{
	int n;
	while (cin >> n){
		if (n == 0){
			break;
		}
		long long total = pow(5, n) - 4;
		long long left = pow(4, n) + n - 4;
		cout << total << " " << left << endl;
	}
	return 0;
}