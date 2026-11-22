*This project has been created as part of the 42 curriculum by melshata.*

# Philosophers

A multithreaded simulation of the classic **Dining Philosophers problem**, written in C using POSIX threads and mutexes.

## Description

The Dining Philosophers problem, formulated by Edsger Dijkstra in 1965, is a classic illustration of the challenges of concurrent programming: synchronization, mutual exclusion, deadlock, and starvation.

A number of philosophers sit around a circular table. Between every two neighboring philosophers lies a single fork, and each philosopher needs **two forks** (the one on their left and the one on their right) to eat. Each philosopher endlessly cycles through three states:

- **Eating** — requires holding both forks
- **Sleeping** — once done eating
- **Thinking** — once done sleeping, before getting hungry again

If a philosopher doesn't get to eat in time, they die — and the simulation must detect and report that death as close to real time as possible.

The goal of this project is to implement this simulation correctly using **threads** (one per philosopher) and **mutexes** (one per fork), while:

- Never letting two philosophers use the same fork at the same time
- Avoiding deadlock (no situation where all philosophers wait on each other forever)
- Avoiding unnecessary starvation (no philosopher should die if it doesn't have to, given the timing arguments)
- Detecting deaths within a few milliseconds of them actually happening
- Stopping the whole simulation cleanly and promptly, whether it stops because of a death or because every philosopher has eaten enough times

## Instructions

### Compilation

```sh
make
```

This compiles the project with `cc -Wall -Wextra -Werror -pthread` and produces an executable named `philo` at the root of the project.

Other Makefile rules:

```sh
make clean   # remove object files
make fclean  # remove object files and the executable
make re      # fclean + all
```

### Usage

```sh
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

| Argument | Meaning |
|---|---|
| `number_of_philosophers` | Number of philosophers, and number of forks |
| `time_to_die` (ms) | If a philosopher hasn't started eating within this much time since their last meal (or the start of the simulation), they die |
| `time_to_eat` (ms) | Time it takes a philosopher to eat once they have both forks |
| `time_to_sleep` (ms) | Time a philosopher spends sleeping after eating |
| `number_of_times_each_philosopher_must_eat` (optional) | If given, the simulation stops as soon as every philosopher has eaten at least this many times |

All arguments must be positive integers.

### Examples

```sh
# 5 philosophers, nobody should die
./philo 5 800 200 200

# 1 philosopher: can only ever pick up one fork, so they die
./philo 1 800 200 200

# Stops automatically once everyone has eaten 7 times
./philo 5 800 200 200 7
```

Each line of output follows the format:

```
timestamp_in_ms philosopher_id action
```

where `action` is one of: `has taken a fork`, `is eating`, `is sleeping`, `is thinking`, `died`.

## Technical choices

- **One mutex per fork**, plus a small set of mutexes to protect shared state (the "stop" flag combined with output printing, and each philosopher's own last-meal-time / meal-count).
- **Deadlock avoidance**: each philosopher always locks the lower-indexed fork first, regardless of which one is logically their "left" or "right" fork. This total ordering on lock acquisition makes a circular wait — and therefore deadlock — impossible.
- **Reduced lock-contention chains**: philosophers with an odd ID wait briefly before their first attempt at the forks, so that non-adjacent philosophers tend to start competing for disjoint pairs of forks instead of all racing for the same fork at once.
- **Non-blocking second fork acquisition**: after taking the first fork, a philosopher polls (`pthread_mutex_trylock`) for the second one instead of blocking on it indefinitely. If the simulation is stopped while waiting, the philosopher releases the first fork immediately instead of holding it pointlessly.
- **Interruptible waiting**: the sleep/think/eat delays are implemented as a polling loop that checks the shared "stop" flag every 500µs, so that as soon as one philosopher dies (or everyone has eaten enough), every other thread wakes up and exits promptly — instead of the program staying alive until the longest-sleeping philosopher's timer naturally runs out.
- **A dedicated monitor thread** continuously checks every philosopher's last meal time against `time_to_die`, and (if relevant) whether everyone has reached the required meal count, and is the only thread responsible for ending the simulation.
- **Special case for a single philosopher**: with only one philosopher there is only one fork, so they can never eat — they simply hold their one fork and die after `time_to_die`, without ever attempting to lock a second fork (which would deadlock against themselves).

## Project structure

```
.
├── Makefile
├── philo.h       # shared structs and prototypes
├── main.c        # entry point, thread creation/joining
├── parsing.c     # argument validation and parsing
├── init.c        # allocation and initialization of shared data
├── routine.c     # a philosopher's life cycle (eat / sleep / think)
├── monitor.c     # death detection and meal-count checking
├── print.c       # thread-safe, death-aware logging
└── utils.c       # small helpers (ft_atoi, timing, interruptible sleep)
```

## Resources

### Classic references

- E. W. Dijkstra, *Hierarchical ordering of sequential processes* (1971) — the paper that introduced the dining philosophers problem
- [POSIX Threads Programming (LLNL tutorial)](https://hpc-tutorials.llnl.gov/posix/)
- `man pthread_create`, `man pthread_mutex_lock`, `man pthread_join`, `man gettimeofday`, `man usleep`
- [The Little Book of Semaphores](https://greenteapress.com/wp/semaphores/) by Allen B. Downey — chapter on the dining philosophers problem, for context on the broader family of solutions (including the semaphore-based one used in the bonus part of this project)
- Wikipedia: [Dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) and [Resource hierarchy solution](https://en.wikipedia.org/wiki/Dining_philosophers_problem#Resource_hierarchy_solution)

### AI usage
### AI usage

An AI assistant (Claude, by Anthropic) was used as a reviewer and debugging aid:

- Explaining the dining philosophers problem and the synchronization concepts
  involved (deadlock avoidance via lock ordering, starvation, race conditions
  on shared state)
- Diagnosing two specific bugs found during testing: a starvation case caused
  by a "domino" effect in fork acquisition under tight timing, and a shutdown
  hang caused by a non-interruptible sleep delay
- Discussing possible fixes and trade-offs for both issues

The implementation itself — the code in this repository — was written
independently, based on that understanding.
