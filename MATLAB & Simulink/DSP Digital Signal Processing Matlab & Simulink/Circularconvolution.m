% To Plot the Circular Convolution in MATLAB.

clc;
close all;
a = [1, 2, 1, 2];
h = [1, 2, 3, 4];

x = a;
N = length(x);
C = zeros(N, N);
for i = 1:N
    C(i, :) = circshift(h, i-1);
end

% Perform circular convolution
result = sum(C);

% Display the circular convolution result
disp('Circular Convolution Result:');
disp(result);

dt = 100/length(x);
% Create a figure

% Plot circles with values of x as text labels
    theta = linspace(0, 2*pi, 100);
    circle_x = cos(theta);
    circle_y = sin(theta);
    figure
    plot(circle_x, circle_y, 'k', 'Color', 'b', 'LineWidth', 1);  % Plot the circle
    axis equal;
    xlim([-1.5, 1.5]);
    ylim([-1.5, 1.5]);
    hold on;
    for i = 1:length(x)
        text(circle_x(i*dt), circle_y(i*dt), num2str(x(i)), 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle', 'EdgeColor', 'r', 'LineWidth', 3);
    end
    title('Circle (x values)');
    hold off;
 figure
 hold on;
for j=1:N
    x = C(j,:);
    theta = linspace(0, 2*pi, 100);
    circle_x = cos(theta);
    circle_y = sin(theta);
   
    subplot(2,2,j);
    plot(circle_x, circle_y, 'k', 'Color', 'b', 'LineWidth', 1);  % Plot the circle
    axis equal;
    xlim([-1.5, 1.5]);
    ylim([-1.5, 1.5]);
    
    for i = 1:length(x)
        text(circle_x(i*dt), circle_y(i*dt), num2str(x(i)), 'HorizontalAlignment', 'center', 'VerticalAlignment', 'middle', 'EdgeColor', 'r', 'LineWidth', 3);
    end
    title('Circle (x values)');
    
end
hold off;