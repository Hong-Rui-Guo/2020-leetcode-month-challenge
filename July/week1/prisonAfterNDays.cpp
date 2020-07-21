class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> temp(8,0);

        //not think it -> this question have regular, period : 14 days 
        //the reason that add 14 is day N which can divide by 14 is not equal to day 0(ex:day 14 = day 28 = day 42 != day 0)
        if (N>14) N = N % 14 + 14;

        //total N days
        for(int i = 0 ; i < N ; i++)
        {
            //calculate next prison cells, store it in temp vector
            for(int j = 1 ; j < cells.size() - 1; j++)
            {
                if(cells.at(j-1) == cells.at(j+1))
                {
                    temp.at(j) = 1;
                }
                else
                {
                    temp.at(j) = 0;
                }
            }

            //update the prison cells
            //cells = temp;
            cells.assign(temp.begin(),temp.end());
        }

        return cells;
    }
};