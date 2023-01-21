class Solution
{
public:
	int findMin(vector<int> &nums)
	{
		int rotate = 0;
		if (nums[0] > nums[nums.size() - 1])
		{
			int low = 0;
			int high = nums.size() - 1;
			while (low < high)
			{
				int mid = (low + high) / 2;

				if (low + 1 == high)
					if (nums[low] > nums[high])
						return nums[high];

				if (nums[mid] > nums[low])
					low = mid;
				if (nums[mid] < nums[low])
					high = mid;
			}
			cout << rotate << "rotate" << endl;
			return nums[rotate];
		}
		else
			return nums[0];
	}
};