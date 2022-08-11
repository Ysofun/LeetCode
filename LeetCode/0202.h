#pragma once



class Solution {
public:

	int CalculateSum(int n)
	{
		int sum = 0;
		while (n != 0)
		{
			sum += pow(n % 10, 2);
			n /= 10;
		}
		return sum;
	}

	bool isHappy(int n) {
		
		int slow = n, fast = n;

		do 
		{
			slow = CalculateSum(slow);
			fast = CalculateSum(fast);
			fast = CalculateSum(fast);
		} while (slow != fast);
		
		return fast == 1;
	}
};