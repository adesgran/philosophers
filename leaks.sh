PHILO_INPUT="2 200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="4 200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="1 200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="0 200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="4 -200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="4 200 200 200 20"
echo "Input ${PHILO_INPUT}"
valgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="4 200a 200 200"
echo "Input ${PHILO_INPUT}"
valgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="2 200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind --tool=helgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="4 200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind --tool=helgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="1 200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind --tool=helgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="0 200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind --tool=helgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="4 -200 200 200"
echo "Input ${PHILO_INPUT}"
valgrind --tool=helgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="4 200 200 200 20"
echo "Input ${PHILO_INPUT}"
valgrind --tool=helgrind ./philo ${PHILO_INPUT}
echo
echo
echo
PHILO_INPUT="4 200a 200 200"
echo "Input ${PHILO_INPUT}"
valgrind --tool=helgrind ./philo ${PHILO_INPUT}
