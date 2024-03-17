function X = myDFT(x)
  N = length(x); % Length of signal
  X = zeros(1,N); % Initialize DFT coefficients
  for k = 1:N
      for n = 1:N
        X(k) = X(k) + x(n)*exp(-1i*2*pi*(k-1)*(n-1)/N);
     end
  end
end
