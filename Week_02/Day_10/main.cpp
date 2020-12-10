class Solution {
public:
    bool validMountainArray(vector<int>& arr) 
    {
        if(arr.size() <= 2)
        {
            return false;
        }
        
        int prev = -1;
        bool going_up = false;
        bool going_down = false;
        
        for (int val : arr)
        {
            if (prev != -1)
            {
                if(val > prev)
                {
                    if(going_down)
                    {
                        return false;
                    }
                    else
                    {
                        going_up = true;
                    }
                    
                }
                else if(val == prev)
                {
                    return false;
                }
                else if(val < prev)
                {
                    if(!going_up)
                    {
                        return false;
                    }
                    else
                    {
                        going_down = true;
                    }
                }
            }
            
            prev = val;

        }
        
        return going_down;
    }
};
