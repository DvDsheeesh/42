*This project has been created as part of the 42 curriculum by babo-sai.*

# Philosophers (42)

## Description

**Philosophers** is a concurrency project in C from the 42 curriculum.
The goal is to solve the Dining Philosophers problem while handling synchronization,
timing precision, and process/thread safety.

This repository contains:

- **Mandatory version** in `philo/` using **threads** and **mutexes**
- **Bonus version** in `philo_bonus/` using **processes** and **semaphores** (`philo_bonus`)

Both implementations simulate philosophers who alternate between:

- taking forks
- eating
- sleeping
- thinking

while respecting strict timing constraints:

- `time_to_die`
- `time_to_eat`
- `time_to_sleep`

---

## Instructions

### Requirements

- Linux environment
- C compiler (`cc`)
- `make`
- `pthread` support (mandatory build uses `-pthread`)
- POSIX semaphore/process support (bonus)

### Compilation

#### Mandatory

```bash
cd philo
make
```

Creates executable:

```bash
./philo
```

#### Bonus

```bash
cd philo_bonus
make
```

Creates executable:

```bash
./philo_bonus
```

#### Useful targets (both projects)

```bash
make clean
make fclean
make re
```

### Execution

Both programs use the same argument format:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

```bash
./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

#### Examples

```bash
./philo 5 800 200 200
./philo_bonus 5 800 200 200 7
```

#### Argument Notes

- All values must be positive integers.
- The 5th argument is optional.
- If the optional argument is provided, simulation ends once all philosophers reached that meal count.

On invalid input, the program prints:

```text
Error
Usage: ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

---

## Features

- Accurate timestamped philosopher actions
- Death detection and simulation stop conditions
- Safe synchronized logging
- Input validation with overflow checks
- Clean resource destruction

### Mandatory (`philo/`)

- Thread-based implementation (`pthread`)
- Forks represented with mutexes
- Dedicated monitor thread for starvation detection
- Mutex-protected shared state (`death`, meals, printing)

### Bonus (`philo_bonus/`)

- Process-based implementation (`fork`)
- Inter-process synchronization with named semaphores
- Per-philosopher process lifecycle management
- Global monitoring and cleanup of children

---

## Project Structure

### Mandatory (`philo/`)

- `Makefile`: builds `philo`
- `philo.h`: shared structs/prototypes
- `main.c`: startup, monitor launch, thread join/cleanup
- `init.c`, `init_helpers.c`: data allocation and initialization
- `parse_args.c`: argument parsing and validation
- `thread.c`: philosopher routine and thread orchestration
- `fork.c`: fork acquisition helpers
- `monitor.c`: death/full checks and monitor routine
- `time.c`: timing, sleep precision, safe printing

### Bonus (`philo_bonus/`)

- `Makefile`: builds `philo_bonus`
- `philo.h`: shared structs/prototypes for bonus
- `main_bonus.c`: setup, process start, monitor, cleanup
- `init_bonus.c`, `init_helpers_bonus.c`: allocation and semaphore setup
- `parse_args_bonus.c`: argument parsing and validation
- `philo_process_bonus.c`, `philo_process_helpers_bonus.c`: philosopher process routine
- `monitor_bonus.c`: process monitoring and termination handling
- `time_bonus.c`: timing and synchronized printing

---

## Behavior Checklist

- No data races in mandatory shared state
- No deadlocks in normal scenarios
- Correct stop when a philosopher dies
- Correct stop when all philosophers ate enough (if optional arg is set)
- No orphan/zombie processes in bonus version
- No memory/resource leaks on normal exit and error paths

---

## Debugging and Validation

### Mandatory with ThreadSanitizer (optional)

```bash
cd philo
make re
cc -Wall -Wextra -Werror -pthread -fsanitize=thread -I. *.c -o philo_tsan
./philo_tsan 5 800 200 200
```

### Bonus process state check

```bash
ps aux | grep philo_bonus
```

Expected: no lingering zombie child processes after exit.

### Additional Test Commands

Run these from the repository root:

```bash
for i in {1..150}; do ./philo_bonus/philo_bonus 4 399 200 200 5; echo '---'; done

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --trace-children=yes --track-fds=yes ./philo_bonus/philo_bonus 6 800 200 200 5

valgrind --tool=helgrind ./philo_bonus/philo_bonus 5 810 200 200 5

valgrind --tool=helgrind ./philo/philo 5 810 200 200 5

valgrind --tool=helgrind ./philo/philo 5 310 200 200 5
```

