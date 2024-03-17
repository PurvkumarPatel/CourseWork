clc;
clear all;
close all;

% FIR filter coefficients for Type 1
filCoeff1 = [0.5, 1, 1, 1, 1, 1, 1, 0.5];
filCoeff1 = filCoeff1 / 6;
% Frequency response
w = linspace(0, pi, 1000);
H1 = freqz(filCoeff1, 1, w);
% Impulse response
n = 0:length(filCoeff1) - 1;
impulse_response1 = filter(filCoeff1, 1, [1 zeros(1, length(filCoeff1) - 1)]);
% Create a new figure for Type 1
figure;
% Magnitude response
subplot(3,1,1);
plot(w / pi, abs(H1), 'b');
title('Type 1 Linear Phase FIR Filter - Magnitude Response');
xlabel('Frequency [rad/sample] / pi');
ylabel('Amplitude', 'Color', 'b');
grid on;
% Phase response
subplot(3,1,2);
angle_H1 = unwrap(angle(H1));
plot(w / pi, angle_H1 / pi);
title('Type 1 Linear Phase FIR Filter - Phase Response');
xlabel('Frequency [rad/sample] / pi');
ylabel('Angle (radians) / pi', 'Color', 'g');
grid on;
% Impulse response
subplot(3,1,3);
stem(n, impulse_response1);
title('Type 1 Linear Phase FIR Filter - Impulse Response');
xlabel('n');
ylabel('h[n]');
grid on;

%----------------------------------------------------------
% FIR filter coefficients for Type 2
filCoeff2 = [-0.5, 1, -1, 1, -1, 1, -1, 0.5];
filCoeff2 = filCoeff2 / 6;
% Frequency response
H2 = freqz(filCoeff2, 1, w);
% Impulse response
impulse_response2 = filter(filCoeff2, 1, [1 zeros(1, length(filCoeff2) - 1)]);
% Create a new figure for Type 2
figure;
% Magnitude response
subplot(3,1,1);
plot(w / pi, abs(H2), 'b');
title('Type 2 Linear Phase FIR Filter - Magnitude Response');
xlabel('Frequency [rad/sample] / pi');
ylabel('Amplitude', 'Color', 'b');
grid on;
% Phase response
subplot(3,1,2);
angle_H2 = unwrap(angle(H2));
plot(w / pi, angle_H2 / pi);
title('Type 2 Linear Phase FIR Filter - Phase Response');
xlabel('Frequency [rad/sample] / pi');
ylabel('Angle (radians) / pi', 'Color', 'g');
grid on;
% Impulse response
subplot(3,1,3);
stem(n, impulse_response2);
title('Type 2 Linear Phase FIR Filter - Impulse Response');
xlabel('n');
ylabel('h[n]');
grid on;

%----------------------------------------------------------
% FIR filter coefficients for Type 3
filCoeff3 = [-1, 2, -3, 4, -3, 2, -1];
filCoeff3 = filCoeff3 / 12;
% Frequency response
H3 = freqz(filCoeff3, 1, w);
% Impulse response
n3 = 0:length(filCoeff3) - 1;
impulse_response3 = filter(filCoeff3, 1, [1 zeros(1, length(filCoeff3) - 1)]);
% Create a new figure for Type 3
figure;
% Magnitude response
subplot(3,1,1);
plot(w / pi, abs(H3), 'b');
title('Type 3 Linear Phase FIR Filter - Magnitude Response');
xlabel('Frequency [rad/sample] / pi');
ylabel('Amplitude', 'Color', 'b');
grid on;
% Phase response
subplot(3,1,2);
angle_H3 = unwrap(angle(H3));
plot(w / pi, angle_H3 / pi);
title('Type 3 Linear Phase FIR Filter - Phase Response');
xlabel('Frequency [rad/sample] / pi');
ylabel('Angle (radians) / pi', 'Color', 'g');
grid on;
% Impulse response
subplot(3,1,3);
stem(n3, impulse_response3);
title('Type 3 Linear Phase FIR Filter - Impulse Response');
xlabel('n');
ylabel('h[n]');
grid on;

%----------------------------------------------------------
% FIR filter coefficients for Type 4
filCoeff4 = [1, -4, 6, -4, 1];
filCoeff4 = filCoeff4 / 16;
% Frequency response
H4 = freqz(filCoeff4, 1, w);
% Impulse response
n4 = 0:length(filCoeff4) - 1;
impulse_response4 = filter(filCoeff4, 1, [1 zeros(1, length(filCoeff4) - 1)]);
% Create a new figure for Type 4
figure;
% Magnitude response
subplot(3,1,1);
plot(w / pi, abs(H4), 'b');
title('Type 4 Linear Phase FIR Filter - Magnitude Response');
xlabel('Frequency [rad/sample] / pi');
ylabel('Amplitude', 'Color', 'b');
grid on;
% Phase response
subplot(3,1,2);
angle_H4 = unwrap(angle(H4));
plot(w / pi, angle_H4 / pi);
title('Type 4 Linear Phase FIR Filter - Phase Response');
xlabel('Frequency [rad/sample] / pi');
ylabel('Angle (radians) / pi', 'Color', 'g');
grid on;
% Impulse response
subplot(3,1,3);
stem(n4, impulse_response4);
title('Type 4 Linear Phase FIR Filter - Impulse Response');
xlabel('n');
ylabel('h[n]');
grid on;