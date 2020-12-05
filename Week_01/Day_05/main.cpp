class Solution 
{
    void Marking(vector<int>& data)
    {
        if (data.size() == 1)
        {
            return;
        }
        
        
        if(data[0] == 1)
        {
            data[1] = 2;
        }

        int last = data.size() -1;

        for (int i =1; i< last ; i++)
        {
            if(data[i] ==1 )
            {
                data[i - 1] = 2;
                data[i + 1] = 2;
            }
        }
        
        if (data[last] ==1)
        {
            data[last -1] = 2;
        }
    }
    
    vector<int> Divide(vector<int> my_arr )
    {   
        vector<int> res;
        
        int count = 0;
        
        while(my_arr.size()!= 0)
        {
            if(my_arr.back() == 0)
            {
                count ++;
            }
            else
            {
                if(count != 0)
                {
                    res.push_back(count);
                    count = 0;
                }
            }
            
            my_arr.pop_back();
                
        }
        
        if(count != 0)
        {
            res.push_back(count);
        }
        
        return res;
    }
    
    int my_sum(vector<int> cur)
    {
        
        int res =0;
        for(int val : cur)
        {

            res+= (val+1)/2;
        }
        
        return res;
    }
   
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) 
    {
        
        Marking(flowerbed);
        vector< int > cur = Divide(flowerbed);
        
        if(n <= my_sum(cur))
        {
            return true;
        }

        return false;
    }
};