class Solution
{
public:
	vector<int> dailyTemperatures(vector<int> &temperatures)
	{
		vector<int> ans(temperatures.size(), 0);
		stack<int> stack;
		for (int i = 0; i < temperatures.size(); i++)
		{
			while (!stack.empty() && temperatures[i] > temperatures[stack.top()])
			{
				int j = stack.top();
				stack.pop();
				ans[j] = i - j;
			}
			stack.push(i);
		}

		return ans;
	}
}
}
;