If you prefer running from inside each folder, the equivalent commands are:

```bash
cd philo_bonus && ./philo_bonus 4 399 200 200 5
cd philo && ./philo 5 810 200 200 5
```

---

## Notes

- The mandatory and bonus implementations intentionally use different concurrency models to match 42 project requirements.
- Timing behavior may vary slightly depending on machine load and scheduler behavior.
- This project is educational and focuses on synchronization correctness and robust lifecycle handling.

---

## Resources

- `SIGKILL`   https://www.suse.com/c/observability-sigkill-vs-sigterm-a-developers-guide-to-process-termination/

- POSIX Threads (`pthread`) : https://pubs.opengroup.org/onlinepubs/7908799/xsh/pthread.h.html
- POSIX Semaphores (`sem_open`, `sem_wait`, `sem_post`) https://www.qnx.com/developers/docs/8.0/com.qnx.doc.neutrino.lib_ref/topic/s/sem_open.html
- UNIX process : https://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/fork/create.html
and 
https://medium.com/@The_Anshuman/lets-understand-fork-in-linux-cb59e56ceb41

### AI Usage

AI tools were used as an assistant for:

- Explaining concurrency concepts (deadlock, starvation, synchronization patterns)
- Brainstorming edge-case test scenarios and evaluation questions
- Improving README wording and structure in English

AI was not used to replace core implementation work. The project code architecture, coding, debugging, and final validation were done by the authors.

---

## Evaluation Prep

Prepared for 42 viva/evaluation based on this repository implementation.

## 1) General Understanding

### Q1: What is the Dining Philosophers problem?
A: It is a classic synchronization problem where N philosophers sit around a table with N forks (one between each pair). A philosopher needs two forks to eat. The challenge is to coordinate concurrent access to shared resources (forks) safely.

### Q2: Why is this problem important?
A: It demonstrates core concurrency issues:
- Deadlock
- Starvation
- Race conditions
- Shared resource contention

### Q3: Real-world analogy?
A: Similar patterns appear in database locks, OS schedulers, thread pools, and services competing for limited resources.

## 2) Program Arguments

### Q4: Explain arguments
`./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat_count]`
- number_of_philosophers: number of philosophers/forks
- time_to_die: max ms without eating
- time_to_eat: ms spent eating
- time_to_sleep: ms spent sleeping
- must_eat_count (optional): simulation stops after all philosophers reach this count

All times are milliseconds.

### Q5: What if optional argument is missing?
A: Simulation continues until a philosopher dies.

### Q6: Invalid input behavior?
A: Code validates positive integer format and overflow (`INT_MAX` guard). On invalid input, it prints:
- Error
- Usage line
and exits with failure.

## 3) Mandatory Version (Threads + Mutexes)

### Q7: How many threads are created?
A: `N + 1`
- N philosopher threads
- 1 monitor thread

### Q8: Why monitor thread?
A: It periodically checks:
- death condition for each philosopher
- completion condition when `must_eat_count > 0`

### Q9: How many mutexes are used?
A:
- N fork mutexes (`data->forks[i]`)
- 1 print mutex (`print_mutex`)
- 1 death mutex (`death_mutex`)
cd philo_bonus && make
./philo_bonus 5 800 200 200
./philo_bonus 5 800 200 200 7
Total: `N + 3`

### Q10: Why print mutex?
A: To keep output lines atomic and readable, preventing interleaved `printf` from multiple threads.

### Q11: What does `death_mutex` protect?
A: Shared `dead` flag and coordination with `safe_print` to avoid printing after termination.

### Q12: What does `meal_mutex` protect?
A:
- `last_meal`
- `meals_eaten`
for all philosophers.

## 4) Deadlock Prevention

### Q13: What strategy does this code use?
A: Fork ordering by index (resource ordering). Each philosopher stores:
- `first_fork = min(left, right)`
- `second_fork = max(left, right)`

So every thread acquires lower-index fork first, then higher-index fork.

### Q14: Why does it prevent deadlock?
A: It breaks circular wait. A strict global order on resource acquisition prevents circular dependency among threads.

### Q15: Is it even/odd ordering?
A: No in this repository. It is global fork-index ordering (initialized in `init_philosopher`).

## 5) Special Cases

### Q16: What happens with one philosopher?
A: `handle_single_fork` handles it:
- takes the only fork
- prints fork message
- waits until death flag is set
- releases fork
A single philosopher cannot eat (needs two forks).

