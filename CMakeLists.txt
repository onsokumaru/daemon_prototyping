cmake_minimum_required(VERSION 3.15)

project(daemon_programs
        VERSION 0.1.0
        LANGUAGES C)

add_compile_options(-g) # enable gdb debugging 

add_executable(simple_getpid src/simple_getpid.c)
add_executable(fork_once src/fork_once.c)
add_executable(fork_and_term src/fork_and_terminate.c)
add_executable(fork_twice src/fork_twice.c)
add_executable(double_fork src/double_fork.c)
add_executable(daemon1 src/daemon_test1.c)
add_executable(daemon2 src/daemon_test2.c)
add_executable(write_pid src/write_pid.c)
add_executable(create_pidfile src/create_pidfile.c)
add_executable(read_pidfile src/read_pidfile.c)
add_executable(is_running src/is_running.c)
