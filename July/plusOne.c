/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *output;
    int temp;
    int extra_check = 1;

    printf("digitsSize : %d\n",digitsSize);
    
    for(int i = digitsSize - 1 ; i >= 0 ; i--)
    {
        if(digits[i] != 9)
        {
            extra_check = 0;
            break;
        }
    }

    // for(int i = digitsSize - 1 ; i >= 0 ; i--)
    // {
    //     temp = digits[i] + 1;

    //     if(temp < 10)
    //     {
    //         if(i == 0)
    //         {
                
    //         }
    //         else
    //         {
                
    //         }
            
    //         break;
    //     }
    //     else
    //     {
    //         digits[i] = 0;
    //     }
    // }

    if(extra_check == 1)
    {
        *returnSize = digitsSize + 1;
        printf("returnSize : %d\n",*returnSize);
        
        // output = (int *) malloc(sizeof( 4*(*returnSize) ) );
        output = (int *) malloc( 4*(*returnSize) );

        // output[0] = 1;
        *output = 1;

        for(int i = 1 ; i < *returnSize ; i++)
        {
            //output[i] = 0;
            *(output + i) = 0;

        }
    }
    else
    {
        *returnSize = digitsSize;
        printf("returnSize : %d\n",*returnSize);

        // output = (int *) malloc(sizeof( 4*(*returnSize) ) );
        output = (int *) malloc(4*(*returnSize) );

        for(int i = digitsSize - 1 ; i >= 0 ; i--)
        {
//            output[i] = digits[i] + 1;
            *(output + i) = digits[i] + 1;

            if(*(output + i) < 10)
            {
                for(int j = i - 1; j >= 0 ; j--)
                {
                    // output[j] = digits[j];
                    *(output + j) = digits[j];
                }
                break;
            }
            else
            {
                // output[i] = 0;
                *(output + i) = 0;
            }
        }
        
    }
    

    return output;

}