//����λ�϶������� �� ��ż��λ�϶���ż��
void oddInoddEvenInEven(std::vector<int>& arr, int len){
	int i = 0; 
	int j = 1;
	while (i < len &&j < len){
		//�ж�ż��λ
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

//���ӷ�����
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