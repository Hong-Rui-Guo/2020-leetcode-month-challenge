class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int input_arr[32];
        int output_arr[32];
        uint32_t output = 0;

        //convert input from decimal to binary
        for(int i = 0 ; i < 32 ; i++)
        {
            input_arr[31 - i] = (n >> i) % 2;
        }

        //reverse binary array
        for(int i = 0 ; i < 32 ; i++)
        {
            output_arr[31 - i] = input_arr[i];
        }

        //convert output from binary to decimal
        for(int i = 0 ; i < 32 ; i++)
        {
            output = output + output_arr[31 - i] * pow(2,i);
        }

        return output;    
    }
};