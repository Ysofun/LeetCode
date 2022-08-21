#pragma once



class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		vector<int> PreCourses(numCourses);
		int n = prerequisites.size();
		for (int i = 0; i < n; i++)
		{
			PreCourses[prerequisites[i][0]]++;
		}

		vector<int> ans;
		queue<int> que;
		vector<bool> CourseSet(numCourses, false);
		for (int i = 0; i < numCourses; i++)
		{
			if (PreCourses[i] == 0)
			{
				que.emplace(i);
				ans.emplace_back(i);
				CourseSet[i] = true;
			}
		}

		while (!que.empty())
		{	
			for (int q = 0; q < que.size(); q++)
			{
				int course = que.front();
				que.pop();

				for (int i = 0; i < n; i++)
				{
					if (prerequisites[i][1] == course)
					{
						int NextCourse = prerequisites[i][0];
						PreCourses[NextCourse]--;
						if (PreCourses[NextCourse] == 0 && !CourseSet[NextCourse])
						{
							CourseSet[NextCourse] = true;
							ans.emplace_back(NextCourse);
							que.emplace(NextCourse);
						}
					}
				}
			}
		}

		return ans.size() == numCourses ? ans : vector<int>();
	}
};