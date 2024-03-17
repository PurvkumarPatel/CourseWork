clc;
clear;
close all;
num = [1, 3];
den = [1, 0.5];
% Create a discrete-time filter object for Direct Form
direct_form = dfilt.df1(num, den);
% Create a discrete-time filter object for Cascade Form
sos = tf2sos(num, den, 'up');
cascade_form = dfilt.df2sos(sos);
% Create a discrete-time filter object for Parallel Form
sos = tf2sos(num, den, 'down');
parallel_form = dfilt.df2sos(sos);
% Create a time vector
Fs = 100;
t = 0:1/Fs:1;
% Generate an impulse input signal
impulse_signal = [1, zeros(1, length(t) - 1)];
% Generate a sine wave input signal
f_sine = 5;
sine_signal = sin(2*pi*f_sine*t);
% Add the impulse and sine wave signals
x = impulse_signal + sine_signal;
y_direct = filter(direct_form, x);
y_cascade = filter(cascade_form, x);
y_parallel = filter(parallel_form, x);
subplot(4, 1, 1); plot(t, x); title('Original Signal Sine');
subplot(4, 1, 2); plot(t, y_direct); title('Direct Form');
subplot(4, 1, 3); plot(t, y_cascade); title('Cascade Form');
subplot(4, 1, 4); plot(t, y_parallel); title('Parallel Form');