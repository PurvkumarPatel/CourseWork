%DIF-FFT
x=input('enter the sequence');
X = dif_fft_with_stages(x);
% Display the final FFT result
fprintf('Final FFT Result:\n');
disp(X);
function X = dif_fft_with_stages(x)
    % Determine the length of the input sequence
    N = length(x);
    if bitand(N, N - 1) ~= 0
        N_padded = 2^nextpow2(N);
        x = [x, zeros(1, N_padded - N)];
    else
        N_padded = N;
    end
    
    stages = log2(N_padded);
    
    % Initialize cell array to store results at each stage
    stage_results = cell(1, stages);
    
    % Perform bit-reversal permutation
    indices = bitrevorder(1:N_padded);
    x = x(indices);
    
    for stage = 1:stages
        % Split the sequence into groups for this stage
        step = 2^stage;
        num_groups = N_padded / step;
        group_size = N_padded / num_groups;
        
        % Initialize arrays for this stage
        stage_result = zeros(1, N_padded);
        twiddle = exp(-2i * pi * (0:(group_size/2-1)) / group_size);
        
        for group = 1:num_groups
            % Calculate the indices for the group
            indices = (group-1) * group_size + (1:group_size);
          
            x_even = x(indices(1:group_size/2));
            x_odd = x(indices(group_size/2+1:end));

            X_even = x_even + twiddle .* x_odd;
            X_odd = x_even - twiddle .* x_odd;
            
            stage_result(indices) = [X_even, X_odd];
        end
        
        stage_results{stage} = stage_result;
    
        x = stage_result;
    end

    X = stage_results{stages};

    for stage = 1:stages
        fprintf('Stage %d:\n', stage);
        disp(stage_results{stage});
    end
end