class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        vector<int> temp;
        vector<int> triplet_arr(3,0);
        int temp_value;
        int sum_2;  //a+b+c=0, fix a, b+c=-a, sum_2 = -a
        int third_num_size;
        int triplet_num = 0;
        bool duplicate_check = false;

        temp.assign(nums.begin(),nums.end());

        //first fixed number(i is index of first num)
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum_2 = -nums.at(i);
            //printf("1\n");
            //swap temp[0] and temp[i]
            temp_value = temp.at(i);
            temp.at(i) = temp.at(0);
            temp.at(0) = temp_value;

            //second fixed number(j is index of second num)
            for(int j = 1 ; j < nums.size() - 1 ; j++)
            {
                third_num_size = nums.size() - (j + 1);
                //printf("2\n");

                //j+k is index of third num
                for(int k = 1 ; k <= third_num_size ; k++)
                {
                    //printf("3\n");

                    if(temp.at(j) + temp.at(j+k) == sum_2)
                    {
                        triplet_arr.at(0) = temp.at(0);
                        triplet_arr.at(1) = temp.at(j);
                        triplet_arr.at(2) = temp.at(j+k);
                        

                        //sort triplet_arr by size
                        sort(triplet_arr.begin(), triplet_arr.end(), less<int>());
                        /*
                        for(int m = 0 ; m < 3 - 1 ; m++)
                        {
                            //printf("4\n");

                            for(int n = 1 ; n <= 3 - (m+1) ; n++)
                            {
                                //printf("5\n");

                                if(triplet_arr.at(m) > triplet_arr.at(m+n))
                                {
                                    temp_value = triplet_arr.at(m);
                                    triplet_arr.at(m) = triplet_arr.at(m+n);
                                    triplet_arr.at(m+n) = temp_value;
                                }
                            }
                        }
                        */

                        //printf("6\n");

                        //check whether new triplet is duplicate in output array
                        for(int m = 0 ; m < triplet_num ; m++)
                        {
                            //printf("7\n");

                            if(output.at(m) == triplet_arr)
                            {
                                duplicate_check = true;
                                break;
                            }
                        }

                        //printf("8\n");

                        if(duplicate_check == false)
                        {
                            //error : can't write output.at(triplet_num) = triplet_arr;
                            output.push_back(triplet_arr);
                            //output.at(triplet_num).assign(triplet_arr.begin(),triplet_arr.end());
                            triplet_num++;
                        }

                        duplicate_check = false;

                        //printf("9\n");
                    }
                }
            }

            //swap temp vector to original order
            temp_value = temp.at(i);
            temp.at(i) = temp.at(0);
            temp.at(0) = temp_value;

        }

        return output;
    }
};