class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) 
            return 1.0 / power(x, -n);
        else 
            return power(x, n);

        /*
        if(n == 0)
        {
            return 1;
        }
        else if(n > 0)
        {
            if(n == 1)
                return x;
            else
            {
                return x * myPow(x,n-1);
            }
        }
        else
        {
            n = abs(n);

            return 1/(x * myPow(x,n-1));
        }
        */
        /*
        double output = 1;

        if(x == 0)
        {
            return 0;
        }
        else if(x == 1)
        {
            return 1;
        }
        else if (x == -1)
        {
            if((n % 2) == 0)
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if(n >= 0)
            {
                for(int i = 0 ; i < n ; i++)
                {
                    output = output * x; 
                }
            }
            else
            {
                for(int i = 0 ; i < (-n) ; i++)
                {
                    output = output / x; 
                }
            }

            return output;            
        }
        */        
    }

private:
    double power(double x, int n) {
        if(n == 0)
        {
            return 1;
        }
        else if(n % 2 == 0 )
        {
            //note: slow , because it must cal myPow for 2 times, reference sol1
            return myPow(x, n/2) * myPow(x, n/2);
        }
        else
        {
            return myPow(x, n/2) * myPow(x, n/2) * x;
        }
    }    
};