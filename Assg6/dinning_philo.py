import threading
import time
import random

# Number of philosophers
num_philosophers = 5

# Locks for chopsticks
chopsticks = [threading.Lock() for _ in range(num_philosophers)]

# Function for a philosopher to eat
def philosopher(id):
    left_chopstick = chopsticks[id]
    right_chopstick = chopsticks[(id + 1) % num_philosophers]

    while True:
        # Think for a while
        time.sleep(random.uniform(0, 1))

        # Try to pick up chopsticks
        print(f"Philosopher {id} is hungry and trying to pick up chopsticks.")
        left_chopstick.acquire()
        right_chopstick.acquire()

        # Eat for a while
        print(f"Philosopher {id} is eating.")
        time.sleep(random.uniform(0, 1))

        # Release chopsticks
        left_chopstick.release()
        right_chopstick.release()

        print(f"Philosopher {id} is done eating and returning to thinking.")

# Create philosopher threads
philosophers = [threading.Thread(target=philosopher, args=(i,)) for i in range(num_philosophers)]

# Start philosopher threads
for philosopher in philosophers:
    philosopher.start()

# Wait for philosopher threads to finish
for philosopher in philosophers:
    philosopher.join()
