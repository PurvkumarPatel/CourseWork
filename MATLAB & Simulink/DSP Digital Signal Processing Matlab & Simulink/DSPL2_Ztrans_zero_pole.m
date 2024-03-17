% DSP Lab 2 Z transform and zero and pole
%% 
% function 1
x = [1,2,3,4,5]; %also use function
l = length(x);
X = 0 ; % initialize output
syms z ; % defining symbol
for i =0 : l-1
    X=X+x(i+1)*z^(-i);
end
disp(x);
disp('Z-Transform X(z) = ');
pretty(X); 
title('Pole-Zero Plot');
zplane(x);

%%
% function 2
fs = 1000;
t = 0:1/fs:1;
f = 50;
x = sin(2*pi*f*t);
X = 0 ; % initialize output
syms z ; % defining symbol
for i =0 : l-1
    X=X+x(i+1)*z^(-i);
end
disp(x);
disp('Z-Transform X(z) = ');
pretty(X); 
title('Pole-Zero Plot');
zplane(x);
%%
% function 3
n = -10:10;
x = zeros(size(n));
x(n > 0) = 1;
x(n < 0) = 2;

l = length(x);
X = 0;
syms z;

for i = 0 : l-1
    X = X + x(i+1) * z^(-i);
end

disp(x);
disp('Z-Transform X(z) = ');
pretty(X);

% Convert symbolic expression to transfer function
[num, den] = numden(X);
num_coeffs = sym2poly(num);
den_coeffs = sym2poly(den);
H = tf(num_coeffs, den_coeffs);

% Plot the zeros and poles
figure;
zplane(num_coeffs, den_coeffs);
title('Pole-Zero Plot');



%%
% function 4
n = 0:10;
x = [1 2 3 4 5 4 3 2 1 0 -1];

% Using built-in ztrans function
syms z;
X = ztrans(x, z);

disp(x);
disp('Z-Transform X(z) = ');
pretty(X);
% Convert the signal to a transfer function
num_coeffs = x; % Numerator coefficients are the signal itself
den_coeffs = 1;  % Denominator coefficients for discrete-time system
H = tf(num_coeffs, den_coeffs);

% Plot the zeros and poles
figure;
zplane(num_coeffs, den_coeffs);
title('Pole-Zero Plot');

%%
% function 5
t = 0:0.3:2;
x = sin(2*pi*2*t) + 0.5*cos(2*pi*5*t);

l = length(x);
X = 0;
syms z;

for i = 0 : l-1
    X = X + x(i+1) * z^(-i);
end

disp(x);
disp('Z-Transform X(z) = ');
pretty(X);


% Convert symbolic expression to transfer function
[num, den] = numden(X);
num_coeffs = sym2poly(num);
den_coeffs = sym2poly(den);
H = tf(num_coeffs, den_coeffs);

% Plot the zeros and poles
figure;
zplane(num_coeffs, den_coeffs);
title('Pole-Zero Plot');

%% additinol only for zero and pole using transfer function
% Clear the workspace and command window

z = tf('z'); % Z-domain variable
% Different input transfer functions
H1 = z / (z - 0.5);
H2 = (z - 0.8) / (z^2 + 0.5*z + 0.25);
H3 = (z^2 - 1) / (z^2 + 2*z + 2);
H4 = (z - 1j) / (z + 0.5 + 0.5j);
H5 = (z + 0.7) / (z^2 - 0.5*z + 0.25);
% Plotting pole-zero plots for each transfer function
figure;
pzmap(H1);
title('Poles and Zeros - Transfer Function 1');
figure;
pzmap(H2);
title('Poles and Zeros - Transfer Function 2');
figure;
pzmap(H3);
title('Poles and Zeros - Transfer Function 3');
figure;
pzmap(H4);
title('Poles and Zeros - Transfer Function 4');
figure;
pzmap(H5);
title('Poles and Zeros - Transfer Function 5');
