C_PROGRAMS  += test/log

run-tests: run-log-tests
run-log-tests:
	sh run-tests.sh test/log

depend: log-depend
log-depend:
	cdeps src/log > src/log/depends.makefile

log-tests: test/log

test/log: src/log/log.o
test/log: src/log/test/log.test.o

tests: log-tests
