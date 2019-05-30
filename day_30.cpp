//破译密码
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A;

	while (getline(cin, A)){
		string B;
		for (size_t i = 0; i < A.length(); i++)
		{
			if ('A' <= A[i] && A[i] <= 'E'){
				B += A[i] + 21;
			}
			else if ('F' <= A[i] && A[i] <= 'Z'){
				B += A[i] - 5;

			}
			else if (A[i] == ' '){
				B += ' ';
			}
		}
		cout << B << endl;
	}
	return 0;
}

//求因子个数
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int num;
	while (cin >> num){
		int count = 0;
		for (int i = 2; i <= sqrt(num); i++)
		{
			if (num%i == 0)
			{
				while (num%i == 0)
				{
					num = num / i;
				}
				count++;
			}
		}
		if (num != 1)
		{
			count++;
		}
		cout << count << endl;
	}
	return 0;
}