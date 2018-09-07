SHELL = /bin/sh
CC = g++
GCC_VERSION := $(shell g++ -dumpversion | awk -F . '{ print $$1 }')
DEBUG = -g -Wall -Wextra -Wlogical-op -Wdouble-promotion -Wshadow -Wformat=2 -Wduplicated-cond -Wnull-dereference -Wduplicated-branches 
CXXFLAGS = -std=c++11 $(DEBUG)

libdir = lib
bindir = bin
docker_tag = dsifford/lab01_task02

targets = $(filter-out main,$(patsubst %.cpp, %, $(wildcard *.cpp)))
headers = $(wildcard *.h)

.PHONY: all
all: installdirs main

.PHONY: docker
docker:
	@ docker rmi $(shell docker images -q --filter dangling=true) 2>/dev/null || true
	@ docker build -t $(docker_tag) -f ../../Dockerfile .
	@ docker run --rm -it $(docker_tag)

.PHONY: installdirs
installdirs: 
	@ mkdir -p $(bindir) $(libdir)

main: $(targets:%=$(libdir)/%.o) $(headers)
	$(CC) $(CXXFLAGS) $? $@.cpp -o $(bindir)/$@

$(libdir)/%.o: %.cpp $(headers)
	$(CC) -c $(CXXFLAGS) $< -o $@

