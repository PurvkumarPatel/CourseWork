% Define analog prototype filter
AnalogFilter = tf([1], [1, 0.5, 0.25]);

% Sample rate (Hz)
Fs = 1000;

% Bilinear Transform using the 'tustin' option
DigitalFilter = c2d(AnalogFilter, 1/Fs, 'tustin');

% Extract the numerator and denominator coefficients as numeric arrays
b = cell2mat(DigitalFilter.Numerator);
a = cell2mat(DigitalFilter.Denominator);

% Generate input signal
t = 0:1/Fs:1;
x = sin(2*pi*100*t);

% Apply the digital filter
y = filter(b, a, x);

% Plot the filtered signal
figure;
subplot(3, 1, 1);
plot(t, x);
title('Original Signal');
subplot(3, 1, 2);
plot(t, y);
title('Filtered Signal (Bilinear Transform)');
impulseResponse = impz(b, a);
t_impulse = (0:length(impulseResponse) - 1) / Fs;
subplot(3,1,3);
plot(t_impulse, impulseResponse);
title('Impulse Response (Bilinear Transform)');