### Q17: What if simulation ends while holding forks?
A: Acquire functions check `is_dead` and unlock before return on stop path. In normal eat flow forks are unlocked after eating.

## 6) Time and Death Detection

### Q18: How is time measured?
A: `gettimeofday`, converted to milliseconds in `get_time`.

### Q19: How is timestamp printed?
A: `timestamp(data) = get_time() - data->start_time`.

### Q20: How does sleep precision work?
A: `ft_usleep` loops with short `usleep(500)` intervals and stop checks (`!is_dead(data)`) for responsive shutdown.

### Q21: Death condition?
A: In monitor:
`if ((get_time() - last_meal) > time_to_die)` then mark dead and print `died` once.

## 7) Philosopher Lifecycle

### Q22: Routine flow?
- optional small initial delay for even IDs
- take first fork
- take second fork
- update `last_meal`
- print eating
- eat (`ft_usleep(time_to_eat)`)
- increment `meals_eaten`
- release forks
- print sleeping
- sleep
- print thinking
- repeat until death/completion

### Q23: How is `must_eat_count` handled?
- per-philosopher early break when own count reached
- monitor also checks global completion (`are_all_philosophers_full`) and stops simulation.

## 8) Error Handling and Cleanup

### Q24: Memory allocation failures?
A: `init_data` checks each allocation/init step and returns failure safely.

### Q25: Thread creation failure?
A: In `start_threads`, if creation fails:
- sets dead flag
- joins already-created threads
- returns failure

### Q26: Cleanup path?
A: `free_data`:
- join path is handled before call
- destroys fork mutexes + global mutexes
- frees arrays (`threads`, `philos`, `forks`)

## 9) Bonus Version (Processes + Semaphores)

### Q27: Main concurrency model?
A: `philo_bonus` uses processes (`fork`) and named semaphores.

### Q28: Which semaphores exist?
A: In bonus data:
- `forks`
- `take_sem`
- `print_sem`
- `death_sem`

### Q29: Why bonus is useful?
A: Demonstrates inter-process synchronization and lifecycle control, not just thread-level locking.

## 10) Evaluation Test Set

### Q30: Minimal strong test set
```bash
# mandatory
cd philo && make
./philo 1 800 200 200
./philo 5 800 200 200
./philo 5 800 200 200 7
./philo 4 410 200 200
./philo 100 800 200 200

# invalid args
./philo
./philo 0 800 200 200
./philo 5 -1 200 200
./philo 5 a 200 200

# bonus
cd philo_bonus && make
./philo_bonus 5 800 200 200
./philo_bonus 5 800 200 200 7
```

### Q31: How to detect deadlock quickly?
- Output freezes for long duration
- No new `is eating` events
cc -Wall -Wextra -Werror -pthread -fsanitize=thread -I. *.c -o philo_tsan

### Q32: How to check starvation?
- Watch for `died` lines under normal safe parameters
- Compare meal distribution using log analysis (`grep "is eating"`)


### Q33: Why lock order matters?
A: Deterministic global order removes circular wait.

### Q34: Why not use plain `sleep`?
A: Lower responsiveness. `ft_usleep` allows frequent stop checks.

### Q35: Why separate death and print mutexes?
A: To protect state correctness (`dead`) and output atomicity independently.

### Q36: Why monitor polling delay exists (`usleep(500)`)?
A: Reduces CPU usage while keeping fast enough death detection.

### Q37: Can this still starve in theory?
A: Deadlock is prevented; starvation risk is reduced by timing strategy and scheduling, but fairness is not mathematically strict in all OS scheduling conditions.

## 12) Code Map

Mandatory references:
- [philo/main.c](philo/main.c)
- [philo/thread.c](philo/thread.c)
- [philo/monitor.c](philo/monitor.c)
- [philo/fork.c](philo/fork.c)
- [philo/time.c](philo/time.c)
- [philo/init.c](philo/init.c)
- [philo/init_helpers.c](philo/init_helpers.c)
- [philo/parse_args.c](philo/parse_args.c)

Bonus references:
- [philo_bonus/main.c](philo_bonus/main_bonus.c)
- [philo_bonus/philo_process_bonus.c](philo_bonus/philo_process_bonus.c)
- [philo_bonus/monitor_bonus.c](philo_bonus/monitor_bonus.c)
- [philo_bonus/init_bonus.c](philo_bonus/init_bonus.c)
- [philo_bonus/parse_args_bonus.c](philo_bonus/parse_args_bonus.c)
