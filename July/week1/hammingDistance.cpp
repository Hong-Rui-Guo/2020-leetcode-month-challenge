class Solution {
public:
    int hammingDistance(int x, int y) {
        int x_binary[32],y_binary[32];
        int x_temp,y_yemp;
        int bit_size = 0;
        int output = 0;

        x_temp = x;
        y_yemp = y;

        //cal how many bits max(x,y) has  
        while( !(x_temp == 0 && y_yemp == 0) )
        {
            x_temp = x_temp >> 1;
            y_yemp = y_yemp >> 1;
            bit_size++;
        }

        //turn x,y from ten to binary
        for(int i = 0 ; i < bit_size ; i++)
        {
            x_binary[(bit_size - 1) - i] = (x >> i) % 2;
            y_binary[(bit_size - 1) - i] = (y >> i) % 2;
        }

        //compare x,y in binary
        for(int i = 0 ; i < bit_size ; i++)
        {
            if(x_binary[i] != y_binary[i])
            {
                output++;
            }
        }

        return output; 
    }
};