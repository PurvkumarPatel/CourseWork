import math

def incremental_search(func, x0, delta_x, max_iterations):
    x = x0
    iterations = 0
    while iterations < max_iterations:
        x_next = x + delta_x
        if func(x) * func(x_next) < 0:
            return x, x_next
        x = x_next
        iterations += 1
    return None, None

def bisection(func, a, b, tolerance, max_iterations):
    if func(a) * func(b) >= 0:
        return None
    a_n = a
    b_n = b
    for n in range(max_iterations):
        m_n = (a_n + b_n) / 2
        if abs(func(m_n)) < tolerance:
            return round(m_n, -int(math.log10(tolerance)))
        if func(a_n) * func(m_n) < 0:
            b_n = m_n
        else:
            a_n = m_n
    return None

def newton_raphson(func, x0, tolerance, max_iterations):
    x = x0
    for n in range(max_iterations):
        fx = func(x)
        if abs(fx) < tolerance:
            return round(x, -int(math.log10(tolerance)))
        derivative = (func(x + tolerance) - func(x)) / tolerance
        x = x - fx / derivative
    return None

while True:
    print("\nNumerical Methods Menu:")
    print("1. Incremental Search Method")
    print("2. Bisection Method")
    print("3. Newton-Raphson Method")
    print("4. Exit")
    
    choice = input("Enter your choice (1/2/3/4): ")
    
    if choice == '1':
        func_str = input("Enter the function in terms of x (e.g., x**2 - 4): ")
        func = lambda x: eval(func_str)
        x0 = float(input("Enter x0: "))
        delta_x = float(input("Enter delta_x: "))
        max_iterations = int(input("Enter max_iterations: "))
        result = incremental_search(func, x0, delta_x, max_iterations)
        if result[0] is not None:
            print(f"Roots found in the interval: [{result[0]}, {result[1]}]")
        else:
            print("Root not found in the given interval.")
    
    elif choice == '2':
        func_str = input("Enter the function in terms of x (e.g., x**2 - 4): ")
        func = lambda x: eval(func_str)
        a = float(input("Enter a: "))
        b = float(input("Enter b: "))
        tolerance = float(input("Enter tolerance: "))
        max_iterations = int(input("Enter max_iterations: "))
        result = bisection(func, a, b, tolerance, max_iterations)
        if result is not None:
            print(f"Approximate root found: {result}")
        else:
            print("Root not found in the given interval or max_iterations exceeded.")
    
    elif choice == '3':
        func_str = input("Enter the function in terms of x (e.g., x**2 - 4): ")
        func = lambda x: eval(func_str)
        x0 = float(input("Enter x0: "))
        tolerance = float(input("Enter tolerance: "))
        max_iterations = int(input("Enter max_iterations: "))
        result = newton_raphson(func, x0, tolerance, max_iterations)
        if result is not None:
            print(f"Approximate root found: {result}")
        else:
            print("Root not found or max_iterations exceeded.")
    
    elif choice == '4':
        print("Exiting the program.")
        break
    
    else:
        print("Invalid choice. Please enter a valid option (1/2/3/4).")
