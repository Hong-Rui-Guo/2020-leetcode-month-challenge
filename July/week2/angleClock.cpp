class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hour_hand_angle, min_hand_angle;
        double min_affect_hour = 0.5*minutes;   //note : ((360/12)/60) = 0,because "/" is cal quotient
        double output;

        //step1:calculate angle of hour and min hand----------------
        //calculate angle of hour hand
        if(hour == 12)
        {
            hour_hand_angle = 0;
        }
        else
        {
            hour_hand_angle = (360/12)*hour;
        }

        hour_hand_angle = hour_hand_angle + min_affect_hour;
        
        //calculate angle of min hand
        min_hand_angle = (360/60)*minutes;

        //--------------------------------------------------------------

        //step2:cal absolute of difference angle between hour and min hand
        printf("hour hand angle : %f\n",hour_hand_angle);
        printf("min hand angle : %f\n",min_hand_angle);
        
        output = abs(hour_hand_angle - min_hand_angle);

        //--------------------------------------------------------------

        //step3:calculate smaller difference angle
        if(output > 180)
        {
            return 360 - output;
        }
        else
        {
            return output;
        }
    }
};