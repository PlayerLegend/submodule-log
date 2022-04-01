C_PROGRAMS  += test/log

run-tests: run-log-tests
run-log-tests:
	sh run-tests.sh test/log

depend: log-depend
log-depend:
	sh makedepend.sh src/log/log.makefile

log-tests: test/log

test/log: src/log/log.o
test/log: src/log/test/log.test.o

tests: log-tests

# DO NOT DELETE

src/log/log.o: src/log/log.h
src/log/test/log.test.o: src/log/log.h
