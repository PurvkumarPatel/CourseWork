% floor fn
% digital to binary and binary to digital conversion
clc;
clear All;
close all;
%LAB 8 UI21CS19 ANALOG TO DIGITAL CONVERSION
% MESSAGE SIGNAL
figure;
t = -1:0.005:1;
pi=3.14;
fm=2;
m=sin(2*pi*fm*t);
subplot(4,1,1);
plot(t,m);
xlabel('time 19');
ylabel('amp 19');
title('MESSAGE SIGNAL UI21CS19');
% PERFECT SAMPLING
fm=1000;
subplot(4,1,2);
stem(t,m);
xlabel('time 19');
ylabel('amp 19');
title('PERFECT SAMPLING SIGNAL UI21CS19');
x=floor(m/0.2);
y=dec2bin(x);
subplot(4,1,3);
plot(t,x);
xlabel('time 19');
ylabel('amp 19');
title('QUANTIZED SIGNAL UI21CS19');
z=bin2dec(y);s
disp(z);

output1=filter(1,1,z);
[B,A]=butter(5,1/42,'low');
output2=filter(B,A,output1);
subplot(4,1,4);
plot(t,output2);