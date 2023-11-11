#ifndef parameters_h
#define parameters_h

#include <cmath>

// Physical constants
const float pi = 3.1416;
const float g = 9.81;       // m/s^2
const float a2= 1.7439e-07;
const float a1=3.9258e-11;
const float kl=1.7571e-08;
const float kd=1.4064e-10;
const float dt = 2e-3;
const float wc=1.0; //rad
const float alpha=(wc*dt)/(1+wc*dt);
const float dt_range=5e-2;


const float Os=0.005;
const float ts_theta=0.3;
const float ts_psi=0.6;

const float zeta = abs(log(Os))/sqrt(pi*pi+log(Os)*log(Os));
const float wn_theta = 4.0/(zeta*ts_theta);

const float wn_psi = 4.0/(zeta*ts_psi);

const float kp_theta=pow(wn_theta,2);
const float kd_theta=2.0*zeta*wn_theta;

const float kp_phi=kp_theta;
const float kd_phi=kd_theta;

const float kp_psi=pow(wn_psi,2);;
const float kd_psi=2.0*zeta*wn_psi;


const float wc_ver = 10.0;
const float amortecimento=sqrt(2)/2;
const float l1=wc_ver*wc_ver;
const float l2=2.0*amortecimento*wc_ver;

const float kp_vertical = 5.8567;
const float kd_vertical = 3.4225;


// Quadcopter dimensions
const float m = 30.0e-3;    // kg
const float I_xx = 16.0e-6; // kg.m^2
const float I_yy = 16.0e-6; // kg.m^2
const float I_zz = 29.0e-6; // kg.m^2
const float l = 33.0e-3;    // m

#endif