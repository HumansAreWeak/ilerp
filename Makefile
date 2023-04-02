.PHONY: compile_test run_test test

compile_test:
	gcc ilerp_test.c -o ilerp_test

run_test:
	./ilerp_test

# MinGW LOVES to add this .exe suffix to things
run_test_win:
	./ilerp_test.exe

test: compile_test run_test

test_win: compile_test run_test_win
