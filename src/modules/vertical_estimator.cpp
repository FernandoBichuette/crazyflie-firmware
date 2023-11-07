#include "vertical_estimator.h"
#include <cmath>

// Class constructor
VerticalEstimator :: VerticalEstimator () : range (E_SDA , E_SCL )
{
    z=0;
    w=0;
}

// Initialize class
void VerticalEstimator :: init ()
{
    range.init();
}

// Predict vertical position and velocity from model
void VerticalEstimator :: predict ( float f_t)
{
    z=z+w*dt;
    if(z>0.05){
        w=w+(-g+(1/m)*f_t)*dt;
    }
}

// Correct vertical position and velocity with measurement
void VerticalEstimator :: correct ( float phi , float theta )
{
    range.read();
    if(range.d<2.0){
        float w_m=w+l1*dt*(range.d*cos(phi)*cos(theta)-z);
        float z_m=z+l2*dt*(range.d*cos(phi)*cos(theta)-z);
        z=z_m;
        w=w_m;

    } 
}