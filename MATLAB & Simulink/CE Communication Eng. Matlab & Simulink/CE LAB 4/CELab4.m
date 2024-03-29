clc;
close all;
clear all;
Am=10;
Ac=15;
fm=1;
fc=10;
m=Am/Ac;
pi=3.14;
t=[-4:0.01:4];
Em=Am*cos(2*pi*fm*t);
figure;
subplot(5,2,1);
plot(t,Em);
title('Modulating signal-UI21CS43');
a=abs(fft(Em));
subplot(5,2,2);
plot(t,a);
title('Modulating signal-UI21CS43');
Ec=Ac*cos(2*pi*fc*t);
subplot(5,2,3);
plot(t,Ec);
title('carrier signal-UI21CS43');
subplot(5,2,3);
a=abs(fft(Ec));
subplot(5,2,4);
plot(t,a);
title('carrier signal-UI21CS43');
m=Am/Ac;
Eam=Ac*[1+m*cos(2*pi*fm*t)].*cos(2*pi*fc*t);
subplot(5,2,5);
plot(t,Eam);
title('AM signal for "m<1"-UI21CS43');
a=abs(fft(Eam));
subplot(5,2,6);
plot(t,a);
title('AM signal for "m<1"-UI21CS43');
m=Am/Ac;
EDSB=[Ac*cos(2*pi*fc*t)].*[Am*cos(2*pi*fm*t)];
subplot(5,2,7);
plot(t,EDSB);
title('DSB-SC-UI21CS43');
a=abs(fft(EDSB));
subplot(5,2,8);
plot(t,a);
title('DSB-SC-UI21CS43');
Em1=Am*sin(2*pi*fm*t);
Ec1=Ac*sin(2*pi*fc*t);
ESSB=Em.*Ec+Em1.*Ec1;
subplot(5,2,9);
plot(t,ESSB);
title('SSB signal-UI21CS43');
a=abs(fft(ESSB));
subplot(5,2,10);
plot(t,a);
title('SSB signal-UI21CS43');