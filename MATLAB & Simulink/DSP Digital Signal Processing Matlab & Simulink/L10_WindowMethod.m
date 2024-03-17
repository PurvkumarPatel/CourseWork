clc;
clear all;
close all;
N = 64;
beta = 2.5;


% Generate window functions
w_rectangular = rectwin(N);
w_bartlett = window(@bartlett, N);
w_blackman_harris = window(@blackmanharris, N);
w_hamming = window(@hamming, N);
w_kaiser = window(@kaiser, N, beta);
w_hann = window(@hann, N);

figure;
subplot(2, 3, 1);
stem(w_rectangular);
title('Rectangular Window');
axis([-10, N+10, 0, 1.5]);

subplot(2, 3, 2);
stem(w_bartlett);
title('Bartlett Window');
axis([-10, N+10, 0, 1.5]);

subplot(2, 3, 3);
stem(w_hann);
title('Hann Window');
axis([-10, N+10, 0, 1.5]);

subplot(2, 3, 4);
stem(w_hamming);
title('Hamming Window');
axis([-10, N+10, 0, 1.5]);

subplot(2, 3, 5);
stem(w_blackman_harris);
title('Blackman-Harris Window');
axis([-10, N+10, 0, 1.5]);

subplot(2, 3, 6);
stem(w_kaiser);
title('Kaiser Window (Beta=2.5)');
axis([-10, N+10, 0, 1.5]);

sgtitle('Window Functions in MATLAB (Stem Plot)');
% Plot the frequency responses

figure;
freqz(w_rectangular);
title('Rectangular Window Frequency Response');
figure;
freqz(w_bartlett);
title('Bartlett Window Frequency Response');
figure;
freqz(w_hann);
title('Hann Window Frequency Response');
figure;
freqz(w_hamming);
title('Hamming Window Frequency Response');
figure;
freqz(w_blackman_harris);
title('Blackman-Harris Window Frequency Response');
figure;
freqz(w_kaiser);
title('Kaiser Window Frequency Response');