# Philosophers

This Repositorie contains my solution to the project `Philosophers` of 42 (Paris).

## Cloning

```shell
git clone https://github.com/Freya-Tenebrae/Philosopher.git
```

## Using

```shell
./philo [number_of_philosophers] [time_to_die time_to_eat] [time_to_sleep] ([number_of_times_each_philosopher_must_eat])
```

### Example

```shell
./philo 4 420 200 200 2
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
201 3 is sleeping
201 4 has taken a fork
202 1 is sleeping
202 4 has taken a fork
202 4 is eating
202 2 has taken a fork
202 2 has taken a fork
202 2 is eating
403 4 is sleeping
403 3 is thinking
403 1 is thinking
403 2 is sleeping
405 3 has taken a fork
405 3 has taken a fork
405 3 is eating
405 1 has taken a fork
405 1 has taken a fork
405 1 is eating
604 4 is thinking
605 1 is sleeping
605 2 is thinking
605 3 is sleeping
607 4 has taken a fork
607 4 has taken a fork
607 4 is eating
608 2 has taken a fork
608 2 has taken a fork
608 2 is eating
```
```shell
./philo 4 200 200 200   
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
200 1 died
```

```shell
./philo 200 800 200 200 5
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
0 3 has taken a fork
0 3 has taken a fork
0 3 is eating
0 5 has taken a fork
0 5 has taken a fork
0 5 is eating
0 7 has taken a fork
0 7 has taken a fork
0 7 is eating
0 9 has taken a fork
0 9 has taken a fork
0 9 is eating
0 11 has taken a fork
0 11 has taken a fork
...
...
...
2033 59 is thinking
2033 120 is sleeping
2033 119 has taken a fork
2035 119 has taken a fork
2035 119 is eating
2033 53 is thinking
2035 58 is sleeping
2033 156 is sleeping
2035 36 is sleeping
2035 35 has taken a fork
2035 35 has taken a fork
2035 35 is eating
2035 31 has taken a fork
```
