clc;
clear all;
close all;

% Define filter specifications
Fs = 4000; % Sampling frequency
N = 8;     % Filter order

% Cutoff frequencies for each filter type
lowpass_freq = 400;    % Cutoff frequency for low-pass filter (Hz)
highpass_freq = 800;   % Cutoff frequency for high-pass filter (Hz)
bandpass_freq = [200, 400]; % Passband frequencies for band-pass filter (Hz)
bandstop_freq = [200, 400]; % Stopband frequencies for band-stop filter (Hz)

% Design Butterworth filters
[b_lowpass, a_lowpass] = butter(N, lowpass_freq / (Fs/2), 'low');
[b_highpass, a_highpass] = butter(N, highpass_freq / (Fs/2), 'high');
[b_bandpass, a_bandpass] = butter(N, bandpass_freq / (Fs/2), 'bandpass');
[b_bandstop, a_bandstop] = butter(N, bandstop_freq / (Fs/2), 'stop');

% Frequency response computation
freq_range = -Fs/2:1:Fs/2;
freq_response_lowpass = freqz(b_lowpass, a_lowpass, freq_range, Fs);
freq_response_highpass = freqz(b_highpass, a_highpass, freq_range, Fs);
freq_response_bandpass = freqz(b_bandpass, a_bandpass, freq_range, Fs);
freq_response_bandstop = freqz(b_bandstop, a_bandstop, freq_range, Fs);

magnitute_lowpass = abs(freq_response_lowpass);
[~,idx] = min(abs(magnitute_lowpass-1/sqrt(2)));
cutoff_frequency_lowpass = freq_range(idx);
disp("Low pass cutoff freq:");
disp(cutoff_frequency_lowpass);
disp("Hz");

magnitute_highpass = abs(freq_response_highpass);
[~,idx] = min(abs(magnitute_highpass-1/sqrt(2)));
cutoff_frequency_highpass = freq_range(idx);
disp("High pass cutoff freq:");
disp(cutoff_frequency_highpass);
disp("Hz");

% Plot frequency responses
figure;

subplot(2,2,1);
plot(freq_range, abs(freq_response_lowpass));
title('Low-Pass Filter');
xlabel('Freq(Hz)');
ylabel('Magnitude');
grid on;

subplot(2,2,2);
plot(freq_range, abs(freq_response_highpass));
title('High-Pass Filter');
xlabel('Freq(Hz)');
ylabel('Magnitude');
grid on;

subplot(2,2,3);
plot(freq_range, abs(freq_response_bandpass));
title('Band-Pass Filter');
xlabel('Freq(Hz)');
ylabel('Magnitude');
grid on;

subplot(2,2,4);
plot(freq_range, abs(freq_response_bandstop));
title('Band-Stop Filter');
xlabel('Freq(Hz)');
ylabel('Magnitude');
grid on;

sgtitle('Frequency Responses of Digital Filters');