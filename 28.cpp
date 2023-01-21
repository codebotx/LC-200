class Solution
{
public:
	vector<int> searchRange(vector<int> &nums, int target)
	{
		vector<int> ans(2, -1);
		if ((nums.size() < 1))
			return ans;

		if (nums.size() == 1)
		{
			if (nums[0] == target)
			{
				ans[0] = 0;
				ans[1] = 0;
			}
			return ans;
		}

		int low = 0;
		int high = nums.size() - 1;
		while (low < high)
		{
			if (low + 1 == high)
			{
				if (nums[low] == target && nums[high] == target)
				{
					ans[0] = low;
					ans[1] = high;
				}
				else if (nums[low] == target)
				{
					ans[0] = low;
					ans[1] = low;
				}
				else if (nums[high] == target)
				{
					ans[0] = high;
					ans[1] = high;
				}
				return ans;
			}

			int mid = (low + high) / 2;

			if (nums[mid] == target)
			{
				ans[0] = mid;
				ans[1] = mid;
				if (nums[mid - 1] == target)
				{
					int k = mid - 1;
					while (k >= 0 && nums[k] == target)
					{
						ans[0] = k;
						k--;
					}
				}
				if (nums[mid + 1] == target)
				{
					int k = mid + 1;
					while (k < nums.size() && nums[k] == target)
					{
						ans[1] = k;
						k++;
					}
				}
				return ans;
			}

			if (nums[mid] > target)
				high = mid;
			if (nums[mid] < target)
				low = mid;
		}

		return ans;
	}
};