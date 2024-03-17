%% fft using DIT and for n number 2 4 8 16 
signal = input('Enter the input signal: ');

N = length(signal);
if N <= 1
    fft_result = signal;
else
    even = signal(1:2:N-1);
    odd = signal(2:2:N);

    % Calculate twiddle factors
    twiddle_factors = exp(-2i * pi * (0:N/2-1) / N);

    % Calculate FFT recursively for even and odd parts
    even_fft = fft(even);
    odd_fft = fft(odd);

    % Combine the even and odd parts with twiddle factors
    fft_result = zeros(1, N);
    for k = 1:N/2
        t = twiddle_factors(k) * odd_fft(k);
        fft_result(k) = even_fft(k) + t;
        fft_result(k + N/2) = even_fft(k) - t;
    end
end

disp('FFT Result:');
disp(fft_result);

%% DIT another approch
% DIT FFT
clc;
clear;
close all;

x = [1 2 3 4 5 6];
X = Dit_fft(x);
disp('Input signal:');
disp(x);
disp('FFT result:');
disp(X);

function X = Dit_fft(x)
    N = length(x);
    if log2(N) ~= round(log2(N))
        error('For Radix-2 sequence must be a power of 2.');
    end 
    if N == 1
        X = x; % Base case
    else
        x_even = x(1:2:N);
        x_odd = x(2:2:N);  

        % Divide recursively
        X_even = Dit_fft(x_even);
        X_odd = Dit_fft(x_odd);     

        % Conquer
        W = exp(-2i * pi / N) .^ (0:N/2-1); % Twiddle factors
        X = zeros(1, N);
        X(1:N/2) = X_even + W .* X_odd;
        X(N/2+1:N) = X_even - W .* X_odd;
    end
end
