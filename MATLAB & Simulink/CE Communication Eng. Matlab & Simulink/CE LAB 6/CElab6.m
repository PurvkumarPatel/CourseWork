clc;
clear ALL;
close all;
%LAB 6 UI21CS43 FM SIGNAL
% MODULATING SIGNAL
figure;
fs=10000;
t = -1:1/fs:1;
pi=3.14;
fm=10;
fc=100;
Am=1;
Ac=1;
B=8;%modulation index
freqdev=B*fm;
m=Am*cos(2*pi*fm*t);
subplot(5,1,1);
plot(t,m);
xlabel('time 43');
ylabel('amp 43');
title('MODULATING SIGNAL UI21CS43');
% CARRIER SIGNAL
c=Ac*cos(2*pi*fc*t);
subplot(5,1,2);
plot(t,c);
xlabel('time 43');
ylabel('amp 43');
title('CARRIER SIGNAL UI21CS43');
% FM SIGNAL
s=Ac*cos(2*pi*fc*t+(B*sin(2*pi*fm*t)));
subplot(5,1,3);
plot(t,s);
xlabel('time 43');
ylabel('amp 43');
title('FM SIGNAL UI21CS43');
%IN-BUILT FM SIGNAL
y=modulate(m,fc,fs,"fm");
subplot(5,1,4);
plot(t,y);
xlabel('time 43');
ylabel('amp 43');
title('FM SIGNAL using IN-BUILT UI21CS43');
%IN-BUILT FM DEMODULATION SIGNAL
z=demod(s,fc,fs,"fm");
subplot(5,1,5);
plot(t,z);
xlabel('time 43');
ylabel('amp 43');
title('FM DEMODULATED SIGNAL using IN-BUILT UI21CS43');