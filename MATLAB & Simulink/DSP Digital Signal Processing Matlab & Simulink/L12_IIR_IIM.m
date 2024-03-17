% Define analog prototype filter
AnalogFilter = tf([1], [1, 0.5, 0.25]);

% Sample rate (Hz)
Fs = 1000;

% Impulse Invariant transformation
DigitalFilter = c2d(AnalogFilter, 1/Fs, 'zoh');

% Generate input signal
t = 0:1/Fs:1;
x = sin(2*pi*100*t);

% Apply the digital filter
y = filter(DigitalFilter.num{1}, DigitalFilter.den{1}, x);

% Plot the filtered signal
figure;
subplot(3, 1, 1);
plot(t, x);
title('Original Signal');
subplot(3, 1, 2);
plot(t, y);
title('Filtered Signal (Impulse Invariant)');
% Plot impulse response of the Impulse Invariant filter
subplot(3, 1, 3);
impulse(DigitalFilter);
title('Impulse Response (Impulse Invariant)');

