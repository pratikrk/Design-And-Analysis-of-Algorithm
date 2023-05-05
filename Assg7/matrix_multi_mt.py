import threading
import random
import time

def multiply_matrices(A, B):
    m = len(A)
    n = len(B[0])
    result = [[0] * n for _ in range(m)]
    threads = []
    
    def multiply_rows(start, end):
        for i in range(start, end):
            for j in range(n):
                for k in range(len(B)):
                    result[i][j] += A[i][k] * B[k][j]
    
    num_threads = min(m, threading.active_count() + 1)
    chunk_size = m // num_threads
    
    for i in range(num_threads):
        start = i * chunk_size
        end = start + chunk_size if i < num_threads - 1 else m
        thread = threading.Thread(target=multiply_rows, args=(start, end))
        threads.append(thread)
        thread.start()
    
    for thread in threads:
        thread.join()
    
    return result

# Generate two random 1000x1000 matrices
A = [[random.randint(0, 100) for j in range(50)] for i in range(40)]
B = [[random.randint(0, 100) for j in range(40)] for i in range(50)]

# Run the multiplication with timing
start_time = time.time()
result = multiply_matrices(A, B)
end_time = time.time()

print(f"Multiplication took {end_time - start_time:.2f} seconds")

print(multiply_matrices(A, B))
