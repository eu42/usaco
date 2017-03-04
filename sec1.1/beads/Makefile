
SHELL := /bin/bash
all: make run check
make: beads.cpp
	g++ beads.cpp
run: a.out
	bash -c "./a.out"
check: expected.out beads.out
	bash -c "comm expected.out beads.out"

