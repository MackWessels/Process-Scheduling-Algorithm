CC=gcc
CFLAGS=-Wall

clean:
	rm -rf *.o
	rm -rf fcfs
	rm -rf sjf
	rm -rf rr
	rm -rf priority
	rm -rf priority_rr

# Build all targets
all: fcfs sjf rr priority priority_rr

# First-Come, First-Served (FCFS)
fcfs: driver.o list.o CPU.o fcfs.o schedulers.o
	$(CC) $(CFLAGS) -o fcfs driver.o fcfs.o list.o CPU.o schedulers.o

# Shortest Job First (SJF)
sjf: driver.o list.o CPU.o sjf.o schedulers.o
	$(CC) $(CFLAGS) -o sjf driver.o sjf.o list.o CPU.o schedulers.o

# Priority Scheduling
priority: driver.o list.o CPU.o priority.o schedulers.o
	$(CC) $(CFLAGS) -o priority driver.o priority.o list.o CPU.o schedulers.o

# Round Robin Scheduling
rr: driver.o list.o CPU.o rr.o schedulers.o
	$(CC) $(CFLAGS) -o rr driver.o rr.o list.o CPU.o schedulers.o

# Priority with Round Robin Scheduling
priority_rr: driver.o list.o CPU.o priority_rr.o schedulers.o
	$(CC) $(CFLAGS) -o priority_rr driver.o priority_rr.o list.o CPU.o schedulers.o

driver.o: driver.c
	$(CC) $(CFLAGS) -c driver.c

fcfs.o: fcfs.c
	$(CC) $(CFLAGS) -c fcfs.c

sjf.o: sjf.c
	$(CC) $(CFLAGS) -c sjf.c

priority.o: priority.c
	$(CC) $(CFLAGS) -c priority.c

rr.o: rr.c
	$(CC) $(CFLAGS) -c rr.c

priority_rr.o: priority_rr.c
	$(CC) $(CFLAGS) -c priority_rr.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

CPU.o: CPU.c cpu.h
	$(CC) $(CFLAGS) -c CPU.c

schedulers.o: schedulers.c schedulers.h
	$(CC) $(CFLAGS) -c schedulers.c
