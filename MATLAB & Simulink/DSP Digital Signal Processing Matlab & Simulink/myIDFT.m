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
