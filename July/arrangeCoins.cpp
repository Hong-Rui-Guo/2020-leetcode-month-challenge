class Solution {
public:
    int arrangeCoins(int n) {
        int rows = 1;
        // int sum = 0;
        int result = n;

        while(true)
        {
            result = result - rows;

            if(result == 0)
            {
                break;
            }
            else if (result < 0)
            {
                rows--;
                break;
            }
            else
            {
                rows = rows + 1;                
            }
            

            /*
            *the following code will overflow
            */

            // sum = sum + rows;
            // if(n == sum)
            // {
            //     break;
            // }
            // else if (n < sum)
            // {
            //     rows--;
            //     break;
            // }            
            // else
            // {
            //     rows = rows + 1;
            // }
        }

        return rows;
    }
};