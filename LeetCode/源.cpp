#include "printMatrix.h"
int main()
{
	vector<vector<int>> nums;
	for (int i = 1; i <= 5; i++)
	{
		vector<int> temp;
		for (int j = 1; j <= 2; j++)
		{
			temp.push_back(i * j);
			cout << i * j << ' ';
		}
		cout << endl;
		nums.push_back(temp);
	}
	cout << endl;
	Solution a;
	a.printMatrix(nums);
}