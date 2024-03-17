% (28-07-2023) (LAB 1) 
% To study and generate continueous and discreate time signal and sequences 
% and to perform various mathematical operations on them using MATLAB
%%
% Continueous Unit step function signal%
t = -1:0.00001:1;
n = length(t);
x = 0:1;
for i = 1:n 
    if t(i) < 0
      x(i)=0;
    else
      x(i)=1;
    end  
end
figure;
plot(t,x,'LineWidth',1.5,Color='g')
xlabel('Time(t)');
ylabel('Amplitute');
title(' Unit Step signal','FontSize',25);
grid on;
axis([-1.1,1.1,-0.1,1.1]);

% Discreate Unit step function sequence %
n = -1:0.05:1;
N = length(n);
y = 0:1;
for i = 1:N 
    if n(i) < 0
      y(i)=0;
    else
      y(i)=1;
    end  
end
figure; % to view previous plot
stem(n,y,'m','LineWidth',0.2,Color='r') % stem for discrete signal
xlabel('Time(n)');
ylabel('Amplitute');
title(' Unit Step Sequence','FontSize',25);
grid on;
axis([-1.1,1.1,-0.1,1.1]);

%% 
% Continueous Unit Ramp function signal%
tr = -1:0.005:1;
r = length(tr);
xr = 0:1;
for i=1:r 
    if tr(i) < 0
      xr(i) = 0;
    else
      xr(i) = tr(i);
    end  
end
figure;
plot(tr,xr,'LineWidth',1.5,Color='g')
xlabel('Time(t)');
ylabel('Amplitute');
title(' Unit Ramp signal','FontSize',25);
grid on;
axis([-1.1,1.1,-0.1,1.1]);

% Discreate Unit Ramp function sequence %
nr = -1:0.05:1;
Nr = length(nr);
yr = 0:1;
for i = 1:Nr 
    if nr(i) < 0
      yr(i) = 0;
    else
      yr(i) = nr(i);
    end  
end
figure; % to view previous plot
stem(nr,yr,'LineWidth',0.2,Color='r') % stem for discrete signal
xlabel('Time(n)');
ylabel('Amplitute');
title(' Unit Ramp Sequence','FontSize',25);
grid on;
axis([-1.1,1.1,-0.1,1.1]);

%% 
% genration of continueous time sine wave signal
t = -1:0.0001:1;
f1 = 1;
f2 = 3;
x1 = sin(2*pi*f1*t);
x2 = sin(2*pi*f2*t);
figure;
plot(t,x1);
hold
plot(t,x2);
% plot(t,x1,'r',t,x2,'b','LineWidth',2) same as above three line 
title(' continueous time sine wave signal ','FontSize',20);
grid on;
legend('1Hz','3Hz');
axis([-1.1,1.1,-1.1,1.1]);

%%
% genration of discrete time sine wave squence
t = -1:0.05:1;
f1 = 1;
f2 = 3;
x1 = sin(2*pi*f1*t);
x2 = sin(2*pi*f2*t);

figure;
stem(t,x1);
hold
stem(t,x2);
% plot(t,x1,'r',t,x2,'b','LineWidth',2) same as above three line 
title(' Discrete time sine wave squence ','FontSize',20);
grid on;
legend('1Hz','3Hz');
axis([-1.1,1.1,-1.1,1.1]);
%%
% Perform addition, subtraction and multiplication on Sinusoidal signals and plot the results.
% Original Sinusoidal Signals
t = linspace(0, 2, 1000);
signal_1 = sin(2 * pi * 1 * t);
signal_2 = sin(2 * pi * 3 * t);

% Perform operations
sum_signal = signal_1 + signal_2;
diff_signal = signal_1 - signal_2;
mult_signal = signal_1 .* signal_2;
div_signal = signal_1 ./ signal_2;

% Plot the original and manipulated signals
subplot(3, 2, 1), plot(t, signal_1), title('Original Sinusoidal 1Hz')
subplot(3, 2, 2), plot(t, signal_2), title('Original Sinusoidal 3Hz')
subplot(3, 2, 3), plot(t, sum_signal), title('Sum of Signals')
subplot(3, 2, 4), plot(t, diff_signal), title('Substraction of Signals')
subplot(3, 2, 5), plot(t, mult_signal), title('Multiplication of Signals')
subplot(3, 2, 6), plot(t, div_signal), title('Divison of Signals')

%%
% Perform time shifting on the signals and plot the results.
% Original Sinusoidal Signal
t = linspace(0, 2, 1000);
original_signal = sin(2 * pi * 1 * t);

% Perform time shifting
delayed_signal = sin(2 * pi * 1 * (t - 0.5)); % Delay by 0.5 seconds
advanced_signal = sin(2 * pi * 1 * (t + 0.5)); % Advance by 0.5 seconds

% Plot the original and shifted signals
subplot(3, 1, 1), plot(t, original_signal), title('Original Sinusoidal Signal')
subplot(3, 1, 2), plot(t, delayed_signal), title('Delayed Signal')
subplot(3, 1, 3), plot(t, advanced_signal), title('Advanced Signal')

%%
% Perform 4, 8 and 16 levels of digitization on sinusoidal signals and plot them.
% Original Sinusoidal Signal
t = linspace(0, 1, 1000);
original_signal = sin(2 * pi * 5 * t);

% Perform digitization
quantization_levels = [4, 8, 16];
quantized_signals = zeros(length(quantization_levels), length(t));

for i = 1:length(quantization_levels)
    quantized_signals(i, :) = round(original_signal * (quantization_levels(i) - 1)) / (quantization_levels(i) - 1);
end

% Plot the original and quantized signals
subplot(2, 2, 1), plot(t, original_signal), title('Original Sinusoidal Signal')
for i = 1:length(quantization_levels)
    subplot(2, 2, i + 1), plot(t, quantized_signals(i, :)), title(['Quantization: ' num2str(quantization_levels(i)) ' levels'])
end

%%
% perform arithmatice operation on above to sine wave and digitize them in
% 4,8,16 level
% Conversion of Analog to Digital Sign
%%
% how read audio file in matlab and listen them
load handel.mat
audiowrite("handel.wav",y,Fs)
clear y Fs
info = audioinfo("handel.wav") %infor of filr
[y,Fs] = audioread("handel.wav");
sound(y,Fs) % listen sound

