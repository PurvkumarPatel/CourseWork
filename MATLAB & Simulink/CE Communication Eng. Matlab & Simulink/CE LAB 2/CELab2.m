%sin using inbuilt function
clc;
clear all;
close all;
figure;
t=[-10:0.1:10];
a=sin(t);
subplot(5,2,1);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('sinwave UI21CS43');
y=fftshift(abs(fft(a)));
subplot(5,2,2);
plot(y);
xlabel('Time UI21CS43');
ylabel('amplitude UI21CS43');
%AXIS([-10 10 -2 2]);
title('sinwave UI21CS43');
%cos using inbuilt function
t=[-10:0.1:10];
a=cos(t);
subplot(5,2,3);
plot(t,a);



xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('cos UI21CS43');
y=fftshift(abs(fft(a)));
subplot(5,2,4);
plot(y);
xlabel('Time UI21CS43');
ylabel('amplitude UI21CS43');
%AXIS([-10 10 -2 2]);
title('COS UI21CS43');
%ExponentialFunction
t=[-10:0.1:10];
a=exp(t);
subplot(5,2,5);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('ExponenentialFunction UI21CS43');
y=fftshift(abs(fft(a)));
subplot(5,2,6);
plot(y);
xlabel('Time UI21CS43');
ylabel('amplitude UI21CS43');
%AXIS([-10 10 -2 2]);
title('EXPONENTIAL UI21CS43');
%RectangularPulse
t=[-10:0.1:10];
a=rectpuls(t);
subplot(5,2,7);



plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
axis([-10 10 -2 2]);
title('RectangularPulse UI21CS43');
y=fftshift(abs(fft(a)));
subplot(5,2,8);
plot(y);
xlabel('Time UI21CS43');
ylabel('amplitude UI21CS43');
%AXIS([-10 10 -2 2]);
title('EXPONENTIAL UI21CS43');
%UnitImpulseFunction
t=[-10:0.1:10];
y=(t==0);
subplot(5,2,9);
plot(t,y);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('UnitImpulseFunction UI21CS43');
y=fftshift(abs(fft(a)));
subplot(5,2,10);
plot(y);
xlabel('Time UI21CS43');
ylabel('amplitude UI21CS43');
%AXIS([-10 10 -2 2]);
title('EXPONENTIAL_UI21CS43');