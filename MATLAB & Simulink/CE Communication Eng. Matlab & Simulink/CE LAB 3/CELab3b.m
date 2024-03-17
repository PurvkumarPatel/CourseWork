clc;
clear all;
close all;

figure;
%1)Am=0.5,m<1 (Under Modulation) \

%Message Signal \
pi=3.14;
t=[0:0.1:100];
Em=0.5;
Fm=100;
a=Em*cos(2*pi*Fm*t);
subplot(3,4,1);
plot(t,a);
axis([0 100 -2 2]);
xlabel('Time UI21CS43');
ylabel('Amplitude UI21CS43');
title('Message Signal UI21CS43');

%Carrier Signal \
Ec=1;
Fc=1000;
b=Ec*cos(2*pi*Fc*t);



subplot(3,4,2);
plot(t,b);
axis([0 100 -2 2]);
xlabel('Time UI21CS43');
ylabel('Amplitude UI21CS43');
title('Carrier Signal UI21CS43');

%Modulated Signal \
c=(Ec + Em*cos(2*pi*Fm*t)).*cos(2*pi*Fc*t);
subplot(3,4,3);
plot(t,c);
axis([0 100 -2 2]);
xlabel('Time UI21CS43');
ylabel('Amplitude UI21CS43');
title('Under Modulated Signal UI21CS43');

%Reconstruction in Under modulation \
D=c.*b
[B,A]=butter(5,1/22,'low');
F=filter(B,A,D);
subplot(3,4,4);
plot(t,F);
xlabel('Time UI21CS43');
ylabel('Amplitude UI21CS43');
title('Reconstruction for m<1 UI21CS43');


%2)Am=1,m=1 (Prefect Modulation) \

%Modulated Signal \
Em=1;
c=(Ec + Em*cos(2*pi*Fm*t)).*cos(2*pi*Fc*t);
subplot(3,4,7);
plot(t,c);
axis([0 100 -2 2]);
xlabel('Time UI21CS43');
ylabel('Amplitude UI21CS43');
title('Prefect Modulated Signal UI21CS43');

%Reconstruction in Perfect modulation \
D=c.*b
[B,A]=butter(5,1/22,'low');
F=filter(B,A,D);
subplot(3,4,8);
plot(t,F);
xlabel('Time UI21CS43');
ylabel('Amplitude UI21CS43');
title('Reconstruction for m=1 UI21CS43');

%3)Am=2,m>1 (Over Modulation) \

%Modulated Signal \


Em=2;
c=(Ec + Em*cos(2*pi*Fm*t)).*cos(2*pi*Fc*t);
subplot(3,4,5);
plot(t,c);
axis([0 100 -3.1 3.1]);
xlabel('Time UI21CS43');
ylabel('Amplitude UI21CS43');
title('Over Modulated Signal UI21CS43');

%Reconstruction in Over modulation \
D=c.*b
[B,A]=butter(5,1/22,'low');
F=filter(B,A,D);
subplot(3,4,6);
plot(t,F);
xlabel('Time UI21CS43');
ylabel('Amplitude UI21CS43');
title('Reconstruction for m>1 UI21CS43');