%UnitStepFunction
clc;
clear all;
close all;
figure;
t=[-10:0.1:10];
y=(t>=0);
subplot(3,2,1);
plot(t,y);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);



title('unitstepfunction UI21CS43');
%UnitImpulseFunction
t=[-10:0.1:10];
y=(t==0);
subplot(3,2,2);
plot(t,y);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('UnitImpulseFunction UI21CS43');
%RampSignal
t=[-10:0.1:10];
a=t;
subplot(3,2,3);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
axis([-10 10 -2 2]);
title('RampSignal UI21CS43');
%SignumFunction
t=[-10:0.1:10];
a=sign(t);
subplot(3,2,4);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('SignumFunction UI21CS43');
%Exponential Function
t=[-10:0.1:10];
a=exp(t);
subplot(3,2,5);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43’);
%AXIS([-10 10 -2 2]);


title('ExponenentialFunction UI21CS43');
%RectangularPulse
t=[-10:0.1:10];
a=rectpuls(t);
subplot(3,2,6);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
axis([-10 10 -2 2]);
title('RectangularPulse UI21CS43');