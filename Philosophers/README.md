# Philosophers - a possible solving of resource starvation task

The description of the classical problem can be found [here](https://en.wikipedia.org/wiki/Dining_philosophers_problem).

In this repo, you will find a practical try to solve this problem with the use of multithreading.

In the beginning, there are equal amounts of threads (philosophers) and mutexes(forks). Every thread performs actions (eating) and blocks resources, and then gives resources to another one. 

The threads have a defined time to be alive, after which the program stops: a philosopher is unable to eat dies from starvation. 

The problem is considered to be solved if philosophers avoid dying with adequate eating and starving times.

## Usage

1. `make` in the root directory
2. Execute following command `./philo <number of philosophers> <time to die> <time to eat> <time to sleep> <eating times>`
    
    * `number of philosophers` - any positive integer. Defines a number of threads.
    * `time to die` - time in milliseconds, should be >= 60 ms. Defines a time period after the last resource usage, during which a thread is alive.
    * `time to eat` - time in milliseconds, should be >= 60 ms. Defines a resource usage time period.
    * `time to sleep` - time in milliseconds, should be >= 60 ms. Defines a time period after the last resource usage, during which a thread cannot use available resources.
    * `eating times` - optional parameter, any positive integer. Defines a number of times each thread should use resources. When every thread achieves this number, the program stops.

Valid example:

```bash
./philo 5 800 200 200
```

**Terminal output**:

```bash
<time since the start of the program in ms> : <philosopher ID> <philosopher state>
```

Example:

```bash
./philo 5 800 200 200
0 ms: Philosopher 1 has taken a left fork
0 ms: Philosopher 1 has taken a right fork
0 ms: Philosopher 1 is eating
3 ms: Philosopher 3 has taken a left fork
3 ms: Philosopher 3 has taken a right fork
3 ms: Philosopher 3 is eating
201 ms: Philosopher 1 is sleeping
201 ms: Philosopher 5 has taken a left fork
201 ms: Philosopher 5 has taken a right fork
201 ms: Philosopher 5 is eating
```