class Solution
{
public:
	int binarysearch(int low, int high, int target, vector<int> &nums)
	{

		if (nums.size() == 1)
			if (target == nums[0])
				return 0;
			else
				return -1;

		if (low == high)
			if (target == nums[low])
				return low;
			else
				return -1;

		cout << low << " " << high << " "
				 << " Low High" << endl;
		while (low < high)
		{
			int mid = (low + high) / 2;

			if ((low + 1 == high) && nums[high] != target && nums[low] != target)
				return -1;

			if (nums[mid] == target)
				return mid;
			else if (nums[mid + 1] == target)
				return mid + 1;
			else if (nums[mid] > target)
				high = mid;
			else if (nums[mid] < target)
				low = mid;
		}
		return 0;
	}
	int search(vector<int> &nums, int target)
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
					{
						rotate = high;
						break;
					}

				if (nums[mid] > nums[low])
					low = mid;
				if (nums[mid] < nums[low])
					high = mid;
			}
			cout << rotate << "rotate" << endl;
			if (binarysearch(0, rotate - 1, target, nums) == -1)
				return (binarysearch(rotate, nums.size() - 1, target, nums));
			else
				return binarysearch(0, rotate - 1, target, nums);
		}
		else
			return (binarysearch(0, nums.size() - 1, target, nums));
	}
};