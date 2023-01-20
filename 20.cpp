class Solution
{
public:
	bool isValidSudoku(vector<vector<char>> &board)
	{

		for (int i = 0; i < board.size(); i++)
		{
			unordered_map<char, int> map;
			for (int j = 0; j < board[0].size(); j++)
				map[board[i][j]]++;

			for (auto it = map.begin(); it != map.end(); it++)
			{
				if (isdigit(it->first) && (it->second == 1))
					continue;

				else if (isdigit(it->first) && (it->second != 1))
					return false;
			}
			map.clear();
		}

		for (int i = 0; i < board[0].size(); i++)
		{
			unordered_map<char, int> map;
			for (int j = 0; j < board[0].size(); j++)
				map[board[j][i]]++;
			for (auto it = map.begin(); it != map.end(); it++)
			{
				if (isdigit(it->first) && (it->second == 1))
					continue;
				else if (isdigit(it->first) && (it->second != 1))
					return false;
			}
			map.clear();
		}
		unordered_map<char, int> map;

		for (int start = 0; start < 9; start += 3)
		{
			for (int i = start; i < start + 3; i++)
				for (int j = 0; j < 3; j++)
					map[board[i][j]]++;

			for (auto it = map.begin(); it != map.end(); it++)
			{
				if (isdigit(it->first) && (it->second == 1))
					continue;
				else if (isdigit(it->first) && (it->second != 1))
					return false;
			}
			map.clear();
		}
		for (int start = 0; start < 9; start += 3)
		{
			for (int i = start; i < start + 3; i++)
				for (int j = 3; j < 6; j++)
					map[board[i][j]]++;

			for (auto it = map.begin(); it != map.end(); it++)
			{
				if (isdigit(it->first) && (it->second == 1))
					continue;
				else if (isdigit(it->first) && (it->second != 1))
					return false;
			}
			map.clear();
		}
		for (int start = 0; start < 9; start += 3)
		{
			for (int i = start; i < start + 3; i++)
				for (int j = 6; j < 9; j++)
					map[board[i][j]]++;

			for (auto it = map.begin(); it != map.end(); it++)
			{
				if (isdigit(it->first) && (it->second == 1))
					continue;
				else if (isdigit(it->first) && (it->second != 1))
					return false;
			}
			map.clear();
		}

		return true;
	}
};