SOURCES := $(shell find src -name '*.cpp')
OBJS := $(SOURCES:%.cpp=%.o)
TESTSOURCES := $(filter-out $(wildcard src/main*), $(SOURCES) $(shell find test -name '*.cpp'))
TESTOBJS := $(filter-out $(wildcard src/main*), $(TESTSOURCES:%.cpp=%.o))
DFLAG?=debug
PCH_SRC = src/precompile.h
PCH_HEADERS = src/places.h
PCH_OUT = src/precompile.h.gch

ifeq ($(shell sh -c 'uname -s'),Linux)
	LIBFLAGS=-L. -Wl,-rpath=.
else
	LIBFLAGS=-Llib -static-libgcc -static-libstdc++
endif

ifneq (,$(findstring release,$(MAKECMDGOALS)))
	CFLAGS=-std=c++11 -O2 -s
else
	CFLAGS=-std=c++11 -g
endif

help :
	@echo "Welcome to Islander Makefile!"
	@echo "Commands available are:"
	@echo "make debug		# Compiles islander to ./bin/islander, runs unit tests, then runs a clean"
	@echo "make release		# Compiles islander to ./bin/islander with compiler flags to optimise for executable size + speed, runs unit tests, then runs a clean"
	@echo "make islander		# Compiles islander to ./bin/islander, then runs unit tests"
	@echo "make clean		# Removes all *.o files in the project"
	@echo "make unit_test		# Compiles the test executable to ./bin/test_islander, then runs unit tests"
	@echo "make dockerislander	# Runs compilation and unit tests in a container, then copies executables out to ./bin/"
	@echo "make dockerclean	# Removes the islander container"
	@echo "make dockercp		# Copies executables out from the islander container, and into ./bin"
	@echo "make dockerrun		# Runs given target in islander container (defaults to debug)"
	@echo "make dockerbuild	# Builds the islander container"

debug : islander clean

release : islander clean

islander : $(OBJS) unit_test
	g++ $(OBJS) -o bin/islander -Wall $(LIBFLAGS) $(CFLAGS)

clean :
	rm -f $(OBJS) $(TESTOBJS)

$(PCH_OUT): $(PCH_SRC) $(PCH_HEADERS)
	g++ -Iinclude -Wall $(CFLAGS) -o $@ $<

%.o : %.cpp $(PCH_OUT)
	g++ $< -c -o $@ -include $(PCH_SRC) -Iinclude -Wall $(CFLAGS)

unit_test : test
	./bin/test_islander -fc

test : $(TESTOBJS)
	g++ $(TESTOBJS) -o bin/test_islander -Wall $(LIBFLAGS) $(CFLAGS)

dockerislander : dockercp
	make dockerclean

dockerclean :
	docker rm islanderbuilder

dockercp : dockerrun
	docker cp islanderbuilder:/islander/bin/islander ./bin && docker cp islanderbuilder:/islander/bin/test_islander ./bin

dockerrun : dockerbuild
	docker run --name islanderbuilder iislanderbuilder make clean $(DFLAG)

dockerbuild :
	docker build -t iislanderbuilder .
