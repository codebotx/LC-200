class Solution
{
public:
	vector<int> findClosestElements(vector<int> &arr, int k, int x)
	{

		if (arr.size() == 1 || k == arr.size())
			return arr;

		int index = -1;
		int low = 0, high = arr.size() - 1;
		while (low < high)
		{
			int mid = (low + high) / 2;
			if (low + 1 == high)
			{
				if (arr[low] == x)
					index = low;

				else if (arr[high] == x)
					index = high;

				else if (arr[low] < x && arr[high] > x)
					index = low;

				break;
			}

			if (arr[mid] == x)
			{
				index = mid;
				break;
			}

			if (arr[mid] > x)
			{
				if (arr[mid - 1] <= x)
				{
					index = mid - 1;
					break;
				}

				high = mid;
			}
			if (arr[mid] < x)
			{
				if (arr[mid + 1] > x)
				{
					index = mid;
					break;
				}
				else if (arr[mid + 1] == x)
				{
					index = mid + 1;
					break;
				}
				low = mid;
			}
		}
		if (index == -1)
		{
			if (x < arr[0])
			{
				vector<int> res(arr.begin(), arr.begin() + k);
				return res;
			}
			else
			{
				vector<int> res(arr.end() - k, arr.end());
				return res;
			}
		}
		vector<int> res;

		low = index;
		if (low == arr.size() - 1)
		{
			high = low;
			low--;
		}
		else
			high = index + 1;

		cout << low << " " << high << endl;
		while (k)
		{
			if (low >= 0 && high < arr.size())
			{
				if (abs(arr[low] - x) <= abs(arr[high] - x))
				{
					res.push_back(arr[low]);
					low--;
				}
				else
				{
					res.push_back(arr[high]);
					high++;
				}
			}
			else if (low >= 0)
			{
				res.push_back(arr[low]);
				low--;
			}
			else if (high < arr.size())
			{
				res.push_back(arr[high]);
				high++;
			}
			k--;
		}
		sort(res.begin(), res.end());
		return res;
	}
};