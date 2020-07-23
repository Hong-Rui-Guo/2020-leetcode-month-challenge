class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        vector<int> string_record;
        vector<int> start_end_record;
        int j = 0;
        string output;

        if(s.compare("") == 0)
        {
            return "";
        }
        else
        {
            for(int i = 0 ; i < size ; i++)
            {
                if(s.compare(i,1," ") != 0)
                {
                    string_record.push_back(i);
                }
            }

            if(string_record.size() == 0)
            {
                return "";
            }
            else if(string_record.size() == 1)
            {
                output.append(s,string_record[0],1);
                return output;
            }
            else
            {
                size = string_record.size();
                start_end_record.push_back(string_record[j]);
                j++;

                for(int i = 1 ; i < size ; i++)
                {
                    if(string_record[i] - string_record[i-1] != 1)
                    {
                        start_end_record.push_back(string_record[i-1]);
                        start_end_record.push_back(string_record[i]);
                    }
                    else if(i == size-1)
                    {
                        start_end_record.push_back(string_record[i]);
                        continue;
                    }

                    if(i == size-1)
                    {
                        start_end_record.push_back(string_record[i]);
                    }

                }

                size = start_end_record.size();

                for(int i=0; i<string_record.size(); i++) cout << string_record[i] << " ";
                cout << endl;
                for(int i=0; i<start_end_record.size(); i++) cout << start_end_record[i] << " ";
                cout << endl;

                for(int i = size-1 ; i >= 0 ; i=i-2)
                {
                    printf("1\n");
                    output.append(s,start_end_record[i-1],start_end_record[i]-start_end_record[i-1]+1);
                    if(i != 1)
                    {
                        output.append(" ");
                    }
                }

                return output;  
                    
            } 
        }
    }
};