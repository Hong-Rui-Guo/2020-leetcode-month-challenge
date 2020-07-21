class Solution {
public:
    int nthUglyNumber(int n) {
        int seq1[3000],seq2[3000],seq3[3000];
        int index1 = 0;
        int index2 = 0;
        int index3 = 0;
        int min_value,min_index,pre_min;
        int count = 2;
        int output;

        if(n <= 5)
        {
            if(n == 1)
            {
                return 1;
            }
            else if(n == 2)
            {
                return 2;
            }
            else if(n == 3)
            {
                return 3;
            }
            else if(n == 4)
            {
                return 4;
            }
            else
            {
                return 5;
            }
        }
        else
        {
            seq1[0] = 2;
            seq2[0] = 3;
            seq3[0] = 5;
            pre_min = 0;

            while(true)
            {
                //compare value,find min---------------------
                min_value = seq1[index1];
                min_index = 1;

                if(min_value > seq2[index2])
                {
                    min_value = seq2[index2];
                    min_index = 2;
                }

                if(min_value > seq3[index3])
                {
                    min_value = seq3[index3];
                    min_index = 3;
                }
                //-------------------------------------------

                //judge whether min value is same as previous min 
                if(pre_min == min_value)
                {

                    if(min_index == 1)
                    {
                        index1++;
                    }
                    else if (min_index == 2)
                    {
                        index2++;
                    }
                    else
                    {
                        index3++;
                    }
                }
                else
                {
                    if(count == n)
                    {
                        return min_value; 
                    }

                    if(min_index == 1)
                    {
                        index1++;
                    }
                    else if (min_index == 2)
                    {
                        index2++;
                    }
                    else
                    {
                        index3++;
                    }

                    pre_min = min_value;

                    if(min_value < 429496729)
                    {
                        seq1[count - 1] = 2 * min_value;
                        seq2[count - 1] = 3 * min_value;
                        seq3[count - 1] = 5 * min_value;
                    }
                    else if(min_value < 715827882)
                    {
                        seq1[count - 1] = 2 * min_value;
                        seq2[count - 1] = 3 * min_value;
                    }                    
                    else if(min_value < 1073741823)
                    {
                        seq1[count - 1] = 2 * min_value;
                    }                    

                    count++;                    

                }                
            }
        }   
    }
};