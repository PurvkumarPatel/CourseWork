t=0:0.1:10;
fm=input('frequency fm= '); fs=input('frequency fs= '); pi=3.14;
x=cos(2*fm*pi*t); subplot(3,1,1);
plot(t,x);
title('modulating signal-UI21CS43');
y=cos(2*fs*pi*t); subplot(3,1,2);
stem(t,y);
title('sampled signal-UI21CS43');
h=filter(fs,1,y); subplot(3,1,3);
plot(t,h);
title('reconstructed signal-UI21CS43');