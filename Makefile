CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O3 -Ibin -I.
FLEX = flex
BISON = bison
LINT = cpplint

B = bin

SRCS = 	main/main.cc parser/driver.cc parser/nodes.cc \
		eval/interpreter.cc eval/result.cc eval/env.cc
SCAN 	= parser/scanner.ll
PARSE 	= parser/parser.yy
SCANCC 	= $(SCAN:parser/%.ll=$(B)/%.cc)
PARSECC = $(PARSE:parser/%.yy=$(B)/%.cc)
TARGET 	= $(B)/main

.PHONY: clean prebuild all
all: clean prebuild $(TARGET)

clean:
	rm -rf $(B)

prebuild:
	mkdir -p $(B)

$(TARGET): $(SRCS) $(PARSECC) $(SCANCC)
	# -@$(LINT) $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(PARSECC): $(PARSE)
	$(BISON) -o $@ $^ -v

$(SCANCC): $(SCAN)
	$(FLEX) -o $@ $^

