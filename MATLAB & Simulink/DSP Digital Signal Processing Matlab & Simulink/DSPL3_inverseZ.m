% Define the rational Z-transforms
syms z;
X1_z = 1 / (z - 0.5);
X2_z = z / (z - 0.8);
X3_z = (z^2 + z + 1) / (z^2 - 0.6*z + 0.09);
X4_z = (z - 0.5) / (z^2 + 0.2*z + 0.09);
X5_z = (z^2 - 1) / (z^3 + 0.2*z^2 - 0.2*z - 0.04);

% Parameters for inverse Z-transform
n = 0:10; % Time indices

% Initialize inverse Z-transforms
x_n_without_builtin = sym(zeros(5, length(n)));
x_n_with_builtin = cell(1, 5);

% Calculate inverse Z-transform using the definition
Z_transforms = {X1_z, X2_z, X3_z, X4_z, X5_z};

for i = 1:length(Z_transforms)
    X_z = Z_transforms{i};
    x_n_with_builtin{i} = iztrans(X_z);
    
    for k = 1:length(n)
        x_n_without_builtin(i, k) = subs(X_z, z, n(k));
    end
end

% Display inverse Z-transforms
for i = 1:length(Z_transforms)
    disp(['Inverse Z-transform of X', num2str(i), '(z) without built-in function:']);
    pretty(x_n_without_builtin(i, :));
end

disp('Inverse Z-transforms with built-in function:');
for i = 1:length(Z_transforms)
    disp(['Inverse Z-transform of X', num2str(i), '(z) with built-in function:']);
    pretty(x_n_with_builtin{i});
end