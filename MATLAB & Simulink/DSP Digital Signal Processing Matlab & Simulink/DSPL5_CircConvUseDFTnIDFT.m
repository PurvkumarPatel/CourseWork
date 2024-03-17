%% Circular Convolution

%% 1) Using Inbuilt DFT and IDFT Functions
clc;
clear;

% Input sequences
x = input("Enter the first sequence: ");
h = input("Enter the second sequence: ");
lx = length(x);
lh = length(h);
P = max(lx, lh);
n = 0:1:P-1;

% Plot the first signal
subplot(2, 3, 1);
stem(x);
xlabel('n');
ylabel('x(n)');
title('First signal');

% Plot the second signal
subplot(2, 3, 2);
stem(h);
xlabel('m');
ylabel('h(n)');
title('Second signal');

% Compute DFT of the first signal
X = fft(x, P);
subplot(2, 3, 3);
stem(abs(X));  
xlabel('k');
ylabel('|X(k)|');
title('DFT of the first signal');

% Compute DFT of the second signal
H = fft(h, P);
subplot(2, 3, 4);
stem(abs(H));  
xlabel('k');
ylabel('|H(k)|');
title('DFT of the second signal');

% Multiply the DFTs
Y = X .* H;
subplot(2, 3, 5);
stem(abs(Y));  
xlabel('k');
ylabel('|Y(k)|');
title('Multiplication of DFTs');

% Perform circular convolution via IDFT
y = ifft(Y);
subplot(2, 3, 6);
stem(abs(y));  
xlabel('k');
ylabel('|y(k)|');
title('Circular Convolution via IDFT');

sgtitle('Circular Convolution using DFT and IDFT');

%% 2) Using User-Defined DFT and IDFT Functions

% (User-Defined DFT and IDFT functions are assumed to be defined as myDFT and myIDFT)

x = input("Enter the first sequence: ");
h = input("Enter the second sequence: ");
lx = length(x);
lh = length(h);
P = max(lx, lh);
n = 0:1:P-1;

% Plot the first signal
subplot(2, 3, 1);
stem(x);
xlabel('n');
ylabel('x(n)');
title('First signal');

% Plot the second signal
subplot(2, 3, 2);
stem(h);
xlabel('m');
ylabel('h(n)');
title('Second signal');

% Compute DFT of the first signal using user-defined function
X = myDFT(x);
subplot(2, 3, 3);
stem(abs(X));  
xlabel('k');
ylabel('|X(k)|');
title('DFT of the first signal');

% Compute DFT of the second signal using user-defined function
H = myDFT(h);
subplot(2, 3, 4);
stem(abs(H));  
xlabel('k');
ylabel('|H(k)|');
title('DFT of the second signal');

% Multiply the DFTs
Y = X .* H;
subplot(2, 3, 5);
stem(abs(Y));  
xlabel('k');
ylabel('|Y(k)|');
title('Multiplication of DFTs');

% Perform circular convolution via IDFT using user-defined function
y = myIDFT(Y);
subplot(2, 3, 6);
stem(abs(y));  
xlabel('k');
ylabel('|y(k)|');
title('Circular Convolution via IDFT');

sgtitle('Circular Convolution using DFT and IDFT');

%% 3) Using Matrix Multiplication

x = input('Enter the first sequence: ');
h = input('Enter the second sequence: ');

lx = length(x);
lh = length(h);
N = max(lx, lh);

% Create empty matrices for x and h
X = zeros(1, N);
H = zeros(1, N);

% Fill the matrices with the sequences
X(1:lx) = x;
H(1:lh) = h;

% Initialize the circular convolution result
Y = zeros(1, N);

% Perform circular convolution using matrix multiplication
for n = 1:N
    for k = 1:N
        if n - k >= 0
            Y(n) = Y(n) + X(k) * H(n - k + 1);
        else
            Y(n) = Y(n) + X(k) * H(N + n - k + 1);
        end
    end
end

% Plot the result
subplot(2, 1, 1);
stem(Y);
title('Circular Convolution using Matrix Multiplication');
xlabel('n');
ylabel('y(n)');
grid on;

%% 4) Using the Concentric Circle Method

x = input("Enter the first sequence: ");
h = input("Enter the second sequence: ");

lx = length(x);
lh = length(h);
N = max(lx, lh);

% Pad the sequences with zeros to the size of N
x_padded = [x zeros(1, N - lx)];
h_padded = [h zeros(1, N - lh)];

% Initialize the circular convolution result
y = zeros(1, N);

% Initialize figure for plotting concentric circles
figure;
subplot(2, 1, 2);
hold on;

% Perform the concentric circle method
for n = 1:N
    for k = 1:N
        if n - k >= 0
            y(n) = y(n) + x_padded(k) * h_padded(n - k + 1);
        else
            y(n) = y(n) + x_padded(k) * h_padded(N + n - k + 1);
        end
    end
    
    %Plot a circle representing the complex number at this step
    r = abs(y(n));
    theta = angle(y(n));
    t = linspace(0, 2*pi, 100);
    x_circle = r * cos(t);
    y_circle = r * sin(t);
    plot(x_circle, y_circle, 'b');
    axis("equal");
    text(k,y(n) ,"patel");
end

% Plot the result
title('Circular Convolution using Concentric Circle Method');
xlabel('Real');
ylabel('Imaginary');
grid on;

% Display the circular convolution result
subplot(2, 1, 1);
stem(y);
title('Circular Convolution Result');
xlabel('n');
ylabel('y(n)');
grid on;

hold off;

%% Another Approach (Using Built-in cconv Function)

x = [2 2];
h = [1 1 1];
l1 = length(x);
l2 = length(h);
N = max(l1, l2);

% Perform circular convolution using built-in cconv function
a = cconv(x, h, N);

% Plot the result
subplot(2, 1, 1);
stem(a);
title('Circular Convolution with Function');
xlabel('Time');
ylabel('Amplitude');
grid on;

% Pad the sequences with zeros to the size of N
x = [x zeros(1, N - l1)];
h = [h zeros(1, N - l2)];
y = zeros(1, N);

% Perform circular convolution without using a function
for n = 1:N
    for m = 1:N
        j = mod(n - m, N);
        j = j + 1;
        y(n) = y(n) + x(m) * h(j);
    end
end

% Plot the result
subplot(2, 1, 2);
stem(y);
title('Circular Convolution Without Function');
xlabel('Time');
ylabel('Amplitude');
grid on;
