##############################################################################
# Makefile for MST application
# CMP_SC 3050
# Spring 2023
# By Jim Ries (RiesJ@missouri.edu)
##############################################################################
CC = gcc
CFLAGS = -Wall -Werror -c -g -std=c11 -I.
LDFLAGS = -lm -lcs3050 -L.

default: mst

%.o : %.c 
	@echo Compiling $^ ...
	@$(CC) $(CFLAGS) $^

mst : main.o mst.o libcs3050.a
	@echo Linking $@ ...
	@$(CC) $^ $(LDFLAGS) -o $@
	@echo Done!

clean : 
	@rm -rf *.o
	@rm -rf mst
	@echo All Clean!
