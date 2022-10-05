class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        int last = 0;
        vector<vector<int>> v;
        priority_queue<pair<int, int>> p1;
        for (int i = 0; i < buildings.size(); i++)
        {
            int yy = INT_MIN;
            while (p1.size() && p1.top().second < buildings[i][0])
            {
                yy = p1.top().second;
                vector<int> x;
                x.push_back(p1.top().second);
                p1.pop();
                while (p1.size() && p1.top().second <= yy)
                {
                    p1.pop();
                }
                if (p1.size() == 0)
                {
                    x.push_back(0);
                    last = 0;
                }
                else
                {
                    x.push_back(p1.top().first);
                    last = p1.top().first;
                }
                v.push_back(x);
            }
            if (last < buildings[i][2])
            {
                if (v.size() && v[v.size() - 1][0] == buildings[i][0])
                {
                    v.pop_back();
                }
                last = buildings[i][2];
                v.push_back({buildings[i][0],
                             buildings[i][2]});
            }

            p1.push({buildings[i][2],
                     buildings[i][1]});
        }
        int yy = INT_MIN;
        while (p1.size())
        {
            yy = p1.top().second;
            vector<int> x;
            x.push_back(p1.top().second);
            p1.pop();
            while (p1.size() && p1.top().second <= yy)
            {
                p1.pop();
            }
            if (p1.size() == 0)
            {
                x.push_back(0);
                last = 0;
            }
            else
            {
                x.push_back(p1.top().first);
                last = p1.top().first;
            }
            v.push_back(x);
        }
        return v;
    }
};