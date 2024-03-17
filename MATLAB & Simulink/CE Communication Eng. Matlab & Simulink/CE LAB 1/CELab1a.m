%sin
clc;
clear all;
close all;
figure;
t=[-10:0.1:10];
a=sin(t);
subplot(3,2,1);
plot(t,a);
xlabel('time UI21CS43’);
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('sinwave UI21CS43');
%cos
t=[-10:0.1:10];
a=cos(t);
subplot(3,2,2);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('cos UI21CS43');
%tan
t=[-10:0.1:10];
a=tan(t);
subplot(3,2,3);
plot(t,a);
xlabel('time UI21CS43');



ylabel('amp UI21CS43');
axis([-10 10 -2 2]);
title('tan UI21CS43');
%square
t=[-10:0.1:10];
a=(square(t));
subplot(3,2,4);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('square UI21CS43');
%triangular
t=[-10:0.1:10];
a=sawtooth(t,0);
subplot(3,2,5);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('triangular UI21CS43');
%sawtooth
t=[-10:0.1:10];
a=sawtooth(t,0.5);
subplot(3,2,6);
plot(t,a);
xlabel('time UI21CS43');
ylabel('amp UI21CS43');
%AXIS([-10 10 -2 2]);
title('sawtooth UI21CS43');