
.PHONY: test

test: test_cust_strtok
	./test_cust_strtok

test_cust_strtok: test_cust_strtok.c cust_strtok.c cust_strtok.h
	gcc -o $@ $^
