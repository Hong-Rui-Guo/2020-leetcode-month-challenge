class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int length = 0, width = 0;
        int perimeter = 0;
        int cell_perimeter = 4;
        int land_num = 0;

        //determinate whether grid is empty
        if(grid.empty())
        {
            return 0 ;
        }
        else if(grid.at(0).size() == 1 && grid.size() == 1) //determinate whether grid only have one cell
        {
            if(grid[0][0] == 1)
            {
                return 4;
            }
            else
            {
                return 0 ;
            }
        }
        else if(grid.size() == 1)   //determinate whether grid width is 1
        {
            //get length of island
            length = grid.at(0).size();
            printf("island length : %d\n",length);

            //get width of island
            width = grid.size();
            printf("island width : %d\n",width);

            for(int i = 0 ; i < length ; i++)
            {
                if(grid[0][i] == 1)
                {
                    land_num++;
                }
            }

            perimeter = 2*land_num + 2;
            return perimeter;
        }
        else if(grid.at(0).size() == 1)   //determinate whether grid length is 1
        {
            //get length of island
            length = grid.at(0).size();
            printf("island length : %d\n",length);

            //get width of island
            width = grid.size();
            printf("island width : %d\n",width);

            for(int i = 0 ; i < width ; i++)
            {
                if(grid[i][0] == 1)
                {
                    land_num++;
                }
            }

            perimeter = 2*land_num + 2;
            return perimeter;
        }
        else
        {
            //get length of island
            length = grid.at(0).size();
            printf("island length : %d\n",length);

            //get width of island
            width = grid.size();
            printf("island width : %d\n",width);

            //calculate perimeter of island
            for(int i = 0 ; i < width ; i++)
            {
                for(int j = 0 ; j < length ; j++)
                {
                    if(grid[i][j] == 1)
                    {
                        //determine whether cell is in up-left corner
                        if(i == 0 && j == 0)
                        {
                            if(grid[i][j+1] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i+1][j] == 1)
                            {
                                cell_perimeter--;
                            }
                        }
                        else if (i == 0 && j == length - 1) //determine whether cell is in up-right corner
                        {
                            if(grid[i][j-1] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i+1][j] == 1)
                            {
                                cell_perimeter--;
                            }
                        }
                        else if (i == width - 1 && j == 0) //determine whether cell is in down-left corner
                        {
                            if(grid[i][j+1] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i-1][j] == 1)
                            {
                                cell_perimeter--;
                            }
                        }
                        else if (i == width - 1 && j == length - 1) //determine whether cell is in down-right corner
                        {
                            if(grid[i][j-1] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i-1][j] == 1)
                            {
                                cell_perimeter--;
                            }
                        }
                        else if (i == 0) //determine whether cell is in up side
                        {
                            if(grid[i][j-1] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i][j+1] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i+1][j] == 1)
                            {
                                cell_perimeter--;
                            }
                        }
                        else if (i == width - 1) //determine whether cell is in down side
                        {
                            if(grid[i][j-1] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i][j+1] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i-1][j] == 1)
                            {
                                cell_perimeter--;
                            }
                        }
                        else if (j == 0) //determine whether cell is in left side
                        {
                            if(grid[i-1][j] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i+1][j] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i][j+1] == 1)
                            {
                                cell_perimeter--;
                            }
                        }
                        else if (j == length - 1) //determine whether cell is in right side
                        {
                            if(grid[i-1][j] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i+1][j] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i][j-1] == 1)
                            {
                                cell_perimeter--;
                            }
                        }
                        else    //cell is inside
                        {
                            if(grid[i-1][j] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i+1][j] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i][j-1] == 1)
                            {
                                cell_perimeter--;
                            }

                            if(grid[i][j+1] == 1)
                            {
                                cell_perimeter--;
                            }
                        }
                        
                        perimeter = perimeter + cell_perimeter;
                    }

                    //init variable
                    cell_perimeter = 4;
                }
            }
            
            return perimeter;
        }
    }
};