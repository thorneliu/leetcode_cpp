class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int sum = 0;
        for (auto a: A)
        {
            if (a % 2 == 0) sum += a;
        }
        
        for (auto& query : queries)
        {
            int val = query[0];
            int idx = query[1];
            
            if (A[idx] % 2 == 0)
            {
                if (val % 2 == 0)
                {
                    sum += val;
                }
                else
                {
                    sum -= A[idx];
                }
            }
            else
            {
                if (val % 2 != 0)
                {
                    sum += (A[idx] + val);
                }
            }
            
            res.push_back(sum);
            A[idx] += val;
        }
        
        return res;
    }
};
