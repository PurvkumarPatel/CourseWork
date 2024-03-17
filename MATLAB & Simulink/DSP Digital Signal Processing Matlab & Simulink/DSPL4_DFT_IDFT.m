%%
clc;
close all;
clear;

N = 8;
n = 0:N-1;
% function 1
x = cos(2*pi*2*n/N) + 0.5 * cos(2*pi*5*n/N);
% function 2
%x = [1 2 3 4 5];
X = myDFT(x);
reconstructed_x = myIDFT(X);
disp("original signal:")
disp(x)
disp("DFT Result:")
disp(X)
disp("IDFT Result:")
disp(reconstructed_x)

function X = myDFT(x)
    N = length(x);
    X = zeros(1, N);
    for k = 1:N
        X(k) = 0;
        for n = 1:N
            X(k) = X(k) + x(n) * exp(-1i * 2 * pi * (k-1) * (n-1) / N);
        end
    end
end
function x = myIDFT(X)
    N = length(X);
    x = zeros(1, N);
    
    for n = 1:N
        x(n) = 0;
        for k = 1:N
            x(n) = x(n) + X(k) * exp(1i * 2 * pi * (k-1) * (n-1) / N);
        end
        x(n) = x(n) / N; % Normalize by N
    end
end


%%
% function 3 Sine Wave
fs = 1000;         % Sampling frequency
t = 0:1/fs:1;      % Time vector
f = 50;            % Frequency of the sine wave
x = sin(2*pi*f*t); % Sine wave signal

% Calculate DFT using FFT
X = fft(x);
idft = ifft(X);
% Plot the magnitude of DFT
frequencies = linspace(0, fs, length(X));
subplot(3, 1, 1);
plot(frequencies, abs(X));
title('DFT of Sine Wave');
xlabel('Frequency (Hz)');
ylabel('Magnitude');

% Plot the original signal
subplot(3, 1, 2);
plot(t, idft);
title('IDFT or Original Sine Wave');
xlabel('Time (s)');
ylabel('Amplitude');

%%
% function 4 Step Signal
fs = 1000;         % Sampling frequency
t = 0:1/fs:1;      % Time vector
x = ones(size(t)); % Step signal

% Calculate DFT using FFT
X = fft(x);
idft = ifft(X);
% Plot the magnitude of DFT
frequencies = linspace(0, fs, length(X));
subplot(2, 1, 1);
plot(frequencies, abs(X));
title('DFT of Step Signal');
xlabel('Frequency (Hz)');
ylabel('Magnitude');

% Plot the original signal
subplot(2, 1, 2);
plot(t, idft);
title('IDFT or Original Step Signal');
xlabel('Time (s)');
ylabel('Amplitude');

%%
% function 5 custom signal
n = -10:10;        % Discrete time values
x = zeros(size(n)); % Initialize signal with zeros

x(n > 0) = 1;  % Set the values where n > 0 to 1
x(n < 0) = 2;  % Set the values where n < 0 to 2

X = fft(x);
idft = ifft(X);
% Plot the magnitude of DFT
fs = 1 / (n(2) - n(1)); % Calculate the sampling frequency
frequencies = linspace(0, fs, length(X));
subplot(2, 1, 1);
plot(frequencies, abs(X));
title('DFT of Custom Signal');
xlabel('Frequency (Hz)');
ylabel('Magnitude');

% Plot the original signal
subplot(2, 1, 2);
stem(n, idft);
title('IDFT or Original Custom Signal');
xlabel('n');
ylabel('Amplitude');
axis([-10, 10, 0, 3]);