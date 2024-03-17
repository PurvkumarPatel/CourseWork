clc;
clear ALL;
close all;
%LAB 7 UI21CS43 PAM - PWM - PPM SIGNAL
% MESSAGE SIGNAL
figure;
fs=10000;
t = -1:0.001:1;S
pi=3.14;
fm=1000;
fc=16000;
m=sin(2*pi*fm*t);
subplot(4,1,1);
plot(t,m);
xlabel('time 43');
ylabel('amp 43');
title('MODULATING SIGNAL UI21CS43');

% SAWTOOTH CARRIER SIGNAL
c=sawtooth(2*pi*fc*t);
subplot(4,1,2);
plot(t,c);
xlabel('time 43');
ylabel('amp 43');
title('CARRIER SAWTOOTH SIGNAL UI21CS43');

subplot(4,1,3);
plot(t,m,'r',t,c,'b--');
xlabel('time 43');
ylabel('amp 43');
title('MODULATING and CARRIER SIGNAL UI21CS43');
n=length(c);
for i = 1:n
    if m(i)>=c(i)
        pwm(i)=1;
    else
        pwm(i)=0;
    end
end
subplot(4,1,4);
plot(t,pwm);
xlabel('time 43');
ylabel('amp 43');
title('PWM SIGNAL UI21CS43');